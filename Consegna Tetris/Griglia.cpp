#include "Griglia.hpp"

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
        mvwprintw(gameWin, i - 3, j + 1, "' ");
      else
        mvwprintw(gameWin, i - 3, j + 1, "{}");
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
    if (g[row][j] == 0) full = false;
    else j+=2;
  }
  return full;
}

void Griglia::MoveRowsDown(int row) {
  delay_output(50);
  for (int i = row; i > 0; i--) {
    for (int j = 0; j < cols; j+=2) {
      g[i][j] = g[i-1][j];
    }
  }
}

void Griglia::ClearRow(int row) {
  for (int j = 0; j < cols; j+=2) g[row][j] = 0;
}

void Griglia::DeleteRow(int row) {
  ClearRow(row); 
  MoveRowsDown(row);
}

void Griglia::ControlRows() {
  int righe_cancellate = 0;
  for (int i = 0; i < rows; i++) {
    if (isRowFull(i)){
      righe_cancellate++;
      DeleteRow(i);
    }
  }
  if (righe_cancellate == 1) punteggio += 10;
  else if (righe_cancellate == 2) punteggio += 30;
  else if (righe_cancellate == 3) punteggio += 50;
  else if (righe_cancellate == 4) punteggio += 100;
}