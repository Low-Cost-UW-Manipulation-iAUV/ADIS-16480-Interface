/*
 * ADIS 16480 GLOB_CMD Register Interface Header
 * This SPI interface for the ADIS16480 IMU is based on libsoc library by Jack Mitchell
 * Author: Raphael Nagel
 * Date: 04/June/2014
 * 
 */
 
#ifndef _ADIS_16480_GLOB_CMD_
#define _ADIS_16480_GLOB_CMD_

/*Registers needed for the UWEsub's use of the - READ ADDRESSES unless specified*/ 
//Page 3
#define GLOB_CMD 0x8200     // WRITE ADDESSS - Provides access to issue the global system commands (write only)

 /*System Control Commands - Page 3 - 8-bit mode --> split 16-bit commands in upper and lower 8-bit portions*/
#define COMMAND_GLOB_CMD_EKF_RST 0x8000 

#define COMMAND_GLOB_CMD_REF_ROT_RST 0x0200

#define COMMAND_GLOB_CMD_TARE 0x0100

#define COMMAND_GLOB_CMD_SOFT_RST 0x0080

#define COMMAND_GLOB_CMD_FACT_CALIB_RESTORE 0x0040

#define COMMAND_GLOB_CMD_FLASH_UPDT 0x0008

#define COMMAND_GLOB_CMD_FLASH_TEST 0x0004

#define COMMAND_GLOB_CMD_SELF_TST 0x0002



//Function Declarations

uint8_t do_EKF_reset(spi*);
uint8_t do_Reference_rotation_matrix_reset(spi*);
uint8_t do_Tare(spi*);
uint8_t do_Software_reset(spi*);
uint8_t do_Factory_calibration_restore(spi*);
uint8_t do_Flash_memory_update(spi*);
uint8_t do_Flash_memory_test(spi*);
uint8_t do_Self_test(spi*);


#endif
