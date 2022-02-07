#include <lab.h>
#include <term_util.h>
#include <algorithm>


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
}

void buildLab(Lab* lab) {
    int labNum;
    int qNum;
    std::string templatePath;

    std::cout << "---Lab Folder Generator---\n\n";

    std::string intro =
        "Generates lab project folder with the following structure\n";

#if defined(WIN32) || defined(_WIN32) || \
    defined(__WIN32) && !defined(__CYGWIN__)
    std::cout << welcome;
    std::cout << "Lab#" << "/\n"
                 "|-- 1/\n"
                 "|-- 2/\n"
                 "|-- 3/\n"
                 "|-- 4/\n";
#else
        std::cout
        << intro;
    std::cout << "Lab#"
              << "/\n"
                 "├─ 1/\n"
                 "├─ 2/\n"
                 "├─ 3/\n"
                 "├─ 4/\n";

    std::cout << "..." << "\n\n";
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

    //Check if destination exists, if it does ask to delete it
    std::string delOpt;
    char confirmDel;
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

void cleanCin(){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}