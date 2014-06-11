#!/bin/bash
echo "I'll copy all ADIS_Interface files over to the BBB"

scp *.c 			root@192.168.2.101:/home/root/ADIS_Interface/
scp *.h				root@192.168.2.101:/home/root/ADIS_Interface/
scp ADIS_START.sh 	root@192.168.2.101:/home/root/ADIS_Interface/
scp Makefile 		root@192.168.2.101:/home/root/ADIS_Interface/
scp README.md 		root@192.168.2.101:/home/root/ADIS_Interface/

echo "All done, Good Success!"