/*
 * ADIS 16480 C Library Callback interface wrapper source
 * This file allows our C++ objects to register a member function as a callback (callee) for the 
 *	caller in the libsoc library by Jack Mitchell
 * Author: Raphael Nagel
 * Date: 04/July/2014
 * 
 */
/*libsoc defines, etc (stolen from libsoc test files)*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdint.h>
#include <string.h>
#include <sys/time.h>

//ADIS Interface includes
#include "adis_16480_driver/wrapper_C_library_callback_to_Cpp.h" 
#include "adis_16480_driver/spi_ADIS_16480.h"

/*Necessary to allocate space for the static member variable*/
ADIS_16480_Interface* wrapper_for_c_library_single_instance_callback::fObj;

/*Register this function with the C library caller*/
int wrapper_for_c_library_single_instance_callback::glue_job_for_callback(void* ignore){
    return fObj->job_for_callback();
  }

/*Tell this wrapper about the object you would like to use. THIS NEEDS TO BE DONE JUST AFTER INSTANTIATING THE OBJECT, prob. in the main function.*/
void wrapper_for_c_library_single_instance_callback::setObj(ADIS_16480_Interface& obj){
    fObj = &obj;
  }
