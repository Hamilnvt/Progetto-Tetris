#include <iostream>
#include <ncurses.h>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;

    initscr();
    endwin();
}