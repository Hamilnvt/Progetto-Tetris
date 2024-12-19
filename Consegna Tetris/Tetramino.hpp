#pragma once

#include "ncurses.h"
#include "Griglia.hpp"

#define GAME_WIN_HEIGHT 20
#define GAME_WIN_WIDTH 34

#define SPEED 100

#define STARTY 0
#define STARTX (int)GAME_WIN_WIDTH*0.4 + 1

class Tetramino {
    public:
    int y = STARTY;  
    int x = STARTX;
    bool HasReachedEnd = false;
    WINDOW *gameWin;
    Griglia *griglia;

    Tetramino(WINDOW *gameWin, Griglia *griglia);
    
    bool isGameOver();
    
    void MoveDown(int n);
};