/*
 * ADIS 16480 Data Interrupt read function Source
 * This SPI interface for the ADIS16480 IMU is based on libsoc library by Jack Mitchell
 * Author: Raphael Nagel
 * Date: 10/June/2014
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <stdint.h>
#include <string.h> 
//Libsoc library includes

#include "libsoc_gpio.h"
#include "libsoc_debug.h"

//Our includes 
#include "adis_16480_driver/ADIS_interrupt_read.h"
#include "adis_16480_driver/spi_ADIS_16480.h"
#include "adis_16480_driver/wrapper_C_library_callback_to_Cpp.h" 



#include <functional>
 


/*This function will be called when the callback mechanism is used. Place all jobs you want it to do in here.*/
int ADIS_16480_Interface::job_for_callback(){
  
  switch(interrupt_read_option){
  
    case IR_R_HR_YPR_lACC:
      HR_read_YPR_lin_Acc();
      break;

    case IR_R_HR_YPR_lVEL:
      HR_read_YPR_lin_Vel();
      break;    
    
    case IR_R_NOTHING:
      return 1;
      break;

    case IR_R_YPR:
      read_euler_YPR_angles();
      break;

    case IR_R_LACC:
      read_linear_acceleration();      
      break;  

    case IR_R_LVEL:
    read_linear_velocity();
      break;        

    case IR_R_YPR_LACC:
      read_YPR_lin_Acc();
      break;

    case IR_R_YPR_LVEL:
      read_YPR_lin_Vel();    
      break;

    default:
      return 1;        
  }



  if(interrupt_detection_enable_flag){
    detect_missed_IR();
  }

  if(print_data_to_file_flag){
    print_to_file();
  }
  
  return EXIT_SUCCESS;
};


int ADIS_16480_Interface::setup_interrupt_ADIS(int what_to_read)
{
  int ignore_me;
  interrupt_read_option = what_to_read;
  // Enable debug output
  libsoc_set_debug(1);

  // Request gpios
  gpio_input = libsoc_gpio_request(GPIO_INPUT, LS_SHARED);



  // Ensure both gpio were successfully requested and if not tidy up and exit
  if (gpio_input == NULL)
  {
    // If gpio_request was successful
    if (gpio_input)
    {
      // Free gpio request memory
      libsoc_gpio_free(gpio_input);
    }
  
    return EXIT_SUCCESS;  
  }
  
  
  // Set direction to INPUT
  libsoc_gpio_set_direction(gpio_input, INPUT);
  
  // Check the direction
  if (libsoc_gpio_get_direction(gpio_input) != INPUT)
  {
    printf("ADIS16480: IR Read - Failed to set data_ready pin direction to INPUT\n");
  if (gpio_input)
  {
    // Free gpio request memory
    libsoc_gpio_free(gpio_input);
  }
    
    return EXIT_SUCCESS;  
  }
  
  
  
  // Set edge to RISING
  libsoc_gpio_set_edge(gpio_input, RISING);
  
  // Check Edge
  if (libsoc_gpio_get_edge(gpio_input) != RISING)
  {
    printf("ADIS16480: IR Read - Failed to set trigger to RISING edge \n");
  if (gpio_input)
  {
    // Free gpio request memory
    libsoc_gpio_free(gpio_input);
  }
    
    return EXIT_SUCCESS;    }

  // Turn debug off
  libsoc_set_debug(0);

  // Setup callback
  libsoc_gpio_callback_interrupt(gpio_input, &wrapper_for_c_library_single_instance_callback::glue_job_for_callback,(void*) &ignore_me);
  printf("ADIS_16480: Interrupt Handler has been initiated\n");   
  

  
  return EXIT_SUCCESS;
}

int ADIS_16480_Interface::disable_Interrupt_ADIS(void){
  libsoc_gpio_callback_interrupt_cancel(gpio_input);

  // Turn debug back on
  libsoc_set_debug(1);
  
  printf("ADIS_16480: Interrupt Handler has been stopped\n");   
  
  //tidy up afterwards
  // If gpio_request was successful
  if (gpio_input)
  {
    // Free gpio request memory
    libsoc_gpio_free(gpio_input);
  }
}