#include "Linea.hpp"
#include "ncurses.h"

Linea::Linea(WINDOW *gameWin, Griglia *griglia):Tetramino(gameWin,griglia) {} ;

void Linea::Display() {
  if (!isRotated) {
    griglia->SetState(y, x - 4, 1);
    griglia->SetState(y, x - 2, 1);
    griglia->SetState(y, x, 1);
    griglia->SetState(y, x + 2, 1);
  } else {
    griglia->SetState(y - 2, x, 1);
    griglia->SetState(y - 1, x, 1);
    griglia->SetState(y, x, 1);
    griglia->SetState(y + 1, x, 1);
  }
  refresh();
}

void Linea::Clear() {
  if (!isRotated) {
    griglia->SetState(y, x - 4, 0);
    griglia->SetState(y, x - 2, 0);
    griglia->SetState(y, x, 0);
    griglia->SetState(y, x + 2, 0);
  } else {
    griglia->SetState(y - 2, x, 0);
    griglia->SetState(y - 1, x, 0);
    griglia->SetState(y, x, 0);
    griglia->SetState(y + 1, x, 0);
  }
  refresh();
}

void Linea::CheckCollision() {
  if (isRotated) {
    if (griglia->g[y + 3][x] == 1)
      HasReachedEnd = true;
  } else {
    if (griglia->g[y + 2][x - 4] == 1 || griglia->g[y + 2][x - 2] == 1 ||
        griglia->g[y + 2][x] == 1 || griglia->g[y + 2][x + 2] == 1)
      HasReachedEnd = true;
  }
}

bool Linea::CheckLeftEdge() {
  if (isRotated) {
    return (x < 2 ||
            griglia->g[y - 2][x - 2] == 1 ||
            griglia->g[y - 1][x - 2] == 1 ||
            griglia->g[y][x - 2] == 1 ||
            griglia->g[y + 1][x - 2] == 1);
  } else {
    return (x - 4 < 2 || griglia->g[y][x - 6] == 1);
  }
}

bool Linea::CheckRightEdge() {
  if (isRotated) {
    return(x + 4 > griglia->cols ||
           griglia->g[y - 2][x + 2] == 1 ||
           griglia->g[y - 1][x + 2] == 1 ||
           griglia->g[y][x + 2] == 1 ||
           griglia->g[y + 1][x + 2] == 1);
  } else {
    return (x + 6 > griglia->cols || griglia->g[y][x + 4] == 1);
  }
}

bool Linea::cantRotate() {
  if (isRotated) {
    return (x < 4 || x + 4 > griglia->cols ||
            griglia->g[y][x - 4] == 1 ||
            griglia->g[y][x - 2] == 1 ||
            griglia->g[y][x + 2] == 1);
  }
  else {
    return (y < 3 || y + 2 > griglia->rows ||
            griglia->g[y - 2][x] == 1 ||
            griglia->g[y - 1][x] == 1 ||
            griglia->g[y + 1][x] == 1);
  }
}

void Linea::Rotate() {
  Clear();
  isRotated = !isRotated;
}


void Linea::Update(int ch) {
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

  case KEY_UP:
    if (cantRotate())
      break;
    Rotate();
    break;
  }
  CheckCollision();
  if (isRotated) MoveDown(2);
  else MoveDown(1);
  Display();
}