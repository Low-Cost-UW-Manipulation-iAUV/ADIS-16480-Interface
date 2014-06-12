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
#include <iostream>
#include <fstream>

using namespace std;


ADIS_16480_Interface::ADIS_16480_Interface(){
  configure_initialise(SPI_DEVICE, CHIP_SELECT, MODE_3, BITS_16, 11999999);
  tx[0] = 0;
  rx[0] = 0;
}

ADIS_16480_Interface::ADIS_16480_Interface(uint8_t spi_device, uint8_t c_select_line, spi_mode spi_hw_mode, spi_bpw spi_bit_mode, uint32_t spi_frequency){
  configure_initialise(spi_device, c_select_line, spi_hw_mode, spi_bit_mode, spi_frequency);
  uint16_t tx[35], rx[35];
}

uint8_t ADIS_16480_Interface::read_product_id() {
  
  printf("ADIS16480: Reading Product ID\n");
    
  tx[0] = PG0;        //Switch to page 0
  tx[1] = PROD_ID;    //Ask for the PROD_ID
  tx[2] = PG0;       //change back to page 0 while register While getting the PROD_ID

  rx[0] = 0;
  rx[1] = 0;
  rx[2] = 0;
 

  libsoc_spi_rw(spi_dev, tx, rx, 6);

  if (rx[2] != PROD_ID_DEFAULT){
    printf("ADIS16480: wrong PROD_ID, rx[2]: 0x%x\n",rx[2]);
    return 0; // IMplement proper error message later
  }else{
    printf("ADIS16480: correct PROD_ID: 0x%x \n",rx[2]);
    return 1; // IMplement proper error message later
  }
  
  return 0;
}

uint8_t ADIS_16480_Interface::configure_initialise(uint8_t spi_device, uint8_t c_select_line, spi_mode spi_hw_mode, spi_bpw spi_bit_mode, uint32_t spi_frequency){
  libsoc_set_debug(1);
   
  uint8_t status;

  spi_dev = libsoc_spi_init(spi_device, c_select_line);

  if (!spi_dev)
  {
    printf("Failed to get spidev device!\n");
    return EXIT_FAILURE;
  }

  libsoc_spi_set_mode(spi_dev, spi_hw_mode); //ADIS16480 needs 16-bit mode
  libsoc_spi_get_mode(spi_dev);
  
  libsoc_spi_set_speed(spi_dev, spi_frequency); //Seems to be limited to <12MHz ??! weird...
  libsoc_spi_get_speed(spi_dev);
  
  libsoc_spi_set_bits_per_word(spi_dev, spi_bit_mode);
  libsoc_spi_get_bits_per_word(spi_dev);
  
}

uint8_t ADIS_16480_Interface::close(){
  libsoc_spi_free(spi_dev);
  return EXIT_SUCCESS;
}




int main()
{
  int i;
  double x,y,z;
  //uint16_t dec_rate_wanted = 1; //set the dec_rate
  ADIS_16480_Interface my_adis;
  uint8_t status;

  status = my_adis.read_product_id();    //best testing - expect 0x4060
 if(status){
    status = my_adis.read_self_test();
    status = my_adis.read_error_flags();
    //my_adis.do_Software_reset();
    libsoc_set_debug(0);
    //my_adis.set_DEC_RATE(spi_dev,dec_rate_wanted);

    fstream myfile;
    myfile.open ("ADIS-velocity-11-jun-2014-17-29.txt");
    for(i=0;i<100000;i++){  
      my_adis.read_linear_velocity(&x, &y, &z);
      myfile << x << ", " << y << "," << z << "\n";
    }
  
    myfile.close();
  }

  my_adis.close();
  return EXIT_SUCCESS;
}
