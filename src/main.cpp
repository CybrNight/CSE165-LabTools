#include <lab.h>
#include <term_util.h>
#include <files.h>
#include <algorithm>
#include <cstdlib>

void mainMenu();
void printMenu();
void printCredits();
void buildLab(Lab lab);

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
    //If no arguments are passed show main menu for default behvaior
    if (argc < 2){
        mainMenu();
    }else if (argc >= 3){ //If lab name is given then generate default structure without templates
        std::string labNum = argv[1];
        int qNum = atoi(argv[2]);
        if (qNum != 0){
            Lab lab(labNum, qNum);
            
            if (!lab.destExists())
                files::generateFolders(lab);
        }
    }
}

void mainMenu(){
    int choice;

    printMenu();
    std::cin >> choice;

    term::clearConsole();

    Lab lab;

    switch (choice){
        case 1:
            buildLab(lab);
            break;
        default:
            exit (EXIT_SUCCESS);
    }
}

void buildLab(Lab lab) {
    //Define vars to enter into lab object
    std::string labNum;
    int qNum;
    std::string tPath;
    std::string prefix;
    std::string pDir;

    std::cout << "---Lab Folder Generator---\n\n";

    std::string intro =
        "Generates lab project folder with the following structure\n";

    //Print example file structure
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
        term::cleanCin();
        std::cin >> labNum;
    }

    lab.setLabNum(labNum);

    //Check if destination exists, if it does ask to delete it
    std::string delOpt;
    char confirmDel;
    if (lab.destExists()) {
        //Ask if user action for folder
        std::cout << "Destination path (" << lab.getFullPath()
                  << ") already exists.\n";
        std::cout << "I)gnore\nD)elete\nA)bort\n";
        std::cin >> delOpt;

        //Keep asking til valid entry is entered
        while (std::cin.fail()) {
            std::cout << "Choose valid option!\n";
            term::cleanCin();
            std::cin >> delOpt;
        }

        //Convert delOpt to lowercase
        std::transform(delOpt.begin(), delOpt.end(), delOpt.begin(), ::tolower);

        //If delete option is selected confirm with user that they actually
        //want to delete it
        if (delOpt.compare("d") || delOpt.compare("delete")) {
            std::cout << "\nWARNING!!! DIRECTORY " << lab.getFullPath() << " "
            "WILL BE PERMANATELY DELETED!\n Are you sure? (Y/N): ";
            std::cin >> confirmDel;
            confirmDel = std::tolower(confirmDel);

            //Keep asking till vaild option is entered
            while (std::cin.fail() && confirmDel != 'n' && confirmDel != 'y'){
                std::cout << "Choose valid option!\n";
                term::cleanCin();
                std::cin >> confirmDel;
                confirmDel = std::tolower(confirmDel);
            }

            //If yes then delete directory
            if (confirmDel == 'y'){
                std::uintmax_t n = fs::remove_all(lab.getFullPath());
                std::cout << "Deleted directory " << lab.getFullPath() << " folder containing " << n
                        << " files.\n\n";
            }
        } else if (delOpt.compare("a") || delOpt.compare("abort")) {
            exit(EXIT_SUCCESS);
        }
    }

    std::cout << "Enter question count: ";
    std::cin >> qNum;

    //Keep asking until valid option given
    while (std::cin.fail()) {
        std::cout << "Enter question count: ";
        term::cleanCin();
        std::cin >> qNum;
    }
    lab.setQNum(qNum);
    std::cout << "\n";
    lab.printDetails();
    
    //Ask user if they want to continue with defaults
    char defOpt;
    std::cout << "\nContinue with optimized defaults? (Y/N): ";
    std::cin >> defOpt;
    defOpt = std::tolower(defOpt);

    //Keep asking until valid option entered
    while (defOpt != 'n' && defOpt != 'y'){
        std::cout << "Continue with optimized defaults? (Y/N): ";
        term::cleanCin();
        std::cin >> defOpt;
        defOpt = std::tolower(defOpt);
    }

    //If no then ask user to enter new settings
    if (defOpt == 'n') {
        std::cout << "Enter C++ file prefix: ";
        std::cin >> prefix;

        //Keep asking until valid string entry
        while (std::cin.fail()) {
            std::cout << "Enter C++ file prefix: ";
            term::cleanCin();
            std::cin >> prefix;
        }

        lab.setPrefix(prefix);
        std::cout << "\n";

        std::cout << "Enter path to lab parent directory ('.' for current directory): ";
        std::cin >> pDir;

        // Keep asking until valid string entry
        while (std::cin.fail() && !fs::exists(pDir)) {
            if (!fs::exists(pDir)) {
                std::cout << "Entered directory doesn't exist!\n";
            }

            std::cout << "Enter path to lab parent directory ('.' for "
                         "current directory): ";
            term::cleanCin();
            std::cin >> pDir;
        }
        lab.setPDir(pDir);
        std::cout << "\n";

        // Keep asking until valid string entry
        std::cout << "Enter full path to C++ template file: ";
        std::cin >> tPath;

        while (std::cin.fail() && !fs::exists(tPath)) {
            if (!fs::exists(tPath)){
                std::cout << "Entered template file doesn't exist!\n";
            }

            std::cout << "Enter full path to C++ template file: ";
            term::cleanCin();
            std::cin >> tPath;
        }
        lab.setTemplate(tPath);
        std::cout << "\n";
    }

    //TODO: Print out plan for program for user to agree
    files::printFSLayout(lab);

    char choice;
    std::cout << "Will create the above file structure at (" << lab.getPDir()
            << ")\n";
    std::cout << "Continue with operation? (Y/N): ";
    std::cin >> choice;

    //Keep asking until valid option is entered
    while (std::cin.fail()){
        std::cout << "Will create the above file structure at ("
                  << lab.getPDir() << ")\n";
        term::cleanCin();
        std::cin >> choice;
    }

    choice = std::tolower(choice);

    if (choice != 'y'){
        std::cout << "Operation cancelled";
        exit(EXIT_SUCCESS);
    }

    //Generate folders
    try {
        files::generateFolders(lab);
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