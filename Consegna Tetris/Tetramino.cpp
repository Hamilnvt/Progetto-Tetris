#include "Tetramino.hpp"
#include <iostream>


Tetramino::Tetramino(WINDOW *gameWin, Griglia *griglia) {
  this->gameWin = gameWin;
  this->griglia = griglia;
}


void Tetramino::MoveDown(int n) {
  delay_output(SPEED);
  if (y < griglia->rows - n)
    y++;
  else
    HasReachedEnd = true;
}

bool Tetramino::isGameOver() {
  return (HasReachedEnd && y < 3);
}