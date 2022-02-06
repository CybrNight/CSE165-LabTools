#!/bin/bash
#sudo wget -qO - https://raw.githubusercontent.com/CybrNight/CSE165-LabTools/master/install.sh | sudo bash

#Define GitHub root
source=https://raw.githubusercontent.com/CybrNight/CSE165-LabTools/master

mkdir CSE165-LabTools
git clone https://github.com/CybrNight/CSE165-LabTools.git temp
 
make temp/Makefile
cp temp/bin/lab_tools CSE165-LabTools/lab_tools
cp -r temp/res/ CSE165-LabTools

echo Finished building!
rm -r CSE165-LabTools
echo Removed source files!
echo Finished!
echo Run lab_tools binary in this directory