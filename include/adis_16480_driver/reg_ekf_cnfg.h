/*
 * ADIS 16480 EKF__CNFG Register Interface header
 * This SPI interface for the ADIS16480 IMU is based on libsoc library by Jack Mitchell
 * Author: Raphael Nagel
 * Date: 07/June/2014
 * 
 */

 #ifndef _ADIS_16480_EKF_CNFG_
 #define _ADIS_16480_EKF_CNFG_
/*Registers needed for the UWEsub's use of the - READ ADDRESSES unless specified*/ 
//Page 3
#define EKF_CNFG 0x5000

#define EKF_CNFG_DEFAULT 0x0200
/*Bitmasks*/
#define BITMASK_b15to13_11to10_7to5_2     0x131B  //and with EKF_CNFG register to set its not 'used/don't care' bits to 0

/*System Self Check - Page 0*/
#define BITMASK_EKF_CNFG_AUTORCVDIV 		0x1000
#define BITMASK_EKF_CNFG_FADE				0x0200
#define BITMASK_EKF_CNFG_ADPTEKF			0x0100
#define BITMASK_EKF_CNFG_ORIENT_FMR_CTRL	0x0010
#define BITMASK_EKF_CNFG_BDY_FRM_SEL		0x0008
#define BITMASK_EKF_CNFG_MAGDIS				0x0002
#define BITMASK_EKF_CNFG_GRAVRM				0x0001

//Function Declarations
//uint8_t read_adaptive_configuration(spi*);


#endif