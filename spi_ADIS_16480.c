#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdint.h>
#include <string.h>
#include <sys/time.h>

#include "libsoc_spi.h"
#include "libsoc_debug.h"

/**
 * 
 * This SPI interface for the ADIS16480 IMU is based on libsoc library by Jack Mitchell
 * Author: Raphael Nagel
 * Date: 04/June/2014
 */
 
//Define the SPI line and chip select line 
#define SPI_DEVICE   1
#define CHIP_SELECT  0


/*ADIS 16480 Register Pages*/
#define PG0 0x80  // Output data, clock, identification
#define PG1 0x81  // Reserved
#define PG2 0x82  // Calibration
#define PG3 0x83  // Control: sample rate, filtering, I/O, alarms
#define PG4 0x84  // Serial number
#define PG5 0x85  // FIR Filter Bank A Coefficient 0 to Coefficient 59
#define PG6 0x86  // FIR Filter Bank A, Coefficient 60 to Coefficient 119
#define PG7 0x87  // FIR Filter Bank B, Coefficient 0 to Coefficient 59
#define PG8 0x88  // FIR Filter Bank B, Coefficient 60 to Coefficient 119
#define PG9 0x89  // FIR Filter Bank C, Coefficient 0 to Coefficient 59
#define PG10 0x8A // FIR Filter Bank C, Coefficient 60 to Coefficient 119
#define PG11 0x8B // FIR Filter Bank D, Coefficient 0 to Coefficient 59
#define PG12 0x8C // FIR Filter Bank D, Coefficient 60 to Coefficient 119

/*Registers needed for the UWEsub's use of the */ 
#define PROD_ID 0x7e        // Product ID register which is stable and predefined to be 0x4060 = .16480 = 0b0100 0000 0110 0000
#define DIAG_STS 0x0A       // Register holding the startup self test results
#define SYS_E_FLAG 0x0800   // Holds the System Error Flags and new Data flags for the Barometer and Magnetometer

/*Bitmasks*/

#define BITMASK_b15to12_7to_6     0x0F3F
#define BITMASK_b2to3             0xBFF9

#define BITMASK_DIAG_STS_BARO     0x0800

#define BITMASK_DIAG_STS_MAG_Z 0x0400
#define BITMASK_DIAG_STS_MAG_Y 0x0200
#define BITMASK_DIAG_STS_MAG_X 0x0100

#define BITMASK_DIAG_STS_ACC_Z 0x0020
#define BITMASK_DIAG_STS_ACC_Y 0x0010
#define BITMASK_DIAG_STS_ACC_X 0x0008

#define BITMASK_DIAG_STS_GYRO_Z 0x0004
#define BITMASK_DIAG_STS_GYRO_Y 0x0002
#define BITMASK_DIAG_STS_GYRO_X 0x0001

#define BITMASK_SYS_E_FLAG_WDTOUT   0x8000
#define BITMASK_SYS_E_FLAG_EKFDIV   0x2000
#define BITMASK_SYS_E_FLAG_GYROSAT  0x1000
#define BITMASK_SYS_E_FLAG_MAGDIST  0x0800
#define BITMASK_SYS_E_FLAG_ACCEXC   0x0400
#define BITMASK_SYS_E_FLAG_BARONEW  0x0200
#define BITMASK_SYS_E_FLAG_MAGNEW   0x0100
#define BITMASK_SYS_E_FLAG_PROCOVRN 0x0080
#define BITMASK_SYS_E_FLAG_FLUPDFL  0x0040
#define BITMASK_SYS_E_FLAG_DIAG_OVV 0x0020
#define BITMASK_SYS_E_FLAG_SNSRNG   0x0010
#define BITMASK_SYS_E_FLAG_SPIERR   0x0008
#define BITMASK_SYS_E_FLAG_ALM_OVV  0x0001



 /*Global Variables*/
static uint8_t tx[35], rx[35];

uint8_t read_product_id(spi* spi_dev) {
  
  uint16_t merged_data = 0;

  printf("ADIS16480: Reading Product ID\n");
    
  tx[0] = PG0;    //Switch to page 0
  tx[1] = 0x00;
  tx[2] = PROD_ID;
  tx[3] = 0x00;
  tx[4] = 0x00;
  tx[5] = 0x00;



  rx[0] = 0;
  rx[1] = 0;
  rx[2] = 0;
  rx[3] = 0;
  rx[4] = 0;
  rx[5] = 0;

  libsoc_spi_rw(spi_dev, tx, rx, 6);
  
  /*merge the two 8 bit words*/
  merged_data = rx[5];                        //2nd byte to the LSBs
  merged_data = (merged_data | (rx[4]<<8));  //first byte to the MSBs

  if (merged_data != 0x4060){
    printf("ADIS16480: wrong PROD_ID, rx[4]: 0x%x, rx[5] 0x%x \n",rx[4], rx[5]);
    return 0; // IMplement proper error message later
  }else{
    printf("ADIS16480: correct PROD_ID: 0x%x \n",merged_data);
    return 1; // IMplement proper error message later
  }
  
  return 0;
}

