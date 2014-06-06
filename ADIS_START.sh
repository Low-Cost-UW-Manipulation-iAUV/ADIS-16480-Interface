#!/bin/bash

#ADIS16480 Startup script
#This script intialises the ADIS16480 Interface and executes the libsoc based SPI interface with a number of startup checks
#Author: Raphael Nagel
#Date: 06/June/2014

clear
echo "Starting the ADIS16480 Interface"
echo "Loading the Device Tree Overlay"
echo BB-SPIDEV1 > /sys/devices/bone_capemgr.9/slots
echo "Adding the shared libsoc library to the linker path"
export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH

echo "Starting the SPI communication"
./ADIS_Interface