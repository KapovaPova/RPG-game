#ifndef MAIN_GETCH_H
#define MAIN_GETCH_H

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>

inline int getch() {
    struct termios oldt, newt;
    int ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}

#endif

#endif //MAIN_GETCH_H