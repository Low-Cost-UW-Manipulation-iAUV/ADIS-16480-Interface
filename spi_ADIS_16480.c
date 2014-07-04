/**
 * 
 * This SPI interface for the ADIS16480 IMU is based on libsoc library by Jack Mitchell
 * Author: Raphael Nagel
 * Date: 04/June/2014
 */
#define FILENAME_TO_PRINT_DATA_TO "ADIS-Data-04-Jul-2014-17-55.txt"



/*standard defines, etc (stolen from libsoc test files)*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdint.h>
#include <string.h>
#include <sys/time.h>

//Libsoc library includes
#include "libsoc_spi.h"
#include "libsoc_debug.h"  

//ADIS Interface includes
#include "spi_ADIS_16480.h"
 
#include "reg_diag_sts.h"
#include "reg_glob_cmd.h"
#include "reg_sys_e_flag.h"
#include "reg_ekf_cnfg.h"
#include "data_out.h"
#include "ADIS_interrupt_read.h"

#include "wrapper_C_library_callback_to_Cpp.h" 

using namespace std;

//Print the data to console (useful for debugging but might/will slow down the process of reading values)
void ADIS_16480_Interface::print_data_console(bool yesorno){
  print_data_to_console_flag = yesorno;
};

void ADIS_16480_Interface::print_data_file(bool ypr, bool linear_accelerations, bool linear_velocities, bool linear_position, bool angular_velocities){
  if(ypr|linear_accelerations|linear_velocities|angular_velocities){

    print_data_to_file_flag = 1;
    print_ypr_flag = ypr;
    print_linear_accelerations_flag = linear_accelerations;
    print_linear_velocities_flag = linear_velocities;
    print_linear_position_flag = linear_position;
    print_angular_velocities_flag = angular_velocities;

    file_to_print_to.open(FILENAME_TO_PRINT_DATA_TO);
  if(print_ypr_flag){
    file_to_print_to << "yaw, pitch, roll, "; 
  }
  if(print_linear_accelerations_flag){
    file_to_print_to << "x_acceleration_linear, y_acceleration_linear, z_acceleration_linear, "; 
    }
  if(print_linear_velocities_flag){
    file_to_print_to << "x_velocity_linear, y_velocity_linear, z_velocity_linear, "; 
  }
  if(print_linear_position_flag){
    file_to_print_to << "x_position_linear, y_position_linear, z_position_linear, "; 
  }
  if(print_angular_velocities_flag){
    file_to_print_to << "x_velocity_angular, y_velocity_angular, z_velocity_angular, "; 

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
}

uint8_t ADIS_16480_Interface::read_product_id() {
  
  printf("ADIS16480: Reading Product ID\n");
    
  tx[0] = PG0;        //Switch to page 0
  tx[1] = PROD_ID;    //Ask for the PROD_ID
  tx[2] = PG0;       //change back to page 0 while register While getting the PROD_ID

  rx[0] = 0;
  rx[1] = 0;
  rx[2] = 0;
 

  libsoc_spi_rw(spi_dev, tx, rx, 6);

  if (rx[2] != PROD_ID_DEFAULT){
    printf("ADIS16480: wrong PROD_ID, rx[2]: 0x%x\n",rx[2]);
    return 0; // IMplement proper error message later
  }else{
    printf("ADIS16480: correct PROD_ID: 0x%x \n",rx[2]);
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
    printf("Failed to get spidev device!\n");
    return EXIT_FAILURE;
  }

  libsoc_spi_set_mode(spi_dev, spi_hw_mode); //ADIS16480 needs 16-bit mode
  libsoc_spi_get_mode(spi_dev);
  
  libsoc_spi_set_speed(spi_dev, spi_frequency); //Seems to be limited to <12MHz ??! weird...
  libsoc_spi_get_speed(spi_dev);
  
  libsoc_spi_set_bits_per_word(spi_dev, spi_bit_mode);
  libsoc_spi_get_bits_per_word(spi_dev);
  
}

uint8_t ADIS_16480_Interface::close(){
  libsoc_spi_free(spi_dev);
  //close the file if it was open.
  print_data_file(OFF,OFF,OFF,OFF,OFF);
  return EXIT_SUCCESS;
}



//****************************************************************************************************************************************
//****************************************************************************************************************************************
//****************************************************************************************************************************************
//****************************************************************************************************************************************
/*The custom code starts here*/

int main()
{
  int i;
  double x,y,z;
  //uint16_t dec_rate_wanted = 1; //set the dec_rate
  ADIS_16480_Interface my_adis;
  uint8_t status;

  // Set the my_adis  object as the object containing the callee
  wrapper_for_c_library_single_instance_callback::setObj(my_adis) ;
  
  my_adis.print_data_console(ON);
  my_adis.print_data_file(OFF, ON, ON, ON, OFF);

  status = my_adis.read_product_id();    //best testing - expect 0x4060
  if(status){
    status = my_adis.read_self_test();
    status = my_adis.read_error_flags();
    libsoc_set_debug(0);
    //my_adis.set_DEC_RATE(spi_dev,dec_rate_wanted);
    my_adis.set_bits(PG3, EKF_CNFG, BITMASK_EKF_CNFG_GRAVRM);
    my_adis.print_data_console(OFF);
    my_adis.setup_interrupt_ADIS();
    for(i=0;i<100000;i++){  
      //my_adis.read_linear_velocity(&x, &y, &z);
      usleep(10);
    }

    my_adis.disable_Interrupt_ADIS();
  }
  my_adis.close();
  return EXIT_SUCCESS;
}
