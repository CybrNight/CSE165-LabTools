#ifndef LAB_GEN
#define LAB_GEN

#include <string>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

class Lab {
    
    std::string labNum;
    int qNum;

    bool usePrefix;
    bool useTemplate;

    std::string prefix; //C++ file prefix
    fs::path pDir; //Parent directory of lab folder
    fs::path fullPath; //Dirpath is controlled by lab num and p dir
    fs::path tPath; //Template C++ file that will be used for creation

    public:
        Lab();
        Lab(std::string labNum, int qNum);

        void printDetails(); //Print all details
        bool destExists(); //Checks if lab's location is taken

        void setLabNum(std::string labNum);
        void setQNum(int labNum);
        void setPDir(std::string pDir); //Set parent directory and update full path
        void setPrefix(std::string prefix);
        void updateFullPath(); //Builds final path pDir+labNum and saves to dirPath
        void setTemplate(std::string tPath);

        std::string getLabNum();
        std::string getPrefix();

        int getQNum();
        fs::path getPDir();
        fs::path getFullPath();
        fs::path getTemplate();

        bool getUsePrefix();
        bool getUseTemplate();
};

#endif