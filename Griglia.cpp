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
        mvwprintw(gameWin, i + 1, j + 1, "  ");
      else
        mvwprintw(gameWin, i + 1, j + 1, "[]");
    }
  }
}