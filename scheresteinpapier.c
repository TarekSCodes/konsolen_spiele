#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "eigenefunktionen.h"



void scheresteinpapier() {

    srand(time(NULL));
    char* symbole[] = {"Schere", "Stein", "Papier"};
    bool bedingung = true;
    int spielerAuswahl;
    int npcAuswahl;
    int spielerPunkte = 0;
    int npcPunkte = 0;

    // Zeigt die Anleitung und wartet auf eine Enter Eingabe zum starten.
    bildschirmLeeren();
    scheresteinpapierStart();
    bildschirmLeeren();


    while (bedingung) {

        printf("Punktestand Spieler: %d\n", spielerPunkte);
        printf("Punktestand NPC: %d\n\n", npcPunkte);
        printf("[1] Schere\n");
        printf("[2] Stein\n");
        printf("[3] Papier\n");
        printf("\nWähle deine Waffe: ");

        // TODO (tarek#1#): In eigene Funktion implementieren
        int result;
        do {
            result = scanf("%1d", &spielerAuswahl);
            ioBufferLeeren();

            if (spielerAuswahl < 1 || spielerAuswahl > 3 || result != 1) {
                printf("Ungültige Eingabe. Bitte wähle eine der Zahlen von 1-3: ");
            } else {
                break;
            }

        } while (true);

        printf("\nDu wählst: %s\n", symbole[spielerAuswahl - 1]);

        npcAuswahl = rand() % 3;
        printf("Der NPC wählt: %s\n\n", symbole[npcAuswahl]);

        if (symbole[spielerAuswahl - 1] == symbole[npcAuswahl]) {
        printf("Unentschieden, keiner bekommt einen Punkt.\n");
        } else if ((symbole[spielerAuswahl - 1] == "Schere" && symbole[npcAuswahl] == "Papier") ||
            (symbole[spielerAuswahl - 1] == "Papier" && symbole[npcAuswahl] == "Stein") ||
            (symbole[spielerAuswahl - 1] == "Stein" && symbole[npcAuswahl] == "Schere")) {
            printf("Gewonnen, %s schlägt %s. Punkt für dich.\n", symbole[spielerAuswahl - 1], symbole[npcAuswahl]);
            spielerPunkte++;
        } else {
            printf("Verloren, %s schlägt %s. Punkt für den NPC.\n", symbole[npcAuswahl], symbole[spielerAuswahl - 1]);
            npcPunkte++;
        }
        pauseProgramm(3);

        if (spielerPunkte == 3 || npcPunkte == 3) {

            bildschirmLeeren();
            printf("Punktestand Spieler: %d\n", spielerPunkte);
            printf("Punktestand NPC: %d\n\n", npcPunkte);
            printf("3 Punkte erreicht!\n");

            if (spielerPunkte == 3) {
                printf("Glückwunsch du hast gewonnen!\n");
            } else {
                printf("Schade du hast verloren. :(\n");
            }
        } else {
            bildschirmLeeren();
            continue;
        }

        pauseProgramm(2);
        printf("\nMöchtest du noch einmal spielen? (j/n)\n");
        bedingung = jaOderNeinAbfrage();
        if (bedingung) {
            spielerPunkte = 0;
            npcPunkte = 0;
        }
        bildschirmLeeren();
    }



}


void scheresteinpapierStart() {

    printf("Willkommen bei Schere, Stein, Papier!\n\n");
    printf("Das Ziel des Spiels ist es, deinen Gegner zu schlagen, indem du die richtige Wahl triffst.\n\n");
    printf("Hier sind die Regeln:\n");
    printf("- Schere schlägt Papier (Schere schneidet Papier).\n");
    printf("- Papier schlägt Stein (Papier wickelt Stein ein).\n");
    printf("- Stein schlägt Schere (Stein zerbricht Schere).\n\n");
    printf("Wähle eines der drei Symbole aus.\n");
    printf("Wenn du und der NPC dasselbe Symbol wählen, gilt die Runde als unentschieden.\n");
    printf("Wer zuerst 3 Runden Gewinnt, ist der Gesamtsieger und das Spiel endet..\n\n");

    printf("Drücke die Enter-Taste, um das Spiel zu starten...");

    getchar();
}
