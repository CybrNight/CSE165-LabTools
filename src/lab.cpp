#include <lab.h>

#include <algorithm>
#include <fstream>

namespace fs = std::filesystem;

// Lab struct constructor
Lab::Lab() {
    prefix = "N/A";
    usePrefix = false;
    useTemplate = false;
    setLabNum("1");
    qNum = 6;
    setPDir(fs::current_path().u8string());
    tPath = "N/A";

    if (!usePrefix) {
        prefix = "N/A";
    }
}

Lab::Lab(std::string labNum, int qNum) {
    prefix = "N/A";
    usePrefix = false;
    useTemplate = false;
    setLabNum(labNum);
    this->qNum = qNum;
    setPDir(fs::current_path().u8string());
    tPath = "N/A";

    if (!usePrefix) {
        prefix = "N/A";
    }
}

void Lab::updateFullPath() { fullPath = pDir.u8string() + "/Lab" + labNum; }

void Lab::printDetails() {
    std::cout << "Lab" << labNum << " Settings:\n";
    std::cout << "Lab number:[" << labNum << "]\n";
    std::cout << "Number of questions:[" << qNum << "]\n";
    std::cout << "Desination directory:[" << pDir.u8string() << "/Lab" << labNum
              << "]\n\n";

    std::cout << "Use file prefix:[" << std::boolalpha << usePrefix << "]\n";
    std::cout << "File prefix:[" << prefix << "]\n\n";

    std::cout << "Use template file:[" << std::boolalpha << useTemplate
              << "]\n";
    std::cout << "Template file:[" << tPath.u8string() << "]\n";
}

bool Lab::destExists() { return fs::exists(fullPath); }

std::string Lab::getLabNum(){
    return labNum;
}

int Lab::getQNum(){
    return qNum;
}

bool Lab::getUseTemplate() { return useTemplate; }

bool Lab::getUsePrefix() { return usePrefix; }

fs::path Lab::getPDir() { return pDir; }

std::string Lab::getPrefix() { return prefix; }

fs::path Lab::getFullPath() { return fullPath; }

fs::path Lab::getTemplate() { return tPath; }

void Lab::setLabNum(std::string labNum) {
    this->labNum = labNum;
    updateFullPath();
}

void Lab::setPDir(std::string pDir) {
    this->pDir = pDir;
    updateFullPath();
}

void Lab::setQNum(int qNum) { this->qNum = qNum; }

void Lab::setTemplate(std::string tPath) {
    this->tPath = tPath;

    if (!fs::exists(tPath)) {
        tPath = "N/A";
    }
}

void Lab::setPrefix(std::string prefix) { this->prefix = prefix; }
