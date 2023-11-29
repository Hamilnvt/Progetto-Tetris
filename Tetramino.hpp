#pragma once

#include "ncurses.h"
#include "Griglia.hpp"

#define GAME_WIN_HEIGHT 40
#define GAME_WIN_WIDTH 62

#define SPEED 2

#define STARTY 0
#define STARTX 26
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
    Griglia *griglia;

    Tetramino();
    Tetramino(WINDOW *gameWin, Griglia *griglia);

    virtual void Clear();
    bool isGameOver();
    virtual void Update(int ch);
    virtual void Display();
    void MoveDown(int n);
};