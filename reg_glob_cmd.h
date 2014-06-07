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
// Address content for GLOB_CMD 0x82     // WRITE ADDESSS - Provides access to issue the global system commands (write only)

 /*System Control Commands - Page 3 - 8-bit mode --> split 16-bit commands in upper and lower 8-bit portions*/
//Wanted Register Content: COMMAND_GLOB_CMD_EKF_RST 0x8000 
#define COMMAND_GLOB_CMD_EKF_RST_lower 0x8200  
#define COMMAND_GLOB_CMD_EKF_RST_upper 0x8280  

//Wanted Register Content: COMMAND_GLOB_CMD_REF_ROT_RST 0x0200
#define COMMAND_GLOB_CMD_REF_ROT_RST_lower 0x8200
#define COMMAND_GLOB_CMD_REF_ROT_RST_upper 0x8202

//Wanted Register Content: COMMAND_GLOB_CMD_TARE 0x0100
#define COMMAND_GLOB_CMD_TARE_lower 0x8200
#define COMMAND_GLOB_CMD_TARE_upper 0x8201
//Wanted Register Content: COMMAND_GLOB_CMD_SOFT_RST 0x0080
#define COMMAND_GLOB_CMD_SOFT_RST_lower 0x8280
#define COMMAND_GLOB_CMD_SOFT_RST_upper 0x8200
//Wanted Register Content: COMMAND_GLOB_CMD_FACT_CALIB_RESTORE 0x0040
#define COMMAND_GLOB_CMD_FACT_CALIB_RESTORE_lower 0x8240
#define COMMAND_GLOB_CMD_FACT_CALIB_RESTORE_upper 0x8200
//Wanted Register Content: COMMAND_GLOB_CMD_FLASH_UPDT 0x0008
#define COMMAND_GLOB_CMD_FLASH_UPDT_lower 0x8208
#define COMMAND_GLOB_CMD_FLASH_UPDT_upper 0x8200
//Wanted Register Content: COMMAND_GLOB_CMD_FLASH_TEST 0x0004
#define COMMAND_GLOB_CMD_FLASH_TEST_lower 0x8204
#define COMMAND_GLOB_CMD_FLASH_TEST_upper 0x8200
//Wanted Register Content: COMMAND_GLOB_CMD_SELF_TST 0x0002
#define COMMAND_GLOB_CMD_SELF_TST_lower 0x8202
#define COMMAND_GLOB_CMD_SELF_TST_upper 0x8200


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
