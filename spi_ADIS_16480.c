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
 * This spi_test is intended to be run on beaglebone white hardware
 * and uses the SPIDEV1 device on pins P9_31 as SCLK, P9_29 as SI, 
 * P9_30 as as SO, P9_28 as CS.
 *
 * The BeagleBone is connected to a MicroChip 25LC640-I/P 64K EEPROM.
 *
 * The test covers writing 32 bytes of random data, to a random page
 * on the EEPROM. It then reads the page back, and compares the data
 * read against the data sent, the test passes if all data matches.
 * 
 */
 
#define SPI_DEVICE   1
#define CHIP_SELECT  0


#define WREN  0x06
#define WRDI  0x04
#define WRITE 0x02
#define READ  0x03
#define RDSR  0x05
/*Stop deletinhg here*/

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

/*Bitmasks*/


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

  libsoc_spi_rw(spi_dev, tx, rx, 3);
  
  /*merge the two 8 bit words*/
  merged_data = rx[5];                        //2nd byte to the LSBs
  merged_data = (merged_data || (rx[4]<<8));  //first byte to the MSBs

  if (merged_data != 0x4060){
    printf("ADIS16480: wrong PROD_ID: 0x%x%x \n",rx[4], rx[5]);
    return 0; // IMplement proper error message later
  }else{
    printf("ADIS16480: correct PROD_ID: 0x%x \n",merged_data);
    return 1; // IMplement proper error message later
  }
  
  return 0;
}


int main()
{
  libsoc_set_debug(1);
   
  uint8_t status;
  uint16_t page;
  int i;

  spi* spi_dev = libsoc_spi_init(SPI_DEVICE, CHIP_SELECT);

  if (!spi_dev)
  {
    printf("Failed to get spidev device!\n");
    return EXIT_FAILURE;
  }

  libsoc_spi_set_mode(spi_dev, MODE_3);
  libsoc_spi_get_mode(spi_dev);
  
  libsoc_spi_set_speed(spi_dev, 11999999); //Seems to be limited to <12MHz ??! weird...
  libsoc_spi_get_speed(spi_dev);
  
  libsoc_spi_set_bits_per_word(spi_dev, BITS_16);
  libsoc_spi_get_bits_per_word(spi_dev);
  
  status = read_product_id(spi_dev);


  libsoc_spi_free(spi_dev);

  return EXIT_SUCCESS;
}
