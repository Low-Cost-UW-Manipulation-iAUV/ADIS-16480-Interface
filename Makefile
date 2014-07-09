objects = spi_ADIS_16480.o reg_sys_e_flag.o reg_diag_sts.o reg_glob_cmd.o reg_ekf_cnfg.o data_out.o ADIS_interrupt_read.o wrapper_C_library_callback_to_Cpp.o ADIS_write_to_registers.o HR_data_out.o

ADIS_Interface: $(objects)
	g++ -o ADIS_Interface -L /usr/local/lib -lsoc $(objects)

spi_ADIS_16480.o: spi_ADIS_16480.c spi_ADIS_16480.h
	g++ -c -I /usr/local/include  spi_ADIS_16480.c 

reg_sys_e_flag.o: reg_sys_e_flag.c reg_sys_e_flag.h spi_ADIS_16480.h
	g++ -c -I /usr/local/include  reg_sys_e_flag.c

reg_diag_sts.o: reg_diag_sts.c reg_diag_sts.h spi_ADIS_16480.h
	g++ -c -I /usr/local/include  reg_diag_sts.c 

reg_glob_cmd.o: reg_glob_cmd.c reg_glob_cmd.h spi_ADIS_16480.h
	g++ -c -I /usr/local/include reg_glob_cmd.c

reg_ekf_cnfg.o: reg_ekf_cnfg.c reg_ekf_cnfg.h spi_ADIS_16480.h
	g++ -c -I /usr/local/include reg_ekf_cnfg.c

data_out.o: data_out.c data_out.h spi_ADIS_16480.h
	g++ -c -I /usr/local/include data_out.c

HR_data_out.o: HR_data_out.c data_out.h HR_data_out.h spi_ADIS_16480.h
	g++ -c -I /usr/local/include HR_data_out.c	

ADIS_interrupt_read.o: ADIS_interrupt_read.c ADIS_interrupt_read.h spi_ADIS_16480.h
	g++ -c -I /usr/local/include ADIS_interrupt_read.c 

wrapper_C_library_callback_to_Cpp.o: wrapper_C_library_callback_to_Cpp.h wrapper_C_library_callback_to_Cpp.c  spi_ADIS_16480.h
	g++ -c -I /usr/local/include wrapper_C_library_callback_to_Cpp.c 

ADIS_write_to_registers.o: ADIS_write_to_registers.c spi_ADIS_16480.h
		g++ -c -I /usr/local/include ADIS_write_to_registers.c 

clean: 
		rm ADIS_Interface $(objects)
