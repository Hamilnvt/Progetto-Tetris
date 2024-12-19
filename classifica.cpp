#include "classifica.h"


void Classifica(){

    User a[1000];
    char NomeFile[] = "tetris_scores.txt";
    
    ifstream tetris_scores_in;
    tetris_scores_in.open(NomeFile, fstream::app);

    if(tetris_scores_in.fail()){
        exit(1);
    }
    
    int totLines = CountLines(tetris_scores_in);

    TxtToArr(NomeFile, a, totLines);

    OrdinaClassifica(a, totLines);

    tetris_scores_in.close();

    MostraClassifica(a, totLines);
}

//funzione che conta le linee del txt
int CountLines(ifstream &tetris_scores){
    char ch_count[1000];
    int totLines = 0;
    while(tetris_scores.getline(ch_count, 1000)){
        if(!((ch_count[0] == '\0'))){
            totLines++;
        }
    }
    return totLines;
}

//funzione che scrive gli scores su struct User
void TxtToArr(char NomeFile[], User a[], int totLines)
{
    char ch_score[60];

    ifstream In(NomeFile);
    for(int i = 0; i < totLines; i++){
        In >> a[i].name; //i nomi non possono avere spazi
        In >> ch_score;

        //al momento della stampa non accetta lo 0, quindi bisogna convertire 0 in 1
        if(strcmp(ch_score, "0") == 0) 
            a[i].score = 1;
        else
            a[i].score = atoi(ch_score);
    }
}

void OrdinaClassifica(struct User a[], int size){
    int i, j;
    for (i=0; i < size - 1; i++){
        for (j=0; j < size - 1; j++){
            if(a[j].score<a[j+1].score){ //minore perché ordina in ordine decrescente
                swap(a[j], a[j+1]);
            }
        }
    }
}

void InserisciScore(char username[], int score) {
    ofstream tetris_scores_out;

    if (strlen(username) > 20) username[21] = '\0';

    tetris_scores_out.open("tetris_scores.txt", fstream::app);
    if (tetris_scores_out.fail()){
        exit(1);
    }   

    tetris_scores_out << "\n" << username << " " << score;

    tetris_scores_out.close();
}

void MostraClassifica(User a[], int totLines){

    WINDOW *rankw;
    int startx, starty, width, height;

    //dimensione window
    height = LINES; 
    width = COLS/2; 
    starty = 0;
    startx = COLS/4;
    
    rankw = newwin(height, width, starty, startx);
    box(rankw, 0, 0);
    refresh();

    int size_lines = 19; //non funziona su altri schermi
    int highlight = 0;
    int page =  0;

    int choice;
    while(choice != 27){ //tasto esc
    
        //stampa tutto e mette l'highlight su una linea
        if(page<totLines/size_lines+1)
        {
            int pos = page*size_lines;
            for(int i = 0; i < totLines; i++)
            {
                if(pos+i<totLines)
                {
                    if(i == highlight)
                        wattron(rankw, A_REVERSE);
                    
                    mvwprintw(rankw, i+1, 1, a[pos+i].name);

                    int len = strlen(a[pos+i].name);
                    char spaces[LEN] = "";
                    while(len < LEN - 1){
                        strcat(spaces, " ");
                        len++;
                    }
                    mvwprintw(rankw, i+1, 1+strlen(a[pos+i].name), spaces);

                    len = floor(log10(a[pos+i].score));
                    int len_score = 14; 
                    char spcs[len_score] = "";
                    while(len < len_score - 1){
                        strcat(spcs, " ");
                        len++;
                    }
                    
                    if(a[pos+i].score == 1) //qui converte 1 in 0
                        mvwprintw(rankw, i+1, 32, "%d%s", 0, spcs);
                    else
                        mvwprintw(rankw, i+1, 32, "%d%s", a[pos+i].score, spcs);
                    wattroff(rankw, A_REVERSE);
                }
                else 
                {  
                    mvwprintw(rankw, i+1, 1, "                                             ");
                }
                box(rankw,0,0);
                wrefresh(rankw);
            }
        }
        choice = getch();

        switch(choice){
            case KEY_UP:
                if(highlight == 0)
                {
                    if(page != 0){    
                        page--;
                        highlight = size_lines-1;
                    }
                }
                else 
                {
                    highlight--;
                }
                break;
            
            case KEY_DOWN:
                if(highlight == (totLines%size_lines) - 1 && page == totLines/size_lines)
                    break;
                if(highlight == size_lines-1){
                    if(totLines%size_lines == 0 && page == totLines/size_lines - 1) {
                        break;
                    } else {
                        page++; 
                        highlight = 0;
                    }
                }
                else 
                {
                    highlight++;
                }
                break;
        }
    }
    endwin();
}