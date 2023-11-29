#include <iostream>
#include <ncurses.h>

#include "Tetramino.hpp"
#include "Griglia.hpp"
#include "Quadrato.hpp"
#include "Linea.hpp"

#define N_TETRAMINI 2

int main() {

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
  
  Quadrato q = Quadrato(gameWin, &griglia);
  Linea l = Linea(gameWin, &griglia);

  int R = rand()%N_TETRAMINI;

  int ch;
  while ((ch = getch()) != KEY_F(1)) {
    
    if (R == 0) {
      if(q.isGameOver()) {
        // qui si crea l'istanza nella classifica
        mvprintw(0,160,"Fine della partita");
        //break;
      }

      if (q.HasReachedEnd) {
        griglia.ControlRows();
        q = Quadrato(gameWin, &griglia);
        R = rand()%N_TETRAMINI;
      }

      q.Update(ch);
      q.Display();
    }
    else {
      if(l.isGameOver()) {
        // qui si crea l'istanza nella classifica
        mvprintw(0,160,"Fine della partita");
        //break;
      }

      if (l.HasReachedEnd) {
        griglia.ControlRows();
        l = Linea(gameWin, &griglia);
        R = rand()%N_TETRAMINI;
      }

      l.Update(ch);
      l.Display();
    }

    griglia.Update();

    griglia.StampaGriglia();

    box(gameWin, 0, 0);

    wrefresh(gameWin);
    refresh();
  }  
  getch();
  endwin();
  return 0;
}