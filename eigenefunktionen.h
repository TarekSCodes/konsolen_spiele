#ifndef EIGENEFUNKTIONEN_H
#define EIGENEFUNKTIONEN_H

#ifdef _Win32
    #include <windows.h>
    #define OS_WINDOWS 1
#else
    #include <unistd.h>
    #define OS_WINDOWS 0
#endif

int hauptMenu();
void spielStarten(int spielAuswahl);
void hangman();
void tictactoe();

void pauseProgramm(int sekunden);
void bildschirmLeeren();
void ioBufferLeeren();
bool jaOderNeinAbfrage();

#endif
