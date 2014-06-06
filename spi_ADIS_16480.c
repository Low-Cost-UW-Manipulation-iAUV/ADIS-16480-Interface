/**
 * 
 * This SPI interface for the ADIS16480 IMU is based on libsoc library by Jack Mitchell
 * Author: Raphael Nagel
 * Date: 04/June/2014
 */
/*libsoc defines, etc (stolen from libsoc test files)*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdint.h>
#include <string.h>
#include <sys/time.h>

//Libsoc library includes
#include "libsoc_spi.h"
#include "libsoc_debug.h"  
 
//ADIS Interface includes
#include "spi_ADIS_16480.h"
#include "reg_sys_e_flag.h"

//Define the SPI line and chip select line 
#define SPI_DEVICE   1
#define CHIP_SELECT  0




/*Registers needed for the UWEsub's use of the - READ ADDRESSES unless specified*/ 
//Page 0
#define PROD_ID 0x7e        // Product ID register which is stable and predefined to be 0x4060 = .16480 = 0b0100 0000 0110 0000
#define DIAG_STS 0x0A       // Register holding the startup self test results
//Page 3
#define GLOB_CMD 0x82     // WRITE ADDESSS - Provides access to issue the global system commands (write only)

/*Bitmasks*/
#define BITMASK_b15to12_7to_6     0x0F3F  //and with DIAG_STS register to set its not 'used/don't care' bits to 0

/*System Self Check - Page 0*/
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



/*System Control Commands - Page 3 - 8-bit mode --> split 16-bit commands in upper and lower 8-bit portions*/
#define COMMAND_GLOB_CMD_EKF_RST_u 0x80 
#define COMMAND_GLOB_CMD_EKF_RST_l 0x00 

#define COMMAND_GLOB_CMD_REF_ROT_RST_u 0x02
#define COMMAND_GLOB_CMD_REF_ROT_RST_l 0x00

#define COMMAND_GLOB_CMD_TARE_u 0x01
#define COMMAND_GLOB_CMD_TARE_l 0x00

#define COMMAND_GLOB_CMD_SOFT_RST_u 0x00
#define COMMAND_GLOB_CMD_SOFT_RST_l 0x80

#define COMMAND_GLOB_CMD_FACT_CALIB_RESTORE_u 0x00
#define COMMAND_GLOB_CMD_FACT_CALIB_RESTORE_l 0x40

#define COMMAND_GLOB_CMD_FLASH_UPDT_u 0x00
#define COMMAND_GLOB_CMD_FLASH_UPDT_l 0x08

#define COMMAND_GLOB_CMD_FLASH_TEST_u 0x00
#define COMMAND_GLOB_CMD_FLASH_TEST_l 0x04

#define COMMAND_GLOB_CMD_SELF_TST_u 0x00 
#define COMMAND_GLOB_CMD_SELF_TST_l 0x02 


 /*Global Variables*/
//extern static uint8_t tx[35], rx[35]; !!!!!!!!!!!!!!!!!CHECKME!!!!!!!!!!!!

uint8_t do_EKF_reset(spi* spi_dev) {
    
  tx[0] = PG3;    //Switch to page 3
  tx[1] = 0x00;
  tx[2] = GLOB_CMD;
  tx[3] = 0x00;
  tx[4] = COMMAND_GLOB_CMD_EKF_RST_u;
  tx[5] = COMMAND_GLOB_CMD_EKF_RST_l;
  tx[6] = PG0;    //Switch to page 0
  tx[7] = 0x00;   

  libsoc_spi_rw(spi_dev, tx, rx, 8);
  printf("ADIS16480: GLOB_CMD - EKF reset started - wait 416ms\n");

  return 1;
}

uint8_t do_Reference_rotation_matrix_reset(spi* spi_dev) {

    
  tx[0] = PG3;    //Switch to page 3
  tx[1] = 0x00;
  tx[2] = GLOB_CMD;
  tx[3] = 0x00;
  tx[4] = COMMAND_GLOB_CMD_REF_ROT_RST_u;
  tx[5] = COMMAND_GLOB_CMD_REF_ROT_RST_l;
  tx[6] = PG0;    //Switch to page 0
  tx[7] = 0x00;   

  libsoc_spi_rw(spi_dev, tx, rx, 8);
  printf("ADIS16480: GLOB_CMD - Reference Rotation Matrix resetted - wait 1 sample period\n");

  return 1;
}

uint8_t do_Tare(spi* spi_dev) {

    
  tx[0] = PG3;    //Switch to page 3
  tx[1] = 0x00;
  tx[2] = GLOB_CMD;
  tx[3] = 0x00;
  tx[4] = COMMAND_GLOB_CMD_TARE_u;
  tx[5] = COMMAND_GLOB_CMD_TARE_l;
  tx[6] = PG0;    //Switch to page 0
  tx[7] = 0x00;   

  libsoc_spi_rw(spi_dev, tx, rx, 8);
  printf("ADIS16480: GLOB_CMD - TARE done - Was the sensor stable, flat and undisturbed? - wait 1 sample period\n");

  return 1;
}

