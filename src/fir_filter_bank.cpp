/*
 * ADIS 16480 FIR filter banks source
 * It will write the FIR coefficients to the ADIS, starting with the lower bits and finishing with the higher ones.
 * This SPI interface for the ADIS16480 IMU is based on libsoc library by Jack Mitchell
 * Author: Raphael Nagel
 * Date: 13/Aug/2014
 * 
 */
 /*standard defines, etc (stolen from libsoc test files)*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdint.h>
#include <string.h>
#include <sys/time.h>
#include <vector> 

#include "adis_16480_driver/spi_ADIS_16480.h"
#include "std_msgs/MultiArrayLayout.h"
#include "std_msgs/MultiArrayDimension.h"
 
#include "std_msgs/Int32MultiArray.h" 



int ADIS_16480_Interface::setFirCoeffs(uint16_t page,  adis_16480_driver::setFilterCoeffs::Request array){
	unsigned int x = 0;
	int confirm = 0;
	switch(page){
		case PG5:
			ROS_INFO("adis_16480_interface - settings the coeffs for FIR bank A\n");
			break;

	case PG7:
			ROS_INFO("adis_16480_interface - settings the coeffs for FIR bank B\n");
			break;
	
	case PG9:
			ROS_INFO("adis_16480_interface - settings the coeffs for FIR bank C\n");
			break;
		default: 
		ROS_ERROR("adis_16480_interface - trying to write coeffs to invalid FIR bank");
		return EXIT_FAILURE;
	}

	//The 120 taps (16-bit word each) are split across two register pages.
	for(x=0;x<=59;x++){
		confirm = write_word(page, BASE_ADDRESS_BANK+(x * TAP_OFFSET), array.FIR_filter_coeffs[x]);
		if(confirm == EXIT_FAILURE){
			ROS_ERROR("adis_16480_interface - FIR coefficient %d could not be set \n", x);
			return EXIT_FAILURE;
		}
	}

	for(x=0;x<=60;x++){
		write_word((page + 1), BASE_ADDRESS_BANK+(x * TAP_OFFSET), array.FIR_filter_coeffs[60 + x] );
		if(confirm == EXIT_FAILURE){
			ROS_ERROR("adis_16480_interface - FIR coefficient %d could not be set \n", (60+x) );
			return EXIT_FAILURE;
		}
	}

	return EXIT_SUCCESS;
}