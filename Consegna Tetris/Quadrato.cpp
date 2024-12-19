#include "Quadrato.hpp"
#include "ncurses.h"

Quadrato::Quadrato(WINDOW *gameWin, Griglia *griglia):Tetramino(gameWin,griglia) {};

void Quadrato::Display() {
  griglia->SetState(y, x, 1);
  griglia->SetState(y, x + 2, 1);
  griglia->SetState(y + 1, x, 1);
  griglia->SetState(y + 1, x + 2, 1);
  refresh();
}

void Quadrato::Clear() {
  griglia->SetState(y, x, 0);
  griglia->SetState(y, x + 2, 0);
  griglia->SetState(y + 1, x, 0);
  griglia->SetState(y + 1, x + 2, 0);
  refresh();
}

void Quadrato::CheckCollision() {
  if (griglia->g[y + 3][x] == 1 || griglia->g[y + 3][x + 2] == 1)
    HasReachedEnd = true;
}

bool Quadrato::CheckLeftEdge() {
  return (x < 2 || griglia->g[y][x - 2] == 1 || griglia->g[y + 1][x - 2] == 1);
}

bool Quadrato::CheckRightEdge() {
  return (x > griglia->cols - 6 || griglia->g[y][x + 4] == 1 ||
          griglia->g[y + 1][x + 4] == 1);
}

void Quadrato::Update(int ch) {
  Clear();
  switch (ch) {
  case KEY_LEFT:
    if (CheckLeftEdge())
      break;
    x -= 2;
    break;

  case KEY_RIGHT:
    if (CheckRightEdge())
      break;
    x += 2;
    break;
  }
  CheckCollision();
  MoveDown(2);
  Display();
}