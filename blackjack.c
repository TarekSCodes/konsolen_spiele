#include <limits.h>
#include <time.h>
#include <string.h>
#include "eigenefunktionen.h"


// Array mit 52 karten - 2 bis A
const int DECKGROEßE = 52;
char kartenWerte[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'B', 'D', 'K', 'A',
                      '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'B', 'D', 'K', 'A',
                      '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'B', 'D', 'K', 'A',
                      '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'B', 'D', 'K', 'A'};
char kartenDeck[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'B', 'D', 'K', 'A',
                      '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'B', 'D', 'K', 'A',
                      '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'B', 'D', 'K', 'A',
                      '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'B', 'D', 'K', 'A'};
int arrayGroeße = sizeof(kartenDeck) / sizeof(char);

// Der Fisher-Yates-Algorithmus
void kartenDeckMischen(char deck[]) {

    for (int i = DECKGROEßE - 1; i >= 1; i--) {

        int j = rand() % (i + 1);

        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}


void blackjack() {

    srand(time(NULL));
    rand();

    int spielerAnzahl = 1;
    int spielerKontostand = 1000;
    int spielerEinsatz;
    int spielerStatus = 0; // noch im Spiel oder schon raus?
    // 0 raus
    // 1 im spiel
    bool bedingung = true;


    while (bedingung) {

        bildschirmLeeren();

        printf("Du hast noch 1000 € in der Tasche.\n");
        // EINGABE: spieleranzahl - max 3


        printf("Bitte mach deinen Einsatz: ");
        scanf("%10d", &spielerEinsatz);
        ioBufferLeeren();

        kartenDeckMischen(kartenDeck);

        // jedem spieler werden 2 karten vom ende des arrays zugewiesen
            // spielerBlatt muss ein Array sein dem die aktuellen spielerkarten hinzugefügt werden

        // dem dealer eine offene und eine verdeckte
            // dealerBlatt muss ein Array sein dem die aktuellen spielerkarten hinzugefügt werden

        // alle zugewiesenen karten müssen aus dem array entfernt werden

        // TODO Funktion erstellen
        // spielstandPruefen()
            // WENN spielerBlatt > 21
                // verloren geld weg raus die runde
                // spielerKontostand -= spielerEinsatz;
                // spielerEinsatz = 0;
            // WENN SONST (spielerBlatt == 21)
                // gewonnen raus die runde, am ende auszahlen
                // ausser dealer macht auch == 21

        // nun haben alle spieler ausser die mit blackjack oder zu viel, 4 optionen
        printf("Was möchtest du jetzt machen?\n\n");

        printf("[1] Karte\n");
        printf("[2] Halten\n");
        printf("[3] Verdoppeln\n");

        // [1] Karte
            // Der spieler bekommt noch eine karte
            // spielerBLatt + zufallskarte (oder die vom ende des arrays)
            // spielstandPruefen()
                // WENN spielerBlatt > 21
                    // verloren geld weg raus die runde
                    // spielerKontostand -= spielereinsatz
                    // spielereinsatz = 0
                // WENN SONST (spielerBlatt == 21)
                    // gewonnen raus die runde, am ende auszahlen
                    // ausser dealer macht auch == 21
                // WENN SONST (spielerBlatt < 21)
                    // optionen wieder anzeigen

        // [2] Halten
            // weiter zum nächsten spieler

        // [3] Verdoppeln
            // spielerEinsatz * 2
            // 1 Einzige weitere Karte
            // spielstandPruefen()
                // WENN spielerBlatt > 21
                    // verloren geld weg raus die runde
                    // spielerKontostand -= spielereinsatz
                    // spielereinsatz = 0
                // WENN SONST (spielerBlatt == 21)
                    // gewonnen raus die runde, am ende auszahlen
                    // ausser dealer macht auch == 21

        // [4] Teilen - mh lass ich vlt. weg

        // alle spieler waren dran
        // dealer deckt verdeckte karte auf

        // WENN dealerBlatt == 21
            // alle verloren ausser unentschiden bei spielerBlatt == 21
        // WENN SONST dealerblatt > 21
            // Dealer verliert, alle spieler die nicht spielerBlatt > 21 haben gewonnen
        // WENN SONST dealerblatt < 16
            // Dealer nimmt 1 Karte
            // Dann wieder von vorne prüfen

        // Rundenende

        // WENN spielerkonto <= 0
            // Spieler ist dauerhaft aus dem Spiel


        pauseProgramm(2);
        printf("\nMöchtest du noch einmal spielen? (j/n)\n");
        bedingung = jaOderNeinAbfrage();
        if (bedingung) {
            // spielerblatt & dealerBlatt = 0
            // Array wieder komplettieren und mischen
            // spielerAnzahl = 0
            // spielerStatus = 0
        }
        bildschirmLeeren();
    }
}

