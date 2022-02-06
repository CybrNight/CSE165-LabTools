#include <lab_gen.h>
#include <stdio.h>
#include <stdlib.h>

#include <cstdlib>
#include <iostream>
#include <string>


void mainMenu();
void printMenu();
void printCredits();
void buildLab(Lab* lab);

int main() {
    mainMenu();
}

void mainMenu(){
    int choice;

    printMenu();
    std::cin >> choice;
    std::system("clear");

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

    std::cout << "Generate folder structure with the following format:\n";
    std::cout << "Lab" << lab->labNum
              << "/\n"
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

    do {
        std::cout << "Continue with optimized defaults? (Y/N): ";
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

    // Move onto prep for folder creation
    do {
        std::cout << "\nPrint filesystem preview? (Y/N): ";
        std::cin >> choice;
        choice = std::tolower(choice);
    } while (choice != 'y' && choice != 'n');

    if (choice == 'y') {
        std::cout << "\n";
        lab->printFSLayout();
        std::cout << "\n";
    }

    // Print out plan for program for user to agree
    lab->dirPath += "Lab" + std::to_string(lab->labNum);

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