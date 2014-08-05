


#include <stdio.h>
#include <unistd.h>
 

 //ADIS Interface includes
#include "adis_16480_driver/spi_ADIS_16480.h"
#include "adis_16480_driver/ADIS_interrupt_read.h"
#include "adis_16480_driver/driver_services.h"



driver_services::driver_services(ADIS_16480_Interface* a_pointer)
{
  adis_pointer = a_pointer;
}


int driver_services::initiate(ros::Publisher* ros_publisher_handle)
{
  uint status = 0;
	//Store the publisher handle in the object...
  	ros_pub_handle = ros_publisher_handle;


	//Enable Publish to ROS, turn printing to console off
  adis_pointer->publish_to_ros_or_not(ON);
  adis_pointer->print_data_console(OFF);


  //Do startup tests on the ADIS:
    status = adis_pointer->read_product_id();    //best testing - expect 0x4060
  if(status){

    status = adis_pointer->read_self_test();
    status = adis_pointer->read_error_flags();
  }else{
    ROS_ERROR("adis_16480_driver - Cannot connect to IMU");
    adis_pointer->close();
    return 1;
  }

  //Reset the ADIS to remove all settings which might have been changed since its last restart
  adis_pointer->do_Software_reset();
  sleep(2);


	//Initiate the interrupt service routine reading of the data
  adis_pointer->set_DEC_RATE(0);
  adis_pointer->setup_interrupt_detection(ON);
  adis_pointer->setup_interrupt_ADIS(IR_R_HR_YPR_lACC);

  return 0;
}



int driver_services::stop(){

	adis_pointer->disable_Interrupt_ADIS();
	adis_pointer->print_data_console(OFF);
  	adis_pointer->print_data_file(0, OFF, OFF, OFF, OFF, OFF, OFF);
  	adis_pointer->close();

  	return 0;
}


int driver_services::publish_in_ROS(double* yaw, double* pitch, double* roll, double* x, double* y, double* z){
	adis_16480_driver::HR_YPR_lACC imu_data;

	imu_data.ypr.yaw = *yaw;
	imu_data.ypr.pitch = *pitch;
	imu_data.ypr.roll = *roll;

	imu_data.acceleration.linear_x = *x;
	imu_data.acceleration.linear_y = *y;
	imu_data.acceleration.linear_z = *z;


	ros_pub_handle->publish(imu_data);
}


// All Services from here

bool driver_services::doEKFReset(adis_16480_driver::doEKFReset::Request &req, adis_16480_driver::doEKFReset::Response &res){
    ROS_INFO("adis_16480_driver - You have reached the EKFReset function, but nothing is implemented yet");

}


bool driver_services::switchDataOutMode(adis_16480_driver::switchDataOutMode::Request &req, adis_16480_driver::switchDataOutMode::Response &res ){
    ROS_INFO("adis_16480_driver - You have reached the switchDataOutMode function, but nothing is implemented yet");

}


bool driver_services::switchFrame(adis_16480_driver::switchFrame::Request &req, adis_16480_driver::switchFrame::Response &res){
    ROS_INFO("adis_16480_driver - You have reached the switchFrame function, but nothing is implemented yet");

}



bool driver_services::doSoftReset(adis_16480_driver::doSoftReset::Request &req, adis_16480_driver::doSoftReset::Response &res){
    ROS_INFO("adis_16480_driver - You have reached the doSoftReset function, but nothing is implemented yet");

}


bool driver_services::doTare(adis_16480_driver::doTare::Request &req, adis_16480_driver::doTare::Response &res){
    ROS_INFO("adis_16480_driver - You have reached the doTare function, but nothing is implemented yet");

}


bool driver_services::pause(adis_16480_driver::pause::Request &req, adis_16480_driver::pause::Response &res){
    ROS_INFO("adis_16480_driver - You have reached the pause function, but nothing is implemented yet");



}
bool driver_services::setFilterCoeffs(adis_16480_driver::setFilterCoeffs::Request &req, adis_16480_driver::setFilterCoeffs::Response &res){
    ROS_INFO("adis_16480_driver - You have reached the setFilterCoeffs function, but nothing is implemented yet");

}


bool driver_services::startstopFilter(adis_16480_driver::startstopFilter::Request &req, adis_16480_driver::startstopFilter::Response &res){
    ROS_INFO("adis_16480_driver - You have reached the startstopFilter function, but nothing is implemented yet");

}

bool driver_services::setDecRate(adis_16480_driver::setDecRate::Request &req, adis_16480_driver::setDecRate::Response &res){
  res.confirm = adis_pointer->set_DEC_RATE(req.dec_rate);
      ROS_INFO("adis_16480_driver - you have set the Dec Rate");

  return 0;
}