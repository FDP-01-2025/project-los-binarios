#ifndef THIRDSCASINOGAMEPT1_H
#define THIRDCSASINOGAMEPT1_H

#include <iostream>
#include "thirdsCasinoGamept2.h"
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
    cout << "WAIT A SECOND PLEASE\n";
    waitSeconds(2);
    cout << "ARE YOU READY FOR THE FINAL GAME??\n";
    waitSeconds(2);

    playRoulette(money);
}

#endif