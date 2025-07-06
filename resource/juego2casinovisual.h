#ifndef juego2casinovisual_h
#define juego2casinovisual_h

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

char arrows[] = {'W', 'A', 'S', 'D'};

// show the key assigned for each direction
void showarrows(char f) {
    cout << "\nPress the correct key: ";
    switch (f) {
        case 'W': cout << "\033[31m- [W] = UP\033[0m\n"; break;
        case 'A': cout << "\033[32m- [A] = LEFT\033[0m\n"; break;
        case 'S': cout << "\033[33m- [S] = DOWN\033[0m\n"; break;
        case 'D': cout << "\033[34m- [D] = RIGHT\033[0m\n"; break;
    }
    cout << "\n";
}

// show the life that the player has
void showlifes(int attempts) {
    cout << "\nATTEMPTS: ";
    for (int i = 0; i < attempts; i++) cout << "<3 ";
    cout << "\n";
}

// active wait (non-blocking)
void waitt(int miliseconds) {
    auto start = high_resolution_clock::now();
    while (duration_cast<milliseconds>(high_resolution_clock::now() - start).count() < miliseconds) {
        // waiting time
    }
}

// shows the fail messsage and the counter
void losscounter(int seconds, int lifes) {
    cout << "\n You lost an attempt bro...\n";
    cout << " you have " << lifes << " attempt(s) left bro, YOU GOT THIS.\n";
    cout << "\nResuming in: ";
    for (int i = seconds; i >= 1; i--) {
        cout << i << "... ";
        waitt(1000);
    }
    cout << "\n";
    system("cls");
}

#endif