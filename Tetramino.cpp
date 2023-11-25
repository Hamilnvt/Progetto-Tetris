#include "Tetramino.hpp"
#include <iostream>

Tetramino::Tetramino() {}

Tetramino::Tetramino(WINDOW *gameWin, Griglia griglia) {
  this->gameWin = gameWin;
  this->griglia = griglia;
}

void Tetramino::Display() {}

void Tetramino::Update(int ch) {}