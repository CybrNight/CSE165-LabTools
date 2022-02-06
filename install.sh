#!/bin/bash
#sudo wget -qO - https://raw.githubusercontent.com/CybrNight/CSE165-LabTools/master/install.sh | sudo bash

#Define GitHub root
source=https://raw.githubusercontent.com/CybrNight/CSE165-LabTools/master
dest="LabTools"

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

mkdir $dest
git clone https://github.com/CybrNight/CSE165-LabTools.git temp
echo "${green}Cloned repo"
# Build repo 
cd temp
echo "${yellow}Starting build"
make release
echo "${green}Done"
cd ..
echo "${yellow}Organizing program structure"
cp temp/lab_tools $dest
cp -r temp/res/ $dest
echo "${green}Done"
read -n1 -p "${white}Would you like to keep the repo folder? (${green}Y/N${white}):" choice

case $choice in
Y|y)
    rm -r temp
    echo "${red}Deleted source files"
    ;;
esac

echo "${green}"Finished!
echo Run lab_tools binary in this directory