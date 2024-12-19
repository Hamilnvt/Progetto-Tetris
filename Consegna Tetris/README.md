# Titolo Progetto
Tetris

# Descrizione del progetto
Realizzazione del gioco Tetris in C++ per il corso di Programmazione del primo anno del CdL Informatica utilizzando la libreria testuale ncurses.

# Membri
- Joel Baccello
- Samuele Castiglioni
- Mathieu Linty
- Sofia Zanon

# Tecnologie utilizzate
- Librerie: ncurses, fstream, cstring, math.c 
- Text Editor: VSCode
- Terminale

# Modalità d'utilizzo
Eseguendo il file eseguibile Tetris tramite comando da terminale ./Tetris si apre la schermata principale con tre opzioni.
La navigazione avviene tramite freccetta in su e freccetta in giù e per confermare si preme ENTER.
- Nuova Partita: inizia una nuova partita
- Classifica: visualizza la classifica
- Esci: permette di uscire dal gioco

## Funzionamento del gioco:
Il tetramino si sposta lateralmente con le freccette destra e sinistra e il tetramino orizzonatale (I) può essere
ruotato di 90° premendo la freccetta in su.

Completando le righe si guadagano punti, visibili nell'apposito riquadro.
In particolare:
- 1 riga: 10 punti
- 2 righe: 30 punti
- 3 righe: 50 punti
- 4 righe: 100 punti

Il tetramino successivo è visibile nell'apposito riquadro.

Premere altri tasti potrebbe causare ritardi nell'acquisizione di altri input.

Si perde quando il tetramino corrente non ha spazio e tocca il margine superiore della schermata di gioco.
Allora, verrà presentata la schermata del GameOver con il punteggio finale e si dovrà inserire il proprio
username per salvare il risultato nella classifica.
Nell'inserimento dello username (massimo 20 caratteri alfanumerici senza spazi né underscore finali) è possibile
cancellare con il tasto DELETE l'ultimo carattere inserito e confermare con ENTER.
In seguito alla conferma si ritornerà alla schermata principale.


## Classifica:
La classifica si presenta come un elenco di coppie username-punteggio in ordine decrescente secondo il risultato ottenuto.
Per rendere più chiara la visuazzazione, la linea corrente è evidenziata e ci si può muovere con le freccette su e giù.
Per uscire e tornare al menù principale si preme il tasto ESC.