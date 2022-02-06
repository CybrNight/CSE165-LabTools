#include <lab_gen.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <filesystem>

#include <iostream>
#include <string>

namespace fs = std::filesystem;

Lab::Lab() {
    labNum = 1;
    qNum = 1;
    prefix = "";
    pDir = fs::current_path();
    dirPath = "";
    tmplate = fs::current_path();
    tmplate += "/res/t.cpp";
}

void Lab::printDetails() {
    std::cout << "Lab number:[" << labNum << "]\n";
    std::cout << "Number of questions:[" << qNum << "]\n";
    std::cout << "File prefix:[" << prefix << "]\n";
    std::cout << "Directory:[" << pDir << "]\n";
    std::cout << "Template file:[" << tmplate << "]\n";
}

void Lab::printFSLayout(){
    std::cout << "Lab" << labNum << "/\n";
    int max = 10;

    if (qNum < 10){
        max = qNum;
    }

    for (int i = 1; i <= max; i++) {
        std::cout << "├─ " << prefix << i << " /\n";
    }
    
    if (qNum > 10)
        std::cout << qNum-max << " more rows left.\n";
}

bool Lab::isDestEmpty(){   
    return fs::exists(dirPath);
}

int Lab::generateFolders() {
    char choice;

    do{
        std::cout << "Would you like to copy the template C++ file to all folders? ("
                  << tmplate << ") (Y/N): ";
        std::cin >> choice;
    }while (choice != 'y' && choice != 'n');

    fs::create_directory(dirPath);

    for (int i = 1; i <= qNum; i++){
        std::string qPath = dirPath + "/" + prefix + std::to_string(i);
        fs::create_directory(qPath.c_str());
        if (choice == 'y'){
            fs::copy(tmplate, qPath);
        }
    }

    return 1;
}
