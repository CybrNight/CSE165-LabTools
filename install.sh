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

echo Hello

#Define GitHub root
source=https://raw.githubusercontent.com/CybrNight/CSE165-LabTools/master
 
mkdir resource
wget -qO resource/t.cpp $source/resource/t.cpp
wget -qO resource/t_std.cpp $source/resource/t_std.cpp
wget -qO lab_gen.sh $source/lab_gen.sh