#pragma once

#include <ncurses.h>

#define GAME_WIN_HEIGHT 40
#define GAME_WIN_WIDTH 60

#define G_ROWS 39
#define G_COLS 59

class Griglia {
  public:
  int g[G_ROWS][G_COLS];
  int rows = G_ROWS;
  int cols = G_COLS;
  WINDOW *gameWin;

  Griglia(WINDOW *gameWin);
  Griglia();

  void Update();
  
  void DeleteRow(int row);
};
