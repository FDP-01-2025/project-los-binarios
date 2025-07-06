#ifndef juego3casinopt1_h
#define juego3casinopt1_h

#include <iostream>
#include "juego3casinopt2.h"
using namespace std;

void startRouletteGame(double& money) {
    cout << "\n...\n";
    waitSeconds(2);
    cout << "...\n";
    waitSeconds(2);
    cout << "...\n";
    waitSeconds(2);
    cout << "...\n";
    waitSeconds(2);
    cout << "LOADING ROULETTE...\n";
    waitSeconds(2);
    cout << "ARE YOU READY FOR THE FINAL GAME??\n";
    waitSeconds(2);

    playRoulette(money);
}

#endif