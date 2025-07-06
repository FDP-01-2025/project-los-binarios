#ifndef juego3casinopt3_h
#define juego3casinopt3_h

#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

struct Slot;

void waitSeconds(int seconds) {
    clock_t end = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < end) { /* wait */ }
}

Slot forceWinSlot(const vector<Slot>& wheel, const string& color, const vector<int>& numbers) {
    for (const Slot& s : wheel) {
        if (!color.empty() && s.color == color) return s;
        if (!numbers.empty() && find(numbers.begin(), numbers.end(), s.number) != numbers.end()) return s;
    }
    return wheel[rand() % wheel.size()];
}

void displayResult(const Slot& result) {
    cout << "\nResult: ";
    if (result.color == "red") {
        cout << "\033[31m" << result.number << "\033[0m\n";
    } else {
        cout << "\033[34m" << result.number << "\033[0m\n";
    }
}

#endif