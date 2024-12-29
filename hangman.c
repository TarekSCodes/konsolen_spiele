#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "eigenefunktionen.h"

const char *nomen[] = {
    "ABENDESSEN", "ABENTEUER", "BAUERNHOF", "BERGSTEIGEN", "BLUMENSTRAUSS",
    "DACHGEPAECK", "EISENBAHN", "FLUGHAFEN", "FREIZEIT", "GESELLSCHAFT",
    "HANDSCHUHE", "HAUSAUFGABEN", "HOCHSCHULE", "KATZENFUTTER", "LEBENSMITTEL",
    "LICHTQUELLE", "LUFTMATRATZE", "MUELLTONNE", "NACHTISCH", "OBSTGARTEN",
    "PFLANZENWELT", "REGENBOGEN", "SCHMETTERLING", "SCHRANKWAND", "SPIEGELBILD",
    "STRASSENBAHN", "STREICHHOLZ", "TASCHENLAMPE", "WALDWANDERUNG", "ZAHNARZTPRAXIS",
    "AUTOBAN", "BAUMHAUS", "DELFIN", "ELEFANT", "FALKE", "GIRAFFE", "HEMD", "IKONE",
    "JAGD", "KAMEL", "LÖWE", "MAULWURF", "NINJA", "PFERD", "QUALLEN", "TIGER",
    "UNGEHEUER", "WOLF", "XYLOPHON", "YAK", "ZEBRA"
};
void hangmanStart();
const char* getZufaelligenNomen();
void createVerdecktesWort(const char* wort, char* verdecktesWort);


void hangman() {

    // Erstellen eines Zufallswortes, ermitteln der Wortlänge und erstellen eines Arrays mit _
    srand(time(NULL));
    char *zufallswort = getZufaelligenNomen();
    char verdecktesWort[strlen(zufallswort)];
    createVerdecktesWort(zufallswort, verdecktesWort);


    char *spielstandHangman[] = {
    "     \n     \n     \n     \n     \n     \n",
    "     \n    |\n    |\n    |\n    |\n____|\n",
    "     ______\n    |\n    |\n    |\n    |\n____|\n",
    "     ______\n    |     |\n    |     O\n    |\n    |\n____|\n",
    "     ______\n    |     |\n    |     O\n    |    /|\\\n    |\n____|\n",
    "     ______\n    |     |\n    |     O\n    |    /|\\\n    |    / \\\n____|\n"
    };
    int spielstandCounter = 0;
    bool bedingung = true;
    char spielerAuswahl;

    // Zeigt die Anleitung und wartet auf eine Enter Eingabe zum starten.
    bildschirmLeeren();
    hangmanStart();
    bildschirmLeeren();


    // Hier beginnt das eigentliche Spiel.
    while (bedingung){

        fflush(stdout);
        printf("%s", zufallswort);
        printf("%s", spielstandHangman[spielstandCounter]);
        for (int i = 0; i < strlen(zufallswort); i++) {
            printf("%c ", verdecktesWort[i]);
        }

        printf("\n\nGib einen Buchstaben ein: ");
        scanf(" %c", &spielerAuswahl);

        // TODO EINGABE prüfen ob im Wort vorhanden
        // TODO WENN vorhanden Strich durch Buchstaben austauschen
        bool gefunden = false;
        for (int i = 0; i < strlen(zufallswort); i++) {
            if (zufallswort[i] == toupper(spielerAuswahl)) {
                verdecktesWort[i] = toupper(spielerAuswahl);
                gefunden = true;
            }
        }
        // TODO SONST, counter erhöhen und hangman zeichnen
        if (!gefunden) {
            spielstandCounter++;
        } else {
            // TODO
            // WENN kein _ mehr im array ist
            // Gewonnen, Spiel beenden
            // printf("Glückwunsch! Du hast gewonnen.");
        }

        //pauseProgramm(2);
        //printf("\nMöchtest du noch einmal spielen? (j/n)\n");
        //bedingung = jaOderNeinAbfrage();

        if (bedingung) {
            // TODO
            // Neues Wort auswählen
            // spielstandCounter = 0
            // neues Array mit _ _ _
        }

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


const char* getZufaelligenNomen() {

    return nomen[rand() % (sizeof(nomen) / sizeof(nomen[0]))];
}

void createVerdecktesWort(const char* wort, char* verdecktesWort) {

    int wortLaenge = strlen(wort);
    for (int i = 0; i < wortLaenge; i++) {
        verdecktesWort[i] = '_';
    }
}


