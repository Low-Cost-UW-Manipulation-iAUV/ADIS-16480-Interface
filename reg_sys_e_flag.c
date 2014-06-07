/*
 * ADIS 16480 SYS_E_FLAG Register Interface Source
 * This SPI interface for the ADIS16480 IMU is based on libsoc library by Jack Mitchell
 * Author: Raphael Nagel
 * Date: 04/June/2014
 * 
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

#include "spi_ADIS_16480.h"
#include "reg_sys_e_flag.h"


uint8_t read_error_flags(spi* spi_dev) {
  
  uint16_t answer = 0;

  printf("ADIS16480: Reading Error Flags\n");
  
  tx[0] = PG0;        // Switch to page 0
  tx[1] = SYS_E_FLAG; // Send  the Diagnostics register read command
  tx[2] = PG0;      // Get the precious answer bits home to papa (clock the bits from the ADIS to the BBB)

  rx[0] = 0;          // Empty the receiving register
  rx[1] = 0;
  rx[2] = 0;

  libsoc_spi_rw(spi_dev, tx, rx, 6);    //Do the actual SPI commands
  
  answer = (rx[2] & BITMASK_b2to3);      /* The SYS_E_FLAG register bits 14, 1 and 2 are dont care.*/

  if (answer == 0){  //No Errors

    printf("ADIS16480: No System Errors\n"); 
    return 1; // IMplement proper error message later

  }else{
    printf("ADIS16480: System Errors occured:\n");
    printf("ADIS16480: 0x%x \n",answer);


    if(answer & BITMASK_SYS_E_FLAG_WDTOUT){
      printf("ADIS16480: System Error - Watchdog Timer Error\n");
    }
    if(answer & BITMASK_SYS_E_FLAG_EKFDIV){
      printf("ADIS16480: System Error - Ext. Kalman Filter Divergence occured\n");
    }
    if(answer & BITMASK_SYS_E_FLAG_GYROSAT){
      printf("ADIS16480: System Error - Gyroscopes are saturated - EKF impact reduced\n");
    } 
    if(answer & BITMASK_SYS_E_FLAG_MAGDIST){
      printf("ADIS16480: System Error - Magnetic Disturbance has occured - EKF impact reduced\n");
    }       
    if(answer & BITMASK_SYS_E_FLAG_ACCEXC){
      printf("ADIS16480: System Error - Linear Accelerometers are out of range - EKF impact reduced\n");
    }
    if(answer & BITMASK_SYS_E_FLAG_BARONEW){
      printf("ADIS16480: System Error - New Barometer Data\n");
    }
    if(answer & BITMASK_SYS_E_FLAG_MAGNEW){
      printf("ADIS16480: System Error - New Magnetometer Data\n");
    } 
    if(answer & BITMASK_SYS_E_FLAG_PROCOVRN){
      printf("ADIS16480: System Error - Processor Overrun occured\n");
    }  
    if(answer & BITMASK_SYS_E_FLAG_FLUPDFL){
      printf("ADIS16480: System Error - Flash Update failed\n");
    }
    if(answer & BITMASK_SYS_E_FLAG_DIAG_OVV){
      printf("ADIS16480: System Error - A startup error ocuured - please check in DIAG_STS\n");
    }
    if(answer & BITMASK_SYS_E_FLAG_SNSRNG){
      printf("ADIS16480: System Error - Sensors are out of Range\n");
    } 
    if(answer & BITMASK_SYS_E_FLAG_SPIERR){
      printf("ADIS16480: System Error - A SPI communication error occured\n");
    }  
    if(answer & BITMASK_SYS_E_FLAG_ALM_OVV){
      printf("ADIS16480: System Error - A User Programmable Alarm triggered - please check ALM_STS\n");
    }  

    return 0; // Implement proper error message later
  }
  
  printf("ADIS16480: Something went wrong while checking the IMU status, we should never have gotten here.\n");
  return 0;
}