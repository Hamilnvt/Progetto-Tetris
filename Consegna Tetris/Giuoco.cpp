#include "Giuoco.h"

#define N_TETRAMINI 2

void drawNextQuadrato(WINDOW *win) {
  wclear(win);
  box(win,0,0);
  mvwprintw(win,2,5,"{}{}");
  mvwprintw(win,3,5,"{}{}");
}

void drawNextLinea(WINDOW *win) {
  wclear(win);
  box(win,0,0);
  mvwprintw(win,3,3,"{}{}{}{}");
}

void Giuoco(int &punteggio) {

  WINDOW *gameWin = newwin(GAME_WIN_HEIGHT, GAME_WIN_WIDTH, 1, 32);
  Griglia griglia = Griglia(gameWin);

  WINDOW *next_T_win = newwin(6,14,3,13);
  WINDOW *win_punteggio = newwin(5,16,11,12);

  Quadrato q = Quadrato(gameWin, &griglia);
  Linea l = Linea(gameWin, &griglia);

  int Rcurrent = rand()%N_TETRAMINI;
  int Rnext = rand()%N_TETRAMINI;

  keypad(stdscr, TRUE);
  int ch;
  while(!q.isGameOver() || !l.isGameOver()) {
    ch = getch();
    if (Rcurrent == 0) {
      if (q.HasReachedEnd) {
        griglia.ControlRows();
        q = Quadrato(gameWin, &griglia);
        Rcurrent = Rnext;
        Rnext = rand()%N_TETRAMINI;
      }

      q.Update(ch);
    }
    else {
      if (l.HasReachedEnd) {
        griglia.ControlRows();
        l = Linea(gameWin, &griglia);
        Rcurrent = Rnext;
        Rnext = rand()%N_TETRAMINI;
      }

      l.Update(ch);
    }

    griglia.ClearRow(0);
    griglia.ClearRow(1);
    griglia.ClearRow(2);

    griglia.Update();


    box(next_T_win,0,0);
    mvprintw(2,11,"PROSSIMO TETRAMINO");
    if (Rnext == 0) drawNextQuadrato(next_T_win);
    else drawNextLinea(next_T_win);

    box(win_punteggio,0,0);
    mvprintw(10,15,"PUNTEGGIO");
    mvwprintw(win_punteggio,2,2,"%d", griglia.punteggio);    

    box(gameWin, 0, 0);

    wrefresh(next_T_win);
    wrefresh(win_punteggio);
    wrefresh(gameWin);

    refresh();
  }
  punteggio = griglia.punteggio;
  endwin();
}
