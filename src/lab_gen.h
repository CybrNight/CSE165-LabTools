#ifndef LAB_GEN
#define LAB_GEN

#include <string>
#include <iostream>

struct Lab {
    int labNum;
    int qNum;
    std::string prefix;
    std::string pDir;
    std::string dirPath;
    std::string tmplate;

    Lab();
    void printDetails();
    void printFSLayout();
    int generateFolders();
    bool isDestEmpty();
};

#endif