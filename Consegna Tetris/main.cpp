#include <iostream>
#include "Title.h"
#include "Window.hpp"
#include "Giuoco.h"
#include "classifica.h"
#include <cstring>
using namespace std;

#define KEY_TAB 10
//GRANDEZZA terminale: 94x21

int x, y, C_MAX, R_MAX;


void Initialize(int &x, int &y, int &R_MAX, int &C_MAX)
{
    initscr();			
    box(stdscr, 0, 0);
    curs_set(0);
	refresh();
    getmaxyx(stdscr, R_MAX, C_MAX);
    x = N(C_MAX, 3);
    y = N(R_MAX, 3);
}
void doTitle(Wd &Title) //le classi possono essere passate per valore!
{
    Center(C_MAX, &Title);
    STAMPA(Title.RETURN_WINDOW(), '*');
    Title.BOX();
    Title.REFRESH();
}
void doMenu(Wd &Menu, int &St, int &Sc, int &E, int &h, int &a)
{
    a = Menu.RETURN_H()/3;
    Center(C_MAX, &Menu);  
    Menu.BOX();
    Menu.REFRESH();
    St = a/2;
    Sc = St + a;
    E = Sc + a;
    h = a/2;
}

int ContaCifra(int punteggio)
{
    int count=0;
    while(punteggio>0)
    {
        count++;
        punteggio/=10;
    }
    return count;
}

void doInsertName(Wd &InsertName, Wd &GameOver, int punteggio)
{
    int crf = ContaCifra(punteggio);

    Center(C_MAX, &GameOver);
    GameOver.BOX();
    GameOver.COPY("GAMEOVER!");
    GameOver.PRINT_PHRASE(1, GameOver.RETURN_W()/2-4);
    mvprintw(GameOver.RETURN_H()+GameOver.RETURN_Y()+1, GameOver.RETURN_X()+1, "  HAI TOTALIZZATO");
    wattron(stdscr, A_BOLD);
    mvprintw(GameOver.RETURN_H()+GameOver.RETURN_Y()+3, GameOver.RETURN_W()/2-crf/2+GameOver.RETURN_X(), "%i", punteggio);
    wattroff(stdscr, A_BOLD);
    mvprintw(GameOver.RETURN_H()+GameOver.RETURN_Y()+5, GameOver.RETURN_W()/2+GameOver.RETURN_X()-2, "PUNTI");
    GameOver.REFRESH();
    refresh();
    
    Center(C_MAX, &InsertName);
    box(stdscr, 0, 0);
    refresh();
    InsertName.BOX();
    InsertName.COPY("Inserisci Username: ____________________");
    InsertName.PRINT_PHRASE(2, InsertName.RETURN_W()-42);
    InsertName.REFRESH();
}

void InsertGamerTag(Wd &InsertName, Wd &GameOver, char username[], int punteggio)
{
    clear();
    keypad(InsertName.RETURN_WINDOW(), true);
    int command;
    char str[] = "Inserisci Username: ____________________";
    int i = 20;
    int count = 0;
    int crf = ContaCifra(punteggio);
    do
    {
        InsertName.BOX();
        GameOver.BOX();
        mvprintw(GameOver.RETURN_H()+GameOver.RETURN_Y()+1, GameOver.RETURN_X()+1, "  HAI TOTALIZZATO");
        wattron(stdscr, A_BOLD);
        mvprintw(GameOver.RETURN_H()+GameOver.RETURN_Y()+3, GameOver.RETURN_W()/2-crf/2+GameOver.RETURN_X(), "%i", punteggio);
        wattroff(stdscr, A_BOLD);
        mvprintw(GameOver.RETURN_H()+GameOver.RETURN_Y()+5, GameOver.RETURN_W()/2-2+GameOver.RETURN_X(), "PUNTI");
        refresh();
        GameOver.REFRESH();
    
        noecho(); //per non vedere i caratteri (e quindi anche quelli speciali) stampati su video
        command = wgetch(InsertName.RETURN_WINDOW());
        if(command != 10 && i<=strlen(str))
        {
            if(command==263 && i>=20)
            {
                str[--i]='_';
                InsertName.COPY(str);
                InsertName.PRINT_PHRASE(2, InsertName.RETURN_W()-42);
                count--;
            }
            //le condizioni '(char)command-'a'>=0' e '(char)command-'A'>=0' sono necessarie perché se il casting viene fatto con un intero
            //maggiore di 255, il conteggio riparte dal numero a cui viene sottratto 255 (ex. (char)256 vale come char(1)) 
            else if(((char)command-'a'>=0 && (char)command-'a'<=25) || ((char)command-'A'>=0 && (char)command-'A'<=25) || 
                     (char)command == '_' || (((char)command-'0'>=0 && ((char)command-'9'<=9)))) 
            {
                str[i++] = command;
                InsertName.COPY(str);
                InsertName.PRINT_PHRASE(2, InsertName.RETURN_W()-42);
                count++;
            }
        }
        box(stdscr, 0, 0);
        refresh();
        InsertName.REFRESH();    
    } while (command != 10 && i<strlen(str));

    strcpy(str,str+20);
    strncpy(username,str,count);
    username[count] = '\0';

    wclear(InsertName.RETURN_WINDOW());
    wclear(GameOver.RETURN_WINDOW());
    clear();
}


