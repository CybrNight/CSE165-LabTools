#!/bin/bash

#Define settings vars
default_dir=($PWD)
curr_dir=$default_dir
lab=0
q_num=6
file_root="q_"
folder_root="Q_"
std="NO"
dir=""

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

main(){
    echo
    read -p "Enter lab assignment #: " lab
    while [ -z "$lab" ] 
    do
        read -p "Enter lab assignment #: " lab
    done

    #Check that location is free
    dir=$curr_dir/Lab$lab
    if [ -d $dir ] ; then
        echo "${yellow}CAUTION: Folder $dir already exists."
        read -n1 -p "${white}Would you like to delete it? (Y/N):" -i N delete

        case $delete in
        Y|y)   
            echo
            echo
            echo "${red}WARNING: FILES WILL BE PERMANATELY DELETED!"
            read -n1 -p "${white}Proceed with operation? (Y/N): " -i N delete2
            echo
            case $delete2 in
            Y|y)
                rm -r $dir
                echo "${yellow}FILES DELETED!$white"
                echo
                ;;
            esac
            ;;
        esac
    else
        mkdir $dir
    fi;

    read -p "Enter number of lab questions: " q_num
    while [ -z "$q_num" ] 
    do
        read -p "Enter number of lab questions: " q_num
    done

    print_settings
    echo -e "${white}"
    read -n1 -p "$(echo -e "Proceed with following settings? (Y/N): ")" -i N settings
    echo

    case $settings in
    N|n)
        change_settings
        print_settings
        ;;
    esac
    dir=$curr_dir/Lab$lab/$folder_root

    create_folders
}

print_fs_preview(){
    echo "${cyan}File system preview:"
    
}

print_settings(){
    echo
    echo "${cyan}Current Settings:"
    echo "${yellow}Lab assignment #: $white[$green$lab$white]"
    echo "${yellow}Number of lab questions: $white[$green$q_num$white]"
    echo "${yellow}Question folder root name: $white[$green$folder_root$white]"
    echo "${yellow}C++ file root name: $white[$green$file_root$white]"
    echo "${yellow}Lab folder parent directory: $white[$green${curr_dir}$white]"
    echo "${yellow}Include 'using namespace std' in template files: $white[${green}${std}$white]"
}

print_task_list(){
    echo "${red}WARNING!: PROGRAM WILL PERFORM THE FOLLOWING TASKS"
}

change_settings(){
    echo "${green}Leave entry empty for current value"

    read -p "$(echo -e "${white}Enter lab assignment #: ")" -i $lab lab
    read -p "Number of lab questions: " q_num
    read -p "$(echo -e "($green$curr_dir) Lab folder parent directory: ")" -i $curr_dir curr_dir
    read -p "Root filename: " -i $file_root file_root
    read -n1 -p "$(echo -e "Include 'using namespace std' in template files? (Y/N): ")" -i $std std

    #Check if folders already exist
    if [ -d $curr_dir/Lab$lab ] ; then
        echo "${yellow}CAUTION: Setup already done."
        read -n1 -p "Would you like to rebuild? (Y/N):" choice
    fi;
}

create_folders(){
    #Create new folder structure
    for i in `seq 1 $q_num`; do
        dir_f=$dir$i
        file_f=$file_root$i

        mkdir $dir_f              
        case $std in
        "Y"|"y")
            cp "resource/template_std.cpp" $dir_f/$file_f.cpp        
            ;;
        *)
            cp "resource/template.cpp" $dir_f/$file_f.cpp
            ;;

        esac
    done

    #Move existing files if desired
    echo "Done!";   
}
clear
echo "${green}${bold}This script will setup the folder structure for lab assigments for CSE165."
echo "$yellow"
echo "By using this, you take responsibility for any dataloss caused from the usage of this software."
echo "Any modifications to this script will not be supported. Have a nice day."
echo
echo "CSE165-LabTools (C) 2022 Nathan Estrada UC Merced CSE165"
echo "$white"
read -p "-Press enter to continue-"
main