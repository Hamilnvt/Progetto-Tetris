#include <iostream>
#include <ncurses.h>

#include "Quadrato.hpp"

int main() {
    
    initscr();
    start_color();
    noecho();
    curs_set(0);
    cbreak();
    halfdelay(1);
    keypad(stdscr,TRUE);

    WINDOW *gameWin = newwin(GAME_WIN_HEIGHT,GAME_WIN_WIDTH,0,70);

    Quadrato q = Quadrato(gameWin);

    int ch;
    while((ch = getch()) != KEY_F(1)) {
        
        box(gameWin,0,0);
        wrefresh(gameWin);

        q.Update(ch);
        q.Display();


        if(q.HasReachedEnd) {
            mvwprintw(gameWin,1,1,"Fine");
            // qui dividiamo il tetramino nei suoi blocchetti
            // e creiamo il nuovo tetramino
        }

        refresh();
    }   

    endwin();
    return 0;
}