#include "Giuoco.h"

#define N_TETRAMINI 2

void drawNextQuadrato(WINDOW *win) {
  wclear(win);
  box(win,0,0);
  mvwprintw(win,2,5,"[][]");
  mvwprintw(win,3,5,"[][]");
}

void drawNextLinea(WINDOW *win) {
  wclear(win);
  box(win,0,0);
  mvwprintw(win,3,3,"[][][][]");
}

void Giuoco() {

  srand(time(0));

  initscr();
  start_color();
  noecho();
  curs_set(0);
  cbreak();
  halfdelay(1);
  keypad(stdscr, TRUE);

  WINDOW *gameWin = newwin(GAME_WIN_HEIGHT, GAME_WIN_WIDTH, 0, 70);
  Griglia griglia = Griglia(gameWin);

  WINDOW *next_T_win = newwin(6,14,0,135);
  WINDOW *win_punteggio = newwin(5,20,10,135);

  Quadrato q = Quadrato(gameWin, &griglia);
  Linea l = Linea(gameWin, &griglia);

  int Rcurrent = rand()%N_TETRAMINI;
  int Rnext = rand()%N_TETRAMINI;

  int ch;
  while ((ch = getch()) != KEY_F(1)) {

    if (Rcurrent == 0) {
      if(q.isGameOver()) {
        // qui si crea l'istanza nella classifica
        mvprintw(0,160,"Fine della partita");
        break;
      }

      if (q.HasReachedEnd) {
        griglia.ControlRows();
        q = Quadrato(gameWin, &griglia);
        Rcurrent = Rnext;
        Rnext = rand()%N_TETRAMINI;
      }

      q.Update(ch);
      q.Display();
    }
    else {
      if(l.isGameOver()) {
        // qui si crea l'istanza nella classifica
        mvprintw(0,160,"Fine della partita");
        break;
      }

      if (l.HasReachedEnd) {
        griglia.ControlRows();
        l = Linea(gameWin, &griglia);
        Rcurrent = Rnext;
        Rnext = rand()%N_TETRAMINI;
      }

      l.Update(ch);
      l.Display();
    }

    griglia.ClearRow(0);
    griglia.ClearRow(1);
    griglia.ClearRow(2);
    griglia.Update();
    griglia.StampaGriglia();

    //if (Rcurrent == 0)mvprintw(1,160,"Current: quadrato     ");
    //else mvprintw(1,160,"Current: linea         ");
    //if (Rnext == 0)mvprintw(2,160,"Next: quadrato     ");
    //else mvprintw(2,160,"Next: linea         ");

    refresh();

    box(next_T_win,0,0);
    mvprintw(6,133,"Prossimo Tetramino");
    if (Rnext == 0) drawNextQuadrato(next_T_win);
    else drawNextLinea(next_T_win);

    box(win_punteggio,0,0);
    mvwprintw(win_punteggio,1,1,"PUNTEGGIO");
    mvwprintw(win_punteggio,2,1,"%d", griglia.punteggio);    

    box(gameWin, 0, 0);

    wrefresh(next_T_win);
    wrefresh(win_punteggio);
    wrefresh(gameWin);
  }  
  getch();
  endwin();
}
