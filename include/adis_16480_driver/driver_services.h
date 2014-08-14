/**************************************************************************************
*
*    ADIS16480 Driver Services
*
*    Description:
*        This module connects the ADIS driver to ROS

*
*    Created: 30/Jul/2014
*
*    Revision history (major):
* 		v1 - 30/July/2014 - 14:08 born
*		
*
*
***************************************************************************************/

#ifndef _ADIS_16480_DRIVER_
#define _ADIS_16480_DRIVER_


#include "ros/ros.h" //std ros header
//#include "adis_16480_driver/spi_ADIS_16480.h"

#include "adis_16480_driver/HR_YPR_lACC.h"
#include "adis_16480_driver/switchDataOutMode.h"
#include "adis_16480_driver/switchFrame.h"
#include "adis_16480_driver/doEKFReset.h"
#include "adis_16480_driver/doSoftReset.h"
#include "adis_16480_driver/doTare.h"
#include "adis_16480_driver/pause.h"
#include "adis_16480_driver/setFilterCoeffs.h"
#include "adis_16480_driver/startstopFilter.h"
#include "adis_16480_driver/setDecRate.h"

#define MS_TO_US 1000

#define DS_BODY_FRAME 1
#define DS_ENU_FRAME 0
#define DS_MODE_ACC 0
#define DS_MODE_VEL 1
#define ON 1
#define OFF 0
#define DONT_CARE 2

#define BNK_A 0
#define BNK_B 1
#define BNK_C 2
#define BNK_D 3

#define X_AXIS 0
#define Y_AXIS 1
#define Z_AXIS 2
#define XY_AXES_BASE_ADDRESS 0x1600
#define Z_AXES_BASE_ADDRESS 0x1800

#define X_AXIS_ONOFF 0x0800
#define Y_AXIS_ONOFF 0x4000
#define Z_AXIS_ONOFF 0x0003

#define SEL_BNK_A 0x00
#define SEL_BNK_B 0x01
#define SEL_BNK_C 0x10
#define SEL_BNK_D 0x11

class ADIS_16480_Interface;



class driver_services{
public:
	driver_services();
	driver_services(ADIS_16480_Interface* adis_pointer_incoming);

	bool switchDataOutMode(adis_16480_driver::switchDataOutMode::Request &req, adis_16480_driver::switchDataOutMode::Response &res );
	bool switchFrame(adis_16480_driver::switchFrame::Request &req, adis_16480_driver::switchFrame::Response &res);
	bool doEKFReset(adis_16480_driver::doEKFReset::Request &req, adis_16480_driver::doEKFReset::Response &res);
	bool doSoftReset(adis_16480_driver::doSoftReset::Request &req, adis_16480_driver::doSoftReset::Response &res);
	bool doTare(adis_16480_driver::doTare::Request &req, adis_16480_driver::doTare::Response &res);
	bool pause(adis_16480_driver::pause::Request &req, adis_16480_driver::pause::Response &res);
	bool setFilterCoeffs(adis_16480_driver::setFilterCoeffs::Request &req, adis_16480_driver::setFilterCoeffs::Response &res);
	bool startstopFilter(adis_16480_driver::startstopFilter::Request &req, adis_16480_driver::startstopFilter::Response &res);
	bool setDecRate(adis_16480_driver::setDecRate::Request &req, adis_16480_driver::setDecRate::Response &res );
	
	int publish_in_ROS(double* , double* , double* , double* , double* , double* );

	int initiate(ros::Publisher*);
	int stop();

private:
	ADIS_16480_Interface* adis_pointer;

	//ROS publisher handle
	ros::Publisher* ros_pub_handle;


};

#endif