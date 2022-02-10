#include <lab.h>
#include <algorithm>

namespace fs = std::filesystem;

//Lab struct constructor
Lab::Lab() {
    prefix = "N/A";
    usePrefix = false;
    useTemplate = true;
    setLabNum(1);
    setPDir(fs::current_path().u8string());
    tPath = fs::current_path().u8string() + "/res/t.cpp";

    if (!fs::exists(tPath)){
        tPath = "N/A";
        useTemplate = false;
    }

    if (!usePrefix){
        prefix = "N/A";
    }

    qNum = 1;
}

Lab::Lab(int labNum, int qNum){
    prefix = "N/A";
    usePrefix = false;
    useTemplate = false;
    setLabNum(labNum);
    this->qNum = qNum;
    setPDir(fs::current_path().u8string());
    tPath = fs::current_path().u8string() + "/res/t.cpp";

    if (!fs::exists(tPath)) {
        tPath = "N/A";
    }

    if (!usePrefix) {
        prefix = "N/A";
    }
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
    std::cout << "Lab" << labNum << " Settings:\n";
    std::cout << "Lab number:[" << labNum << "]\n";
    std::cout << "Number of questions:[" << qNum << "]\n";
    std::cout << "Desination directory:[" << pDir.u8string() << "/Lab" << labNum << "]\n\n";

    std::cout << "Use file prefix:[" << std::boolalpha << usePrefix << "]\n";
    std::cout << "File prefix:[" << prefix << "]\n\n";

    std::cout << "Use template file:[" << std::boolalpha << useTemplate << "]\n";
    std::cout << "Template file:[" << tPath.u8string() << "]\n";
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

bool Lab::destExists(){   
    return fs::exists(fullPath);
}

int Lab::generateFolders() {
    std::string qPath;
    
    fs::create_directory(fullPath);

    if (tPath.compare("N/A") == 0) {
        std::cout << "NO TEMPLATE FILE SPECIFIED! SKIPPING STEP!\n";
    }

    for (int i = 1; i <= qNum; i++) {
        qPath = fullPath.u8string() + "/" + std::to_string(i);
        fs::create_directory(qPath);


        //Add prefix to qPath if required
        if (usePrefix){
            qPath += "/" + prefix + std::to_string(i) + ".cpp";
        }else{
            qPath += "/" + std::to_string(i) + ".cpp";
        }

        if (useTemplate && tPath.compare("N/A") != 0){
            fs::copy(tPath, qPath);
        }
    }

    return 1;
}

fs::path Lab::getFullPath() {
    return fullPath;
}