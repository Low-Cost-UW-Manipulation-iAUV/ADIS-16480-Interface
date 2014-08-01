/**************************************************************************************
*
*    ADIS16480 Driver Node
*
*    Description:
*        This module will asynchronically read the ADIS16480 and publish its data
*			on the raw_imu topic. 
*			The data is formed of a Quaternion or YPR angles as well as 3x1 vectors for
*			linear acceleration and angular velocities
*
W*    Created: 05/Nov/2013
*
*    Revision history (major):
* 	v1 - 30/July/2014 - 14:08 born
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