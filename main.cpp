#include <iostream>
#include <ncurses.h>

#include "Griglia.hpp"
#include "Quadrato.hpp"

int main() {

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

  int ch;
  while ((ch = getch()) != KEY_F(1)) {

    if(q.isGameOver()) {
      // qui si crea l'istanza nella classifica
      mvprintw(0,+160,"Fine della partita");
      //break;
    }
    
    if (q.HasReachedEnd) {
      q = Quadrato(gameWin, &griglia);
    }

    q.Update(ch);
    q.Display();

    griglia.Update();
    griglia.ControlRows();
    /* if (ch == KEY_UP) {
      mvprintw(1,160,"Delete Row");
      griglia.DeleteRow(41);
    } */
    griglia.StampaGriglia();
    
    box(gameWin, 0, 0);

    wrefresh(gameWin);
    refresh();
  }  
  getch();
  endwin();
  return 0;
}