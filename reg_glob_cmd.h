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
#define GLOB_CMD 0x82     // WRITE ADDESSS - Provides access to issue the global system commands (write only)

 /*System Control Commands - Page 3 - 8-bit mode --> split 16-bit commands in upper and lower 8-bit portions*/
#define COMMAND_GLOB_CMD_EKF_RST_u 0x80 
#define COMMAND_GLOB_CMD_EKF_RST_l 0x00 

#define COMMAND_GLOB_CMD_REF_ROT_RST_u 0x02
#define COMMAND_GLOB_CMD_REF_ROT_RST_l 0x00

#define COMMAND_GLOB_CMD_TARE_u 0x01
#define COMMAND_GLOB_CMD_TARE_l 0x00

#define COMMAND_GLOB_CMD_SOFT_RST_u 0x00
#define COMMAND_GLOB_CMD_SOFT_RST_l 0x80

#define COMMAND_GLOB_CMD_FACT_CALIB_RESTORE_u 0x00
#define COMMAND_GLOB_CMD_FACT_CALIB_RESTORE_l 0x40

#define COMMAND_GLOB_CMD_FLASH_UPDT_u 0x00
#define COMMAND_GLOB_CMD_FLASH_UPDT_l 0x08

#define COMMAND_GLOB_CMD_FLASH_TEST_u 0x00
#define COMMAND_GLOB_CMD_FLASH_TEST_l 0x04

#define COMMAND_GLOB_CMD_SELF_TST_u 0x00 
#define COMMAND_GLOB_CMD_SELF_TST_l 0x02 



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
