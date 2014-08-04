/*
 * ADIS 16480  Data Out Interface Source
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


//ADIS Interface includes
#include "adis_16480_driver/spi_ADIS_16480.h"
#include "adis_16480_driver/data_out.h"
#include "adis_16480_driver/rt_clock.h"


uint8_t ADIS_16480_Interface::read_euler_YPR_angles(double* yaw,  double* pitch,  double* roll) {
	uint16_t yaw_raw, pitch_raw, roll_raw;
	tx[0] = YAW_C32_OUT;    //Ask for Yaw
	tx[1] = PITCH_C31_OUT;    //Ask for  Pitch and store Yaw
	tx[2] = ROLL_C23_OUT;    //Ask for Roll and store pitch	
	tx[3] = PG0;			//go back to PG0 and get the last data

	rx[0] = 0;
	rx[1] = 0;
	rx[2] = 0;
	rx[3] = 0;


	libsoc_spi_rw(spi_dev, tx, rx, 8);

	yaw_raw = rx[1];
	pitch_raw = rx[2];
	roll_raw = rx[3];

	convert_2s_to_x( &yaw_raw,  YAW_ROLL_COUNT_TO_DEGREE,  yaw);
	convert_2s_to_x( &pitch_raw,  YAW_ROLL_COUNT_TO_DEGREE,  pitch);
	convert_2s_to_x( &roll_raw,  YAW_ROLL_COUNT_TO_DEGREE,  roll);


	if (print_data_to_console_flag){
		printf("yaw: % 3.4f, pitch: % 3.4f, roll: % 3.4f \n",*yaw,*pitch,*roll);
	}
	return 1;
}

uint8_t ADIS_16480_Interface::read_euler_YPR_angles(void) {
	uint16_t yaw_raw, pitch_raw, roll_raw;
	tx[0] = YAW_C32_OUT;    //Ask for Yaw
	tx[1] = PITCH_C31_OUT;    //Ask for  Pitch and store Yaw
	tx[2] = ROLL_C23_OUT;    //Ask for Roll and store pitch	
	tx[3] = PG0;			//go back to PG0 and get the last data


	rx[0] = 0;
	rx[1] = 0;
	rx[2] = 0;
	rx[3] = 0;


	libsoc_spi_rw(spi_dev, tx, rx, 8);

	yaw_raw = rx[1];
	pitch_raw = rx[2];
	roll_raw = rx[3];

	convert_2s_to_x( &yaw_raw,  YAW_ROLL_COUNT_TO_DEGREE,  &yaw);
	convert_2s_to_x( &pitch_raw,  YAW_ROLL_COUNT_TO_DEGREE,  &pitch);
	convert_2s_to_x( &roll_raw,  YAW_ROLL_COUNT_TO_DEGREE,  &roll);

	if (print_data_to_console_flag){
		printf("yaw: % 3.4f, pitch: % 3.4f, roll: % 3.4f \n",yaw,pitch,roll);
	}

	return 1;
}

uint8_t ADIS_16480_Interface::read_linear_acceleration(double* x_acc,  double* y_acc,  double* z_acc) {
	uint16_t x_acc_raw, y_acc_raw, z_acc_raw;
	tx[0] = X_ACCL_OUT;    //Ask for Yaw
	tx[1] = Y_ACCL_OUT;    //Ask for  Pitch and store Yaw
	tx[2] = Z_ACCL_OUT;    //Ask for Roll and store pitch	
	tx[3] = PG0;			//go back to PG0 and get the last data

	rx[0] = 0;
	rx[1] = 0;
	rx[2] = 0;
	rx[3] = 0;

	libsoc_spi_rw(spi_dev, tx, rx, 8);

	x_acc_raw = rx[1];
	y_acc_raw = rx[2];
	z_acc_raw = rx[3];

	convert_2s_to_x( &x_acc_raw,  LINEAR_ACC_COUNT_TO_g,  x_acc);
	convert_2s_to_x( &y_acc_raw,  LINEAR_ACC_COUNT_TO_g,  y_acc);
	convert_2s_to_x( &z_acc_raw,  LINEAR_ACC_COUNT_TO_g,  z_acc);

	if (print_data_to_console_flag){
		printf("Accelerations along axis: x: % 2.4fg, y: % 2.4f, z: % 2.4f \n",*x_acc,*y_acc,*z_acc);
	}
	return 1;
}

uint8_t ADIS_16480_Interface::read_linear_acceleration(void) {
	uint16_t x_acc_raw, y_acc_raw, z_acc_raw;
	tx[0] = X_ACCL_OUT;    //Ask for Yaw
	tx[1] = Y_ACCL_OUT;    //Ask for  Pitch and store Yaw
	tx[2] = Z_ACCL_OUT;    //Ask for Roll and store pitch	
	tx[3] = PG0;			//go back to PG0 and get the last data

	rx[0] = 0;
	rx[1] = 0;
	rx[2] = 0;
	rx[3] = 0;			
	libsoc_spi_rw(spi_dev, tx, rx, 8);

	x_acc_raw = rx[1];
	y_acc_raw = rx[2];
	z_acc_raw = rx[3];

	convert_2s_to_x( &x_acc_raw,  LINEAR_ACC_COUNT_TO_g,  &x_acceleration);
	convert_2s_to_x( &y_acc_raw,  LINEAR_ACC_COUNT_TO_g,  &y_acceleration);
	convert_2s_to_x( &z_acc_raw,  LINEAR_ACC_COUNT_TO_g,  &z_acceleration);

	if (print_data_to_console_flag){
		printf("Accelerations along axis: x: % 2.4fg, y: % 2.4f, z: % 2.4f \n",x_acceleration, y_acceleration, z_acceleration);
	}

	return 1;
}

uint8_t ADIS_16480_Interface::read_linear_velocity(double* x_vel,  double* y_vel,  double* z_vel) {
	uint16_t x_vel_raw, y_vel_raw, z_vel_raw;
	tx[0] = X_DELTVEL_OUT;    //Ask for Yaw
	tx[1] = Y_DELTVEL_OUT;    //Ask for  Pitch and store Yaw
	tx[2] = Z_DELTVEL_OUT;    //Ask for Roll and store pitch	
	tx[3] = PG0;			//go back to PG0 and get the last data

	rx[0] = 0;
	rx[1] = 0;
	rx[2] = 0;
	rx[3] = 0;			//go back to PG0 and get the last data

	libsoc_spi_rw(spi_dev, tx, rx, 8);

	x_vel_raw = rx[1];
	y_vel_raw = rx[2];
	z_vel_raw = rx[3];

	convert_2s_to_x( &x_vel_raw,  LINEAR_VEL_COUNT_TO_mpsec,  x_vel);
	convert_2s_to_x( &y_vel_raw,  LINEAR_VEL_COUNT_TO_mpsec,  y_vel);
	convert_2s_to_x( &z_vel_raw,  LINEAR_VEL_COUNT_TO_mpsec,  z_vel);
	

	if (print_data_to_console_flag){
		printf("Velocities along axis: x: % 3.15fm/s, y: % 3.15fm/s, z: % 3.15fm/s \n",*x_vel,*y_vel,*z_vel);
	}
	return 1;
}

uint8_t ADIS_16480_Interface::read_linear_velocity(void) {
	uint16_t x_vel_raw, y_vel_raw, z_vel_raw;
	tx[0] = X_DELTVEL_OUT;    //Ask for Yaw
	tx[1] = Y_DELTVEL_OUT;    //Ask for  Pitch and store Yaw
	tx[2] = Z_DELTVEL_OUT;    //Ask for Roll and store pitch	
	tx[3] = PG0;			//go back to PG0 and get the last data

	rx[0] = 0;
	rx[1] = 0;
	rx[2] = 0;
	rx[3] = 0;			

	libsoc_spi_rw(spi_dev, tx, rx, 8);

	x_vel_raw = rx[1];
	y_vel_raw = rx[2];
	z_vel_raw = rx[3];

//Convert from 2s complement to decimal/
	convert_2s_to_x( &x_vel_raw,  LINEAR_VEL_COUNT_TO_mpsec,  &x_velocity);
	convert_2s_to_x( &y_vel_raw,  LINEAR_VEL_COUNT_TO_mpsec,  &y_velocity);
	convert_2s_to_x( &z_vel_raw,  LINEAR_VEL_COUNT_TO_mpsec,  &z_velocity);

	if (print_data_to_console_flag){
		printf("Velocities along axis: x: % 3.15fm/s, y: % 3.15fm/s, z: % 3.15fm/s \n",x_velocity, y_velocity, z_velocity);
	}
	return 1;
}


uint8_t ADIS_16480_Interface::set_DEC_RATE(uint16_t dec_rate) {
	double data_ready_period;
	uint8_t success_yes_no = 0;

	printf("ADIS16480 - Data Out: setting DEC_RATE to: %d\n",dec_rate);

	success_yes_no = write_word(PG3, DEC_RATE_REG, dec_rate);
	
	if(success_yes_no){
		decimation_rate = dec_rate;
		//Calculate the output sample rate and convert it to period in usec! Forumla from ADIS 16480 datasheet 'AVERAGING/DECIMATION FILTER'
		data_ready_period = (1 / (2460 / ((double)(decimation_rate + 1)) ) );

		data_ready_period_usec = data_ready_period * SECS_TO_USECS;
		
		printf("ADIS16480 - Data Out: DEC_RATE is now: %d\n",dec_rate);
		printf("ADIS16480 - Data Out: Sample Output Rate is now: %4.f\n",(1/data_ready_period));
	}

	return 1;
}


uint8_t ADIS_16480_Interface::read_YPR_lin_Acc(void) {
	uint16_t yaw_raw, pitch_raw, roll_raw;
	uint16_t x_acc_raw, y_acc_raw, z_acc_raw;

	tx[0] = YAW_C32_OUT;    //Ask for Yaw
	tx[1] = PITCH_C31_OUT;    //Ask for  Pitch and store Yaw
	tx[2] = ROLL_C23_OUT;    //Ask for Roll and store pitch	

	tx[3] = X_ACCL_OUT;    //Ask for x Acc
	tx[4] = Y_ACCL_OUT;    //Ask for  y Acc
	tx[5] = Z_ACCL_OUT;    //Ask for z Acc
	tx[6] = PG0;			//go back to PG0 and get the last data

	rx[0] = 0;
	rx[1] = 0;
	rx[2] = 0;
	rx[3] = 0;
	rx[4] = 0;
	rx[5] = 0;
	rx[6] = 0;


	libsoc_spi_rw(spi_dev, tx, rx, 14);

	yaw_raw = rx[1];
	pitch_raw = rx[2];
	roll_raw = rx[3];

	x_acc_raw = rx[4];
	y_acc_raw = rx[5];
	z_acc_raw = rx[6];


//!!!!!!!!!!!!!!! Convert YPR!!!!!!!!!!!!!!!!!!!!!!
	convert_2s_to_x( &yaw_raw,  YAW_ROLL_COUNT_TO_DEGREE,  &yaw);
	convert_2s_to_x( &pitch_raw,  YAW_ROLL_COUNT_TO_DEGREE,  &pitch);
	convert_2s_to_x( &roll_raw,  YAW_ROLL_COUNT_TO_DEGREE,  &roll);

	if (print_data_to_console_flag){
		printf("yaw: % 3.4f, pitch: % 3.4f, roll: % 3.4f \n",yaw,pitch,roll);
	}


//!!!!!!!!!!!!!!! Convert the linear acceleration!!!!!!!!!!!!!!!!!!!!!!
	convert_2s_to_x( &x_acc_raw,  LINEAR_ACC_COUNT_TO_g,  &x_acceleration);
	convert_2s_to_x( &y_acc_raw,  LINEAR_ACC_COUNT_TO_g,  &y_acceleration);
	convert_2s_to_x( &z_acc_raw,  LINEAR_ACC_COUNT_TO_g,  &z_acceleration);
	
	if (print_data_to_console_flag){
		printf("Accelerations along axis: x: % 2.4fg, y: % 2.4f, z: % 2.4f \n",x_acceleration, y_acceleration, z_acceleration);
	}

	return 1;
}


uint8_t ADIS_16480_Interface::read_YPR_lin_Vel(void) {
	uint16_t yaw_raw, pitch_raw, roll_raw;
	uint16_t x_vel_raw, y_vel_raw, z_vel_raw;

	tx[0] = YAW_C32_OUT;    //Ask for Yaw
	tx[1] = PITCH_C31_OUT;    //Ask for  Pitch and store Yaw
	tx[2] = ROLL_C23_OUT;    //Ask for Roll and store pitch	

	tx[3] = X_DELTVEL_OUT;    //Ask for x Acc
	tx[4] = Y_DELTVEL_OUT;    //Ask for  y Acc
	tx[5] = Z_DELTVEL_OUT;    //Ask for z Acc
	tx[6] = PG0;			//go back to PG0 and get the last data

	rx[0] = 0;
	rx[1] = 0;
	rx[2] = 0;
	rx[3] = 0;
	rx[4] = 0;
	rx[5] = 0;
	rx[6] = 0;

	libsoc_spi_rw(spi_dev, tx, rx, 14);

	yaw_raw = rx[1];
	pitch_raw = rx[2];
	roll_raw = rx[3];

	x_vel_raw = rx[4];
	y_vel_raw = rx[5];
	z_vel_raw = rx[6];

//!!!!!!!!!!!!!!! Convert YPR!!!!!!!!!!!!!!!!!!!!!!
	convert_2s_to_x( &yaw_raw,  YAW_ROLL_COUNT_TO_DEGREE,  &yaw);
	convert_2s_to_x( &pitch_raw,  YAW_ROLL_COUNT_TO_DEGREE,  &pitch);
	convert_2s_to_x( &roll_raw,  YAW_ROLL_COUNT_TO_DEGREE,  &roll);

	if (print_data_to_console_flag){
		printf("yaw: % 3.4f, pitch: % 3.4f, roll: % 3.4f \n",yaw,pitch,roll);
	}

//Convert from 2s complement to decimal/

	convert_2s_to_x( &x_vel_raw,  LINEAR_VEL_COUNT_TO_mpsec,  &x_velocity);
	convert_2s_to_x( &y_vel_raw,  LINEAR_VEL_COUNT_TO_mpsec,  &y_velocity);
	convert_2s_to_x( &z_vel_raw,  LINEAR_VEL_COUNT_TO_mpsec,  &z_velocity);

	if (print_data_to_console_flag){
		printf("Velocities along axis: x: % 3.15fm/s, y: % 3.15fm/s, z: % 3.15fm/s \n",x_velocity, y_velocity, z_velocity);
	}
	return 1;
}
 
//convert the 16-bit 2s complement data to binary
int ADIS_16480_Interface::convert_2s_to_x(uint16_t* raw_data, double conversion_rate, double* converted_data){
	
	if(*raw_data & BITMASK_TEST_2s_NEG){ 	// if negative 
		*raw_data = ~*raw_data;				// invert it
		*raw_data = *raw_data + 1;			
		*converted_data = (-1) * (((double) *raw_data) * conversion_rate);
	}else{
		*converted_data = ((double) *raw_data) * conversion_rate;
	}	
	return 1;

}
