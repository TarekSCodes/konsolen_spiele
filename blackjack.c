
// Array mit 52 karten - 2 bis A
// zufallszahl wird genutzt um array neu zu sortieren und zwar nach jeder runde

// int spielerAnzahl
// EINGABE: spieleranzahl - max 3
// int spielerKonto

// EINGABE: spielerEinsatz - spieler machen ihre einsätze
// jedem spieler werden 2 karten vom ende des arrays zugewiesen
// dem dealer eine offene und eine verdeckte
// alle zugewiesenen karten müssen aus dem array entfernt werden


// WENN spielerBlatt > 21
    // verloren geld weg raus die runde
// WENN SONST (spielerBlatt == 21)
    // gewonnen raus die runde, am ende auszahlen
    // ausser dealer macht auch == 21

// nun haben alle spieler ausser die mit blackjack oder zu viel, 4 optionen
// [1] Karte
    // Der spieler bekommt noch eine karte
    // WENN spielerBlatt > 21
        // verloren geld weg raus die runde
    // WENN SONST (spielerBlatt == 21)
        // gewonnen raus die runde, am ende auszahlen
        // optionen wieder anzeigen
// [2] Halten
    // weiter zum nächsten spieler
// [3] Verdoppeln
    // spielerEinsatz * 2
    // 1 Einzige weitere Karte, danach raus und am ende auswerten
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

// EINGABE: Noch ein Runde j/n
// WENN NICHT
    // Spiel beenden zurück ins Hauptmenü
// SONST
    // spielerblatt & dealerBlatt = 0
    // Array wieder komplettieren und mischen




