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
    "AUTOBAHN", "BAUMHAUS", "DELFIN", "ELEFANT", "FALKE", "GIRAFFE", "HEMD", "IKONE",
    "JAGD", "KAMEL", "LÖWE", "MAULWURF", "NINJA", "PFERD", "QUALLEN", "TIGER",
    "UNGEHEUER", "WOLF", "XYLOPHON", "YAK", "ZEBRA"
};
void hangmanStart();
const char* getZufaelligenNomen();
void createVerdecktesWort(const char* zufallswort, char* verdecktesWort);
bool checkEingabe(const char* zufallswort, char* verdecktesWort, char spielerAuswahl);



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
        //printf("%s", zufallswort);
        printf("%s\n", spielstandHangman[spielstandCounter]);
        for (int i = 0; i < strlen(zufallswort); i++) {
            printf("%c ", verdecktesWort[i]);
        }

        printf("\n\nGib einen Buchstaben ein: ");
        scanf(" %c", &spielerAuswahl);

        // Hier prüfe ich ob der eingegebene Buchstabe gefunden wurde.
        // Falls ja kommt ein true zurück und die/das '_' Zeichen wurde
        // durch den Buchstaben ersetzt
        bool gefunden = checkEingabe(zufallswort, verdecktesWort, spielerAuswahl);

        // Ab hier nutze ich die Information ob ein Buchstabe gefunden wurde
        // Im ersten Abschnitt folgt was passieren soll wenn nicht
        if (!gefunden) {
            spielstandCounter++;

            if (spielstandCounter == 5) {

                bildschirmLeeren();
                printf("%s", spielstandHangman[spielstandCounter]);
                printf("\nDer Hangman baumelt. Leider verloren!\n");
                printf("Das gesuchte Wort lautete: %s\n", zufallswort);
            } else {
                bildschirmLeeren();
                continue;
            }

        // Ab hier kommt die Logik was passieren soll falls der Buchstabe gefunden wurde
        } else {
            // Prüfen ob noch '_' im Array sind, wenn nicht wurde das gesamte Wort gefunden
            int wortGefunden = 0;
            for (int i = 0; i < strlen(verdecktesWort); i++) {
                if (verdecktesWort[i] == '_') {
                    wortGefunden++;
                }
            }


            if (wortGefunden == 0) {
                bildschirmLeeren();
                printf("%s", spielstandHangman[spielstandCounter]);
                printf("\nGlückwunsch! Du hast gewonnen.\n");
            } else {
                bildschirmLeeren();
                continue;
            }
        }

        pauseProgramm(2);
        printf("\nMöchtest du noch einmal spielen? (j/n)\n");
        bedingung = jaOderNeinAbfrage();
        if (bedingung) {
            spielstandCounter = 0;
            zufallswort = getZufaelligenNomen();
            createVerdecktesWort(zufallswort, verdecktesWort);
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


void createVerdecktesWort(const char* zufallswort, char* verdecktesWort) {

    for (int i = 0; i < strlen(zufallswort); i++) {
        verdecktesWort[i] = '_';
    }
}


bool checkEingabe(const char* zufallswort, char* verdecktesWort, char spielerAuswahl) {

    bool fund = false;
    for (int i = 0; i < strlen(zufallswort); i++) {
        if (zufallswort[i] == toupper(spielerAuswahl)) {
            verdecktesWort[i] = toupper(spielerAuswahl);
            fund = true;
        }
    }
    return fund;
}

