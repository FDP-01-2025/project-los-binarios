#ifndef juego1casinopt2_h
#define juego1casinopt2_h

#include <iostream>
#include <chrono>
#include <string>
#include "juego1casinopt3.h"
using namespace std;
using namespace std::chrono;

// Game logic — returns true if player solved all phrases
bool runCodeGame(double& money) {
    auto start = high_resolution_clock::now();

    for (int i = 0; i < (int)phrases.size(); i++) {
        bool correct = false;
        while (!correct) {
            auto now = high_resolution_clock::now();
            int elapsed = duration_cast<seconds>(now - start).count();
            if (elapsed >= 60) {
                return false;
            }

            cout << "\n⏳ Time left: " << 120 - elapsed << " seconds\n";
            cout << "==== PHRASE " << (i + 1) << " ====\n";
            showEncodedPhrase(phrases[i]);

            cout << "Enter phrase " << i + 1 << ": ";
            string input;
            getline(cin, input);

            if (clean(input) == clean(phrases[i].realPhrase)) {
                cout << "✅ Correct!\n";
                correct = true;
            } else {
                cout << "❌ Incorrect. Try again.\n";
            }
        }
    }

    return true;
}

#endif