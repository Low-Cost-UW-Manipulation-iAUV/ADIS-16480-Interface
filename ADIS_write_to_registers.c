/**
 * This file allows to set bits in the control registers on the ADIS16480
 * This SPI interface for the ADIS16480 IMU is based on libsoc library by Jack Mitchell
 * Author: Raphael Nagel
 * Date: 04/July/2014
 */

 /*standard defines, etc (stolen from libsoc test files)*/
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

#include "wrapper_C_library_callback_to_Cpp.h" 


//Sets bits on the registers. !!! THIS ONLY SETS BITS !!!
uint8_t ADIS_16480_Interface::set_bits(uint16_t page, uint16_t base_address, uint16_t bits_to_set) {
  uint16_t register_content_before;
  uint16_t register_content_after;
  uint16_t lower_address_write;
  uint16_t upper_address_write;


  printf("ADIS16480 - Register Write - Setting the following bits: 0x%x in Register (base address): 0x%x on Page: %x\n", bits_to_set, base_address, (page & (~BITMASK_WRITE_REGISTER)));
    
  tx[0] = page;             //Switch to page 
  tx[1] = base_address;    //Ask for the register content
  tx[2] = PG0;           //change back to page 0 while register While getting the PROD_ID

  rx[0] = 0;
  rx[1] = 0;
  rx[2] = 0;
 
  libsoc_spi_rw(spi_dev, tx, rx, 6);

  register_content_before = rx[2];
  printf("ADIS16480 - Register Write - Before: 0x%x\n",register_content_before);
  printf("ADIS16480 - Register Write - Writing new content and reading it back...\n");

  register_content_after = register_content_before | bits_to_set;


//Set the address bit and add the lower 8 bits of the data to be written.
  // see the ADIS 16480 write to register documentation. 
  lower_address_write = (base_address | BITMASK_WRITE_REGISTER) | (register_content_after & BITMASK_WRITE_LOWER_8_BITS); 
  upper_address_write = ((base_address + UPPER_DATA_BYTE) | BITMASK_WRITE_REGISTER) | ((register_content_after & BITMASK_WRITE_UPPER_8_BITS_BEFORE_SHIFT) >> SHIFTDOWN_UPPER_8_BITS); 
  tx[0] = page;             //Switch to page 
  tx[1] = lower_address_write;   //Send lower 8 bits of data
  tx[2] = upper_address_write;    //send upper 8 bits of data
  tx[3] = PG0;

  rx[0] = 0;
  rx[1] = 0;
  rx[2] = 0;
  rx[3] = 0;

  libsoc_spi_rw(spi_dev, tx, rx, 8);  

  tx[0] = page;             //Switch to page 
  tx[1] = base_address;
  tx[2] = PG0;

  rx[0] = 0;
  rx[1] = 0;
  rx[2] = 0;

  libsoc_spi_rw(spi_dev, tx, rx, 6);  

//Check that the write was successfull.
  if(rx[2] == register_content_after){
    printf("ADIS16480 - Register Write: Success, register now contains: 0x%x\n",rx[2]);

    return 1;

  }else{
    printf("ADIS16480 - Register Write: FAILURE, register now contains: 0x%x\n",rx[2]);

    return 0;

  }

}

