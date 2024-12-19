
#include <iostream>
#include <ncurses.h>
#include <cstring>
#include "Window.hpp"

Wd::Wd(int _h, int _w, int _y, int _x)
{
    height = _h;
    width = _w;
    y = _y;
    x = _x;
    w = newwin(height, width, _y, _x);
}

void Wd::COPY(const char *x)
{
    strcpy(str, x);
}
void Wd::PRINT_PHRASE(int _y, int _x)
{
    if(_y < height && _x < width)
        mvwprintw(w, _y, _x, str);
}
void Wd::MOVE(int _y, int _x)
{
    y = _y;
    x = _x;
}
void Wd::REFRESH()
{
    wrefresh(w);
} 
void Wd::BOX()
{
    box(w, 0, 0);
}
void Wd::NEW()
{
    delwin(w);
    w = newwin(height, width, y, x);
    wrefresh(w);
}
int Wd::RETURN_W()
{
    return width;
}
int Wd::RETURN_H()
{
    return height;
}
int Wd::RETURN_X()
{
    return x;
}
int Wd::RETURN_Y()
{
    return y;
}
WINDOW* Wd::RETURN_WINDOW()
{
    return w;
}

int N(int c, int n)
{
    if(c%n==0)
        return c/n;
    else
    {
        n--;
        int i=1;
        while(c/i != n)
            i++;
        return i;
    }
}
void Center(int witdh, Wd *son)
{
    int wf = witdh;
    int ws = son->RETURN_W();
    son->MOVE(son->RETURN_Y(), wf/2 - ws/2);
    son->NEW();
}
