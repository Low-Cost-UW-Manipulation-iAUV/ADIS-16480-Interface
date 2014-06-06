/*
 * ADIS 16480 SYS_E_FLAG Register Interface Headers
 * This SPI interface for the ADIS16480 IMU is based on libsoc library by Jack Mitchell
 * Author: Raphael Nagel
 * Date: 04/June/2014
 * 
 */

#ifndef _ADIS16480_SYS_E_FLAG_
#define _ADIS16480_SYS_E_FLAG_

/*Registers*/
#define SYS_E_FLAG 0x08   // Holds the System Error Flags and new Data flags for the Barometer and Magnetometer

/*Bitmasks*/
#define BITMASK_b2to3	0xBFF9  //and with SYS_E_FLAG register to set its not 'used/don't care' bits to 0

/*System Errors - Page 0*/
#define BITMASK_SYS_E_FLAG_WDTOUT   0x8000
#define BITMASK_SYS_E_FLAG_EKFDIV   0x2000
#define BITMASK_SYS_E_FLAG_GYROSAT  0x1000
#define BITMASK_SYS_E_FLAG_MAGDIST  0x0800
#define BITMASK_SYS_E_FLAG_ACCEXC   0x0400
#define BITMASK_SYS_E_FLAG_BARONEW  0x0200
#define BITMASK_SYS_E_FLAG_MAGNEW   0x0100
#define BITMASK_SYS_E_FLAG_PROCOVRN 0x0080
#define BITMASK_SYS_E_FLAG_FLUPDFL  0x0040
#define BITMASK_SYS_E_FLAG_DIAG_OVV 0x0020
#define BITMASK_SYS_E_FLAG_SNSRNG   0x0010
#define BITMASK_SYS_E_FLAG_SPIERR   0x0008
#define BITMASK_SYS_E_FLAG_ALM_OVV  0x0001

/*Functions*/

uint8_t read_error_flags(spi* );



#endif