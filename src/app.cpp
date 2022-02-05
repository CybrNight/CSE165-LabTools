#include <lab_gen.h>
#include <stdio.h>
#include <stdlib.h>

#include <cstdlib>
#include <iostream>
#include <string>


void mainMenu();
void printMenu();
void printCredits();

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

void printMenu(){
    std::cout << "CSE165-LabTools\n\n";
    std::cout << "1. Lab folder generator\n";
    std::cout << "2. Lab grading\n";
    std::cout << "3. GitHub\n";
    std::cout << "4. Credits\n";
    std::cout << "5. Quit\n";
}