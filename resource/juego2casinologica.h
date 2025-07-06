#ifndef juego2casinologica_h
#define juego2casinologica_h

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <chrono>
#include "juego2casinovisual.h"

using namespace std;
using namespace std::chrono;

void startReactionGame(double& money) {
    srand(time(0));
    int attempts = 3;
    const int gametime = 45;
    auto start = high_resolution_clock::now();

    system("cls");
    cout << "=============================\n";
    cout << "     REACTION CHALLENGE\n";
    cout << "=============================\n";
    cout << "\nStarting money: $" << money << "\n";
    cout << "\nInstructions:\n";
    cout << "- REACT QUICKLY BY PRESSING THE CORRECT KEY.\n";
    cout << "\033[31m- [W] = UP\033[0m\n";
    cout << "\033[32m- [A] = LEFT\033[0m\n";
    cout << "\033[33m- [S] = DOWN\033[0m\n";
    cout << "\033[34m- [D] = RIGHT\033[0m\n";
    cout << "- YOU ONLY HAVE ONE SECOND TO RESPOND...\n";
    cout << "- YOU HAVE 3 ATTEMPTS TO SURVIVE 45 SECONDS\n";

    cout << "\nTHE GAME STARTS IN: ";
    for (int i = 10; i >= 1; i--) {
        cout << i << "... ";
        waitt(1000);
    }

    system("cls");

    while (attempts > 0) {
        auto now = high_resolution_clock::now();
        auto timepassed = duration_cast<seconds>(now - start).count();
        if (timepassed >= gametime) {
            cout << "\n LET'S GOOOOOO!! You survived the 45 seconds, cookie pookie!\n";
            money *= 2;
            return;
        }

        char target = arrows[rand() % 4];

        cout << "=========================\n";
        showarrows(target);
        showlifes(attempts);
        cout << "=========================\n";

        auto startarrow = high_resolution_clock::now();
        bool pressed = false;
        bool failed = false;

        while (duration_cast<milliseconds>(high_resolution_clock::now() - startarrow).count() < 1400) {
            if (_kbhit()) {
                char key = toupper(_getch());
                pressed = true;
                if (key == target) {
                    cout << "\n:) YEAH BRO!!\n";
                } else {
                    cout << "\n:( Almost bro!! That was not the correct direction.\n";
                    attempts--;
                    failed = true;
                }
                break;
            }
        }

        if (!pressed) {
            cout << "\n:o TOO SLOW BRO!! You have to be faster if you wanna win.\n";
            attempts--;
            failed = true;
        }

        if (failed && attempts > 0) {
            losscounter(5, attempts);
        } else {
            waitt(500);
            system("cls");
        }
    }

    // If the player lost
    cout << "\nBro... I'm sorry... GAME OVER!!\n";
    money /= 2;
}

#endif
