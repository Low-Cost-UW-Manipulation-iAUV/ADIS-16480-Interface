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
	tx_old[0] = PG0;        //Switch to page 0
	tx_old[1] = YAW_C32_OUT;    //Ask for Yaw
	tx_old[2] = PITCH_C31_OUT;    //Ask for  Pitch and store Yaw
	tx_old[3] = ROLL_C23_OUT;    //Ask for Roll and store pitch	
	tx_old[4] = PG0;       //change back to page 0 while register While storing roll

	rx_old[0] = 0;
	rx_old[1] = 0;
	rx_old[2] = 0;
	rx_old[3] = 0;
	rx_old[4] = 0;

	libsoc_spi_rw(spi_dev, tx_old, rx_old, 10);

	yaw_raw = rx_old[2];
	pitch_raw = rx_old[3];
	roll_raw = rx_old[4];

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

uint8_t read_linear_acceleration(spi* spi_dev,  double* x_acc,  double* y_acc,  double* z_acc) {
	uint16_t x_acc_raw, y_acc_raw, z_acc_raw;
	tx_old[0] = PG0;        //Switch to page 0
	tx_old[1] = X_ACCL_OUT;    //Ask for Yaw
	tx_old[2] = Y_ACCL_OUT;    //Ask for  Pitch and store Yaw
	tx_old[3] = Z_ACCL_OUT;    //Ask for Roll and store pitch	
	tx_old[4] = PG0;       //change back to page 0 while register While storing roll

	rx_old[0] = 0;
	rx_old[1] = 0;
	rx_old[2] = 0;
	rx_old[3] = 0;
	rx_old[4] = 0;

	libsoc_spi_rw(spi_dev, tx_old, rx_old, 10);

	x_acc_raw = rx_old[2];
	y_acc_raw = rx_old[3];
	z_acc_raw = rx_old[4];

/*Convert from 2s complement to decimal*/
	if(x_acc_raw & BITMASK_TEST_2s_NEG){ //if negative 
		x_acc_raw = ~x_acc_raw;		//
		x_acc_raw = x_acc_raw + 1;
		*x_acc = (-1)* ((double) x_acc_raw) * LINEAR_ACC_COUNT_TO_g;
	}else{
		*x_acc = (double) x_acc_raw * LINEAR_ACC_COUNT_TO_g;
	}

/*Convert from 2s complement to decimal*/
	if(y_acc_raw & BITMASK_TEST_2s_NEG){ //if negative 
		y_acc_raw = ~y_acc_raw;		//
		y_acc_raw = y_acc_raw + 1;
		*y_acc = (-1)* ((double) y_acc_raw) * LINEAR_ACC_COUNT_TO_g;
	}else{
		*y_acc = (double) y_acc_raw * LINEAR_ACC_COUNT_TO_g;
	}

/*Convert from 2s complement to decimal*/
	if(z_acc_raw & BITMASK_TEST_2s_NEG){ //if negative 
		z_acc_raw = ~z_acc_raw;		//
		z_acc_raw = z_acc_raw + 1;
		*z_acc = (-1)* ((double) z_acc_raw) * LINEAR_ACC_COUNT_TO_g;
	}else{
		*z_acc = (double) z_acc_raw * LINEAR_ACC_COUNT_TO_g;
	}	

	printf("Accelerations along axis: x: % 2.4fg, y: % 2.4f, z: % 2.4f \n",*x_acc,*y_acc,*z_acc);

	return 1;
}

uint8_t read_linear_velocity(spi* spi_dev,  double* x_vel,  double* y_vel,  double* z_vel) {
	uint16_t x_vel_raw, y_vel_raw, z_vel_raw;
	tx_old[0] = PG0;        //Switch to page 0
	tx_old[1] = X_DELTVEL_OUT;    //Ask for Yaw
	tx_old[2] = Y_DELTVEL_OUT;    //Ask for  Pitch and store Yaw
	tx_old[3] = Z_DELTVEL_OUT;    //Ask for Roll and store pitch	
	tx_old[4] = PG0;       //change back to page 0 while register While storing roll

	rx_old[0] = 0;
	rx_old[1] = 0;
	rx_old[2] = 0;
	rx_old[3] = 0;
	rx_old[4] = 0;

	libsoc_spi_rw(spi_dev, tx_old, rx_old, 10);

	x_vel_raw = rx_old[2];
	y_vel_raw = rx_old[3];
	z_vel_raw = rx_old[4];

/*Convert from 2s complement to decimal*/
	printf("velocities: x 0x%04x, y 0x%04x, z 0x%04x\n",x_vel_raw, y_vel_raw, z_vel_raw);
	if(x_vel_raw & BITMASK_TEST_2s_NEG){ //if negative 
		x_vel_raw = ~x_vel_raw;		//
		x_vel_raw = x_vel_raw + 1;
		*x_vel = (-1)* ((double) x_vel_raw) * LINEAR_VEL_COUNT_TO_mpsec;
	}else{
		*x_vel = (double) x_vel_raw * LINEAR_VEL_COUNT_TO_mpsec;
	}

/*Convert from 2s complement to decimal*/
	if(y_vel_raw & BITMASK_TEST_2s_NEG){ //if negative 
		y_vel_raw = ~y_vel_raw;		//
		y_vel_raw = y_vel_raw + 1;
		*y_vel = (-1)* ((double) y_vel_raw) * LINEAR_VEL_COUNT_TO_mpsec;
	}else{
		*y_vel = (double) y_vel_raw * LINEAR_VEL_COUNT_TO_mpsec;
	}

/*Convert from 2s complement to decimal*/
	if(z_vel_raw & BITMASK_TEST_2s_NEG){ //if negative 
		z_vel_raw = ~z_vel_raw;		//
		z_vel_raw = z_vel_raw + 1;
		*z_vel = (-1)* ((double) z_vel_raw) * LINEAR_VEL_COUNT_TO_mpsec;
	}else{
		*z_vel = (double) z_vel_raw * LINEAR_VEL_COUNT_TO_mpsec;
	}	

	//printf("Velocities along axis: x: % 3.15fm/s, y: % 3.15fm/s, z: % 3.15fm/s \n",*x_vel,*y_vel,*z_vel);

	return 1;
}

uint8_t set_DEC_RATE(spi* spi_dev, uint16_t dec_rate) {

	tx_old[0] = PG3;    //Switch to page 3
	tx_old[1] = DEC_RATE_READ;    //Switch to page 0
	tx_old[2] = DEC_RATE_WRITE | (dec_rate & BITMASK_WRITE_LOWER) ;	//write the lower data byte first
	tx_old[3] = (DEC_RATE_WRITE + UPPER_DATA_BYTE) | (dec_rate & BITMASK_WRITE_UPPER) ;	//then the upper byte
	tx_old[4] = DEC_RATE_READ;    //Switch to page 0
	tx_old[5] = PG0;    //Switch to page 0

	rx_old[0] = 0;
	rx_old[1] = 0;
	rx_old[2] = 0;
	rx_old[3] = 0;
	rx_old[4] = 0;
	rx_old[5] = 0;

	printf("ADIS16480: setting DEC_RATE to: %d, tx2: %x, tx3: %x\n",dec_rate, tx_old[2], tx_old[3]);

	libsoc_spi_rw(spi_dev, tx_old, rx_old, 12);
	printf("ADIS16480: DEC_RATE was: %d\n",rx_old[2]);
	printf("ADIS16480: DEC_RATE set to: %d\n",rx_old[5]);
	return 1;
}