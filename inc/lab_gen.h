#ifndef LAB_GEN
#define LAB_GEN

#include <string>
#include <iostream>

struct Lab {
    int labNum;
    int qNum;
    std::string fiPrefix;
    std::string dir;
    std::string tmplate;

    Lab();
    void printDetails();
    void printFSLayout();
};

void buildLab(Lab* lab);
void checkEmpty(std::string path);

#endif