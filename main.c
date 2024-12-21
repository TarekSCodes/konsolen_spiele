#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "eigenefunktionen.h"


int main()
{
    bool bedingung = true;

    /* Hauptschleife, hier passiert die ganze Magie, die die App am laufen hält.
     * Das Menü wird angezeigt, der Spieler trifft eine Wahl,
     * und das Spiel wird gestartet. Wenn der Spieler das Spiel beendet kommt er
     * hierher zurück und kann auswählen ob er weitermachen möchte.
     * Wenn ja startet ein neuer Schleifen Durchlauf.
     */
    while (bedingung) {

        bildschirmLeeren();

        /* Das Hauptmenu mit der Spieleauswahl wird angezeigt,
         * der Spieler wählt eins aus und die funktion gibt die
         * Auswahl als Integer Wert zurück.
         */
        int spielAuswahl = hauptMenu();

        pauseProgramm(1);

        if (spielAuswahl == 0)
            bedingung = false;
        else
            spielStarten(spielAuswahl);


    }

    bildschirmLeeren();
    printf("Auf Wiedersehen bis zum nächsten mal. :)\n");


    return 0;
}
