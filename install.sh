#!/bin/bash
#sudo wget -qO - https://raw.githubusercontent.com/CybrNight/CSE165-LabTools/master/install.sh | sudo bash

#Define GitHub root
source=https://raw.githubusercontent.com/CybrNight/CSE165-LabTools/master

git clone https://github.com/CybrNight/CSE165-LabTools.git
cd CSE165-LabTools

make
cp bin/lab_tools lab_tools
cd ..

echo Finished!

rm -r CSE165-LabTools

echo Run lab_tools binary.