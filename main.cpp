#include <iostream>
#include <ncurses.h>
#include "Window.h"
using namespace std;
int x, y, R_MAX, C_MAX;

int main()
{
    initscr();
    box(stdscr, 0, 0);
    refresh();
    getmaxyx(stdscr, R_MAX, C_MAX);

    
    x = N(C_MAX, 5);
    y = N(R_MAX, 3);

    Wd Title(10, 40, 0, 0);
    Center(C_MAX, Title);
    Title.BOX();
    Title.REFRESH();
    

    getch();
    endwin(); 
    return 0;
}
