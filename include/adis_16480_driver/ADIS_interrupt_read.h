/*
 * ADIS 16480 Data Interrupt read function header
 * This SPI interface for the ADIS16480 IMU is based on libsoc library by Jack Mitchell
 * Author: Raphael Nagel
 * Date: 10/June/2014
 * 
 */
#ifndef _ADIS_16480_IR_READ_
#define _ADIS_16480_IR_READ_

//control the switch statement in the callback job function
#define IR_R_NOTHING 0
#define IR_R_LR_YPR 1
#define IR_R_LR_LACC 2 
#define IR_R_LR_LVEL 3 
#define IR_R_LR_YPR_LACC 4
#define IR_R_LR_YPR_LVEL 5
#define IR_R_HR_YPR_lACC 6
#define IR_R_HR_YPR_lVEL 7

#define IR_R_ROS_HR_YPR_lACC 8
#define IR_R_ROS_HR_YPR_lVEL 9

/*The Data_Ready line coming from the ADIS through the Interface board*/
#define GPIO_INPUT 49  /*It is on pin 23, but internally on the BBB's GPIO1[17]
						--> 32bit offset to get to 2nd controller:
						17+32 = 49*/

#endif