//Clears bits on the registers. 
uint8_t ADIS_16480_Interface::clear_bits(uint16_t page, uint16_t base_address, uint16_t bits_to_clear) {
  uint16_t register_content_before;
  uint16_t register_content_after;
  uint16_t lower_address_write;
  uint16_t upper_address_write;


  printf("ADIS16480 - Register Write - Clearing the following bits: 0x%x in Register (base address): 0x%x on Page: %d\n", bits_to_clear, base_address, page);
    
  tx[0] = page;             //Switch to page 
  tx[1] = base_address;    //Ask for the register content
  tx[2] = PG0;           //change back to page 0 while register While getting the PROD_ID

  rx[0] = 0;
  rx[1] = 0;
  rx[2] = 0;
 
  libsoc_spi_rw(spi_dev, tx, rx, 6);

  register_content_before = rx[2];
  printf("ADIS16480 - Register Write - Before: 0x%x\n",register_content_before);

//Invert the bits to be set and AND the result with the content.
  register_content_after = register_content_before & (~bits_to_clear);  

//Set the address bit and add the lower 8 bits of the data to be written.
  lower_address_write = (base_address | BITMASK_WRITE_REGISTER) | (register_content_after & BITMASK_WRITE_LOWER_8_BITS); 
  upper_address_write = ((base_address + UPPER_DATA_BYTE) | BITMASK_WRITE_REGISTER) | ((register_content_after & BITMASK_WRITE_UPPER_8_BITS_BEFORE_SHIFT) >> SHIFTDOWN_UPPER_8_BITS); 
  
  tx[0] = page;             //Switch to page 
  tx[1] = lower_address_write;   //Send lower 8 bits of data
  tx[2] = upper_address_write;    //send upper 8 bits of data
  tx[3] = PG0;

  rx[0] = 0;
  rx[1] = 0;
  rx[2] = 0;
  rx[3] = 0;

  libsoc_spi_rw(spi_dev, tx, rx, 8);  

  tx[0] = page;             //Switch to page 
  tx[1] = base_address;
  tx[2] = PG0;

  rx[0] = 0;
  rx[1] = 0;
  rx[2] = 0;

  libsoc_spi_rw(spi_dev, tx, rx, 6);  

//Check that the write was successfull.
  if(rx[2] == register_content_after){
    printf("ADIS16480 - Register Write: Success, register now contains: 0x%x\n",rx[2]);

    return 1;

  }else{
    printf("ADIS16480 - Register Write: FAILURE, register now contains: 0x%x\n",rx[2]);

    return 0;

  }

}

// Writes a 16-bit word to an ADIS register
uint8_t ADIS_16480_Interface::write_word(uint16_t page, uint16_t base_address, uint16_t word_to_write) {
  uint16_t register_content_after;
  uint16_t lower_address_write;
  uint16_t upper_address_write;


  printf("ADIS16480 - Register Write - Writing the following word  : 0x%x in Register (base address): 0x%x on Page: %d\n", word_to_write, base_address, page);
    
   
  register_content_after = word_to_write;

//Set the address bit and add the lower 8 bits of the data to be written.
  lower_address_write = (base_address | BITMASK_WRITE_REGISTER) | (register_content_after & BITMASK_WRITE_LOWER_8_BITS); 
  upper_address_write = ((base_address + UPPER_DATA_BYTE) | BITMASK_WRITE_REGISTER) | ((register_content_after & BITMASK_WRITE_UPPER_8_BITS_BEFORE_SHIFT) >> SHIFTDOWN_UPPER_8_BITS); 
  
  tx[0] = page;             //Switch to page 
  tx[1] = lower_address_write;   //Send lower 8 bits of data
  tx[2] = upper_address_write;    //send upper 8 bits of data
  tx[3] = PG0;

  rx[0] = 0;
  rx[1] = 0;
  rx[2] = 0;
  rx[3] = 0;

  libsoc_spi_rw(spi_dev, tx, rx, 8);  

  tx[0] = page;             //Switch to page 
  tx[1] = base_address;
  tx[2] = PG0;

  rx[0] = 0;
  rx[1] = 0;
  rx[2] = 0;

  libsoc_spi_rw(spi_dev, tx, rx, 6);  

//Check that the write was successfull.
  if(rx[2] == register_content_after){
    printf("ADIS16480 - Register Write: Success, register now contains: 0x%x\n",rx[2]);

    return 1;

  }else{
    printf("ADIS16480 - Register Write: FAILURE, register now contains: 0x%x\n",rx[2]);

    return 0;

  }

}