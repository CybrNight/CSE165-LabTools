#ifndef LAB_GEN
#define LAB_GEN

#include <string>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

class Lab {
    
    int labNum;
    int qNum;

    std::string prefix; //C++ file prefix
    fs::path pDir; //Parent directory of lab folder
    fs::path fullPath; //Dirpath is controlled by lab num and p dir
    fs::path tPath; //Template C++ file that will be used for creation

    public:
        Lab();
        void printDetails(); //Print all details
        void printFSLayout(); //Print filesystem layout
        int generateFolders(bool useTemplate); //Generates all folders for lab
        bool isDestEmpty(); //Checks if lab's location is taken

        void setLabNum(int labNum);
        void setQNum(int labNum);
        void setPDir(std::string pDir); //Set parent directory and update full path
        void updateFullPath(); //Builds final path pDir+labNum and saves to dirPath
        void setTemplate(std::string tPath);

        int getLabNum();
        int getQNum();
        fs::path getPDir();
        fs::path getFullPath();
        fs::path getTemplate();
};

#endif