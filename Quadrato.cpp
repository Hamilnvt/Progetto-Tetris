#include "ncurses.h"
#include "Quadrato.hpp"

Quadrato::Quadrato(WINDOW *gameWin) {
    this->gameWin = gameWin;
}

Quadrato::Quadrato() {

}

void Quadrato::Display() { 
    mvwprintw(gameWin,y,x,"[]");
    mvwprintw(gameWin,y,x+WIDTH,"[]");
    mvwprintw(gameWin,y+HEIGHT,x,"[]");
    mvwprintw(gameWin,y+HEIGHT,x+WIDTH,"[]");
    wrefresh(gameWin);
    refresh();
}

void Quadrato::Clear() {
    mvwprintw(gameWin,y,x,"  ");
    mvwprintw(gameWin,y,x+WIDTH,"  ");
    mvwprintw(gameWin,y+HEIGHT,x,"  ");
    mvwprintw(gameWin,y+HEIGHT,x+WIDTH,"  ");
    wrefresh(gameWin);
    refresh();
}

void Quadrato::CheckLateralEdges() {
    if(x < 1) x = 1;
    if(x + WIDTH > GAME_WIN_WIDTH - 3) x = GAME_WIN_WIDTH - 3 - WIDTH;
}

void Quadrato::MoveDown() {
    delay_output(SPEED);
    Clear();
    y++;
}

void Quadrato::CheckBottomEdge() {
    if (y + HEIGHT > GAME_WIN_HEIGHT - 3) {
        y = GAME_WIN_WIDTH - 3 - HEIGHT;
        HasReachedEnd = true;
    } 
}

void Quadrato::Update(int ch) {
	switch(ch)
	{	case KEY_LEFT:
			Clear();
			x -= WIDTH;
            Display();
			break;
		case KEY_RIGHT:
            Clear();
            x += WIDTH;
            Display();
			break;
	}
    CheckLateralEdges();
    CheckBottomEdge();
    MoveDown();
}