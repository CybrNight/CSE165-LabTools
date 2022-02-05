#!/bin/bash
#wget -O - https://raw.githubusercontent.com/CybrNight/CSE165-LabTools/master/install.sh | sudo bash

#Define GitHub root
source=https://raw.githubusercontent.com/CybrNight/CSE165-LabTools/master
 
install(){
    mkdir resource
    wget -O resource/t.cpp $source/resource/lab_gen.sh
    wget -O resource/t_std.cpp $source/resource/lab_gen.sh
    wget -O lab_gen.sh $source/lab_gen.sh
}

update(){
    rm -r resource
    install
}

while getopts 'iur' flag;
do
case $flag in
    i) install ;;
    u) update ;;
    *) printf "Usage: ./install.sh -i | -u" ;;
    esac
done   