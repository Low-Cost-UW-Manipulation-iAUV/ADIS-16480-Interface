/*
 * ADIS 16480 Data Interrupt read function header
 * This SPI interface for the ADIS16480 IMU is based on libsoc library by Jack Mitchell
 * Author: Raphael Nagel
 * Date: 10/June/2014
 * 
 */
#ifndef _ADIS_16480_IR_READ_
#define _ADIS_16480_IR_READ_

/*The Data_Ready line coming from the ADIS through the Interface board*/
#define GPIO_INPUT 49  /*It is on pin 23, but internally on the BBB's GPIO1[17]
						--> 32bit offset to get to 2nd controller:
						17+32 = 49*/

#endif