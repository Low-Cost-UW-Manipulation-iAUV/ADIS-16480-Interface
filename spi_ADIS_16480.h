/*
 * ADIS 16480 Global Register defines  
 * This SPI interface for the ADIS16480 IMU is based on libsoc library by Jack Mitchell
 * Author: Raphael Nagel
 * Date: 04/June/2014
 * 
 */

#ifndef _ADIS_16480_PG_RG_DEFS_
#define _ADIS_16480_PG_RG_DEFS_


static uint16_t tx[35], rx[35];	//Predefine the rx and tx register

//Define the SPI line and chip select line 
#define SPI_DEVICE   1
#define CHIP_SELECT  0

//Bitmasks
#define BITMASK_WRITE_REGISTER 0x0800     //Use this to | (OR) register addresses if you want to write to that register


/*ADIS 16480 Register Pages*/
#define PG0 0x8000  // Output data, clock, identification
#define PG1 0x8100  // Reserved
#define PG2 0x8200  // Calibration
#define PG3 0x8300  // Control: sample rate, filtering, I/O, alarms
#define PG4 0x8400  // Serial number
#define PG5 0x8500  // FIR Filter Bank A Coefficient 0 to Coefficient 59
#define PG6 0x8600  // FIR Filter Bank A, Coefficient 60 to Coefficient 119
#define PG7 0x8700  // FIR Filter Bank B, Coefficient 0 to Coefficient 59
#define PG8 0x8800  // FIR Filter Bank B, Coefficient 60 to Coefficient 119
#define PG9 0x8900  // FIR Filter Bank C, Coefficient 0 to Coefficient 59
#define PG10 0x8A00 // FIR Filter Bank C, Coefficient 60 to Coefficient 119
#define PG11 0x8B00 // FIR Filter Bank D, Coefficient 0 to Coefficient 59
#define PG12 0x8C00 // FIR Filter Bank D, Coefficient 60 to Coefficient 119

#endif
