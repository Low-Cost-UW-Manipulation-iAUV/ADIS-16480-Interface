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
*     v1 - 30/July/2014 - 14:08 born
*   
*
*
***************************************************************************************/


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

//Resets the EKF after some time specified in ms
bool driver_services::doEKFReset(adis_16480_driver::doEKFReset::Request &req, adis_16480_driver::doEKFReset::Response &res){
    ROS_INFO("adis_16480_driver - Doing a EKF reset in %d seconds", req.msecs_to);
    usleep(req.msecs_to*MS_TO_US);
    res.confirm = adis_pointer->do_EKF_reset();
    ROS_INFO("adis_16480_driver - started EKF reset");
      return EXIT_SUCCESS;
}

//Switches the Data Out mode from YPR + Acc to YPE + Velocities(integrated on the ADIS 16480)
bool driver_services::switchDataOutMode(adis_16480_driver::switchDataOutMode::Request &req, adis_16480_driver::switchDataOutMode::Response &res ){
    
  if(req.mode == DS_MODE_ACC){
      ROS_INFO("adis_16480_driver - Switching Data Mode to YPR plus acceleration");
      res.confirm = adis_pointer->switchDataOutMode(DS_MODE_ACC);
        ROS_INFO("adis_16480_driver -  switched DataOutMode to YPR plus acceleration");
        return EXIT_SUCCESS;
  }

  if(req.mode == DS_MODE_VEL){
      ROS_INFO("adis_16480_driver - Switching Data Mode to YPR plus velocity");
      res.confirm = adis_pointer->switchDataOutMode(DS_MODE_VEL);
        ROS_INFO("adis_16480_driver - switched DataOutMode to YPR plus velocity");
        return EXIT_SUCCESS;  
  }  
  return EXIT_FAILURE;
}

//Switches from the std East North Up reference frame to the Body frame with x,y,z axes along the edges of the box
bool driver_services::switchFrame(adis_16480_driver::switchFrame::Request &req, adis_16480_driver::switchFrame::Response &res){
  if(req.Mode==DS_BODY_FRAME){
      ROS_INFO("adis_16480_driver - Switching to Body Frame in %d ms",req.msecs_to);
      usleep(req.msecs_to*MS_TO_US);
      res.confirm = adis_pointer->set_bits(PG3, EKF_CNFG, BITMASK_EKF_CNFG_BDY_FRM_SEL)
      if(res.confirm){
        ROS_INFO("adis_16480_driver - successfully switched to Body Frame");
        return EXIT_SUCCESS;
      }else{
        ROS_ERROR("adis_16480_driver - could not switch to Body Frame");
        return EXIT_FAILURE;
      }
  }

  if(req.Mode==DS_ENU_FRAME){
    ROS_INFO("adis_16480_driver - Switching to ENU Frame in %d ms",req.msecs_to);
    usleep(req.msecs_to*MS_TO_US);
    res.confirm = adis_pointer->clear_bits(PG3, EKF_CNFG, BITMASK_EKF_CNFG_BDY_FRM_SEL)
      if(res.confirm){
        ROS_INFO("adis_16480_driver - successfully switched to ENU Frame");
        return EXIT_SUCCESS;
      }else{
        ROS_ERROR("adis_16480_driver - could not switch to ENU Frame");
        return EXIT_FAILURE;
      }    
  }
  return EXIT_FAILURE;
}


//reset everything on the ADIS == power off and power on
bool driver_services::doSoftReset(adis_16480_driver::doSoftReset::Request &req, adis_16480_driver::doSoftReset::Response &res){
    ROS_INFO("adis_16480_driver - Doing a Soft Reset in %d msecs", req.msecs_to);
    usleep(req.msecs_to*MS_TO_US);
    res.confirm = adis_pointer->do_Software_reset();
    usleep(1800000); //sleep for 1.8s while reset is working
    ROS_INFO("adis_16480_driver - Software reset done");
    return EXIT_SUCCESS;

}

//Set the current orientation as the new reference orientation
bool driver_services::doTare(adis_16480_driver::doTare::Request &req, adis_16480_driver::doTare::Response &res){
    ROS_INFO("adis_16480_driver - Doing TARE in %d msecs",req.msecs_to);
    usleep(req.msecs_to*MS_TO_US);
    adis_pointer->do_Tare();
    ROS_INFO("adis_16480_driver - Did Tare");
    return EXIT_SUCCESS;
}

//pause the data_output of the ADIS
bool driver_services::pause(adis_16480_driver::pause::Request &req, adis_16480_driver::pause::Response &res){  
  if(req.onoff==ON){
    ROS_INFO("adis_16480_driver - Starting Pause in %dmsecs", req.msecs_to);
    usleep(req.msecs_to*MS_TO_US);
    res.confirm = adis_pointer->pause(ON);
    ROS_INFO("adis_16480_driver - Pausing");
    return EXIT_SUCCESS;
  }

 if(req.onoff==OFF){
    ROS_INFO("adis_16480_driver - Stopping Pause in %dmsecs", req.msecs_to);
    usleep(req.msecs_to*MS_TO_US);
    res.confirm = adis_pointer->pause(OFF);
    ROS_INFO("adis_16480_driver - Resuming Work");
    return EXIT_SUCCESS;
  }

  return EXIT_FAILURE;
}

