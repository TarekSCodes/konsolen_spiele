#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "eigenefunktionen.h"

void tictactoeStart();
void neuesSpielfeld(char spielfeld[3][3]);
void printSpielfeld(char spielfeld[3][3]);
bool pruefeSieg(char spielfeld[3][3], char amZug);
bool spielfeldVoll(char spielfeld[3][3]);


void tictactoe() {

    char spielfeld[3][3];
    bool bedingung = true;
    neuesSpielfeld(spielfeld);
    int spielerWechsel = 2;
    char spielerAuswahl;

    // Zeigt die Anleitung und wartet auf eine Enter Eingabe zum starten.
    bildschirmLeeren();
    tictactoeStart();
    bildschirmLeeren();


    // Hier beginnt das eigentliche Spiel.
    while (bedingung){

        fflush(stdout);
        printSpielfeld(spielfeld);

        char amZug = (spielerWechsel % 2 == 0) ? 'X' : 'O';
        printf("\nSpieler %c du bist am Zug.\n", amZug);
        printf("Setz dein Symbol, indem du die Position im Raster angibst: ");
        scanf(" %1c", &spielerAuswahl);
        ioBufferLeeren();

        // Array prüfen ob die Auswahl gefunden wurde
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (spielfeld[i][j] == spielerAuswahl) {
                    spielfeld[i][j] = amZug;
                    spielerWechsel++;
                }
            }
        }

        // Hier prüft das Programm ob ein Spieler gewonnen hat
        // oder ob das Spielfeld voll ist ohne das jemand gewonnen hat
        // trifft beides nicht zu, startet ein neuer Durchlauf der while Schleife
        if  (pruefeSieg(spielfeld, amZug)) {

            bildschirmLeeren();
            printSpielfeld(spielfeld);
            printf("\nSpieler %c hat gewonnen!\n", amZug);

        } else if (spielfeldVoll(spielfeld)) {

            bildschirmLeeren();
            printSpielfeld(spielfeld);
            printf("\nDas Spielfeld ist voll, niemand hat gewonnen.\n");

        } else {

            bildschirmLeeren();
            continue;
        }

        pauseProgramm(2);
        printf("\nMöchtest du noch einmal spielen? (j/n)\n");
        bedingung = jaOderNeinAbfrage();
        if (bedingung) {
            neuesSpielfeld(spielfeld);
            spielerWechsel = 2;
        }
        bildschirmLeeren();
    }
}


void tictactoeStart() {

    printf("Willkommen bei Tic-Tac-Toe\n\n");
    printf("Tic-Tac-Toe ist ein Strategiespiel für zwei Spieler,\n"
           "bei dem du versuchst, drei deiner Symbole in eine Reihe zu bringen.\n\n");
    printf("Das Spielfeld besteht aus einem 3x3-Raster.\nSpieler 1 verwendet das Symbol 'X', und Spieler 2 verwendet das Symbol 'O'.\n");
    printf("Die Spieler setzen abwechselnd ihre Symbole, indem sie die Position im Raster angeben.\n");
    printf("Das Spiel endet, wenn ein Spieler drei seiner Symbole horizontal,\nvertikal oder diagonal anordnet, oder wenn das Spielfeld voll ist und niemand gewonnen hat.\n\n");

    printf("Drücke die Enter-Taste, um das Spiel zu starten...");

    getchar();
}


void neuesSpielfeld(char spielfeld[3][3]) {

    char initial[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            spielfeld[i][j] = initial[i][j];
        }
    }
}


void printSpielfeld(char spielfeld[3][3]) {

    printf("\n");
    printf("\t %c | %c | %c \n", spielfeld[0][0], spielfeld[0][1], spielfeld[0][2]);
    printf("\t---|---|---\n");
    printf("\t %c | %c | %c \n", spielfeld[1][0], spielfeld[1][1], spielfeld[1][2]);
    printf("\t---|---|---\n");
    printf("\t %c | %c | %c \n", spielfeld[2][0], spielfeld[2][1], spielfeld[2][2]);
}


bool pruefeSieg(char spielfeld[3][3], char amZug) {

    return ((spielfeld[0][0] == amZug && spielfeld[0][1] == amZug && spielfeld[0][2] == amZug) ||
            (spielfeld[1][0] == amZug && spielfeld[1][1] == amZug && spielfeld[1][2] == amZug) ||
            (spielfeld[2][0] == amZug && spielfeld[2][1] == amZug && spielfeld[2][2] == amZug) ||
            (spielfeld[0][0] == amZug && spielfeld[1][0] == amZug && spielfeld[2][0] == amZug) ||
            (spielfeld[0][1] == amZug && spielfeld[1][1] == amZug && spielfeld[2][1] == amZug) ||
            (spielfeld[0][2] == amZug && spielfeld[1][2] == amZug && spielfeld[2][2] == amZug) ||
            (spielfeld[0][0] == amZug && spielfeld[1][1] == amZug && spielfeld[2][2] == amZug) ||
            (spielfeld[0][2] == amZug && spielfeld[1][1] == amZug && spielfeld[2][0] == amZug));
}


bool spielfeldVoll(char spielfeld[3][3]) {

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (spielfeld[i][j] >= '1' && spielfeld[i][j] <= '9') {
                return false;
            }
        }
    }
    return true;
}
