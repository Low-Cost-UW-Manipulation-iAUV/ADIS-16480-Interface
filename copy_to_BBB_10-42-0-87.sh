#!/bin/bash
echo "I'll copy all ADIS_Interface files over to the BBB"

rsync -avzh *.c 			root@10.42.0.87:/home/root/ADIS_Interface/
rsync -avzh *.h				root@10.42.0.87:/home/root/ADIS_Interface/
rsync -avzh ADIS_START.sh 	root@10.42.0.87:/home/root/ADIS_Interface/
rsync -avzh Makefile 		root@10.42.0.87:/home/root/ADIS_Interface/
rsync -avzh README.md 		root@10.42.0.87:/home/root/ADIS_Interface/

echo "All done, Good Success!"