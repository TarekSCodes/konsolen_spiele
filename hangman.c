#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "eigenefunktionen.h"

const char *nomen[] = {
    "Abendessen", "Abenteuer", "Bauernhof", "Bergsteigen", "Blumenstrauß",
    "Dachgepäck", "Eisenbahn", "Flughafen", "Freizeit", "Gesellschaft",
    "Handschuhe", "Hausaufgaben", "Hochschule", "Katzenfutter", "Lebensmittel",
    "Lichtquelle", "Luftmatratze", "Mülltonne", "Nachtisch", "Obstgarten",
    "Pflanzenwelt", "Regenbogen", "Schmetterling", "Schrankwand", "Spiegelbild",
    "Straßenbahn", "Streichholz", "Taschenlampe", "Waldwanderung", "Zahnarztpraxis"
};
void hangmanStart();
const char* getZufaelligenNomen();


void hangman() {

    bool bedingung = true;
    char spielerAuswahl;

    // Erstellen eines Zufallswortes, ermitteln der Wortlänge und erstellen eines Arrays mit _
    srand(time(NULL));
    char *zufallswort = nomen[rand() % (sizeof(nomen) / sizeof(nomen[0]))];
    int wortLaenge = strlen(zufallswort);
    char verdecktesWort[wortLaenge];
    for (int i = 0; i < wortLaenge; i++) {
        verdecktesWort[i] = '_';
    }

    char *spielstandHangman[] = {
    "     \n     \n     \n     \n     \n     \n",
    "     \n    |\n    |\n    |\n    |\n____|\n",
    "     ______\n    |\n    |\n    |\n    |\n____|\n",
    "     ______\n    |     |\n    |     O\n    |\n    |\n____|\n",
    "     ______\n    |     |\n    |     O\n    |    /|\\\n    |\n____|\n",
    "     ______\n    |     |\n    |     O\n    |    /|\\\n    |    / \\\n____|\n"
    };
    int spielstandCounter = 0;

    // Zeigt die Anleitung und wartet auf eine Enter Eingabe zum starten.
    bildschirmLeeren();
    hangmanStart();
    bildschirmLeeren();


    // Hier beginnt das eigentliche Spiel.
    while (bedingung){

        fflush(stdout);
        printf("%s", zufallswort);
        printf("%s", spielstandHangman[spielstandCounter]);
        for (int i = 0; i < wortLaenge; i++) {

            printf("%c ", verdecktesWort[i]);
        }

        printf("\n\nGib einen Buchstaben ein: ");
        scanf(" %c", &spielerAuswahl);

        // TODO EINGABE prüfen ob im Wort vorhanden
        // TODO WENN vorhanden Strich durch Buchstaben austauschen
        // TODO SONST, counter erhöhen und hangman zeichnen
        for (int i = 0; i < wortLaenge; i++) {
            if (zufallswort[i] == spielerAuswahl) {
                verdecktesWort[i] = spielerAuswahl;
            }
        }


        //bedingung = jaOderNeinAbfrage();


        bildschirmLeeren();
    }
}


void hangmanStart() {

    printf("Willkommen bei Hangman\n\n");
    printf("Hangman ist ein Ratespiel, bei dem du ein geheimes Wort erraten musst.\n");
    printf("Du bekommst die Anzahl der Buchstaben des Wortes angezeigt und kannst Buchstaben eingeben.\n");
    printf("Für jeden falschen Buchstaben wird ein Teil des Galgens gezeichnet.\n");
    printf("Wenn der Galgen vollständig ist, hast du verloren. Wenn du das Wort richtig erraten hast, gewinnst du!\n\n");

    printf("Drücke die Enter Taste zum Starten...");
    getchar();
}




