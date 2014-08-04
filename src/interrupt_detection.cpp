/*
 * ADIS 16480 Interface Detect missed Interrupt
 * This SPI interface for the ADIS16480 IMU is based on libsoc library by Jack Mitchell
 * Author: Raphael Nagel
 * Date: 09/July/2014
 * 
 */
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
#include "adis_16480_driver/interrupt_detection.h"


//Detect the number of interrupts missed
uint8_t ADIS_16480_Interface::detect_missed_IR(){
	timespec current_time;
 	timespec time_in_between_calls;
 	long usec_time_in_between_calls;

 	clock_gettime(CLOCK_REALTIME, &current_time);

 	time_in_between_calls.tv_sec = current_time.tv_sec - last_callback_timestamp.tv_sec;
 	time_in_between_calls.tv_nsec = current_time.tv_nsec - last_callback_timestamp.tv_nsec;

 	usec_time_in_between_calls = (time_in_between_calls.tv_sec * IR_DETECT_S_TO_uS) + (time_in_between_calls.tv_nsec / IR_DETECT_nS_TO_uS);
	last_callback_timestamp = current_time;
 	/**/
 	if(usec_time_in_between_calls > (IR_DETECT_LEEWAY_MULTIPLYER * data_ready_period_usec)){
 		
 		IRs_missed = (uint8_t) (usec_time_in_between_calls / data_ready_period_usec);
 		return 0;
 	}else{
 		
 		IRs_missed = 0;
 		return 1;
 	}


}

//initiate the interrupt_detection
void ADIS_16480_Interface::setup_interrupt_detection(bool ONOFF){

	if(ONOFF){
		clock_gettime(CLOCK_REALTIME, &last_callback_timestamp);
	}

	interrupt_detection_enable_flag = ONOFF;
}
