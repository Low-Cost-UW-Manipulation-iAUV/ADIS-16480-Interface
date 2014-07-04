#!/bin/bash
echo "I'll copy all ADIS_Interface files over to the BBB"

rsync -avzh *.c 			root@192.168.2.101:/home/root/ADIS_Interface/
rsync -avzh *.h				root@192.168.2.101:/home/root/ADIS_Interface/
rsync -avzh ADIS_START.sh 	root@192.168.2.101:/home/root/ADIS_Interface/
rsync -avzh Makefile 		root@192.168.2.101:/home/root/ADIS_Interface/
rsync -avzh README.md 		root@192.168.2.101:/home/root/ADIS_Interface/

echo "All done, Good Success!"