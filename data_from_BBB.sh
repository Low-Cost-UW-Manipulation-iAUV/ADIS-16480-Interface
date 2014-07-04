#!/bin/bash
echo "I'll get the data files from the BBB"

rsync -avzh root@10.42.0.87:/home/root/ADIS_Interface/*.txt ./

echo "All done, Have fun in Matlab!"