/*
 * ADIS 16480 GLOB_CMD Data Read Interface Source
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
#include "data_out.h"

uint8_t read_euler_YPR_angles(spi* spi_dev,  double* yaw,  double* pitch,  double* roll) {
	uint16_t yaw_raw, pitch_raw, roll_raw;
	tx[0] = PG0;        //Switch to page 0
	tx[1] = YAW_C32_OUT;    //Ask for Yaw
	tx[2] = PITCH_C31_OUT;    //Ask for  Pitch and store Yaw
	tx[3] = ROLL_C23_OUT;    //Ask for Roll and store pitch	
	tx[4] = PG0;       //change back to page 0 while register While storing roll

	rx[0] = 0;
	rx[1] = 0;
	rx[2] = 0;
	rx[3] = 0;
	rx[4] = 0;

	libsoc_spi_rw(spi_dev, tx, rx, 10);

	yaw_raw = rx[2];
	pitch_raw = rx[3];
	roll_raw = rx[4];

/*Convert from 2s complement to decimal*/
	if(yaw_raw & BITMASK_TEST_2s_NEG){ //if negative 
		yaw_raw = ~yaw_raw;		//
		yaw_raw = yaw_raw + 1;
		*yaw = (-1)* ((double) yaw_raw) * YAW_ROLL_COUNT_TO_DEGREE;
	}else{
		*yaw = (double) yaw_raw * YAW_ROLL_COUNT_TO_DEGREE;
	}

/*Convert from 2s complement to decimal*/
	if(roll_raw & BITMASK_TEST_2s_NEG){ //if negative 
		roll_raw = ~roll_raw;		//
		roll_raw = roll_raw + 1;
		*roll = (-1)* ((double) roll_raw) * YAW_ROLL_COUNT_TO_DEGREE;
	}else{
		*roll = ((double) roll_raw) * YAW_ROLL_COUNT_TO_DEGREE;
	}	

/*Convert from 2s complement to decimal*/
	if(pitch_raw & BITMASK_TEST_2s_NEG){ //if negative 
		pitch_raw = ~pitch_raw;		//
		pitch_raw = pitch_raw + 1;
		*pitch = (-1)* ((double) pitch_raw) * YAW_ROLL_COUNT_TO_DEGREE;
	}else{
		*pitch = ((double) pitch_raw) * YAW_ROLL_COUNT_TO_DEGREE;
	}	

	printf("yaw: % 3.4f, pitch: % 3.4f, roll: % 3.4f \n",*yaw,*pitch,*roll);

	return 1;
}
