/*
 * ADIS 16480 DIAG_STS Register Interface Header
 * This SPI interface for the ADIS16480 IMU is based on libsoc library by Jack Mitchell
 * Author: Raphael Nagel
 * Date: 04/June/2014
 * 
 */

#ifndef _ADIS_16480_DIAG_STS_
#define _ADIS_16480_DIAG_STS_

/*Registers needed for the UWEsub's use of the - READ ADDRESSES unless specified*/ 
//Page 0
#define DIAG_STS 0x0A00       // Register holding the startup self test results


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

//Function Declarations

//uint8_t read_self_test(spi*);


#endif
