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
#include "reg_ekf_cnfg.h"
#include "data_out.h"
#include "ADIS_interrupt_read.h"

//IO stream
//#include <iostream>
//#include <fstream>

//using namespace std;

 /*Global Variables*/
//extern static uint8_t tx[35], rx[35]; !!!!!!!!!!!!!!!!!CHECKME!!!!!!!!!!!!


uint8_t read_product_id(spi* spi_dev) {
  
  printf("ADIS16480: Reading Product ID\n");
    
  tx[0] = PG0;        //Switch to page 0
  tx[1] = PROD_ID;    //Ask for the PROD_ID
  tx[2] = PG0;       //change back to page 0 while register While getting the PROD_ID

  rx[0] = 0;
  rx[1] = 0;
  rx[2] = 0;
 

  libsoc_spi_rw(spi_dev, tx, rx, 6);

  if (rx[2] != PROD_ID_DEFAULT){
    printf("ADIS16480: wrong PROD_ID, rx[2]: 0x%x\n",rx[3]);
    return 0; // IMplement proper error message later
  }else{
    printf("ADIS16480: correct PROD_ID: 0x%x \n",rx[3]);
    return 1; // IMplement proper error message later
  }
  
  return 0;
}


int main()
{
  int i;
   double x,y,z;
  uint16_t dec_rate_wanted = 1; //set the dec_rate
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
  
  libsoc_spi_set_bits_per_word(spi_dev, BITS_16);
  libsoc_spi_get_bits_per_word(spi_dev);
  
  status = read_product_id(spi_dev);    //best testing - expect 0x4060
  if(status){
    status = read_self_test(spi_dev);
    status = read_error_flags(spi_dev);
    sleep(2);
    libsoc_set_debug(0);
    set_DEC_RATE(spi_dev,dec_rate_wanted);

  //fstream myfile;
  //myfile.open ("ADIS-velocity-11-jun-2014-17-29.txt");
   for(i=0;i<100000;i++){  
      read_linear_velocity(spi_dev, &x, &y, &z);
      //myfile << x << ", " << y << "," << z << "\n";
    }
  }
  //myfile.close();


  libsoc_spi_free(spi_dev);

  return EXIT_SUCCESS;
}
