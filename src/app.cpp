#include <lab_gen.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <filesystem>
#include <ctype.h>


void mainMenu();
void printMenu();
void printCredits();
void buildLab(Lab* lab);

namespace fs = std::filesystem;

int main() {
    mainMenu();
}

void mainMenu(){
    int choice;

    printMenu();
    std::cin >> choice;

#ifdef OS_WINDOWS
    std::system("cls");
#else
    std::system("clear");
#endif


    Lab* lab;

    switch (choice){
        case 1:
            lab = new Lab();
            buildLab(lab);
            break;
        default:
            exit (EXIT_SUCCESS);
    }
}

void buildLab(Lab* lab) {
    char choice;

    std::cout << "---Lab Folder Generator---\n\n";

#ifndef _WIN32
    std::cout << "Generate folder structure with the following format:\n";
    std::cout << "Lab" << lab->labNum
              << "/\n"
                 "|-- 1/\n"
                 "|-- 2/\n"
                 "|-- 3/\n"
                 "|-- 4/\n\n";
#else
    std::cout << "Generate folder structure with the following format:\n";
    std::cout << "Lab" << lab->labNum
              << "/\n"
                 "├─ 1/\n"
                 "├─ 2/\n"
                 "├─ 3/\n"
                 "├─ 4/\n\n";
#endif

    // Initialize lab object
    std::cout << "Enter lab number: ";
    std::cin >> lab->labNum;

    std::cout << "Enter question count: ";
    std::cin >> lab->qNum;

    std::cout << "\n";
    std::cout << "\n";

    lab->dirPath += "Lab" + std::to_string(lab->labNum);
    std::string choice2;

    //Check if folder already exists
    if (lab->isDestEmpty()){
        std::cout << "Destination path (" << lab->dirPath << ") already exists.\n";
        std::cout << "I)gnore\nD)elete\nA)bort\n";
        std::cin >> choice2;
        std::string choice2 = "";
        transform(choice2.begin(), choice2.end(), choice2.begin(), ::tolower);

        if (choice2.compare("d") || choice2.compare("delete")){
            std::uintmax_t n = fs::remove_all(lab->dirPath);
            std::cout << "Deleted Lab" << lab->labNum << " folder + " << n << " files.\n\n";
        }else{
            exit(EXIT_SUCCESS);
        }
    }

    lab->printDetails();

    do {
        std::cout << "\nContinue with optimized defaults? (Y/N): ";
        std::cin >> choice;
        choice = std::tolower(choice);
    } while (choice != 'y' && choice != 'n');

    if (choice == 'n') {
        std::cout << "Enter C++ file prefix: ";
        std::cin >> lab->labNum;

        std::cout << "Enter lab parent directory: ";
        std::cin >> lab->qNum;

        std::cout << "Enter path to template file: ";
        std::cin >> lab->qNum;
    }

    // Print out plan for program for user to agree
    lab->generateFolders();
}

void printMenu(){
    std::cout << "CSE165-LabTools\n\n";
    std::cout << "1. Lab folder generator\n";
    std::cout << "2. Lab grading\n";
    std::cout << "3. GitHub\n";
    std::cout << "4. Credits\n";
    std::cout << "5. Quit\n";
}