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

	if (print_data_to_console_flag){
		printf("yaw: % 3.4f, pitch: % 3.4f, roll: % 3.4f \n",*yaw,*pitch,*roll);
	}
	return 1;
}

uint8_t ADIS_16480_Interface::read_euler_YPR_angles() {
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

/*Convert from 2s complement to decimal*/
	if(yaw_raw & BITMASK_TEST_2s_NEG){ //if negative 
		yaw_raw = ~yaw_raw;		//
		yaw_raw = yaw_raw + 1;
		yaw = (-1)* ((double) yaw_raw) * YAW_ROLL_COUNT_TO_DEGREE;
	}else{
		yaw = (double) yaw_raw * YAW_ROLL_COUNT_TO_DEGREE;
	}

/*Convert from 2s complement to decimal*/
	if(roll_raw & BITMASK_TEST_2s_NEG){ //if negative 
		roll_raw = ~roll_raw;		//
		roll_raw = roll_raw + 1;
		roll = (-1)* ((double) roll_raw) * YAW_ROLL_COUNT_TO_DEGREE;
	}else{
		roll = ((double) roll_raw) * YAW_ROLL_COUNT_TO_DEGREE;
	}	

/*Convert from 2s complement to decimal*/
	if(pitch_raw & BITMASK_TEST_2s_NEG){ //if negative 
		pitch_raw = ~pitch_raw;		//
		pitch_raw = pitch_raw + 1;
		pitch = (-1)* ((double) pitch_raw) * YAW_ROLL_COUNT_TO_DEGREE;
	}else{
		pitch = ((double) pitch_raw) * YAW_ROLL_COUNT_TO_DEGREE;
	}	

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

	if (print_data_to_console_flag){
		printf("Accelerations along axis: x: % 2.4fg, y: % 2.4f, z: % 2.4f \n",*x_acc,*y_acc,*z_acc);
	}
	return 1;
}

uint8_t ADIS_16480_Interface::read_linear_acceleration() {
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

/*Convert from 2s complement to decimal*/
	if(x_acc_raw & BITMASK_TEST_2s_NEG){ //if negative 
		x_acc_raw = ~x_acc_raw;		//
		x_acc_raw = x_acc_raw + 1;
		x_acceleration = (-1)* ((double) x_acc_raw) * LINEAR_ACC_COUNT_TO_g;
	}else{
		x_acceleration = (double) x_acc_raw * LINEAR_ACC_COUNT_TO_g;
	}

/*Convert from 2s complement to decimal*/
	if(y_acc_raw & BITMASK_TEST_2s_NEG){ //if negative 
		y_acc_raw = ~y_acc_raw;		//
		y_acc_raw = y_acc_raw + 1;
		y_acceleration = (-1)* ((double) y_acc_raw) * LINEAR_ACC_COUNT_TO_g;
	}else{
		y_acceleration = (double) y_acc_raw * LINEAR_ACC_COUNT_TO_g;
	}

/*Convert from 2s complement to decimal*/
	if(z_acc_raw & BITMASK_TEST_2s_NEG){ //if negative 
		z_acc_raw = ~z_acc_raw;		//
		z_acc_raw = z_acc_raw + 1;
		z_acceleration = (-1)* ((double) z_acc_raw) * LINEAR_ACC_COUNT_TO_g;
	}else{
		z_acceleration = (double) z_acc_raw * LINEAR_ACC_COUNT_TO_g;
	}

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

//Convert from 2s complement to decimal/
	if (print_data_to_console_flag){
		printf("raw velocities: x 0x%04x, y 0x%04x, z 0x%04x\n",x_vel_raw, y_vel_raw, z_vel_raw);
	}
	if(x_vel_raw & BITMASK_TEST_2s_NEG){ //if negative 
		x_vel_raw = ~x_vel_raw;		//
		x_vel_raw = x_vel_raw + 1;
		*x_vel = (-1)* ((double) x_vel_raw) * LINEAR_VEL_COUNT_TO_mpsec;
	}else{
		*x_vel = (double) x_vel_raw * LINEAR_VEL_COUNT_TO_mpsec;
	}

//Convert from 2s complement to decimal/
	if(y_vel_raw & BITMASK_TEST_2s_NEG){ //if negative 
		y_vel_raw = ~y_vel_raw;		//
		y_vel_raw = y_vel_raw + 1;
		*y_vel = (-1)* ((double) y_vel_raw) * LINEAR_VEL_COUNT_TO_mpsec;
	}else{
		*y_vel = (double) y_vel_raw * LINEAR_VEL_COUNT_TO_mpsec;
	}

//Convert from 2s complement to decimal
	if(z_vel_raw & BITMASK_TEST_2s_NEG){ //if negative 
		z_vel_raw = ~z_vel_raw;		//
		z_vel_raw = z_vel_raw + 1;
		*z_vel = (-1)* ((double) z_vel_raw) * LINEAR_VEL_COUNT_TO_mpsec;
	}else{
		*z_vel = (double) z_vel_raw * LINEAR_VEL_COUNT_TO_mpsec;
	}	

	if (print_data_to_console_flag){
		printf("Velocities along axis: x: % 3.15fm/s, y: % 3.15fm/s, z: % 3.15fm/s \n",*x_vel,*y_vel,*z_vel);
	}
	return 1;
}

