#include "Title.h"
#include <iostream>
#include "ncurses.h"
int T(WINDOW *w, int c, int r, int segnaposto, int ascii)
{
    c /= 6;
    int raggio;
    if(c%3==0)
        raggio = c/3;
    else    
        raggio = c/3 + 3-c%3;
    int pos = (c - raggio)/2;
    for(int i = 0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if((i<r/4) || (j>pos && j<pos+raggio))
                mvwprintw(w, i, j + segnaposto, "%c", ascii);
            else
                mvwprintw(w, i, j + segnaposto, " ");
        }
    }
    return c+segnaposto;
}
int E(WINDOW *w, int c, int r, int segnaposto, int ascii)
{
    c /= 6;
    int raggio, riga;
    if(c%3==0)
        raggio = c/3;
    else    
        raggio = c/3 + 3-c%3;
    
    if(r%2==0)
        riga = r/2;
    else    
        riga = r/2 -1;

    int pos = riga;
    for(int i = 0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(r%2!=0)
            {
                if((j<raggio) || (i<riga/2 || i>r-riga/2-1 || i == riga || i == riga+1 || i==riga+2))
                    mvwprintw(w, i, j + segnaposto, "%c", ascii);
                else
                    mvwprintw(w, i, j + segnaposto, " ");
            }
            else
            {
                if((j<raggio) || (i<riga/2 || i>r-riga/2-1 || i == riga || i == riga-1))
                    mvwprintw(w, i, j + segnaposto, "%c", ascii);
                else
                    mvwprintw(w, i, j + segnaposto, " ");
            }
        }
    }
    return c+segnaposto;
}
int R(WINDOW *w, int c, int r, int segnaposto, int ascii)
{
    c /= 6;
    int porzione= c/4;
    int contatore=0;
    int contatoreblocco = 0;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(i<r/2)
            {
                if(i<=porzione/2 || j<porzione || j>c-porzione-1 || ((i>r/2-porzione)))
                    mvwprintw(w, i, j + segnaposto, "%c", ascii);
                else    
                    mvwprintw(w, i, j + segnaposto, " ");
            }
            else
            {
                if(j<porzione)
                    mvwprintw(w, i, j + segnaposto, "%c", ascii);
                else 
                {
                    if(j>c-porzione*(2-contatoreblocco)-1 && j<c-porzione*(1-contatoreblocco))
                        mvwprintw(w, i, j + segnaposto, "%c", ascii);
                    else    
                        mvwprintw(w, i, j + segnaposto, " ");
                }
            }
        }
        if(i>=r/2)
        {
            contatore++;
            if(contatore%porzione == 0 && contatoreblocco<1)
            {
                contatoreblocco++;
            }
        } 
    }
    return c+segnaposto;
}
int I(WINDOW *w, int c, int r, int segnaposto,int ascii)
{
    c /= 6;
    int raggio;
    if(c%3==0)
        raggio = c/3;
    else    
        raggio = c/3 + 3-c%3;

    int pos = (c - raggio)/2;
    
    for(int i = 0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(j<raggio)
                mvwprintw(w, i, j + segnaposto, "%c", ascii);
            else
                mvwprintw(w, i, j + segnaposto, " ");
        }
    }
    return raggio+segnaposto;
}
void S(WINDOW *w, int c, int r, int segnaposto, int ascii)
{
    c/=6;
    int raggio, riga, n_rig;
    if(c%4==0)
        raggio = c/4;
    else    
        raggio = c/4 + 4-c%4;
   
    riga = raggio / 3;
    n_rig = r/2 - riga/2;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(i<n_rig)
            {
                if(i<=riga || j<raggio)
                     mvwprintw(w, i, j + segnaposto, "%c", ascii);
                else
                     mvwprintw(w, i, j + segnaposto, " ");
            }
            else
            {
                if(i<=n_rig + riga/2)
                     mvwprintw(w, i, j + segnaposto, "%c", ascii);
                else
                {
                    if(j>c-raggio-1)
                         mvwprintw(w, i, j + segnaposto, "%c", ascii);
                    else
                    {
                        if(i>=r-riga-1)
                             mvwprintw(w, i, j + segnaposto, "%c", ascii);
                        else
                             mvwprintw(w, i, j + segnaposto, " ");
                    }
                }
            }
        }
    }
}

void STAMPA(WINDOW *w, int ascii)
{
    int x_max, y_max, segnaposto, a=0;
    getmaxyx(w, y_max, x_max);
    
    a = I(w, x_max, y_max, 0, ascii);
    wclear(w);
    segnaposto = (x_max - (5+(x_max/6)*5 + a)) / 2;
    
    segnaposto = T(w, x_max, y_max, segnaposto, ascii);
    segnaposto = E(w, x_max, y_max, segnaposto+1, ascii);
    segnaposto = T(w, x_max, y_max, segnaposto+1, ascii);
    segnaposto = R(w, x_max, y_max, segnaposto+1, ascii);
    segnaposto = I(w, x_max, y_max, segnaposto+1, ascii);
    S(w, x_max, y_max, segnaposto+1, ascii);
}