uint8_t do_Software_reset(spi* spi_dev) {

    
  tx[0] = PG3;    //Switch to page 3
  tx[1] = 0x00;
  tx[2] = GLOB_CMD;
  tx[3] = 0x00;
  tx[4] = COMMAND_GLOB_CMD_SOFT_RST_u;
  tx[5] = COMMAND_GLOB_CMD_SOFT_RST_l;
  tx[6] = PG0;    //Switch to page 0
  tx[7] = 0x00;   

  libsoc_spi_rw(spi_dev, tx, rx, 8);
  printf("ADIS16480: GLOB_CMD - Software reset started - wait 1.8s \n");

  return 1;
}
uint8_t do_Factory_calibration_restore(spi* spi_dev) {

    
  tx[0] = PG3;    //Switch to page 3
  tx[1] = 0x00;
  tx[2] = GLOB_CMD;
  tx[3] = 0x00;
  tx[4] = COMMAND_GLOB_CMD_FACT_CALIB_RESTORE_u;
  tx[5] = COMMAND_GLOB_CMD_FACT_CALIB_RESTORE_l;
  tx[6] = PG0;    //Switch to page 0
  tx[7] = 0x00;   

  libsoc_spi_rw(spi_dev, tx, rx, 8);
  printf("ADIS16480: GLOB_CMD - Factory Calibration restore started - wait 1 sample period\n");

  return 1;
}
uint8_t do_Flash_memory_update(spi* spi_dev) {

    
  tx[0] = PG3;    //Switch to page 3
  tx[1] = 0x00;
  tx[2] = GLOB_CMD;
  tx[3] = 0x00;
  tx[4] = COMMAND_GLOB_CMD_FLASH_UPDT_u;
  tx[5] = COMMAND_GLOB_CMD_FLASH_UPDT_l;
  tx[6] = PG0;    //Switch to page 0
  tx[7] = 0x00;   

  libsoc_spi_rw(spi_dev, tx, rx, 8);
  printf("ADIS16480: GLOB_CMD - Flash Memory update started - wait 1.1s\n");

  return 1;
}
uint8_t do_Flash_memory_test(spi* spi_dev) {
    
  tx[0] = PG3;    //Switch to page 3
  tx[1] = 0x00;
  tx[2] = GLOB_CMD;
  tx[3] = 0x00;
  tx[4] = COMMAND_GLOB_CMD_EKF_RST_u;
  tx[5] = COMMAND_GLOB_CMD_EKF_RST_l;
  tx[6] = PG0;    //Switch to page 0
  tx[7] = 0x00;   

  libsoc_spi_rw(spi_dev, tx, rx, 8);
  printf("ADIS16480: GLOB_CMD - Flash memory test started - wait 53ms\n");

  return 1;
}
uint8_t do_Self_test(spi* spi_dev) {
    
  tx[0] = PG3;    //Switch to page 3
  tx[1] = 0x00;
  tx[2] = GLOB_CMD;
  tx[3] = 0x00;
  tx[4] = COMMAND_GLOB_CMD_EKF_RST_u;
  tx[5] = COMMAND_GLOB_CMD_EKF_RST_l;
  tx[6] = PG0;    //Switch to page 0
  tx[7] = 0x00;   

  libsoc_spi_rw(spi_dev, tx, rx, 8);
  printf("ADIS16480: GLOB_CMD - Self test started - wait 12ms\n");

  return 1;
}

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
  merged_data = (merged_data & BITMASK_b15to12_7to_6);      /* The DIAG_STS register bits 15-12 and 7-6 
                                                are don't care and might be set without there being a problem.*/

  if (merged_data == 0){  //No Errors

    printf("ADIS16480: Self Test results show  NO errors\n"); 
    return 1; // IMplement proper error message later

  }else{
    printf("ADIS16480: Self Test showed the following ERRORS:\n");

    if(merged_data & BITMASK_DIAG_STS_BARO){
      printf("ADIS16480: Self Test - Barometer Error\n");
    }
    /*Check the Magnetometer*/
    if(merged_data & BITMASK_DIAG_STS_MAG_Z){
      printf("ADIS16480: Self Test - Magnetometer Z-axis Error\n");
    }
    if(merged_data & BITMASK_DIAG_STS_MAG_Y){
      printf("ADIS16480: Self Test - Magnetometer Y-axis Error\n");
    }
    if(merged_data & BITMASK_DIAG_STS_MAG_X){
      printf("ADIS16480: Self Test - Magnetometer X-axis Error\n");
    }
    /*Check the Accelerometer*/
    if(merged_data & BITMASK_DIAG_STS_ACC_Z){
      printf("ADIS16480: Self Test - Accelerometer Z-axis Error\n");
    }
    if(merged_data & BITMASK_DIAG_STS_ACC_Y){
      printf("ADIS16480: Self Test - Accelerometer Y-axis Error\n");
    }
    if(merged_data & BITMASK_DIAG_STS_ACC_X){
      printf("ADIS16480: Self Test - Accelerometer X-axis Error\n");
    }
    /*Check the Gyroscopes*/
    if(merged_data & BITMASK_DIAG_STS_GYRO_Z){
      printf("ADIS16480: Self Test - Gyroscope Z-axis Error\n");
    }
    if(merged_data & BITMASK_DIAG_STS_GYRO_Y){
      printf("ADIS16480: Self Test - Gyroscope Y-axis Error\n");
    }
    if(merged_data & BITMASK_DIAG_STS_GYRO_X){
      printf("ADIS16480: Self Test - Gyroscope X-axis Error\n");
    }

    return 0; // Implement proper error message later
  }
  
  printf("ADIS16480: Something went wrong while checking the IMU status, we should never have gotten here.\n");
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
    status = read_error_flags(spi_dev);
  }

  libsoc_spi_free(spi_dev);

  return EXIT_SUCCESS;
}
