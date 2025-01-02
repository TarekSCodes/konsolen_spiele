#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "eigenefunktionen.h"

void zahlenratenStart();


void zahlenraten() {

    bool bedingung = true;
    int spielerAuswahl;
    int versuche = 0;
    srand(time(NULL));
    rand();
    int zufallsZahl = (rand() % 100) + 1;

    // Zeigt die Anleitung und wartet auf eine Enter Eingabe zum starten.
    bildschirmLeeren();
    zahlenratenStart();
    bildschirmLeeren();


    // Hier beginnt das eigentliche Spiel.
    while (bedingung){

        fflush(stdout);

        printf("Gib deinen Tipp ein: ");
        scanf(" %3d", &spielerAuswahl);
        ioBufferLeeren();


        if  (spielerAuswahl == zufallsZahl) {

            printf("\nSpieler hat gewonnen!\n");
        } else if (spielerAuswahl > zufallsZahl) {

            printf("zu hoch\n\n");
        } else {

            printf("zu niedrig\n\n");
        }
        versuche++;

        if (spielerAuswahl == zufallsZahl || versuche == 5) {
            if (spielerAuswahl != zufallsZahl) {
                printf("\nDu hast leider verloren. :(\n");
            }
            pauseProgramm(2);

            printf("\nMöchtest du noch einmal spielen? (j/n)\n");
            bedingung = jaOderNeinAbfrage();
            if (bedingung) {
                zufallsZahl = (rand() % 100) + 1;
                versuche = 0;
                bildschirmLeeren();
            }
        }
    }
}


void zahlenratenStart() {

    printf("Willkommen beim Zahlenraten-Spiel!\n\n");
    printf("In diesem Spiel denkt sich der Computer eine Zahl zwischen 1 und 100 aus.\n");
    printf("Deine Aufgabe ist es, diese Zahl in maximal 5 Versuchen zu erraten.\n\n");
    printf("Nach jeder Eingabe erhältst du einen Hinweis, ob die gesuchte Zahl\n");
    printf("größer oder kleiner ist als deine Eingabe.\n");
    printf("Schaffst du es nicht innerhalb von 5 Versuchen, hast du leider verloren.\n\n");

    printf("Drücke die Enter-Taste, um das Spiel zu starten...");

    getchar();
}

