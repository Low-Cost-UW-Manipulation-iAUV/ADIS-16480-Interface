/*
 * ADIS 16480 EKF_CNFG Register Interface source
 * This SPI interface for the ADIS16480 IMU is based on libsoc library by Jack Mitchell
 * Author: Raphael Nagel
 * Date: 07/June/2014
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
#include "adis_16480_driver/reg_ekf_cnfg.h"


uint8_t ADIS_16480_Interface::read_adaptive_configuration() {
	uint16_t answer = 0;

	printf("ADIS16480: EKF_CNFG - Reading Status\n");
    
	tx[0] = PG3;    //Switch to page 3
	tx[1] = EKF_CNFG;	//command to read
	tx[2] = PG0;

	rx[0] = 0;
	rx[1] = 0;
	rx[2] = 0;

	libsoc_spi_rw(spi_dev, tx, rx, 6);
	answer = (rx[2] & BITMASK_b15to13_11to10_7to5_2);      /* Some EKF_CNFG register bits
                                            are don't care and might be set without there being a problem.*/

	if (answer == EKF_CNFG_DEFAULT){
		printf("ADIS16480: EKF_CNFG - At default setting. (D) \n");
		return 1; // IMplement proper error message later
	}else{
		printf("ADIS16480: EKF_CNFG - Some settings have been changed (!!!) : 0x%x \n",rx[2]);
		printf("rx[0]: 0x%x, rx[1]: 0x%x, rx[2]: 0x%x \n", rx[0], rx[1], rx[2]);

		if(answer & BITMASK_EKF_CNFG_AUTORCVDIV){
			printf("ADIS16480: EKF_CNFG - (!!!) Automatic recovery from EKF divergence ACTIVE\n");
		}else{
			printf("ADIS16480: EKF_CNFG - (D) Automatic recovery from EKF divergence OFF \n");
		}

		if(answer & BITMASK_EKF_CNFG_FADE){
			printf("ADIS16480: EKF_CNFG - (D) Gyroscope Fade ACTIVE\n");
		}else{
		printf("ADIS16480: EKF_CNFG - (!!!) Gyroscope Fade OFF\n");
		}

		if(answer & BITMASK_EKF_CNFG_ADPTEKF){
			printf("ADIS16480: EKF_CNFG - (!!!) Adaptive EKF OFF\n");
		}else{
			printf("ADIS16480: EKF_CNFG - (D) Adaptive EKF ACTIVE\n");			
		}

		if(answer & BITMASK_EKF_CNFG_ORIENT_FMR_CTRL){
			printf("ADIS16480: EKF_CNFG - (!!!) Orientation Format is ROTATION MATRIX\n");
		}else{
			printf("ADIS16480: EKF_CNFG - (D) Orientation Format is QUATERNION & EULER\n");
		}

		if(answer & BITMASK_EKF_CNFG_BDY_FRM_SEL){
			printf("ADIS16480: EKF_CNFG - (!!!) Reference Frame is BODY FRAME\n");
		}else{
			printf("ADIS16480: EKF_CNFG - (D) Reference Frame is LOCAL NAV FRAME\n");
		}

		if(answer & BITMASK_EKF_CNFG_MAGDIS){
			printf("ADIS16480: EKF_CNFG - (!!!) Magnetometer OFF\n");
		}else{
			printf("ADIS16480: EKF_CNFG - (D) Magnetometer ACTIVE\n");			
		}

		if(answer & BITMASK_EKF_CNFG_GRAVRM){
			printf("ADIS16480: EKF_CNFG - (!!!) Gravity removal ACTIVE\n");
		}else{
			printf("ADIS16480: EKF_CNFG - (D) Gravity removal OFF\n");			
		}



		return 0; // IMplement proper error message later
	}

	return 0;
}
