#include <files.h>

#include <filesystem>
#include <fstream>
#include <string>

namespace fs = std::filesystem;

int files::generateFolders(Lab lab) {
    std::string qPath;

    // Get all vars from lab object
    bool usePrefix = lab.getUsePrefix();
    bool useTemplate = lab.getUseTemplate();

    std::string pDir = lab.getPDir();
    std::string fullPath = lab.getFullPath();
    std::string prefix = lab.getPrefix();
    std::string tPath = lab.getTemplate();

    // Create parent dir and the full dir
    fs::create_directory(pDir);
    fs::create_directory(fullPath);

    // Create all question subfolders
    for (int i = 1; i <= lab.getQNum(); i++) {
        qPath = lab.getFullPath().u8string() + "/" + std::to_string(i);
        fs::create_directory(qPath);

        // Add prefix to qPath if required
        if (lab.getUsePrefix()) {
            qPath += "/" + prefix + std::to_string(i) + ".cpp";
        } else {
            qPath += "/" + std::to_string(i) + ".cpp";
        }

        // If template file defined, copy it. Otherwise build generic from
        // scratch
        if (useTemplate && tPath.compare("N/A") != 0) {
            fs::copy(tPath, qPath);
        } else {
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

void files::printFSLayout(Lab lab) {
    std::string labNum = lab.getLabNum();
    std::string prefix = lab.getPrefix();
    int qNum = lab.getQNum();

    std::cout << "Lab" << labNum << "/\n";
    int max = 10;

    if (qNum < 10) {
        max = qNum;
    }

    for (int i = 1; i <= max; i++) {
        std::cout << "├─" << i << " /\n";
        if (prefix.compare("N/A") != 0) {
            std::cout << "|  ├─ " << prefix << i << ".cpp"
                      << "\n";
        } else
            std::cout << "|  ├─ " << i << ".cpp"
                      << "\n";
    }

    if (qNum > 10) std::cout << qNum - max << " more rows left.\n";
}