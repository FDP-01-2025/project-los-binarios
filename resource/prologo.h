#define PROLOGO_H
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "sleep.h"
using namespace std;

void cricketBeep() {
    for (int i = 0; i < 3; i++) {
        Beep(1500, 200); // Frequency duration
        Sleep(300);
        Beep(2000, 150);
        Sleep(800);
    }
}

int pro() {
    cricketBeep();
    cout << "ASCII: Magna V\n";
    wait(1000);
    
    cout << "Friday night. Miskho Jhones, psychology student.\n";
    cout << "After failing Financial Accounting for the third time in a row, Miskho fell asleep...\n";
    wait(7500);

    system("cls");
    cout << "ASCII: Miskho asleep\n";
    wait(2500);

    system("cls");
    cout << "ASCII: Security guard enters Magna V\n";
    wait(1000);
    cout << "The UCA security guard walks into Magna V...\n";
    wait(4000);

    system("cls");
    cout << "ASCII: Guard waking up Miskho\n";
    wait(750);
    cout << "GUARD: WAKE UP, BOY! It's 6 P.M. What are you doing here?\n";
    cout << "Confused, Miskho asks the strange man who he is...\n";
    wait(8000);

    system("cls");
    cout << "ASCII: Miskho and guard talking\n";
    wait(750);
    cout << "GUARD: I'm the university security. And you have a big problem.\n";
    cout << "You can't be here right now... So I'm giving you a special mission.\n";
    cout << "If you don't complete it...\n";
    cout << "THE UNIVERSITY WILL BLOW UP... AND YOU'LL BE PART OF IT.\n";
    wait(12000);

    system("cls");
    cout << "ASCII: Miskho and guard talking\n";
    wait(750);
    cout << "Miskho: WHAT? ARE YOU CRAZY?\n";
    cout << "GUARD: I'm not joking. You will have to find the legendary...\n";
    cout << "----------------------Ol Koi----------------------\n";
    wait(7000);

    system("cls");
    cout << "ASCII: Miskho and guard talking\n";
    wait(750);
    cout << "Miskho: And what is that? How am I supposed to get it?\n";
    cout << "GUARD: That's your problem. But I will give you a clue...\n";
    cout << "In the library, there exists a conveniently convenient manual about the Ol Koi,\n";
    cout << "containing absolutely everything, including how to (maybe) get it, step by painfully obvious step.\n";
    cout << "The university is in your hands now...\n";
    wait(12000);

    system("cls");
    cout << "ASCII: Guard walking away\n";
    wait(2500);

    system("cls");
    cout << "-----------MISKHO JHONES-----------\n";
    cout << "---------THE MISSING OL KOI--------\n";

    getch();
    return 1;
}
