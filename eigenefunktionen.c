#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "eigenefunktionen.h"


int hauptMenu() {

    int spielAuswahl;

    while (true) {

        printf("Hey du, schön das du da bist. :)\n\n");
        printf("Du kannst zum Zeitvertreib aus verschiedenen Spielen auswählen.\n\n");

        printf("[1] Hangman\n");
        printf("[2] Tic-Tac-Toe\n");
        printf("[3] Schere-Stein-Papier\n");
        printf("[0] Zum Beenden des Programms\n");


        printf("\nGibt einfach die Zahl des gewünschten Spiels ein "
               "und drücke die Enter Taste: ");

        scanf("%1d", &spielAuswahl);
        ioBufferLeeren();

        break;
    }
    return spielAuswahl;
}


void spielStarten(int spielAuswahl) {

    switch(spielAuswahl) {
    case 1:
        hangman();
        break;
    case 2:
        tictactoe();
        break;
    case 3:
        scheresteinpapier();
        break;
    }
}


void ioBufferLeeren() {

    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


bool jaOderNeinAbfrage() {

    char goOn;

    do {

        printf("Bitte gib 'j' (ja) oder 'n' (nein) ein: ");
        scanf(" %1c", &goOn);
        ioBufferLeeren();

        if (goOn == 'J' || goOn == 'j')
            return true;

          else if (goOn == 'n' || goOn == 'N')
            return false;

          else
            printf("Ungültige Eingabe. ");

    } while (true);
}






