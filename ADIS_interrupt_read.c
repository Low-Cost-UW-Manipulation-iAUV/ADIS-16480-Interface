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
#include "ADIS_interrupt_read.h"
#include "spi_ADIS_16480.h"
#include "wrapper_C_library_callback_to_Cpp.h" 



#include <functional>
 

/*Calculate the average time inbetween interrupts*/
int callback_test(void* arg){
  
  int* tmp_count = (int*) arg;
  *tmp_count = *tmp_count +1;
  //my_adis.read_euler_YPR_angles();
  //my_adis.read_linear_acceleration();
  return EXIT_SUCCESS;
}



/*This function will be called when the callback mechanism is used. Place all jobs you want it to do in here.*/
int ADIS_16480_Interface::job_for_callback(){
  
  read_euler_YPR_angles();
  read_linear_acceleration();
  if(print_data_to_file_flag){
    print_to_file();
  }
  
  return EXIT_SUCCESS;
};


int ADIS_16480_Interface::setup_interrupt_test(void)
{
  // Create both gpio pointers
  interrupt_count = 0; //initialise the rpivate member
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
  libsoc_gpio_callback_interrupt(gpio_input, &callback_test,(void*) &interrupt_count);
  
  sleep(10);
  libsoc_gpio_callback_interrupt_cancel(gpio_input);
  
  // Turn debug back on
  libsoc_set_debug(1);
  
  printf("ADIS_16480: Interrupt test - we've had  %d in 10 sec\n", interrupt_count);   
    
  // Cancel the callback on interrupt

  
  

  
  //tidy up afterwards
  // If gpio_request was successful
  if (gpio_input)
  {
    // Free gpio request memory
    libsoc_gpio_free(gpio_input);
  }
  
  return EXIT_SUCCESS;
}

int ADIS_16480_Interface::setup_interrupt_ADIS(void)
{
  int ignore_me;

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