/**
 * 
 * This SPI interface for the ADIS16480 IMU is based on libsoc library by Jack Mitchell
 * Author: Raphael Nagel
 * Date: 04/June/2014
 */
#define FILENAME_TO_PRINT_DATA_TO "ADIS-Data-#-%d-24-Jul-2014-17-55"


/*standard defines, etc (stolen from libsoc test files)*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdint.h>
#include <string.h>
#include <sys/time.h>

//Libsoc library includes
#include <libsoc_spi.h>
#include <libsoc_debug.h>  

//ADIS Interface includes
#include "adis_16480_driver/spi_ADIS_16480.h"
 
#include "adis_16480_driver/reg_diag_sts.h"
#include "adis_16480_driver/reg_glob_cmd.h"
#include "adis_16480_driver/reg_sys_e_flag.h"
#include "adis_16480_driver/reg_ekf_cnfg.h"
#include "adis_16480_driver/data_out.h"
#include "adis_16480_driver/ADIS_interrupt_read.h"

#include "adis_16480_driver/wrapper_C_library_callback_to_Cpp.h" 

using namespace std;

//Print the data to console (useful for debugging but might/will slow down the process of reading values)
void ADIS_16480_Interface::print_data_console(bool yesorno){
  print_data_to_console_flag = yesorno;
};

void ADIS_16480_Interface::publish_to_ros_or_not(bool yesorno){
  publish_in_ros_flag = yesorno;
};


void ADIS_16480_Interface::register_driver_service(driver_services* my_driver_incoming ){
  my_driver = my_driver_incoming;
}

void ADIS_16480_Interface::print_data_file(unsigned int counter, bool IR_miss_detect, bool ypr, bool linear_accelerations, bool linear_velocities, bool linear_position, bool angular_velocities){
  char filename[40] = "";

  if(ypr|linear_accelerations|linear_velocities|angular_velocities){

    print_data_to_file_flag = 1;
    print_ypr_flag = ypr;
    print_linear_accelerations_flag = linear_accelerations;
    print_linear_velocities_flag = linear_velocities;
    print_linear_position_flag = linear_position;
    print_angular_velocities_flag = angular_velocities;
    
    sprintf(filename, FILENAME_TO_PRINT_DATA_TO, counter);
    strcat(filename,".txt");
    file_to_print_to.open(filename);
  
    if(IR_miss_detect){
      file_to_print_to << "interrupts missed, "; 
    }
    if(print_ypr_flag){
      file_to_print_to << "yaw, pitch, roll, "; 
    }
    if(print_linear_accelerations_flag){
      file_to_print_to << "x acceleration linear, y acceleration linear, z acceleration linear, "; 
      }
    if(print_linear_velocities_flag){
      file_to_print_to << "x velocity linear, y velocity linear, z velocity linear, "; 
    }
    if(print_linear_position_flag){
      file_to_print_to << "x position linear, y position linear, z position linear, "; 
    }
    if(print_angular_velocities_flag){
      file_to_print_to << "x velocity angular, y velocity angular, z velocity angular, "; 

    }
    file_to_print_to << "\n";  
}else{

    print_data_to_console_flag = 0;
    print_data_to_file_flag = 0;
    print_ypr_flag = 0;
    print_linear_accelerations_flag = 0;
    print_linear_velocities_flag = 0;
    print_linear_position_flag = 0;
    print_angular_velocities_flag = 0;  
    file_to_print_to.close();  
  }
};

void ADIS_16480_Interface::print_to_file(){

  //print the time on the ADIS

  if(interrupt_detection_enable_flag){
    if(IRs_missed < 10000){
      file_to_print_to << IRs_missed << ", "; 
    }else{
      file_to_print_to << "!!!ERROR: Detection probably disabled!!!" << ", "; 
    }
  }
  if(print_ypr_flag){
    file_to_print_to << yaw << "," << pitch << "," << roll << ","; 
  }
  if(print_linear_accelerations_flag){
    file_to_print_to << x_acceleration << "," << y_acceleration << "," << z_acceleration << ",";
    }
  if(print_linear_velocities_flag){
    file_to_print_to << x_velocity << "," << y_velocity << "," << z_velocity << ",";
  }
  if(print_linear_position_flag){
    file_to_print_to << x_position << "," << y_position << "," << z_position << ",";
  }
  if(print_angular_velocities_flag){

  }

  file_to_print_to << "\n";

};

//Initialises the ADIS with the settings needed for my BBB-custom_board-ADIS setup
ADIS_16480_Interface::ADIS_16480_Interface(){
  configure_initialise(SPI_DEVICE, CHIP_SELECT, MODE_3, BITS_16, 11999999);
 
  tx[0] = 0;
  rx[0] = 0;
 
  yaw=0;
  pitch = 0;
  roll = 0;
 
  x_acceleration = 0;
  y_acceleration = 0;
  z_acceleration = 0;
 
  x_velocity = 0;
  y_velocity = 0;
  z_velocity = 0;

  x_position = 0;
  y_position = 0;
  z_position = 0;

  print_data_to_console_flag = 0;
  print_data_to_file_flag = 0;
  print_ypr_flag = 0;
  print_linear_accelerations_flag = 0;
  print_linear_velocities_flag = 0;
  print_angular_velocities_flag = 0;

  publish_in_ros_flag = 1;

  interrupt_detection_enable_flag = 0;
  IRs_missed = 20000;
  decimation_rate = 0;
  //The standard data_ready Period as define by the output rate found in the ADIS 16480datasheet
  data_ready_period_usec = (1/2460) * SECS_TO_USECS;


}

ADIS_16480_Interface::ADIS_16480_Interface(uint8_t spi_device, uint8_t c_select_line, spi_mode spi_hw_mode, spi_bpw spi_bit_mode, uint32_t spi_frequency){
  configure_initialise(spi_device, c_select_line, spi_hw_mode, spi_bit_mode, spi_frequency);
  uint16_t tx[35], rx[35];

  tx[0] = 0;
  rx[0] = 0;
  
  yaw=0;
  pitch = 0;
  roll = 0;
  
  x_acceleration = 0;
  y_acceleration = 0;
  z_acceleration = 0;
  
  x_velocity = 0;
  y_velocity = 0;
  z_velocity = 0;

  x_position = 0;
  y_position = 0;
  z_position = 0;

  print_data_to_console_flag = 0;
  print_data_to_file_flag = 0;
  print_ypr_flag = 0;
  print_linear_accelerations_flag = 0;
  print_linear_velocities_flag = 0;
  print_angular_velocities_flag = 0;

  publish_in_ros_flag = 1;

  interrupt_detection_enable_flag = 0;
  IRs_missed = 20000;
  decimation_rate = 0;
  //The standard data_ready Period as define by the output rate found in the ADIS 16480datasheet
  data_ready_period_usec = (1/2460) * SECS_TO_USECS;
}

uint8_t ADIS_16480_Interface::read_product_id() {
  
  ROS_INFO("ADIS_16480_Driver: Reading Product ID\n");
    
  tx[0] = PG0;        //Switch to page 0
  tx[1] = PROD_ID;    //Ask for the PROD_ID
  rx[0] = 0;
  rx[1] = 0;
  rx[2] = 0;
 

  libsoc_spi_rw(spi_dev, tx, rx, 6);

  if (rx[2] != PROD_ID_DEFAULT){
    ROS_ERROR("ADIS_16480_Driver: wrong PROD_ID, rx[2]: 0x%x\n",rx[2]);
    return 0; // IMplement proper error message later
  }else{
    ROS_INFO("ADIS_16480_Driver: correct PROD_ID: 0x%x \n",rx[2]);
    return 1; // IMplement proper error message later
  }
  
  return 0;
}

uint8_t ADIS_16480_Interface::configure_initialise(uint8_t spi_device, uint8_t c_select_line, spi_mode spi_hw_mode, spi_bpw spi_bit_mode, uint32_t spi_frequency){
  libsoc_set_debug(1);
   
  uint8_t status;

  spi_dev = libsoc_spi_init(spi_device, c_select_line);

  if (!spi_dev)
  {
    ROS_ERROR("ADIS_16480_Driver - Failed to get spidev device!\n");
    return EXIT_FAILURE;
  }

  libsoc_spi_set_mode(spi_dev, spi_hw_mode); //ADIS16480 needs 16-bit mode
  libsoc_spi_get_mode(spi_dev);
  
  libsoc_spi_set_speed(spi_dev, spi_frequency); //Seems to be limited to <12MHz ??! weird...
  libsoc_spi_get_speed(spi_dev);
  
  libsoc_spi_set_bits_per_word(spi_dev, spi_bit_mode);
  libsoc_spi_get_bits_per_word(spi_dev);
 
 return EXIT_SUCCESS; 
}

uint8_t ADIS_16480_Interface::close(){
  libsoc_spi_free(spi_dev);
  //close the file if it was open.
  print_data_file(0, OFF, OFF,OFF,OFF,OFF,OFF);
  return EXIT_SUCCESS;
}



//****************************************************************************************************************************************
//****************************************************************************************************************************************
//****************************************************************************************************************************************
//****************************************************************************************************************************************
