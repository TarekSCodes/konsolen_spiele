#include <limits.h>
#include <time.h>
#include <string.h>
#include "eigenefunktionen.h"

#define DECKGROESSE 52

enum Status {
    VERLOREN,
    IM_SPIEL,
    NICHTS_GEHT_MEHR,
    GEWONNEN
};


void einsatzFestlegen(int *konto, int *einsatz) {

    printf("Du hast noch %d € in der Tasche.\n", *konto);

    do
    {
        int temp = 0;
        printf("Bitte mach deinen Einsatz: ");
        if(scanf(" %10d", &temp) != 1) {
            bildschirmLeeren();
            printf("Ungültige Eingabe. Bitte Zahl eingeben.\n");
            ioBufferLeeren();
            continue;
        }
        ioBufferLeeren();
        printf("\n");

        if (temp > *konto)
        {
            printf("Soviel hast du nicht mehr.\n");
        }
        else
        {
            *einsatz = temp;
            break;
        }
    }
    while (true);
}


// Der Fisher-Yates-Algorithmus
void kartenDeckMischen(int deck[]) {

    for (int i = DECKGROESSE - 1; i >= 1; i--)
    {

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

    for (int i = 0; i < DECKGROESSE; i++)
    {
        if (blatt[i] != 0)
        {

            *blattWert += blatt[i];
            if (isDealer == 1 && i == 1)
            {
                printf("%c ", 'X');
            }
            else
            {
                printf("%d ", blatt[i]);
            }
        }
    }
    if (isDealer == 1)
    {
        printf("\n\t[%c]\n", 'X');
    }
    else
    {
        printf("\n\t[%d]\n", *blattWert);
    }
}


void arrayNullen(int *blattArray) {

    for (int i = 0; i < DECKGROESSE; i++)
    {
        blattArray[i] = 0;
    }
}


void spielstandPruefen(int wert, enum Status *spielerStatus) {

    if (wert > 21)
    {
        *spielerStatus = VERLOREN;
        printf("\nKartenwert zu hoch, du hast die Runde verloren.\n");
        printf("Drücke die Enter-Taste zum weitermachen... ");
        getchar();
    }
    else if (wert == 21)
    {
        // gewonnen raus die runde, am ende auszahlen
        // ausser dealer macht auch == 21
        *spielerStatus = NICHTS_GEHT_MEHR;
        printf("\nGlückwunsch! Du hast 21 erreicht.\n");
        printf("Du kannst keine weiteren Karten mehr ziehen.\n\n");
        printf("Drücke die Enter-Taste zum weitermachen... ");
        getchar();
    }
    else if (wert < 21)
    {
        // optionen wieder anzeigen
        // spielerStatus = 1 bleibt
    }
}


void spielerAktionen(
    enum Status *spielerStatus,
    int *spielerBlatt,
    int *spielerKartenAnzahl,
    int *kartenDeck,
    int *arrayGroesse,
    int *spielerEinsatz,
    int *spielerBlattWert,
    int *dealerBlatt,
    int *dealerBlattWert) {

    while (*spielerStatus == IM_SPIEL)
    {

        printf("\nWas möchtest du jetzt machen?\n\n");

        printf("[1] Karte\n");
        printf("[2] Halten\n");
        printf("[3] Verdoppeln\n");

        int optionAuswahl;
        printf("\nTriff ein Wahl: ");
        scanf(" %1d", &optionAuswahl);
        printf("\n");
        ioBufferLeeren();

        switch(optionAuswahl)
        {

        case 1:
            // Karte
            spielerBlatt[(*spielerKartenAnzahl)++] = zieheKarte(kartenDeck, arrayGroesse);
            break;
        case 2:
            // Halten
            // weiter zum nächsten spieler
            *spielerStatus = NICHTS_GEHT_MEHR;
            break;
        case 3:
            // Verdoppeln
            // 1 Einzige weitere Karte
            *spielerEinsatz *= 2;
            spielerBlatt[(*spielerKartenAnzahl)++] = zieheKarte(kartenDeck, arrayGroesse);
            *spielerStatus = NICHTS_GEHT_MEHR;
            break;
        default:
            bildschirmLeeren();
            printf("Ungültige Option. Bitte wähle erneut.\n\n");
            printSpielstand(spielerBlatt, spielerBlattWert, 0);
            printf("\tSpieler\n\n");

            // Anzeigen der Dealerkarten
            printSpielstand(dealerBlatt, dealerBlattWert, 1);
            printf("\tDealer\n");
            continue;
        }

        bildschirmLeeren();
        printf("\n");
        // Anzeigen der Spielerkarten
        printSpielstand(spielerBlatt, spielerBlattWert, 0);
        printf("\tSpieler\n\n");

        // Anzeigen der Dealerkarten
        printSpielstand(dealerBlatt, dealerBlattWert, 1);
        printf("\tDealer\n");

        spielstandPruefen(*spielerBlattWert, spielerStatus);
    }
}


void spieleDealerRunde(
    int *spielerBlatt,
    int *spielerBlattWert,
    int *dealerBlatt,
    int *dealerBlattWert,
    enum Status *spielerStatus,
    int *dealerKartenAnzahl,
    int *kartenDeck,
    int *arrayGroesse) {

    bool geprueft = false;
    do
    {

        printSpielstand(spielerBlatt, spielerBlattWert, 0);
        printf("\tSpieler\n\n");

        // dealer deckt verdeckte karte auf
        printSpielstand(dealerBlatt, dealerBlattWert, 0);
        printf("\tDealer\n\n");

        if (*dealerBlattWert == 21)
        {
            geprueft = true;
            printf("Der Dealer hat 21, Rundenende.\n");
            *spielerStatus = (*spielerBlattWert == 21) ? IM_SPIEL : VERLOREN;
        }
        else if (*dealerBlattWert > 21)
        {
            geprueft = true;
            printf("Der Dealer hat sich überkauft.\n");
            printf("Alle Spieler mit einem Blatt bis 21 haben gewonnen.\n");
            *spielerStatus = (*spielerBlattWert <= 21) ? GEWONNEN : VERLOREN;
        }
        else if (*dealerBlattWert <= 16)
        {
            printf("Der Dealer nimmt noch eine Karte.\n\n");
            dealerBlatt[(*dealerKartenAnzahl)++] = zieheKarte(kartenDeck, arrayGroesse);

        }
        else
        {
            geprueft = true;

            if (*spielerBlattWert > 21)
                *spielerStatus = VERLOREN;
            else if (*spielerBlattWert > *dealerBlattWert)
                *spielerStatus = GEWONNEN;
            else if (*spielerBlattWert == *dealerBlattWert)
                *spielerStatus = IM_SPIEL;
            else
                *spielerStatus = VERLOREN;

            printf("Runde beendet.\n");
            printf("Es folgt die Auswertung.\n\n");

        }
        getchar();
        bildschirmLeeren();
    }
    while (!geprueft);
}


werteRundenErgebnisAus(
    enum Status *spielerStatus,
    int *spielerKontostand,
    int *spielerEinsatz,
    int *spielerBlattWert,
    int *dealerBlattWert) {

    switch (*spielerStatus)
    {
    case GEWONNEN:
        printf("Glückwunsch, du hast diese Runde gewonnen! :)\n");
        *spielerKontostand += *spielerEinsatz;
        break;
    case VERLOREN:
        printf("Du hast leider verloren :(\n");
        *spielerKontostand -= *spielerEinsatz;
        break;
    case IM_SPIEL:
        if (*spielerBlattWert > *dealerBlattWert)
        {
            printf("Glückwunsch, du hast diese Runde gewonnen! :)\n");
            *spielerKontostand += *spielerEinsatz;
        }
        else if (*spielerBlattWert == *dealerBlattWert)
        {
            printf("Unentschieden, nicht gewonnen, nichts verloren.\n");
        }
        else
        {
            printf("Du hast leider verloren :(\n");
            *spielerKontostand -= *spielerEinsatz;
        }
        break;
    }
}


void blackjack() {

    int kartenWerte[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11,
                         2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11,
                         2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11,
                         2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11
                        };
    int kartenDeck[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11,
                        2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11,
                        2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11,
                        2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11
                       };
    int arrayGroesse = sizeof(kartenDeck) / sizeof(int);
    srand(time(NULL));
    rand();

    kartenDeckMischen(kartenDeck);
    int spielerAnzahl = 1;
    int spielerKontostand = 1000;
    int spielerEinsatz;
    enum Status spielerStatus = IM_SPIEL;
    bool bedingung = true;
    int spielerBlatt[DECKGROESSE] = {0};
    int dealerBlatt[DECKGROESSE] = {0};
    int spielerKartenAnzahl = 0;
    int dealerKartenAnzahl = 0;
    int spielerBlattWert = 0;
    int dealerBlattWert = 0;


    while (bedingung)
    {

        bildschirmLeeren();

        einsatzFestlegen(&spielerKontostand, &spielerEinsatz);

        // jedem spieler werden 2 karten vom ende des arrays zugewiesen
        // dem dealer eine offene und eine verdeckte
        spielerBlatt[spielerKartenAnzahl++] = zieheKarte(kartenDeck, &arrayGroesse);
        dealerBlatt[dealerKartenAnzahl++] = zieheKarte(kartenDeck, &arrayGroesse);
        spielerBlatt[spielerKartenAnzahl++] = zieheKarte(kartenDeck, &arrayGroesse);
        dealerBlatt[dealerKartenAnzahl++] = zieheKarte(kartenDeck, &arrayGroesse);

        // Anzeigen der Spielerkarten
        printSpielstand(spielerBlatt, &spielerBlattWert, 0);
        printf("\tSpieler\n\n");

        // Anzeigen der Dealerkarten
        printSpielstand(dealerBlatt, &dealerBlattWert, 1);
        printf("\tDealer\n");

        spielstandPruefen(spielerBlattWert, &spielerStatus);

        // Nun haben alle spieler ausser die mit blackjack || > 21 , 4 Optionen
        spielerAktionen(&spielerStatus, spielerBlatt, &spielerKartenAnzahl, kartenDeck,
                        &arrayGroesse, &spielerEinsatz, &spielerBlattWert, dealerBlatt, &dealerBlattWert);


        // [4] Teilen - mh lass ich vlt. weg

        // alle spieler waren dran
        bildschirmLeeren();
        printf("Aller Spieler haben Ihren Zug beendet.\n");
        printf("Der Dealer ist dran und zeigt seine verdeckte Karte.\n\n");

        spieleDealerRunde(spielerBlatt, &spielerBlattWert, dealerBlatt, &dealerBlattWert,
                          &spielerStatus, &dealerKartenAnzahl, kartenDeck, &arrayGroesse);


        printf("Dein Blatt: %d\n", spielerBlattWert);
        printf("Blatt des Dealers: %d\n\n", dealerBlattWert);
        printf("Dein Einsatz war: %d €\n", spielerEinsatz);

        werteRundenErgebnisAus(&spielerStatus, &spielerKontostand, &spielerEinsatz, &spielerBlattWert, &dealerBlattWert);

        printf("Neuer Kontostand: %d €\n", spielerKontostand);
        getchar();

        // Rundenende
        // WENN spielerkonto <= 0
        if (spielerKontostand <= 0) {
            pauseProgramm(2);
            printf("Du bist Pleite, das Spiel ist zu Ende.\n");
            printf("\nMöchtest du noch einmal spielen? (j/n)\n");
            bedingung = jaOderNeinAbfrage();
            spielerKontostand = 1000;
        }


        spielerBlattWert = 0;
        dealerBlattWert = 0;
        spielerStatus = IM_SPIEL;
        arrayNullen(spielerBlatt);
        arrayNullen(dealerBlatt);
        arrayGroesse = DECKGROESSE;
        kartenDeckMischen(kartenDeck);
        spielerKartenAnzahl = 0;
        dealerKartenAnzahl = 0;
    }
}