uint8_t read_self_test(spi* spi_dev) {
  
  uint16_t merged_data = 0;

  printf("ADIS16480: Reading Self Test Results\n");
    
  tx[0] = PG0;        // Switch to page 0
  tx[1] = 0x00;
  tx[2] = DIAG_STS;   // Send  the Diagnostics register read command
  tx[3] = 0x00;
  tx[4] = 0x00;       // Get the precious answer bits home to papa (clock the bits from the ADIS to the BBB)
  tx[5] = 0x00;


  rx[0] = 0;          // Empty the receiving register
  rx[1] = 0;
  rx[2] = 0;
  rx[3] = 0;
  rx[4] = 0;
  rx[5] = 0;

  libsoc_spi_rw(spi_dev, tx, rx, 6);    //Do the actual SPI commands
  
  /*merge the two 8 bit words*/
  merged_data = rx[5];                        // 2nd byte to the LSBs
  merged_data = (merged_data | (rx[4]<<8));  // first byte to the MSBs
  merged_data = (merged_data && BITMASK_b15to12_7to_6);      /* The DIAG_STS register bits 15-12 and 7-6 
                                                are don't care and might be set without there being a problem.*/

  if (merged_data == 0){  //No Errors

    printf("ADIS16480: Self Test results show  NO errors"); 
    return 1; // IMplement proper error message later

  }else{
    printf("ADIS16480: Self Test showed the following ERRORS:");

    if(merged_data & BITMASK_DIAG_STS_BARO){
      printf("ADIS16480: Self Test - Barometer Error");
    }
    /*Check the Magnetometer*/
    if(merged_data & BITMASK_DIAG_STS_MAG_Z){
      printf("ADIS16480: Self Test - Magnetometer Z-axis Error");
    }
    if(merged_data & BITMASK_DIAG_STS_MAG_Y){
      printf("ADIS16480: Self Test - Magnetometer Y-axis Error");
    }
    if(merged_data & BITMASK_DIAG_STS_MAG_X){
      printf("ADIS16480: Self Test - Magnetometer X-axis Error");
    }
    /*Check the Accelerometer*/
    if(merged_data & BITMASK_DIAG_STS_ACC_Z){
      printf("ADIS16480: Self Test - Accelerometer Z-axis Error");
    }
    if(merged_data & BITMASK_DIAG_STS_ACC_Y){
      printf("ADIS16480: Self Test - Accelerometer Y-axis Error");
    }
    if(merged_data & BITMASK_DIAG_STS_ACC_X){
      printf("ADIS16480: Self Test - Accelerometer X-axis Error");
    }
    /*Check the Gyroscopes*/
    if(merged_data & BITMASK_DIAG_STS_GYRO_Z){
      printf("ADIS16480: Self Test - Gyroscope Z-axis Error");
    }
    if(merged_data & BITMASK_DIAG_STS_GYRO_Y){
      printf("ADIS16480: Self Test - Gyroscope Y-axis Error");
    }
    if(merged_data & BITMASK_DIAG_STS_GYRO_X){
      printf("ADIS16480: Self Test - Gyroscope X-axis Error");
    }

    return 0; // Implement proper error message later
  }
  
  printf("ADIS16480: Something went wrong while checking the IMU status, we should never have gotten here.");
  return 0;
}



int main()
{
  libsoc_set_debug(1);
   
  uint8_t status;

  spi* spi_dev = libsoc_spi_init(SPI_DEVICE, CHIP_SELECT);

  if (!spi_dev)
  {
    printf("Failed to get spidev device!\n");
    return EXIT_FAILURE;
  }

  libsoc_spi_set_mode(spi_dev, MODE_3); //ADIS16480 needs 16-bit mode
  libsoc_spi_get_mode(spi_dev);
  
  libsoc_spi_set_speed(spi_dev, 11999999); //Seems to be limited to <12MHz ??! weird...
  libsoc_spi_get_speed(spi_dev);
  
  libsoc_spi_set_bits_per_word(spi_dev, BITS_8);
  libsoc_spi_get_bits_per_word(spi_dev);
  
  status = read_product_id(spi_dev);    //best testing - expect 0x4060
  if(status){
    status = read_self_test(spi_dev);
  }

  libsoc_spi_free(spi_dev);

  return EXIT_SUCCESS;
}
