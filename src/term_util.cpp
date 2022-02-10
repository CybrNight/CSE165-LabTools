#include "term_util.h"
#include <algorithm>
#include <iostream>

void clearConsole() {
    std::system("clear");
}

void cleanCin() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}