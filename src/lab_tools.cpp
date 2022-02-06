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
void cleanCin();

namespace fs = std::filesystem;

int main() {
    mainMenu();
}

void mainMenu(){
    int choice;

    printMenu();
    std::cin >> choice;

#ifdef _WIN32
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
    int labNum;
    int qNum;
    std::string templatePath;

    std::cout << "---Lab Folder Generator---\n\n";

#ifdef _WIN32
    std::cout << "Generate folder structure with the following format:\n";
    std::cout << "Lab#"
              << "/\n"
                 "|-- 1/\n"
                 "|-- 2/\n"
                 "|-- 3/\n"
                 "|-- 4/\n\n";
#else
    std::cout << "Generate folder structure with the following format:\n";
    std::cout << "Lab#"
              << "/\n"
                 "├─ 1/\n"
                 "├─ 2/\n"
                 "├─ 3/\n"
                 "├─ 4/\n\n";
#endif

    // Initialize lab object
    std::cout << "Enter lab number: ";
    std::cin >> labNum;

    //Keep asking until valid option given
    while (std::cin.fail()){
        std::cout << "Enter lab number: ";
        cleanCin();
        std::cin >> labNum;
    }

    lab->setLabNum(labNum);

    std::string delOpt;
    if (lab->isDestEmpty()) {
        std::cout << "Destination path (" << lab->getFullPath()
                  << ") already exists.\n";
        std::cout << "I)gnore\nD)elete\nA)bort\n";
        std::cin >> delOpt;

        while (std::cin.fail()) {
            std::cout << "Choose valid option!\n";
            cleanCin();
            std::cin >> delOpt;
        }

        transform(delOpt.begin(), delOpt.end(), delOpt.begin(), ::tolower);

        if (delOpt.compare("d") || delOpt.compare("delete")) {
            std::uintmax_t n = fs::remove_all(lab->getFullPath());
            std::cout << "Deleted Lab" << labNum << " folder + " << n
                      << " files.\n\n";
        } else {
            exit(EXIT_SUCCESS);
        }
    }

    std::cout << "Enter question count: ";

    //Keep asking until valid option given
    while (std::cin.fail()) {
        std::cout << "Enter question count: ";
        cleanCin();
        std::cin >> labNum;
    }

    std::cin >> qNum;

    std::cout << "\n";

    //Check if folder already exists

    lab->setQNum(qNum);

    lab->printDetails();

    char defOpt;
    do {
        std::cout << "\nContinue with optimized defaults? (Y/N): ";
        std::cin >> defOpt;
        defOpt = std::tolower(defOpt);
    } while (defOpt != 'y' && defOpt != 'n');

    if (defOpt == 'n') {
        std::cout << "Enter C++ file prefix: ";
        std::cin >> labNum;

        std::cout << "Enter lab parent directory: ";
        std::cin >> qNum;

        std::cout << "Enter path to template file: ";
        std::cin >> templatePath;
    }

    // Print out plan for program for user to agree
    char t;
    do {
        std::cout
            << "Would you like to copy the template C++ file to all folders? ("
            << lab->getTemplate().u8string() << ") (Y/N): ";
        std::cin >> t;
        t = std::tolower(t);
    } while (t != 'y' && t != 'n');

    lab->generateFolders(t == 'y');
}

void printMenu(){
    std::cout << "CSE165-LabTools\n\n";
    std::cout << "1. Lab folder generator\n";
    std::cout << "2. Lab grading\n";
    std::cout << "3. GitHub\n";
    std::cout << "4. Credits\n";
    std::cout << "5. Quit\n";
}

void cleanCin(){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}