void ScritteGameOver(char username[], int punteggio) {
    Wd GameOver(3, 21, (R_MAX-5)/2-5, 0);
    Wd InsertName(5, 44, (R_MAX-5)/2+5, 0);
    doInsertName(InsertName, GameOver, punteggio);
    InsertGamerTag(InsertName, GameOver, username, punteggio);
    box(stdscr,0,0);
    refresh();
}
void Print_Highlighted_Menu(Wd &Menu, int Start, int Score, int Exit, int &highlight, int altezza, int &finestra)
{
    //Stampa delle scelte del menu
    for(int i=Start; i<=Exit; i+=altezza)
    {
        if(i == highlight) wattron(Menu.RETURN_WINDOW(), A_REVERSE); //se la scelta è quella, evidenziala
        if(i==Start)
            { Menu.COPY("Nuova Partita"); Menu.PRINT_PHRASE(Start, Menu.RETURN_W()/2-6); }
        else if(i==Score)
            { Menu.COPY("Classifica"); Menu.PRINT_PHRASE(Score, Menu.RETURN_W()/2-5); }
        else if(i==Exit)
            { Menu.COPY("Esci"); Menu.PRINT_PHRASE(Exit, Menu.RETURN_W()/2-2); }
        wattroff(Menu.RETURN_WINDOW(), A_REVERSE);
    }
    //Modifica di quale scelta deve essere evidenziata
    int choice = wgetch(Menu.RETURN_WINDOW());
    if(choice)
    {
        if(choice == KEY_UP)
            {  highlight-=altezza; if(highlight<Start) highlight = Start; }
        else if(choice == KEY_DOWN)
            {  highlight+=altezza; if(highlight>Exit) highlight = Exit; }
        else if(choice == KEY_TAB)
            { finestra = highlight; }
    }
}



void doBody(Wd &Title, Wd &Menu, int St, int Sc, int E, int h, int a, int R_MAX, int C_MAX)
{
    bool statement = true;
    int finestra = -1;
    do
    {
        if(finestra == -1)
        {
            doTitle(Title);
            doMenu(Menu, St, Sc, E, h, a);
            finestra = 0;
        }
        else if(finestra==0)
        {
             keypad(Menu.RETURN_WINDOW(), true);
             Print_Highlighted_Menu(Menu, St, Sc, E, h, a, finestra);
        }
        else
        {
            wclear(Title.RETURN_WINDOW());
            wclear(Menu.RETURN_WINDOW());
            clear();
            refresh();
            if(finestra == St)
            {
                //codice del gioco
                int punteggio = 216;
                Giuoco(punteggio);

                clear();
                box(stdscr,0,0);
                refresh();
                
                char username[21];
                ScritteGameOver(username,punteggio);

                InserisciScore(username,punteggio);
            }else if(finestra == Sc)
            {
                Classifica();
                box(stdscr,0,0);
                refresh();
                
            }else if(finestra == E)
            {
                statement = false;
            }
            finestra = -1;
        }
        clear();
    }while(statement);
}

int main()
{
    srand(time(0));
    
    initscr();
    start_color();
    noecho();
    curs_set(0);
    cbreak();
    halfdelay(1);
    keypad(stdscr, TRUE);

    Initialize(x, y, R_MAX, C_MAX);
    int wt = N(C_MAX-x, 1);
    int ht = N(R_MAX-y, 2);

    Wd Title(ht+3, wt, 1, 0);
    mvwprintw(Title.RETURN_WINDOW(),10,10,"%d",R_MAX);
    mvwprintw(Title.RETURN_WINDOW(),11,10,"%d",C_MAX);



    int wm = N(Title.RETURN_W(), 3);
    int hm = N(R_MAX-Title.RETURN_Y(), 4);

    Wd Menu(hm*2-1, wm, Title.RETURN_Y()+Title.RETURN_H(), 0);
    int Start, Score, Exit, highlight;
    int altezza;
    
    doBody(Title, Menu, Start, Score, Exit, highlight, altezza, R_MAX, C_MAX);

    refresh();			
	endwin();

    return 0;
}