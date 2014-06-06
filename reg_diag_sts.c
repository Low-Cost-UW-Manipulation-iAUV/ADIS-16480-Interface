/*
 * ADIS 16480 DIAG_STS Register Interface source
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

//ADIS Interface includes
#include "spi_ADIS_16480.h"
#include "reg_diag_sts.h"

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