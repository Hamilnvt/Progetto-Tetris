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

  Quadrato q = Quadrato(gameWin, griglia);

  int ch;
  while ((ch = getch()) != KEY_F(1)) {

    box(gameWin, 0, 0);
    wrefresh(gameWin);

    //q.Update(ch);
    q.Display();

    griglia.Update();
    
    if (q.HasReachedEnd) {
      mvwprintw(gameWin, 1, 1, "Fine");
      ch = KEY_F(1);
    }

    wrefresh(gameWin);
    refresh();
  }
  getch();
  endwin();
  return 0;
}