#ifndef EIGENEFUNKTIONEN_H
#define EIGENEFUNKTIONEN_H

#include <stdbool.h>

/* Damit lasse ich den Präprozessor prüfen ob
 * das OS Windows ist oder Linux.
 * Jenachdem werden unterschiedliche #include benötigt und eingebunden.
 */
#ifdef _WIN32
    #include <windows.h>
    #define bildschirmLeeren() system("cls")
    #define pauseProgramm(sekunden) Sleep((sekunden) * 1000)
    #define setzeZeichencodierung() system("chcp 65001 > nul")
#elif __linux__ && __unix__
    #include <unistd.h>
    #define bildschirmLeeren() system("clear")
    #define pauseProgramm(sekunden) sleep(sekunden)
    #define setzeZeichencodierung()
#endif

int hauptMenu();
void spielStarten(int spielAuswahl);
void hangman();
void tictactoe();
void blackjack();
void ioBufferLeeren();
bool jaOderNeinAbfrage();

#endif
