#ifndef EIGENEFUNKTIONEN_H
#define EIGENEFUNKTIONEN_H

/* Damit lasse ich den Präprozessor prüfen ob
 * das OS Windows ist oder Linux.
 * Jenachdem werden unterschiedliche #include benötigt und eingebunden.
 */
#ifdef _Win32
    #include <windows.h>
    #define bildschirmLeeren() system("cls")
    #define pauseProgramm() Sleep((sekunden) * 1000)
#elif __linux__ && __unix__
    #include <unistd.h>
    #define bildschirmLeeren(sekunden) system("clear")
    #define pauseProgramm(sekunden) sleep(sekunden)
#endif

int hauptMenu();
void spielStarten(int spielAuswahl);
void hangman();
void tictactoe();
void ioBufferLeeren();
bool jaOderNeinAbfrage();

#endif