uint8_t ADIS_16480_Interface::read_linear_velocity() {
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
	if (print_data_to_console_flag){
		printf("velocities: x 0x%04x, y 0x%04x, z 0x%04x\n",x_vel_raw, y_vel_raw, z_vel_raw);
	}

	if(x_vel_raw & BITMASK_TEST_2s_NEG){ //if negative 
		x_vel_raw = ~x_vel_raw;		//
		x_vel_raw = x_vel_raw + 1;
		x_velocity = (-1)* ((double) x_vel_raw) * LINEAR_VEL_COUNT_TO_mpsec;
	}else{
		x_velocity = (double) x_vel_raw * LINEAR_VEL_COUNT_TO_mpsec;
	}

//Convert from 2s complement to decimal/
	if(y_vel_raw & BITMASK_TEST_2s_NEG){ //if negative 
		y_vel_raw = ~y_vel_raw;		//
		y_vel_raw = y_vel_raw + 1;
		y_velocity = (-1)* ((double) y_vel_raw) * LINEAR_VEL_COUNT_TO_mpsec;
	}else{
		y_velocity = (double) y_vel_raw * LINEAR_VEL_COUNT_TO_mpsec;
	}

//Convert from 2s complement to decimal
	if(z_vel_raw & BITMASK_TEST_2s_NEG){ //if negative 
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


uint8_t ADIS_16480_Interface::set_DEC_RATE(uint16_t dec_rate) {

	tx[0] = PG3;    //Switch to page 3
	tx[1] = DEC_RATE_READ;    //Switch to page 0
	tx[2] = DEC_RATE_WRITE | (dec_rate & BITMASK_WRITE_LOWER) ;	//write the lower data byte first
	tx[3] = (DEC_RATE_WRITE + UPPER_DATA_BYTE) | (dec_rate & BITMASK_WRITE_UPPER) ;	//then the upper byte
	tx[4] = DEC_RATE_READ;    //Switch to page 0
	tx[5] = PG0;    //Switch to page 0

	rx[0] = 0;
	rx[1] = 0;
	rx[2] = 0;
	rx[3] = 0;
	rx[4] = 0;
	rx[5] = 0;

	printf("ADIS16480: setting DEC_RATE to: %d, tx2: %x, tx3: %x\n",dec_rate, tx[2], tx[3]);

	libsoc_spi_rw(spi_dev, tx, rx, 12);
	printf("ADIS16480: DEC_RATE was: %d\n",rx[2]);
	printf("ADIS16480: DEC_RATE set to: %d\n",rx[5]);
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

/*Convert from 2s complement to decimal*/
	if(yaw_raw & BITMASK_TEST_2s_NEG){ //if negative 
		yaw_raw = ~yaw_raw;		//
		yaw_raw = yaw_raw + 1;
		yaw = (-1)* ((double) yaw_raw) * YAW_ROLL_COUNT_TO_DEGREE;
	}else{
		yaw = (double) yaw_raw * YAW_ROLL_COUNT_TO_DEGREE;
	}

/*Convert from 2s complement to decimal*/
	if(roll_raw & BITMASK_TEST_2s_NEG){ //if negative 
		roll_raw = ~roll_raw;		//
		roll_raw = roll_raw + 1;
		roll = (-1)* ((double) roll_raw) * YAW_ROLL_COUNT_TO_DEGREE;
	}else{
		roll = ((double) roll_raw) * YAW_ROLL_COUNT_TO_DEGREE;
	}	

/*Convert from 2s complement to decimal*/
	if(pitch_raw & BITMASK_TEST_2s_NEG){ //if negative 
		pitch_raw = ~pitch_raw;		//
		pitch_raw = pitch_raw + 1;
		pitch = (-1)* ((double) pitch_raw) * YAW_ROLL_COUNT_TO_DEGREE;
	}else{
		pitch = ((double) pitch_raw) * YAW_ROLL_COUNT_TO_DEGREE;
	}	

	if (print_data_to_console_flag){
		printf("yaw: % 3.4f, pitch: % 3.4f, roll: % 3.4f \n",yaw,pitch,roll);
	}


//!!!!!!!!!!!!!!! Convert the linear acceleration!!!!!!!!!!!!!!!!!!!!!!
	/*Convert from 2s complement to decimal*/
	if(x_acc_raw & BITMASK_TEST_2s_NEG){ //if negative 
		x_acc_raw = ~x_acc_raw;		//
		x_acc_raw = x_acc_raw + 1;
		x_acceleration = (-1)* ((double) x_acc_raw) * LINEAR_ACC_COUNT_TO_g;
	}else{
		x_acceleration = (double) x_acc_raw * LINEAR_ACC_COUNT_TO_g;
	}

/*Convert from 2s complement to decimal*/
	if(y_acc_raw & BITMASK_TEST_2s_NEG){ //if negative 
		y_acc_raw = ~y_acc_raw;		//
		y_acc_raw = y_acc_raw + 1;
		y_acceleration = (-1)* ((double) y_acc_raw) * LINEAR_ACC_COUNT_TO_g;
	}else{
		y_acceleration = (double) y_acc_raw * LINEAR_ACC_COUNT_TO_g;
	}

/*Convert from 2s complement to decimal*/
	if(z_acc_raw & BITMASK_TEST_2s_NEG){ //if negative 
		z_acc_raw = ~z_acc_raw;		//
		z_acc_raw = z_acc_raw + 1;
		z_acceleration = (-1)* ((double) z_acc_raw) * LINEAR_ACC_COUNT_TO_g;
	}else{
		z_acceleration = (double) z_acc_raw * LINEAR_ACC_COUNT_TO_g;
	}

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

/*Convert from 2s complement to decimal*/
	if(yaw_raw & BITMASK_TEST_2s_NEG){ //if negative 
		yaw_raw = ~yaw_raw;		//
		yaw_raw = yaw_raw + 1;
		yaw = (-1)* ((double) yaw_raw) * YAW_ROLL_COUNT_TO_DEGREE;
	}else{
		yaw = (double) yaw_raw * YAW_ROLL_COUNT_TO_DEGREE;
	}

/*Convert from 2s complement to decimal*/
	if(roll_raw & BITMASK_TEST_2s_NEG){ //if negative 
		roll_raw = ~roll_raw;		//
		roll_raw = roll_raw + 1;
		roll = (-1)* ((double) roll_raw) * YAW_ROLL_COUNT_TO_DEGREE;
	}else{
		roll = ((double) roll_raw) * YAW_ROLL_COUNT_TO_DEGREE;
	}	

/*Convert from 2s complement to decimal*/
	if(pitch_raw & BITMASK_TEST_2s_NEG){ //if negative 
		pitch_raw = ~pitch_raw;		//
		pitch_raw = pitch_raw + 1;
		pitch = (-1)* ((double) pitch_raw) * YAW_ROLL_COUNT_TO_DEGREE;
	}else{
		pitch = ((double) pitch_raw) * YAW_ROLL_COUNT_TO_DEGREE;
	}	

	if (print_data_to_console_flag){
		printf("yaw: % 3.4f, pitch: % 3.4f, roll: % 3.4f \n",yaw,pitch,roll);
	}

//Convert from 2s complement to decimal/
	if (print_data_to_console_flag){
		printf("velocities: x 0x%04x, y 0x%04x, z 0x%04x\n",x_vel_raw, y_vel_raw, z_vel_raw);
	}

	if(x_vel_raw & BITMASK_TEST_2s_NEG){ //if negative 
		x_vel_raw = ~x_vel_raw;		//
		x_vel_raw = x_vel_raw + 1;
		x_velocity = (-1)* ((double) x_vel_raw) * LINEAR_VEL_COUNT_TO_mpsec;
	}else{
		x_velocity = (double) x_vel_raw * LINEAR_VEL_COUNT_TO_mpsec;
	}

//Convert from 2s complement to decimal/
	if(y_vel_raw & BITMASK_TEST_2s_NEG){ //if negative 
		y_vel_raw = ~y_vel_raw;		//
		y_vel_raw = y_vel_raw + 1;
		y_velocity = (-1)* ((double) y_vel_raw) * LINEAR_VEL_COUNT_TO_mpsec;
	}else{
		y_velocity = (double) y_vel_raw * LINEAR_VEL_COUNT_TO_mpsec;
	}

//Convert from 2s complement to decimal
	if(z_vel_raw & BITMASK_TEST_2s_NEG){ //if negative 
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