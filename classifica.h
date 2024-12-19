#include <iostream>
#include <fstream>
#include <cstring>
#include <ncurses.h>
#include <cmath>
using namespace std;

#define LEN 32

//struct per la classifica
struct User{
    char name[60];
    int score;
};

//funzione che conta le linee del txt
int CountLines(ifstream& tetris_scores);

//funzione che scrive gli scores su struct User
void TxtToArr(char NomeFile[], User a[], int totLines);

void OrdinaClassifica(struct User a[], int size);

void MostraClassifica(User a[], int size_ar);

void Classifica();

void InserisciScore(char username[], int score);