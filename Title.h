#ifndef TITLE_H
#define TITLE_H
#include "ncurses.h"
void STAMPA(WINDOW *w, int ASCII);
int T(WINDOW *w, int c, int r, int segnaposto, int ASCII);
int E(WINDOW *w, int c, int r, int segnaposto, int ASCII);
int R(WINDOW *w, int c, int r, int segnaposto, int ASCII);
int I(WINDOW *w, int c, int r, int segnaposto, int ASCII);
void S(WINDOW *w, int c, int r, int segnaposto, int ASCII);
void DIMENSIONI(int *sub_c, int *sub_r, int c, int r);
#endif