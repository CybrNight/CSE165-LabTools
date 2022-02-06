#!/bin/bash
#sudo wget -qO - https://raw.githubusercontent.com/CybrNight/CSE165-LabTools/master/install.sh | sudo bash

#Define GitHub root
source=https://raw.githubusercontent.com/CybrNight/CSE165-LabTools/master

git clone https://github.com/CybrNight/CSE165-LabTools.git

make CSE165-LabTools/Makefile
cp CSE165-LabTools/bin/lab_tools lab_tools
sudo chmod +x lab_tools

echo Finished building!
rm -r CSE165-LabTools
echo Removed source files!
echo Finished!
echo Run lab_tools binary.