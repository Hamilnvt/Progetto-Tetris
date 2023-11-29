#include "Tetramino.hpp"
#include <iostream>

Tetramino::Tetramino() {}

Tetramino::Tetramino(WINDOW *gameWin, Griglia *griglia) {
  this->gameWin = gameWin;
  this->griglia = griglia;
}

void Tetramino::Display() {}

void Tetramino::Update(int ch) {}

void Tetramino::Clear() {}

void Tetramino::MoveDown(int n) {
  delay_output(SPEED);
  Clear();
  if (y < griglia->rows - n)
    y++;
  else
    HasReachedEnd = true;
}

bool Tetramino::isGameOver() {
  return (HasReachedEnd && y < 3);
}