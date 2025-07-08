#ifndef FIRSTCASINOGAMEPT1_H
#define FIRSTCASINOGAMEPT1_H
#pragma once

#include <iostream>
#include "firstCasinoGamept2.h"
using namespace std;

void pauseseconds(int seconds) {
    clock_t end = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < end) { /* espera */ }
}
// This function replaces main() logic and can be called from another file
void startCodeGame(double& money) {
    cout << " WELCOME TO THE CODE GAME!!\n";
    cout << "You start with $" << money << ". Solve the phrases to double your money.\n";
    cout << "You have 2 MINUTES total to solve 3 phrases.\n\n";

    bool success = runCodeGame(money);

    cout << "\n=== FINAL RESULT ===\n";
    if (success) {
        money *= 2;
        cout << " SUCCESS! You doubled your money!\n";
    } else {
        money /= 2;
        cout << " Time is up! You lost half your money.\n";
    }

    cout << " Current balance: $" << money << "\n";
pauseseconds(5);
}
#endif