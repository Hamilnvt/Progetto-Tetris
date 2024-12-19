#ifndef GIUOCO_H
#define GIUOCO_H

#include <iostream>
#include <ncurses.h>

#include "Tetramino.hpp"
#include "Griglia.hpp"
#include "Quadrato.hpp"
#include "Linea.hpp"


void drawNextQuadrato(WINDOW *win);
void drawNextLinea(WINDOW *win);

void Giuoco(int &punteggio);

#endif