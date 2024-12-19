
#ifndef WINDOW_HPP
#define WINDOW_HPP
#include "ncurses.h"
class Wd
{
    private:
        int height;
        int width;
        int y;
        int x;
        char str[100];
        WINDOW *w;
    public:
        Wd(int _h, int _w, int _y, int _x);

        void COPY(const char *x);
        void PRINT_PHRASE(int _y, int _x);

        void MOVE(int _y, int _x);
        void REFRESH(); 
        void BOX();
        void NEW();

        int RETURN_W();
        int RETURN_H();
        int RETURN_X();
        int RETURN_Y();
        WINDOW* RETURN_WINDOW();
};

int N(int c, int n);
void Center(int witdh, Wd *son);

#endif