bool driver_services::setFilterCoeffs(adis_16480_driver::setFilterCoeffs::Request &req, adis_16480_driver::setFilterCoeffs::Response &res){
    ROS_INFO("adis_16480_driver - Setting FIR coeffs");
    usleep(req.msecs_to*MS_TO_US);
    res.confirm = setFirCoeffs(req.FIR_Bank, req.FIR_filter_coeffs);
  if(res.confirm){
    ROS_INFO("adis_16480_driver -  Set FIR coeffs");
    return EXIT_SUCCESS;
  }else{
    ROS_ERROR("adis_16480_driver - could not set FIR coeffs");
    return EXIT_FAILURE;
  }          
}


bool driver_services::startstopFilter(adis_16480_driver::startstopFilter::Request &req, adis_16480_driver::startstopFilter::Response &res){
    uint8_t base_address = 0;
    uint8_t bitmask = 0;
    switch(req.axis){
      case X_AXIS:
        base_address = XY_AXES_BASE_ADDRESS;
        bitmask = X_AXIS_ONOFF;
        break;

      case Y_AXIS:
        base_address = XY_AXES_BASE_ADDRESS;
        bitmask = Y_AXIS_ONOFF; 
        break;

      case Z_AXIS:
        base_address = Z_AXES_BASE_ADDRESS;
        bitmask = Z_AXIS_ONOFF; 
        break;

       default:
       ROS_ERROR("ADIS_16480_Interface - StartStopFilter - no valid axis specified");
       return EXIT_FAILURE; 
    }

    switch(req.bank){
      case BNK_A:
        bank = SEL_BNK_A;
        break;

      case BNK_B:
        bank = SEL_BNK_B;
        break;

      case BNK_C:
        bank = SEL_BNK_C;
        break;

      case BNK_D:
        bank = SEL_BNK_D;
        break;

      default:
        ROS_ERROR("ADIS_16480_Interface - StartStopFilter - no valid Filter BANK specified");
        return EXIT_FAILURE;
    }
        

  switch(req.onoffdc){
    case ON:
      ROS_INFO("ADIS_16480_Interface - starting the filter for axis (xyz) %d with Bank (ABCD) %d", req.axis, req.bank);
      usleep(req.msecs_to*MS_TO_US);

      res.confirm = adis_pointer->write_word(PG3, base_address, bank);            //Select the right filter

      if(res.confirm ==  EXIT_SUCCESS){                                           //If successful

        res.confirm = adis_pointer->set_bits(PG3, base_address, bitmask);         //Turn the filter on
      }else{                                                        

        ROS_ERROR("ADIS_16480_Interface - StartStopFilter - Failed to select the right filter bank ");
        return EXIT_FAILURE;  
      }
      if(res.confirm == EXIT_SUCCESS){
        ROS_INFO("ADIS_16480_Interface - StartStopFilter - Successfully activated the FIR filter");
        return EXIT_SUCCESS;
      }else{
        ROS_ERROR("ADIS_16480_Interface - StartStopFilter - Failed to activate the FIR filter ");
        return EXIT_FAILURE;            
      }
      break;

    case OFF:
      ROS_INFO("ADIS_16480_Interface - Stopping the filter for axis (xyz) %d with Bank (ABCD) %d", req.axis, req.bank);
      usleep(req.msecs_to*MS_TO_US);        
      res.confirm = adis_pointer->clear_bits(PG3, base_address, bitmask);
     if(res.confirm == EXIT_SUCCESS){
        ROS_INFO("ADIS_16480_Interface - StartStopFilter - Successfully deactivated the FIR filter");
        return EXIT_SUCCESS;
      }else{
        ROS_ERROR("ADIS_16480_Interface - StartStopFilter - Failed to deactivate the FIR filter");
        return EXIT_FAILURE;            
      }        
      break;
      
    case DONT_CARE:
      ROS_INFO("ADIS_16480_Interface - Changing the filter bank for axis (xyz) %d to Bank (ABCD) %d", req.axis, req.bank);
      usleep(req.msecs_to*MS_TO_US);        
      adis_pointer->write_word(PG3, base_address, bank);
     if(res.confirm == EXIT_SUCCESS){
        ROS_INFO("ADIS_16480_Interface - StartStopFilter - Successfully switched FIR filter bank");
        return EXIT_SUCCESS;
      }else{
        ROS_ERROR("ADIS_16480_Interface - StartStopFilter - Failed to switch the FIR filter bank");
        return EXIT_FAILURE;            
      }             
      break;

    default:
      ROS_ERROR("ADIS_16480_Interface - you didnt specify whether to start, stop or don't care");
      return EXIT_FAILURE;
  }
}

bool driver_services::setDecRate(adis_16480_driver::setDecRate::Request &req, adis_16480_driver::setDecRate::Response &res){
  ROS_INFO("adis_16480_driver - Setting the Dec Rate");
  res.confirm = adis_pointer->set_DEC_RATE(req.DEC_RATE);

  if(res.confirm){
    ROS_INFO("adis_16480_driver -  Set Dec_Rate");
    return EXIT_SUCCESS;
  }else{
    ROS_ERROR("adis_16480_driver - could not set DEC_RATE");
    return EXIT_FAILURE;
  }      
  

  return EXIT_SUCCESS;
}