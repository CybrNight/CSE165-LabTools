#include <lab.h>
#include <algorithm>
#include <fstream>

namespace fs = std::filesystem;

//Lab struct constructor
Lab::Lab() {
    prefix = "N/A";
    usePrefix = false;
    useTemplate = false;
    setLabNum("1");
    qNum = 6;
    setPDir(fs::current_path().u8string());
    tPath = "N/A";

    if (!usePrefix){
        prefix = "N/A";
    }
}

Lab::Lab(std::string labNum, int qNum){
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

fs::path Lab::getTemplate(){
    return tPath;
}

void Lab::setLabNum(std::string labNum){
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

    if (!fs::exists(tPath)) {
        tPath = "N/A";
    }
}

void Lab::setPrefix(std::string prefix){
    this->prefix = prefix;
}

void Lab::updateFullPath(){
    fullPath = pDir.u8string() + "/Lab" + labNum;
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
    
    for (int i = 1; i <= max; i++) {
        std::cout << "├─" << i << " /\n";
        if (prefix.compare("N/A") != 0){
            std::cout << "|  ├─ " << prefix << i << ".cpp"
                      << "\n";
        }else
            std::cout << "|  ├─ " << i << ".cpp" << "\n";
    }
    
    if (qNum > 10)
        std::cout << qNum-max << " more rows left.\n";
}

bool Lab::destExists(){   
    return fs::exists(fullPath);
}

int Lab::generateFolders() {
    std::string qPath;
    
    //Create parent dir and the full dir
    fs::create_directory(pDir);
    fs::create_directory(fullPath);

    //Create all question subfolders
    for (int i = 1; i <= qNum; i++) {
        qPath = fullPath.u8string() + "/" + std::to_string(i);
        fs::create_directory(qPath);


        //Add prefix to qPath if required
        if (usePrefix){
            qPath += "/" + prefix + std::to_string(i) + ".cpp";
        }else{
            qPath += "/" + std::to_string(i) + ".cpp";
        }

        //If template file defined, copy it. Otherwise build generic from scratch
        if (useTemplate && tPath.compare("N/A") != 0){
            fs::copy(tPath, qPath);
        }else{
            std::ofstream outfile(qPath);
            outfile << "#include <iostream>\n";
            outfile << "#include <string>\n";
            outfile << "int main(){\n";
            outfile << "\n";
            outfile << "}\n";
            outfile.close();
        }
    }

    return 1;
}

fs::path Lab::getPDir(){
    return pDir;
}

fs::path Lab::getFullPath() {
    return fullPath;
}