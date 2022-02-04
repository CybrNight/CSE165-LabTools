#!/bin/bash

#Define default directory
default_dir=($PWD)
lab=1
q_num=6
root_name="none"
std="N"

#Define colors
black='\e[0;30m' # Black - Regular
red='\e[0;31m' # Red
green='\e[0;32m' # Green
yellow='\e[0;33m' # Yellow
blue='\e[0;34m' # Blue
purple='\e[0;35m' # Purple
cyan='\e[0;36m' # Cyan
white='\e[0;37m' # White
bold=$(tput bold)
RESET="\033[0m"

clear
echo -e "${green}${bold}This script will setup the folder structure for the lab. ${RESET}"
echo -e "${red}${bold}WARNING: By default this will create a new directory in the same directory as setup.sh ($green$default_dir${red}${bold}) containing all created files!"
read -p "-Press enter to continue-"
echo 

read -p "Enter lab assignment # (i.e 3): " lab
while [ -z "$lab"] do
    read -p "Enter lab assignment # (i.e 3): " lab
done

echo -e "${yellow}Default values listed in ${green}${bold}green${yellow}${bold}."
echo
echo -e "${green}${bold}Leave entry empty for defaults${RESET}"

read -p "$(echo -e "($green$default_dir$RESET) Enter new root directory: ")" curr_dir

#Check if curr_dir is empty
if [ -z "$curr_dir"] ; then
    curr_dir = $default_dir
fi

read -n1 -p "Enter # of lab questions (): " q_num
read -p "Enter root filename. Leave empty for default ($root_name): " root_name
read -n1 -p "() Include 'using namespace std' in template files? (Y/N): " std

#Check if folders already exist
if [ -d $curr_dir"/Lab$"lab ] ; then
    echo -e "${yellow}CAUTION: Setup already done.${RESET}"
    read -n1 -p "Would you like to rebuild? (Y/N):" choice
fi;

echo


#Create new folder structure
for i in `seq 1 6`; do
    mkdir $i
            
    case $std in
    "Y"|"y")
        cp "resource/template_std.cpp" $i/$root$i.cpp        
        ;;
    *)
        cp "resource/template.cpp" $i/$root$i.cpp
        ;;

    esac
done

#Move existing files if desired
echo "Done!";