/*
 * ADIS 16480 C Library Callback interface wrapper header
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
#include "adis_16480_driver/spi_ADIS_16480.h"
#include <stdint.h>


#ifndef _WRAPPER_C_LIB_CPP_
#define _WRAPPER_C_LIB_CPP_

 /*This wrapper allows our instanciated class (object) to provide one of its member functions to an external C library
  In this case the library is the mentioned libsoc library. It relies on a static member function which will hold a pointer to the ADIS_16480_Interface object my_adis.*/
class wrapper_for_c_library_single_instance_callback{
	wrapper_for_c_library_single_instance_callback();
public:
  static int glue_job_for_callback(void*);
  static void setObj(ADIS_16480_Interface&);

private:

  static ADIS_16480_Interface* fObj;
};

#endif

//!!!!! Do the following after instantiating the object which is meant to provide the callee: !!!!!
/*

wrapper_for_c_library_single_instance_callback::setObj(my_adis);

*/