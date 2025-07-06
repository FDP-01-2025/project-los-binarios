#ifndef juego2casinopt1_h
#define juego2casinopt1_h

#include <iostream>
#include "juego1casinopt2.h"
using namespace std;

// This function replaces `main()` logic and can be called from another file
void startCodeGame(double& money) {
    cout << "🎮 WELCOME TO THE CODE GAME!\n";
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
}

#endif
