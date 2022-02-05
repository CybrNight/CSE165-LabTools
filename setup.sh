#!/bin/bash

#Define settings vars
default_dir=($PWD)
curr_dir=$default_dir
lab=-1
q_num=-1
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
    print_menu
    read -n1 -p "$white" menu_select
    case $menu_select in
    1)
        clear
        build_new_lab
        ;;
    2)
        #Do Update
        printf "This should do update"
        ;;
    3)
        clear
        print_credits
        clear
        main
        ;;
    4)
        clear
        exit 1
        ;;
    esac
}



print_credits(){
    printf  "${yellow}CSE165-LabTools (C) 2022 Nathan Estrada\n" 
    printf  "Automatically builds the folder structure for CSE165 labs\n\n"
    printf  "By using this, you take responsibility for any dataloss caused from the usage of this software.\n"
    printf  "Any modifications to this script will not be supported. Have a nice day.\n"
    read -p "${white}-Press enter to continue-"
}

print_menu(){
    printf "${purple}${bold}CSE165-LabTools\n\n"
    printf "1. Generate lab folders\n"
    printf "2. Update setup\n"
    printf "3. Credits\n"
    printf "4. Quit\n"
}

build_new_lab(){
    printf "${green}---Lab Folder Generator---\n\n"

    printf "${yellow}CAUTION:By default the new lab directory is created in the same directory as this script.\n"
    printf ".\n\n$white"

    #Get lab number
    read -p "Enter lab assignment #: " lab
    while [ $lab -le -1 ] 
    do
        read -N2 -p "Enter lab assignment #: " lab
    done

    #Check that location is free
    check_free

    #Get number of lab questions
    read -p "Enter number of lab questions: " q_num
    while [ -z "$q_num" ] 
    do
        read -p "Enter number of lab questions: " q_num
    done

    print_settings
    printf  "${white}"
    read -n1 -p "$(printf "Proceed with following settings? (Y/N): ")" -i N settings
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
    printf "${cyan}File system preview:"
    
}

print_settings(){
    printf "${cyan}Current Settings:\n"
    printf "${yellow}Lab assignment #: $white[$green$lab$white]\n"
    printf "${yellow}Number of lab questions: $white[$green$q_num$white]\n"
    printf "${yellow}Question folder root name: $white[$green$folder_root$white]\n"
    printf "${yellow}C++ file root name: $white[$green$file_root$white]\n"
    printf "${yellow}Lab folder parent directory: $white[$green${curr_dir}$white]\n"
    printf "${yellow}Include 'using namespace std' in template files: $white[${green}${std}$white]\n"
}

print_task_list(){
    printf "${red}WARNING!: PROGRAM WILL PERFORM THE FOLLOWING TASKS"
}

change_settings(){
    printf "${green}Leave entry empty for current value"

    read -p "$(printf -e "${white}Enter lab assignment #: ")" -i $lab lab
    read -p "Number of lab questions: " q_num
    read -p "$(printf -e "($green$curr_dir) Lab folder parent directory: ")" -i $curr_dir curr_dir
    read -p "Root filename: " -i $file_root file_root
    read -n1 -p "$(printf -e "Include 'using namespace std' in template files? (Y/N): ")" -i $std std
    echo

    #Check if folders already exist
    check_free
}

check_free(){
     dir=$curr_dir/Lab$lab
    if [ -d $dir ] ; then
        printf "${yellow}CAUTION: Folder $dir already exists.\n"
        read -n1 -p "${white}Would you like to delete it? (Y/N):" -i N delete
        echo

        case $delete in
        Y|y)   
            printf  "\n\n${red}WARNING: FILES WILL BE PERMANATELY DELETED!\n"
            read -n1 -p "${white}Proceed with operation? (Y/N): " -i N delete2
            echo
            case $delete2 in
            Y|y) 
                rm -r $dir #Delete lab directory
                printf  "${yellow}FILES DELETED!$white\n"
                ;;
            esac
            ;;
        esac
    else
        mkdir $dir #Make lab directory
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
    printf "Done!\n";   
}
clear
main