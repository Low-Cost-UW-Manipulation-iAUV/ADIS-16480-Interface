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
 
#include "reg_diag_sts.h"
#include "reg_glob_cmd.h"
#include "reg_sys_e_flag.h"

/*Registers needed for the UWEsub's use of the - READ ADDRESSES unless specified*/ 
//Page 0
#define PROD_ID 0x7e        // Product ID register which is stable and predefined to be 0x4060 = .16480 = 0b0100 0000 0110 0000

 /*Global Variables*/
//extern static uint8_t tx[35], rx[35]; !!!!!!!!!!!!!!!!!CHECKME!!!!!!!!!!!!


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
