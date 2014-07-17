/*
 * ADIS 16480 Interface High Res Data out Source
 * This SPI interface for the ADIS16480 IMU is based on libsoc library by Jack Mitchell
 * Author: Raphael Nagel
 * Date: 09/July/2014
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
#include "HR_data_out.h"




uint8_t ADIS_16480_Interface::HR_read_YPR_lin_Acc(void) {
	uint16_t yaw_raw, pitch_raw, roll_raw;
	uint32_t x_acc_raw, y_acc_raw, z_acc_raw;

	tx[0] = YAW_C32_OUT;    //Ask for Yaw
	tx[1] = PITCH_C31_OUT;    //Ask for  Pitch and store Yaw
	tx[2] = ROLL_C23_OUT;    //Ask for Roll and store pitch	

	tx[3] = X_ACCL_OUT;    //Ask for x Acc
	tx[4] = X_ACCL_LOW;    //Ask for x Acc

	tx[5] = Y_ACCL_OUT;    //Ask for  y Acc
	tx[6] = Y_ACCL_LOW;    //Ask for  y Acc

	tx[7] = Z_ACCL_OUT;    //Ask for z Acc
	tx[8] = Z_ACCL_LOW;    //Ask for z Acc

	tx[9] = PG0;			//go back to PG0 and get the last data

	rx[0] = 0;
	rx[1] = 0;
	rx[2] = 0;
	rx[3] = 0;
	rx[4] = 0;
	rx[5] = 0;
	rx[6] = 0;
	rx[7] = 0;
	rx[8] = 0;
	rx[9] = 0;

	libsoc_spi_rw(spi_dev, tx, rx, 20);

	yaw_raw = rx[1];
	pitch_raw = rx[2];
	roll_raw = rx[3];

	x_acc_raw = rx[4]<<16;			//Load the MSB into the upper 16 bits of the output register
	x_acc_raw = x_acc_raw + rx[5];	//Then load the extra 16 bits resolution into the LSB slots

	y_acc_raw = rx[6]<<16;
	y_acc_raw = y_acc_raw + rx[7];

	z_acc_raw = rx[8]<<16;
	z_acc_raw = z_acc_raw + rx[9];


//!!!!!!!!!!!!!!! Convert YPR!!!!!!!!!!!!!!!!!!!!!!

	convert_2s_to_x( &yaw_raw,  YAW_ROLL_COUNT_TO_DEGREE,  &yaw);
	convert_2s_to_x( &pitch_raw,  YAW_ROLL_COUNT_TO_DEGREE,  &pitch);
	convert_2s_to_x( &roll_raw,  YAW_ROLL_COUNT_TO_DEGREE,  &roll);

	if (print_data_to_console_flag){
		printf("yaw: % 3.4f, pitch: % 3.4f, roll: % 3.4f \n",yaw,pitch,roll);
	}


//!!!!!!!!!!!!!!! Convert the linear acceleration!!!!!!!!!!!!!!!!!!!!!!
	HR_convert_2s_to_x( &x_acc_raw,  HR_LINEAR_ACC_COUNT_TO_g,  &x_acceleration);
	HR_convert_2s_to_x( &y_acc_raw,  HR_LINEAR_ACC_COUNT_TO_g,  &y_acceleration);
	HR_convert_2s_to_x( &z_acc_raw,  HR_LINEAR_ACC_COUNT_TO_g,  &z_acceleration);


	if (print_data_to_console_flag){
		printf("Accelerations along axis: x: % 2.4fg, y: % 2.4f, z: % 2.4f \n",x_acceleration, y_acceleration, z_acceleration);
	}

	return 1;
}


uint8_t ADIS_16480_Interface::HR_read_YPR_lin_Vel(void) {
	uint16_t yaw_raw, pitch_raw, roll_raw;
	uint32_t x_vel_raw, y_vel_raw, z_vel_raw;

	tx[0] = YAW_C32_OUT;    //Ask for Yaw
	tx[1] = PITCH_C31_OUT;    //Ask for  Pitch and store Yaw
	tx[2] = ROLL_C23_OUT;    //Ask for Roll and store pitch	

	tx[3] = X_DELTVEL_OUT;    //Ask for x Acc
	tx[4] = X_DELTVEL_LOW;    //Ask for x Acc

	tx[5] = Y_DELTVEL_OUT;    //Ask for  y Acc
	tx[6] = Y_DELTVEL_LOW;    //Ask for  y Acc

	tx[7] = Z_DELTVEL_OUT;    //Ask for z Acc
	tx[8] = Z_DELTVEL_LOW;    //Ask for z Acc

	tx[9] = PG0;			//go back to PG0 and get the last data

	rx[0] = 0;
	rx[1] = 0;
	rx[2] = 0;
	rx[3] = 0;
	rx[4] = 0;
	rx[5] = 0;
	rx[6] = 0;
	rx[7] = 0;
	rx[8] = 0;
	rx[9] = 0;	

	libsoc_spi_rw(spi_dev, tx, rx, 20);

	yaw_raw = rx[1];
	pitch_raw = rx[2];
	roll_raw = rx[3];

	x_vel_raw = rx[4];
	x_vel_raw = x_vel_raw | rx[5];

	y_vel_raw = rx[6];
	y_vel_raw = y_vel_raw| rx[7];

	z_vel_raw = rx[8];
	z_vel_raw = z_vel_raw | rx[9];


//!!!!!!!!!!!!!!! Convert YPR!!!!!!!!!!!!!!!!!!!!!!

	convert_2s_to_x( &yaw_raw,  YAW_ROLL_COUNT_TO_DEGREE,  &yaw);
	convert_2s_to_x( &pitch_raw,  YAW_ROLL_COUNT_TO_DEGREE,  &pitch);
	convert_2s_to_x( &roll_raw,  YAW_ROLL_COUNT_TO_DEGREE,  &roll);

	if (print_data_to_console_flag){
		printf("yaw: % 3.4f, pitch: % 3.4f, roll: % 3.4f \n",yaw,pitch,roll);
	}

// USE ME AT A LATER STAGE
	//HR_convert_2s_to_x( &x_vel_raw,  HR_LINEAR_VEL_COUNT_TO_mpsec,  &x_velocity);
	//HR_convert_2s_to_x( &y_vel_raw,  HR_LINEAR_VEL_COUNT_TO_mpsec,  &y_velocity);
	//HR_convert_2s_to_x( &z_vel_raw,  HR_LINEAR_VEL_COUNT_TO_mpsec,  &z_velocity);

	if(x_vel_raw & HR_BITMASK_TEST_2s_NEG){ //if negative 
		x_vel_raw = ~x_vel_raw;		//
		x_vel_raw = x_vel_raw + 1;
		x_velocity = (-1)* ((double) x_vel_raw) * LINEAR_VEL_COUNT_TO_mpsec;
	}else{
		x_velocity = (double) x_vel_raw * LINEAR_VEL_COUNT_TO_mpsec;
	}

//Convert from 2s complement to decimal/
	if(y_vel_raw & HR_BITMASK_TEST_2s_NEG){ //if negative 
		y_vel_raw = ~y_vel_raw;		//
		y_vel_raw = y_vel_raw + 1;
		y_velocity = (-1)* ((double) y_vel_raw) * LINEAR_VEL_COUNT_TO_mpsec;
	}else{
		y_velocity = (double) y_vel_raw * LINEAR_VEL_COUNT_TO_mpsec;
	}

//Convert from 2s complement to decimal
	if(z_vel_raw & HR_BITMASK_TEST_2s_NEG){ //if negative 
		z_vel_raw = ~z_vel_raw;		//
		z_vel_raw = z_vel_raw + 1;
		z_velocity = (-1)* ((double) z_vel_raw) * LINEAR_VEL_COUNT_TO_mpsec;
	}else{
		z_velocity = (double) z_vel_raw * LINEAR_VEL_COUNT_TO_mpsec;
	}	

	if (print_data_to_console_flag){
		printf("Velocities along axis: x: % 3.15fm/s, y: % 3.15fm/s, z: % 3.15fm/s \n",x_velocity, y_velocity, z_velocity);
	}
	return 1;
}

//convert the 16-bit 2s complement data to binary
int ADIS_16480_Interface::HR_convert_2s_to_x(uint32_t* raw_data, double conversion_rate, double* converted_data){
	
	if(*raw_data & HR_BITMASK_TEST_2s_NEG){ 	// if negative 
		*raw_data = ~*raw_data;				// invert it
		*raw_data = *raw_data + 1;			
		*converted_data = (-1) * (((double) *raw_data) * conversion_rate);
	}else{
		*converted_data = ((double) *raw_data) * conversion_rate;
	}	
	return 1;

}