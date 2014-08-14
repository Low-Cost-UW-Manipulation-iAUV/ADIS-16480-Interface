/*
 * ADIS 16480 FIR filter banks header
 * It is used to write the filter coefficients to the IMU
 * This SPI interface for the ADIS16480 IMU is based on libsoc library by Jack Mitchell
 * Author: Raphael Nagel
 * Date: 13/Aug/2014
 * 
 */

#ifndef _ADIS_16480_FIR_FILTER_
#define _ADIS_16480_FIR_FILTER_

#define FILTR_BNK_0 0x16
#define FILTR_BNK_1 0x18

#define TAP_OFFSET 2

//on BNK0
#define BIT_FILTR_BNK_X_ACC_ONOFF 0x0800
#define BIT_FILTR_BNK_Y_ACC_ONOFF 0x4000
#define BITS_FILTR_BNK_XY_ONOFF 0x4800

#define BASE_ADDRESS_BANK 0x0800


//on BNK1
#define BIT_FILTR_BNK_Z_ACC_ONOFF 0x0003

#endif