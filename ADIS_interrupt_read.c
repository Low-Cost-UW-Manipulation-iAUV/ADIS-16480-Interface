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

#include "libsoc_gpio.h"
#include "libsoc_debug.h"
#include "ADIS_interrupt_read.h"


static int interrupt_count = 0;

/*Calculate the average time inbetween interrupts*/
int callback_test(void* interrupt_count)
{
  int* tmp_interrupt_count = (int*) interrupt_count;
  *tmp_interrupt_count = *tmp_interrupt_count +1; 
  return EXIT_SUCCESS;
}



int setup_interrupt_test(void)
{
  // Create both gpio pointers
  gpio *gpio_input;

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
  libsoc_gpio_callback_interrupt(gpio_input, &callback_test, (void*) &interrupt_count);
  
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
