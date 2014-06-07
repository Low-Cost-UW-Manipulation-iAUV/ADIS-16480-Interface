#!/bin/bash
echo "I'll copy all ADIS_Interface files over to the BBB"

scp *.c 			root@10.42.0.87:/home/root/ADIS_Interface/
scp *.h				root@10.42.0.87:/home/root/ADIS_Interface/
scp ADIS_START.sh 	root@10.42.0.87:/home/root/ADIS_Interface/
scp Makefile 		root@10.42.0.87:/home/root/ADIS_Interface/
scp README.md 		root@10.42.0.87:/home/root/ADIS_Interface/

echo "All done, Good Success!"