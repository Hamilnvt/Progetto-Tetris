#include "Quadrato.hpp"
#include "ncurses.h"

Quadrato::Quadrato() {}

Quadrato::Quadrato(WINDOW *gameWin, Griglia *griglia) {
  this->gameWin = gameWin;
  this->griglia = griglia;
}

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

void Quadrato::MoveDown() {
  delay_output(SPEED);
  Clear();
  if (y < griglia->rows - 2)
    y++;
  else
    HasReachedEnd = true;
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

bool Quadrato::isGameOver() {
  return (HasReachedEnd && y < 3);
}

void Quadrato::Update(int ch) {
  switch (ch) {
  case KEY_LEFT:
    if (CheckLeftEdge())
      break;

    Clear();
    x -= 2;
    Display();
    break;
  case KEY_RIGHT:
    if (CheckRightEdge())
      break;

    Clear();
    x += 2;
    Display();
    break;
  }
  CheckCollision();
  MoveDown();
}