#!/bin/bash

#Define GitHub root
source=https://raw.githubusercontent.com/CybrNight/CSE165-LabTools/master
 
install(){
    
}

update(){
    echo Update
}

while getopts 'iur' flag;
do
case $flag in
    i) install ;;
    u) update ;;
    esac
done   