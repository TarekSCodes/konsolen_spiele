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

    bildschirmLeeren();

    bool bedingung = true;
    //int counter = 0;
    srand(time(NULL));

    // Zeigt die Anleitung und wartet auf eine Enter Eingabe zum starten.
    hangmanStart();

    bildschirmLeeren();

    // Hier beginnt das eigentliche Spiel.
    while (bedingung){

        fflush(stdout);
        bedingung = jaOderNeinAbfrage();


    }

    bildschirmLeeren();

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

/*
const char* getZufaelligenNomen() {

    //const char *zufallsNomen =

    return zufallsNomen;
}
*/






