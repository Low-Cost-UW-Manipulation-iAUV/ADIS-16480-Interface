/*
 * ADIS 16480 Global Register defines  
 * This SPI interface for the ADIS16480 IMU is based on libsoc library by Jack Mitchell
 * Author: Raphael Nagel
 * Date: 04/June/2014
 * 
 */

#ifndef _ADIS_16480_PG_RG_DEFS_
#define _ADIS_16480_PG_RG_DEFS_

/*libsoc defines, etc (stolen from libsoc test files)*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdint.h>
#include <string.h>
#include <sys/time.h>

//Libsoc library includes
#include <libsoc_gpio.h>
#include <libsoc_spi.h>
#include <libsoc_debug.h> 

#include "adis_16480_driver/driver_services.h"

//IO stream
#include <iostream>
#include <fstream>

using namespace std;



static uint16_t tx_old[35], rx_old[35];	//Predefine the rx and tx register

#define SECS_TO_USECS 1000000 

#define ON 1
#define OFF 0

//Define the SPI line and chip select line 
#define SPI_DEVICE   1
#define CHIP_SELECT  0

/*Registers needed for the UWEsub's use of the - READ ADDRESSES unless specified*/ 
//Page 0
#define PROD_ID 0x7e00        // Product ID register which is stable and predefined to be 0x4060 = .16480 = 0b0100 0000 0110 0000
#define PROD_ID_DEFAULT 0x4060

// Configuration of the Real Time clock and some other bits not used by us.
#define CONFIG 0x0A00
#define BITMASK_RTCLOCK_STOPWATCH_ON 0x0003 

//Bitmasks
#define BITMASK_WRITE_REGISTER 0x8000     //Use this to & (AND) register addresses if you want to write to that register
#define UPPER_DATA_BYTE 0x0100
#define BITMASK_WRITE_LOWER_8_BITS 0x00FF
#define BITMASK_WRITE_UPPER_8_BITS_BEFORE_SHIFT 0xFF00
#define SHIFTDOWN_UPPER_8_BITS 8

//Disturbance Detection Registers
#define ACC_DISTB_THR 0x5600
#define MAG_DISTB_THR 0x5800

/*ADIS 16480 Register Pages*/

#define PG0 0x8000  // Output data, clock, identification
#define PG1 0x8001  // Reserved
#define PG2 0x8002  // Calibration
#define PG3 0x8003  // Control: sample rate, filtering, I/O, alarms
#define PG4 0x8004  // Serial number
#define PG5 0x8005  // FIR Filter Bank A Coefficient 0 to Coefficient 59
#define PG6 0x8006  // FIR Filter Bank A, Coefficient 60 to Coefficient 119
#define PG7 0x8007  // FIR Filter Bank B, Coefficient 0 to Coefficient 59
#define PG8 0x8008  // FIR Filter Bank B, Coefficient 60 to Coefficient 119
#define PG9 0x8009  // FIR Filter Bank C, Coefficient 0 to Coefficient 59
#define PG10 0x800A // FIR Filter Bank C, Coefficient 60 to Coefficient 119
#define PG11 0x800B // FIR Filter Bank D, Coefficient 0 to Coefficient 59
#define PG12 0x800C // FIR Filter Bank D, Coefficient 60 to Coefficient 119


class ADIS_16480_Interface{
public:
	ADIS_16480_Interface();
	ADIS_16480_Interface(uint8_t , uint8_t , spi_mode , spi_bpw , uint32_t );

//spi_ADIS_16480.c/h
	uint8_t read_product_id();
	uint8_t close();

	uint8_t set_bits(uint16_t , uint16_t , uint16_t );
	uint8_t clear_bits(uint16_t, uint16_t, uint16_t);
	uint8_t write_word(uint16_t, uint16_t, uint16_t );

	void print_data_console(bool);
	void print_data_file(unsigned int, bool, bool, bool, bool, bool, bool);
	void publish_to_ros_or_not(bool yesorno);
	void register_driver_service(driver_services* );

//reg_diag_sts.c/.h
	uint8_t read_self_test();

//reg_ekf_cnfg.c/.h
	uint8_t read_adaptive_configuration();	
//reg_sys_e_flag.c/.h
	uint8_t read_error_flags();

//reg_glob_cmd.c/.h
	uint8_t do_EKF_reset();
	uint8_t do_Reference_rotation_matrix_reset();
	uint8_t do_Tare();
	uint8_t do_Software_reset();
	uint8_t do_Factory_calibration_restore();
	uint8_t do_Flash_memory_update();
	uint8_t do_Flash_memory_test();
	uint8_t do_Self_test();

//data_out.c/h
	uint8_t read_euler_YPR_angles(double* ,  double* ,  double* );
	uint8_t read_euler_YPR_angles(void);
	uint8_t read_linear_acceleration(double* ,  double* ,  double* );
	uint8_t read_linear_acceleration(void);
	uint8_t read_linear_velocity(double* ,  double* ,  double* );
	uint8_t read_linear_velocity(void);
	uint8_t set_DEC_RATE(uint16_t );
	uint8_t read_YPR_lin_Acc(void);
	uint8_t HR_read_YPR_lin_Acc(double*, double* , double* , double* , double* , double* );

	uint8_t read_YPR_lin_Vel(void);

//HR_data_out.c/h data_out.h
	uint8_t HR_read_YPR_lin_Acc(void);
	uint8_t HR_read_YPR_lin_Vel(void);	

//ADIS_interrupt_read.c/h
	int setup_interrupt_ADIS(int);
	int disable_Interrupt_ADIS(void);
	int job_for_callback();

//interrupt_detection.c/h
	void setup_interrupt_detection(bool);
	uint8_t detect_missed_IR(void);




private:
	uint8_t configure_initialise(uint8_t , uint8_t , spi_mode , spi_bpw , uint32_t );
	bool print_data_to_console_flag;
	bool print_data_to_file_flag;
	bool print_ypr_flag;
	bool print_linear_accelerations_flag;
	bool print_linear_velocities_flag;
	bool print_linear_position_flag;
	bool print_angular_velocities_flag;

	bool publish_in_ros_flag;

//ADIS_interrupt_read.c/h
	int interrupt_read_option;	
  	
//spi_ADIS_16480.c/h
	void print_to_file();
  	ofstream file_to_print_to;
  	driver_services* my_driver;

//interrupt_detection.c/h
	bool interrupt_detection_enable_flag;
	uint16_t IRs_missed;
	timespec last_callback_timestamp;
	uint16_t decimation_rate;


//data_out.c/.h
	double data_ready_period_usec;
	int convert_2s_to_x(uint16_t* , double , double* );
	int HR_convert_2s_to_x(uint32_t* , double , double* );
  

	spi* spi_dev ;
	uint16_t tx[35], rx[35];	//Predefine the rx and tx register
	int interrupt_count;
	double yaw, pitch, roll;
	double x_acceleration, y_acceleration, z_acceleration;
	double x_velocity, y_velocity, z_velocity;
	double x_position, y_position, z_position;
	// Create both gpio pointers
  	gpio *gpio_input;



};


#endif
