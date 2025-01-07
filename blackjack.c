#include <limits.h>
#include <time.h>
#include <string.h>
#include "eigenefunktionen.h"

#define DECKGROESSE 52

// Der Fisher-Yates-Algorithmus
void kartenDeckMischen(int deck[]) {

    for (int i = DECKGROESSE - 1; i >= 1; i--) {

        int j = rand() % (i + 1);

        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}


int zieheKarte(int deck[], int *groesse) {

    int karte = deck[*groesse - 1];
    (*groesse)--;
    return karte;
}


static void printSpielstand(int blatt[], int *blattWert, int isDealer) {

    *blattWert = 0;
    printf("\t");

    for (int i = 0; i < DECKGROESSE; i++) {
        if (blatt[i] != 0) {

            *blattWert += blatt[i];
            if (isDealer == 1 && i == 1) {
                printf("%c ", 'X');
            } else {
                printf("%d ", blatt[i]);
            }
        }
    }
    if (isDealer == 1) {
        printf("\n\t[%c]\n", 'X');
    } else {
        printf("\n\t[%d]\n", *blattWert);
    }
}


void arrayNullen(int *blattArray) {

    for (int i = 0; i < DECKGROESSE; i++) {
        blattArray[i] = 0;
    }
}


void spielstandPruefen(int wert, int *konto, int *einsatz, int *status) {

    if (wert > 21) {
        // verloren geld weg raus die runde
        *konto -= *einsatz;
        *einsatz = 0;
        *status = 0;
        printf("\nKartenwert zu hoch, du hast die Runde verloren.\n");
        printf("Drücke die Enter-Taste zum weitermachen... ");
        getchar();
    } else if (wert == 21) {
        // gewonnen raus die runde, am ende auszahlen
        // ausser dealer macht auch == 21
        *status = 2;
        printf("Glückwunsch! Du hast 21 erreicht.\n");
        printf("Du kannst keine weiteren Karten mehr ziehen.\n");
        printf("Drücke die Enter-Taste zum weitermachen... ");
        getchar();
    } else if (wert < 21) {
        // optionen wieder anzeigen
        // spielerStatus = 1 bleibt
    }
}


void blackjack() {

    int kartenWerte[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11,
                         2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11,
                         2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11,
                         2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};
    int kartenDeck[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11,
                        2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11,
                        2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11,
                        2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};
    int arrayGroesse = sizeof(kartenDeck) / sizeof(int);
    srand(time(NULL));
    rand();

    kartenDeckMischen(kartenDeck);
    int spielerAnzahl = 1;
    int spielerKontostand = 1000;
    int spielerEinsatz;
    int spielerStatus = 1; // noch im Spiel oder schon raus?
    // 0 raus - überkauft, verliert in jedem Fall
    // 1 im spiel - kann noch ziehen
    // 2 Nicht verloren - nichts geht mehr
    bool bedingung = true;
    int spielerBlatt[DECKGROESSE] = {0};
    int dealerBlatt[DECKGROESSE] = {0};
    int spielerKartenAnzahl = 0;
    int dealerKartenAnzahl = 0;
    int wertSpielerBlatt = 0;
    int wertDealerBlatt = 0;


    while (bedingung) {

        bildschirmLeeren();

        printf("Du hast noch %d € in der Tasche.\n", spielerKontostand);
        // EINGABE: spieleranzahl - max 3

        do {
            int temp = 0;
            printf("Bitte mach deinen Einsatz: ");
            scanf(" %10d", &temp);
            ioBufferLeeren();
            printf("\n");

            if (temp > spielerKontostand) {
                printf("Soviel hast du nicht mehr.\n");
            } else {
                spielerEinsatz = temp;
                break;
            }
        } while (true);

        // jedem spieler werden 2 karten vom ende des arrays zugewiesen
        // dem dealer eine offene und eine verdeckte
        spielerBlatt[spielerKartenAnzahl++] = zieheKarte(kartenDeck, &arrayGroesse);
        dealerBlatt[dealerKartenAnzahl++] = zieheKarte(kartenDeck, &arrayGroesse);
        spielerBlatt[spielerKartenAnzahl++] = zieheKarte(kartenDeck, &arrayGroesse);
        dealerBlatt[dealerKartenAnzahl++] = zieheKarte(kartenDeck, &arrayGroesse);

        // Anzeigen der Spielerkarten
        printSpielstand(spielerBlatt, &wertSpielerBlatt, 0);
        printf("\tSpieler\n\n");

        // Anzeigen der Dealerkarten
        printSpielstand(dealerBlatt, &wertDealerBlatt, 1);
        printf("\tDealer\n");

        spielstandPruefen(wertSpielerBlatt, &spielerKontostand, &spielerEinsatz, &spielerStatus);

        // Nun haben alle spieler ausser die mit blackjack || > 21 , 4 Optionen
        while (spielerStatus == 1) {

            printf("\nWas möchtest du jetzt machen?\n\n");

            printf("[1] Karte\n");
            printf("[2] Halten\n");
            printf("[3] Verdoppeln\n");

            int optionAuswahl;
            printf("\nTriff ein Wahl: ");
            scanf(" %1d", &optionAuswahl);
            printf("\n");
            ioBufferLeeren();

            switch(optionAuswahl) {

            case 1:
                // Karte
                spielerBlatt[spielerKartenAnzahl++] = zieheKarte(kartenDeck, &arrayGroesse);
                break;
            case 2:
                // Halten
                // weiter zum nächsten spieler
                spielerStatus = 2;
                break;
            case 3:
                // Verdoppeln
                // 1 Einzige weitere Karte
                spielerEinsatz *= 2;
                spielerBlatt[spielerKartenAnzahl++] = zieheKarte(kartenDeck, &arrayGroesse);
                spielerStatus = 2;
                break;
            }

            bildschirmLeeren();
            printf("\n");
            // Anzeigen der Spielerkarten
            printSpielstand(spielerBlatt, &wertSpielerBlatt, 0);
            printf("\tSpieler\n\n");

            // Anzeigen der Dealerkarten
            printSpielstand(dealerBlatt, &wertDealerBlatt, 1);
            printf("\tDealer\n");

            spielstandPruefen(wertSpielerBlatt, &spielerKontostand, &spielerEinsatz, &spielerStatus);
        }



        // [4] Teilen - mh lass ich vlt. weg

        // alle spieler waren dran
        // dealer deckt verdeckte karte auf

        // WENN dealerBlatt == 21
            // alle verloren ausser unentschieden bei spielerBlatt == 21
            // bei spielerStatus = 2
        // WENN SONST dealerblatt > 21
            // Dealer verliert, alle spieler die nicht spielerBlatt > 21 haben gewonnen
            // spielerStatus = 2;
        // WENN SONST dealerblatt < 16
            // Dealer nimmt 1 Karte
            // Dann wieder von vorne prüfen

        // Rundenende

        // WENN spielerkonto <= 0
            // Spieler ist dauerhaft aus dem Spiel


//        pauseProgramm(2);
//        printf("\nMöchtest du noch einmal spielen? (j/n)\n");
//        bedingung = jaOderNeinAbfrage();
//        if (bedingung) {
            wertSpielerBlatt = 0;
            wertDealerBlatt = 0;
            spielerStatus = 1;
            arrayNullen(spielerBlatt);
            arrayNullen(dealerBlatt);
            arrayGroesse = DECKGROESSE;
            kartenDeckMischen(kartenDeck);
            spielerKartenAnzahl = 0;
            dealerKartenAnzahl = 0;
//            // spielerAnzahl = 0
//        }
        //bildschirmLeeren();
    }
}

