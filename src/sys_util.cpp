#include <sys_util.h>
#include <algorithm>

void clearConsole(){
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}