#include <lab_gen.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <iostream>
#include <string>

Lab::Lab() {
    labNum = 1;
    qNum = 1;
    fiPrefix = "";
    dir = "";
    tmplate = "res/t.cpp";
}

void Lab::printDetails() {
    std::cout << "Lab number:[" << labNum << "]\n";
    std::cout << "Number of questions:[" << qNum << "]\n";
    std::cout << "File prefix:[" << fiPrefix << "]\n";
    std::cout << "Directory:[" << dir << "]\n";
    std::cout << "Template file:[" << tmplate << "]\n";
}

void Lab::printFSLayout(){
    std::cout << "Lab" << labNum << "/\n";
    int max = 10;

    if (qNum < 10){
        max = qNum;
    }

    for (int i = 1; i <= max; i++) {
        std::cout << "├─ " << fiPrefix << i << " /\n";
    }
    
    if (qNum > 10)
        std::cout << qNum-max << " more rows left.\n";
}

void buildLab(Lab* lab) {
    char choice;

    std::cout << "---Lab Folder Generator---\n\n";

    std::cout << "Generate folder structure with the following format:\n";
    std::cout << "Lab" << lab->labNum << "/\n"
    "├─ 1 /\n"
    "├─ 2 /\n"
    "├─ 3 /\n"
    "├─ 4 /\n\n";

    // Initialize lab object
    std::cout << "Enter lab number: ";
    std::cin >> lab->labNum;

    std::cout << "Enter question count: ";
    std::cin >> lab->qNum;

    std::cout << "\n";
    lab->printDetails();
    std::cout << "\n";
    
    do{
        std::cout << "Continue with optimized defaults? (Y/N): ";
        std::cin >> choice;
        choice = std::tolower(choice);
    }while (choice != 'y' && choice != 'n');

    if (choice == 'y'){
        //Change settings!
    }

    //Move onto prep for folder creation
    do {
        std::cout << "\nPrint filesystem preview? (Y/N): ";
        std::cin >> choice;
        choice = std::tolower(choice);
    } while (choice != 'y' && choice != 'n');

    if (choice == 'y'){
        std::cout << "\n";
        lab->printFSLayout();
        std::cout << "\n";
    }
}


void generateFolders(){
    //std::mkdir();
}

void checkEmpty(std::string path){

}
