#include <ncurses.h>
#include "Griglia.hpp"

#define GAME_WIN_HEIGHT 40
#define GAME_WIN_WIDTH 60

#define SPEED 50

#define STARTY 1
#define STARTX 20
#define WIDTH 2
#define HEIGHT 1
#define LENGTH 4

class Tetramino {
    public:
    int y = STARTY;  
    int x = STARTX;
    int w = WIDTH;
    int h = HEIGHT;
    bool HasReachedEnd = false;
    WINDOW *gameWin;
    Griglia griglia;

    Tetramino();
    Tetramino(WINDOW *gameWin, Griglia griglia);

    void Update(int ch);
    void Display();
};