#!/bin/bash
echo "I'll copy all ADIS_Interface files over to the BBB"

scp *.c 			BBB_BRLNET:/home/root/ADIS_Interface/
rsync -avzh *.h				BBB_BRLNET:/home/root/ADIS_Interface/
rsync -avzh ADIS_START.sh 	BBB_BRLNET:/home/root/ADIS_Interface/
rsync -avzh Makefile 		BBB_BRLNET:/home/root/ADIS_Interface/
rsync -avzh README.md 		BBB_BRLNET:/home/root/ADIS_Interface/

echo "All done, Good Success!"