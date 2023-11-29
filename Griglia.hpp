#pragma once

#include <ncurses.h>

#define G_ROWS 42
#define G_COLS 60

class Griglia {
  public:
  int g[G_ROWS][G_COLS];
  int rows = G_ROWS;
  int cols = G_COLS;
  WINDOW *gameWin;

  Griglia(WINDOW *gameWin);
  Griglia();

  void Update();
  void SetState(int y, int x, int s);

  bool isRowFull(int row);
  void DeleteRow(int row);
  void MoveRowsDown(int deleted_row);
  void ControlRows();

  void StampaGriglia();
};
