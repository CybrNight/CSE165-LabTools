#include "term_util.h"
#include <algorithm>

void clearConsole() {
#ifdef _OS_WINDOWS
    std::system("cls");
#else
    std::system("clear");
#endif
}