#include <lab_gen.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <filesystem>

#include <iostream>
#include <string>

namespace fs = std::filesystem;

//Lab struct constructor
Lab::Lab() {
    setLabNum(1);
    setPDir(fs::current_path().u8string());
    tPath = fs::current_path().u8string() + "/res/t.cpp";
    qNum = 1;
    prefix = "";
}

fs::path Lab::getTemplate(){
    return tPath;
}

void Lab::setLabNum(int labNum){
    this->labNum = labNum;
    updateFullPath();
}

void Lab::setPDir(std::string pDir){
    this->pDir = pDir;
    updateFullPath();
}

void Lab::setQNum(int qNum){
    this->qNum = qNum;
}

void Lab::setTemplate(std::string tPath){
    this->tPath = tPath;
}

void Lab::updateFullPath(){
    fullPath = pDir.u8string() + "/Lab" + std::to_string(labNum);
}

void Lab::printDetails() {

    std::cout << "Lab number:[" << labNum << "]\n";
    std::cout << "Number of questions:[" << qNum << "]\n";
    std::cout << "File prefix:[" << prefix << "]\n";
    std::cout << "Directory:[" << pDir.u8string() << "/Lab" << labNum << "]\n";
    std::cout << "Template file:[" << tPath << "]\n";
}

void Lab::printFSLayout(){
    std::cout << "Lab" << labNum << "/\n";
    int max = 10;

    if (qNum < 10){
        max = qNum;
    }
    
#ifdef _WIN32
    for (int i = 1; i <= max; i++) {
        std::cout << "|--" << prefix << i << " /\n";
    }
#else
    for (int i = 1; i <= max; i++) {
        std::cout << "├─" << prefix << i << " /\n";
    }
#endif
    
    if (qNum > 10)
        std::cout << qNum-max << " more rows left.\n";
}

bool Lab::isDestEmpty(){   
    return fs::exists(fullPath);
}

int Lab::generateFolders(bool useTmplate) {
    char choice;

    fs::create_directory(fullPath);

    for (int i = 1; i <= qNum; i++){
        std::string qPath = fullPath.u8string() + "/" + prefix + std::to_string(i);
        fs::create_directory(qPath);
        if (useTmplate){
            fs::copy(tPath, qPath+"/"+prefix+std::to_string(i)+".cpp");
        }
    }

    return 1;
}

fs::path Lab::getFullPath() {
    return fullPath;
}