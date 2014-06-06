objects = spi_ADIS_16480.o reg_sys_e_flag.o 
export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH

ADIS_Interface : $(objects)
	gcc -o ADIS_Interface -L /usr/local/lib -lsoc $(objects)

spi_ADIS_16480.o : spi_ADIS_16480.c spi_ADIS_16480.h
	gcc -c -I /usr/local/include  spi_ADIS_16480.c 

reg_sys_e_flag.o : reg_sys_e_flag.c reg_sys_e_flag.h  spi_ADIS_16480.h
	gcc -c -I /usr/local/include  reg_sys_e_flag.c 

clean: 
		rm ADIS_Interface $(objects)
