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

/*Registers needed for the UWEsub's use of the - READ ADDRESSES unless specified*/ 
//Page 0
#define PROD_ID 0x7e00        // Product ID register which is stable and predefined to be 0x4060 = .16480 = 0b0100 0000 0110 0000
#define PROD_ID_DEFAULT 0x4060

//Bitmasks
#define BITMASK_WRITE_REGISTER 0x0800     //Use this to | (OR) register addresses if you want to write to that register


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

#endif
