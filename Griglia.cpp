#include "Griglia.hpp"

Griglia::Griglia() {}

Griglia::Griglia(WINDOW *gameWin) {
  this->gameWin = gameWin;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      g[i][j] = 0;
    }
  }
}

void Griglia::Update() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j += 2) {
      if (g[i][j] == 0)
        mvwprintw(gameWin, i - 3, j + 1, "  ");
      else
        mvwprintw(gameWin, i - 3, j + 1, "[]");
    }
  }
  wrefresh(gameWin);
}

void Griglia::SetState(int y, int x, int s) {
  if (x % 2 == 1)
    x++;
  g[y][x] = s;
}

bool Griglia::isRowFull(int row) {
  bool full = true;
  int j = 0;
  while (j < cols && full) {
    mvprintw(2,180,"%i",g[row][j]);
    if (g[row][j] == 0) full = false;
    else j++;
  }
  return full;
}

void Griglia::MoveRowsDown(int deleted_row) {
  delay_output(50);
  for (int i = deleted_row; i > 0; i--) {
    for (int j = 0; j < cols; j++) {
      g[i][j] = g[i-1][j];
    }
  }
}

void Griglia::DeleteRow(int row) {
  for (int j = 0; j < cols; j++) g[row][j] = 0;
  // calcolo punti...
  MoveRowsDown(row);
}

void Griglia::ControlRows() {
  for (int i = 0; i < rows; i++) {
    if (isRowFull(i)) DeleteRow(i);
  }
}

void Griglia::StampaGriglia() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j += 2) {
      mvprintw(i, j, "%i",g[i][j]);
    }
  }
}