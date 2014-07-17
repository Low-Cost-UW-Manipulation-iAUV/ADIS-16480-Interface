ADIS-16480-Interface
====================

This is an spi interface to the ADIS16480 IMU it uses the libsoc library by Jack Mitchell

libsoc 16-bit SPI words
----
The libsoc library has been modified to use 16-bit SPI words and can be found here: https://github.com/compiaffe/libsoc
The real libsoc should support 16-bit SPI words from 0.7 onwards. https://github.com/jackmitch/libsoc

"Installing" modified libsoc
----
Installation of the modified libsoc on the Beagle Bone Black goes as follows:

get the source

cd libsoc-master
./autogen.sh
./configure
make install

When compiling we have to specify where this library is placed…

    Linking Flags: -L /usr/local/lib as in g++ -o ADIS_Interface -L /usr/local/lib -lsoc $(objects)
    Compiling Flags -I /usr/local/include as in g++ -c -I /usr/local/include reg_sys_e_flag.c

When executing the software we have to add the library to the path:

    export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH


An example of the above can be found in the Makefile


Use of the ADIS 16480 Interface
----
At the moment the main function is placed inside the ADIS16480.c. It should really be somewhere else-.-
Find inspiration there.

The example uses the interrupts generated by the ADIS data_ready line to do a callback read as specified by the parameter in

"setup_interrupt_ADIS();"
