/*
 * ADIS 16480 GLOB_CMD Register Interface Source
 * This SPI interface for the ADIS16480 IMU is based on libsoc library by Jack Mitchell
 * Author: Raphael Nagel
 * Date: 04/June/2014
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

//Libsoc library includes
#include "libsoc_spi.h"
#include "libsoc_debug.h"  

//ADIS Interface includes
#include "spi_ADIS_16480.h"
#include "reg_glob_cmd.h"


uint8_t do_EKF_reset(spi* spi_dev) {

tx[0] = PG3;    //Switch to page 3
tx[1] = GLOB_CMD;
tx[2] = COMMAND_GLOB_CMD_EKF_RST;
tx[3] = PG0;    //Switch to page 0

libsoc_spi_rw(spi_dev, tx, rx, 8);
printf("ADIS16480: GLOB_CMD - EKF reset started - wait 416ms\n");

return 1;
}

uint8_t do_Reference_rotation_matrix_reset(spi* spi_dev) {

tx[0] = PG3;    //Switch to page 3
tx[1] = GLOB_CMD;
tx[2] = COMMAND_GLOB_CMD_REF_ROT_RST;
tx[3] = PG0;    //Switch to page 0

libsoc_spi_rw(spi_dev, tx, rx, 8);
printf("ADIS16480: GLOB_CMD - Reference Rotation Matrix resetted - wait 1 sample period\n");

return 1;
}

uint8_t do_Tare(spi* spi_dev) {


tx[0] = PG3;    //Switch to page 3
tx[1] = GLOB_CMD;
tx[2] = COMMAND_GLOB_CMD_TARE;
tx[3] = PG0;    //Switch to page 0

libsoc_spi_rw(spi_dev, tx, rx, 8);
printf("ADIS16480: GLOB_CMD - TARE done - Was the sensor stable, flat and undisturbed? - wait 1 sample period\n");

return 1;
}

uint8_t do_Software_reset(spi* spi_dev) {


tx[0] = PG3;    //Switch to page 3
tx[1] = GLOB_CMD;
tx[2] = COMMAND_GLOB_CMD_SOFT_RST;
tx[3] = PG0;    //Switch to page 0

libsoc_spi_rw(spi_dev, tx, rx, 8);
printf("ADIS16480: GLOB_CMD - Software reset started - wait 1.8s \n");

return 1;
}
uint8_t do_Factory_calibration_restore(spi* spi_dev) {


tx[0] = PG3;    //Switch to page 3
tx[1] = GLOB_CMD;
tx[2] = COMMAND_GLOB_CMD_FACT_CALIB_RESTORE;
tx[3] = PG0;    //Switch to page 0

libsoc_spi_rw(spi_dev, tx, rx, 8);
printf("ADIS16480: GLOB_CMD - Factory Calibration restore started - wait 1 sample period\n");

return 1;
}
uint8_t do_Flash_memory_update(spi* spi_dev) {


tx[0] = PG3;    //Switch to page 3
tx[1] = GLOB_CMD;
tx[2] = COMMAND_GLOB_CMD_FLASH_UPDT;
tx[3] = PG0;    //Switch to page 0

libsoc_spi_rw(spi_dev, tx, rx, 8);
printf("ADIS16480: GLOB_CMD - Flash Memory update started - wait 1.1s\n");

return 1;
}
uint8_t do_Flash_memory_test(spi* spi_dev) {

tx[0] = PG3;    //Switch to page 3
tx[1] = GLOB_CMD;
tx[2] = COMMAND_GLOB_CMD_EKF_RST;
tx[3] = PG0;    //Switch to page 0

libsoc_spi_rw(spi_dev, tx, rx, 8);
printf("ADIS16480: GLOB_CMD - Flash memory test started - wait 53ms\n");

return 1;
}
uint8_t do_Self_test(spi* spi_dev) {

tx[0] = PG3;    //Switch to page 3
tx[1] = GLOB_CMD;
tx[2] = COMMAND_GLOB_CMD_EKF_RST;
tx[3] = PG0;    //Switch to page 0

libsoc_spi_rw(spi_dev, tx, rx, 8);
printf("ADIS16480: GLOB_CMD - Self test started - wait 12ms\n");

return 1;
}
