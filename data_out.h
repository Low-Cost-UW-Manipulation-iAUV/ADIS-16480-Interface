/*
 * ADIS 16480 GLOB_CMD Data Read Interface Header
 * This SPI interface for the ADIS16480 IMU is based on libsoc library by Jack Mitchell
 * Author: Raphael Nagel
 * Date: 04/June/2014
 * 
 */
#ifndef _ADIS_16480_DATA_
#define _ADIS_16480_DATA_

#define YAW_ROLL_COUNT_TO_DEGREE  0.005493164 //180°/2^15counts
#define LINEAR_ACC_COUNT_TO_g 0.0008
#define LINEAR_VEL_COUNT_TO_mpsec 0.006103516	//200/2^15

/*Bitmasks*/
#define BITMASK_TEST_2s_NEG 0x8000
#define BITMASK_WRITE_LOWER 0x00FF
#define BITMASK_WRITE_UPPER 0xFF00


/*Define the registers*/
#define DEC_RATE_WRITE 0x8C00
#define DEC_RATE_READ 0x0C00

#define TEMP_OUT 0x0E00

#define X_GYRO_LOW 0x1000
#define X_GYRO_OUT 0x1200

#define Y_GYRO_LOW 0x1400
#define Y_GYRO_OUT 0x1600

#define Z_GYRO_LOW 0x1800
#define Z_GYRO_OUT 0x1A00

#define X_ACCL_LOW 0x1C00
#define X_ACCL_OUT 0x1E00

#define Y_ACCL_LOW 0x2000
#define Y_ACCL_OUT 0x2200

#define Z_ACCL_LOW 0x2400
#define Z_ACCL_OUT 0x2600

#define X_MAGN_OUT 0x2800
#define Y_MAGN_OUT 0x2A00
#define Z_MAGN_OUT 0x2C00

#define BAROM_LOW 0x2E00
#define BAROM_OUT 0x3000

#define X_DELTANG_LOW 0x4000
#define X_DELTANG_OUT 0x4200

#define Y_DELTANG_LOW 0x4400
#define Y_DELTANG_OUT 0x4600 

#define Z_DELTANG_LOW 0x4800
#define Z_DELTANG_OUT 0x4A00

#define X_DELTVEL_LOW 0x4C00
#define X_DELTVEL_OUT 0x4E00

#define Y_DELTVEL_LOW 0x5000
#define Y_DELTVEL_OUT 0x5200

#define Z_DELTVEL_LOW 0x5400
#define Z_DELTVEL_OUT 0x5600

#define Q0_C11_OUT 0x6000
#define Q1_C12_OUT 0x6200
#define Q2_C13_OUT 0x6400
#define Q3_C21_OUT 0x6600

#define C22_OUT 0x6800

#define ROLL_C23_OUT 0x6A00
#define PITCH_C31_OUT 0x6C00
#define YAW_C32_OUT 0x6E00

#define C33_OUT 0x7000

/*Function Prototypes*/

uint8_t read_euler_YPR_angles(spi*,  double*,  double*,  double*); //takes yaw, pitch, roll in this order
uint8_t read_linear_acceleration(spi* ,  double*,  double*,  double*);
uint8_t read_linear_velocity(spi* ,  double*,  double*,  double*);
uint8_t set_DEC_RATE(spi*, uint16_t);

#endif