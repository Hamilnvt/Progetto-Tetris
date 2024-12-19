#pragma once

#include <ncurses.h>

#define G_ROWS 22
#define G_COLS 32

class Griglia {
  public:
  int g[G_ROWS][G_COLS];
  int rows = G_ROWS;
  int cols = G_COLS;
  int punteggio = 0;
  WINDOW *gameWin;

  Griglia(WINDOW *gameWin);

  void Update();
  void SetState(int y, int x, int s);

  void ClearRow(int row);

  bool isRowFull(int row);
  void DeleteRow(int row);
  void MoveRowsDown(int row);
  void ControlRows();

};
