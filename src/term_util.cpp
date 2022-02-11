#include "term_util.h"
#include <algorithm>
#include <iostream>

void term::clearConsole() {
    std::system("clear");
}

void term::cleanCin() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}