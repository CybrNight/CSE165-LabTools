#!/bin/bash
#sudo wget -qO - https://raw.githubusercontent.com/CybrNight/CSE165-LabTools/master/install.sh | sudo bash

#Define GitHub root
source=https://raw.githubusercontent.com/CybrNight/CSE165-LabTools/master

mkdir CSE165-LabTools
git clone https://github.com/CybrNight/CSE165-LabTools.git temp

# Build repo 
make release temp/Makefile
cp temp/bin/lab_tools CSE165-LabTools/lab_tools
cp -r temp/res/ CSE165-LabTools
rm -r temp

echo Removed source files
echo Finished building!
echo Finished!
echo Run lab_tools binary in this directory