/*
 * ADIS 16480 Interface Real Time Clock Defines
 * This SPI interface for the ADIS16480 IMU is based on libsoc library by Jack Mitchell
 * Author: Raphael Nagel
 * Date: 09/July/2014
 * 
 */
#ifndef _ADIS_16480_RT_CLOCK_
#define _ADIS_16480_RT_CLOCK_

#define TIME_MS_OUT 0x7800
#define TIME_DH_OUT 0x7A00
#define TIME_YM_OUT 0x7C00

//blocks out everything out except the seconds & it with the register output
#define BITMASK_RTCLOCK_SECONDS_OUT 0x003F

 #endif