#!/bin/bash
#sudo wget -O - https://raw.githubusercontent.com/CybrNight/CSE165-LabTools/master/install.sh | sudo bash

#Define colors
black="$(tput setaf 0)"
red="$(tput setaf 9)" 
green="$(tput setaf 10)"
yellow="$(tput setaf 11)" 
blue="$(tput setaf 12)"
purple="$(tput setaf 13)" 
cyan="$(tput setaf 14)" 
white="$(tput setaf 15)" 
bold=$(tput bold) 
RESET=$(tput reset) 



#Define GitHub root
source=https://raw.githubusercontent.com/CybrNight/CSE165-LabTools/master

mkdir LabTools
cd LabTools
git clone https://github.com/CybrNight/CSE165-LabTools.git .
chmod +x lab_gen.sh
