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
*    Author: Raphael Nagel <first.lastname(#)posteo.de>
*    Created: 05/Nov/2013
*
*    Revision history (major):
* 	v1 - 30/July/2014 - 14:08 born
*		
*
*
***************************************************************************************/
#include <stdio.h>
#include <unistd.h>
 
#include <ros/ros.h> //std ros header
#include <ros/xmlrpc_manager.h> //These are necessary to allow printing ROS_INFO's after receiving a shutdown request
#include <signal.h>	


//Libsoc library includes
//#include "libsoc_spi.h"
#include "libsoc_debug.h"  

//ADIS Interface includes
#include "adis_16480_driver/wrapper_C_library_callback_to_Cpp.h"
#include "adis_16480_driver/ADIS_interrupt_read.h"
#include "adis_16480_driver/driver_services.h"
#include "adis_16480_driver/spi_ADIS_16480.h"


// Signal-safe flag for whether shutdown is requested
sig_atomic_t volatile g_request_shutdown = 0;

// Replacement SIGINT handler
void mySigIntHandler(int sig)
{
  g_request_shutdown = 1;
}
 
// Replacement "shutdown" XMLRPC callback
void shutdownCallback(XmlRpc::XmlRpcValue& params, XmlRpc::XmlRpcValue& result)
{
  int num_params = 0;
  if (params.getType() == XmlRpc::XmlRpcValue::TypeArray)
    num_params = params.size();
  if (num_params > 1)
  {
    std::string reason = params[1];
    ROS_WARN("Shutdown request received. Reason: [%s]", reason.c_str());
    g_request_shutdown = 1; // Set flag
  }
 
  result = ros::xmlrpc::responseInt(1, "", 0);
}
/*End of the SIGINT handling*/


using namespace std;



int main(int argc, char** argv){
 
  uint8_t status;

  ros::init(argc, argv, "adis_16480_driver", ros::init_options::NoSigintHandler);
  ros::NodeHandle n;

  /*SIGINT handling*/
  signal(SIGINT, mySigIntHandler);
 
	// Override XMLRPC shutdown
  ros::XMLRPCManager::instance()->unbind("shutdown");
  ros::XMLRPCManager::instance()->bind("shutdown", shutdownCallback);
  /*End of SIGINT handling*/
    

  //Initiate the hardware and interfaces    
	ADIS_16480_Interface my_adis;
  
  //Register the hardware handle with the wrapper  
  driver_services my_driver(&my_adis);
  my_adis.register_driver_service(&my_driver);
  //Set the my_adis object as the object containing the callee
  wrapper_for_c_library_single_instance_callback::setObj(my_adis) ;
  
    //initiate the topic
  ros::Publisher IMU_message = n.advertise<adis_16480_driver::HR_YPR_lACC>("raw_imu", 1000); 
  
    //get the ball rolling - I think this needs to be done before registering the services...
  status = my_driver.initiate(&IMU_message);
  if(status != 0){
    return 1;
  }

  //Register all Services
  ros::ServiceServer service_doEKFReset = n.advertiseService("doEKFReset", &driver_services::doEKFReset, &my_driver);
  ros::ServiceServer service_doSoftReset = n.advertiseService("doSoftReset", &driver_services::doSoftReset, &my_driver);
  ros::ServiceServer service_doTare = n.advertiseService("doTare", &driver_services::doTare, &my_driver);
  ros::ServiceServer service_pause = n.advertiseService("pause", &driver_services::pause, &my_driver);
  ros::ServiceServer service_setFilterCoeffs = n.advertiseService("setFilterCoeffs", &driver_services::setFilterCoeffs, &my_driver);
  ros::ServiceServer service_startstopFilter = n.advertiseService("startstopFilter", &driver_services::startstopFilter, &my_driver);
  ros::ServiceServer service_switchDataOutMode = n.advertiseService("switchDataOutMode", &driver_services::switchDataOutMode, &my_driver);
  ros::ServiceServer service_switchFrame = n.advertiseService("switchFrame", &driver_services::switchFrame, &my_driver);
  ros::ServiceServer service_switchFrame = n.advertiseService("setDecRate", &driver_services::setDecRate, &my_driver);


  


  //I'm not sure if spin works with the fancy shutdown stuff I'm trying to use...
  ros::spin();  

  my_driver.stop();
 
 return 0;
}
