#include <lab.h>
#include <term_util.h>
#include <algorithm>
#include <cstdlib>

void mainMenu();
void printMenu();
void printCredits();
void buildLab(Lab* lab);
void cleanCin();

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
    //If no arguments are passed show main menu for default behvaior
    if (argc < 2){
        mainMenu();
    }else if (argc >= 3){ //If lab name is given then generate default structure without templates
        int labNum = atoi(argv[1]);
        int qNum = atoi(argv[2]);
        if (labNum != 0 && qNum != 0){
            Lab* lab = new Lab(labNum, qNum);
            
            if (!lab->destExists())
                lab->generateFolders();
        }
    }
}

void mainMenu(){
    int choice;

    printMenu();
    std::cin >> choice;

    clearConsole();

    Lab* lab;

    switch (choice){
        case 1:
            lab = new Lab();
            buildLab(lab);
            break;
        default:
            exit (EXIT_SUCCESS);
    }

    delete lab;
}

void buildLab(Lab* lab) {
    int labNum;
    int qNum;
    std::string templatePath;
    std::string prefix;
    std::string pDir;

    std::cout << "---Lab Folder Generator---\n\n";

    std::string intro =
        "Generates lab project folder with the following structure\n";

    std::cout << intro;
    std::cout << "Lab#"
              << "/\n"
                 "├─ 1/\n"
                 "├─ 2/\n"
                 "├─ 3/\n"
                 "├─ 4/\n";

    std::cout << "..." << "\n\n";

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

    //Check if destination exists, if it does ask to delete it
    std::string delOpt;
    char confirmDel;
    if (lab->destExists()) {
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
            std::cout << "\nWARNING!!! DIRECTORY " << lab->getFullPath() << " "
            "WILL BE PERMANATELY DELETED!\n Are you sure? (Y/N): ";
            std::cin >> confirmDel;

            while (std::cin.fail()){
                std::cout << "Choose valid option!\n";
                cleanCin();
                std::cin >> confirmDel;
            }

            confirmDel = std::tolower(confirmDel);

            if (confirmDel == 'y'){
                std::uintmax_t n = fs::remove_all(lab->getFullPath());
                std::cout << "Deleted directory " << lab->getFullPath() << " folder containing " << n
                        << " files.\n\n";
            }
        } else {
            exit(EXIT_SUCCESS);
        }
    }

    std::cout << "Enter question count: ";
    std::cin >> qNum;

    //Keep asking until valid option given
    while (std::cin.fail()) {
        std::cout << "Enter question count: ";
        cleanCin();
        std::cin >> qNum;
    }
    lab->setQNum(qNum);
    std::cout << "\n";
    lab->printDetails();
    
    char defOpt;
    std::cout << "\nContinue with optimized defaults? (Y/N): ";
    std::cin >> defOpt;
    do { 
        defOpt = std::tolower(defOpt);
    } while (defOpt != 'y' && defOpt != 'n');

    if (defOpt == 'n') {
        std::cout << "Enter C++ file prefix: ";
        std::cin >> prefix;

        while (std::cin.fail()) {
            std::cout << "Enter C++ file prefix: ";
            cleanCin();
            std::cin >> prefix;
        }

        lab->setPrefix(prefix);
        std::cout << "\n";

        std::cout << "Enter path to lab parent directory: ";
        std::cin >> pDir;

        while (std::cin.fail()) {
            std::cout << "Enter path to lab parent directory: ";
            cleanCin();
            std::cin >> pDir;
        }
        lab->setPDir(pDir);
        std::cout << "\n";

        std::cout << "Enter path to template file including C++ file: ";
        std::cin >> templatePath;

        while (std::cin.fail()) {
            std::cout << "Enter path to template file including C++ file: ";
            cleanCin();
            std::cin >> templatePath;
        }
        lab->setTemplate(templatePath);
        std::cout << "\n";
    }

    //TODO: Print out plan for program for user to agree
    lab->printFSLayout();

    char choice;
    std::cout << "Will create the above file structure at (" << lab->getPDir()
            << ")\n";
    std::cout << "Continue with operation? (Y/N): ";
    std::cin >> choice;

    choice = std::tolower(choice);

    if (choice != 'y'){
        std::cout << "Operation cancelled";
        exit(EXIT_SUCCESS);
    }

    try {
        lab->generateFolders();
        std::cout << "Files created successfully" << "\n";
    }catch (int e){
        std::cout << "Failed to create lab files. Returned " << e << "\n";
    }
}

void printMenu(){
    std::cout << "CSE165-LabTools\n\n";
    std::cout << "1. Lab folder generator\n";
    std::cout << "2. Lab grading (not implemented) \n";
    std::cout << "3. Credits (not implemented) \n";
    std::cout << "4. Quit\n";
}