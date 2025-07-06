#define CARRERA_H
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "sleep.h"
using namespace std;


void imprimirPista(int posMiskho, int posRival) {
    system("cls");
    const int META = 50;
     cout << "---------------------RACE FOR THE BATTERY ---------------------\n";

    // Línea de meta
    cout << "META:     |";
    for (int i = 0; i < META; ++i) cout << "-";
    cout << "|\n";

    // Miskho
    cout << "Miskho:   |";
    for (int i = 0; i < posMiskho; ++i) cout << " ";
    cout << "  ___/_____|___\\\\__\n";

    cout << "          |";
    for (int i = 0; i < posMiskho; ++i) cout << " ";
    cout << " |   _     _   ___|\n";

    cout << "          |";
    for (int i = 0; i < posMiskho; ++i) cout << " ";
    cout << " ='-( o )---( o )-'\n";

    // Vigilante
    cout << "Vigilante:|";
    for (int i = 0; i < posRival; ++i) cout << " ";
    cout << "  ___/_____|___\\\\__\n";

    cout << "          |";
    for (int i = 0; i < posRival; ++i) cout << " ";
    cout << " |   _     _   ___|\n";

    cout << "          |";
    for (int i = 0; i < posRival; ++i) cout << " ";
    cout << " ='-( o )---( o )-'\n";

    cout << "\nPress [D] to advance!\n";
}


int carrera(int rivalVelocidadMs) {
    const int META = 50;
    int posMiskho = 0, posRival = 0;
    DWORD lastRivalMove = GetTickCount();

    imprimirPista(posMiskho, posRival);

    while (posMiskho < META && posRival < META) {
        if (_kbhit()) {
            char tecla = _getch();
            if (tecla == 'd' || tecla == 'D') {
                posMiskho++;
                imprimirPista(posMiskho, posRival);
            }
        }

        DWORD ahora = GetTickCount();
        if (ahora - lastRivalMove >= rivalVelocidadMs) {
            posRival++;
            lastRivalMove = ahora;
            imprimirPista(posMiskho, posRival);
        }

        Sleep(20);
    }

    cout << "\n";
    if (posMiskho >= META && posRival >= META) {
        cout << "EPIC DRAW!\n";
        return 0;
    } else if (posMiskho >= META) {
        cout << "Miskho wins!\n";
        return 1;
    } else {
        cout << "You lost\n";
        return -1;
    }
}


int race() {
    int rivalVelocidadMs = 400, resultado;
    cout << "The conveniently convenient Ol Koi manual starts explaining to Miskho that only 2 parts are missing\n";
    cout << "and the Ol Koi will be his.\n";
    cout << "The next object is the battery, required to make the Ol Koi work.\n";
    cout << "It is located in the Electrical Engineering Department.\n";
    cout << "\n[ASCII of energy building here]\n";
    wait(13000);
    system("cls");

    cout << "[ASCII of Rasputin on his car]\n";
    cout << "Rasputin: Hey Miskho! I heard you're looking for this battery.\n";
    cout << "I'm Rasputin, an electrical engineer. I just built this car.\n";
    cout << "If you win a race against me, the battery is yours!\n";
    wait(11000);
    system("cls");
    cout << "\n[ASCII of Kia Soul here]\n";
    wait(2500);
    system("cls");

    resultado = carrera(rivalVelocidadMs);
    wait(1000);
    system("cls");

    if (resultado == 1) {
        cout << "Ok, you win this time, but it won't happen again." << endl;
        cout << "Now, you'll drive this:" << endl;
        cout << "ASCII bus" << endl;
        wait(7000);
        system("cls");
        cout << "Get ready, because now I will use all I have!" << endl;
    } else if (resultado == 0) {
        cout << "Ok, I'll admit that it was a good race. Let's run again to break the draw." << endl;
        cout << "But now, you'll drive this:" << endl;
        cout << "ASCII bus" << endl;
        wait(7000);
        system("cls");
        cout << "Get ready, because now I will use all I have!" << endl;
    } else {
        cout << "You lost, but I'll give you another chance." << endl;
        cout << "But now, you'll drive this:" << endl;
        cout << "ASCII bus" << endl;
        wait(7000);
        system("cls");
        cout << "Get ready, because now I will use all I have!" << endl;
    }

    rivalVelocidadMs = 100;
    cout << "NOW IT STARTS!";
    resultado = carrera(rivalVelocidadMs);

    if (resultado == 1) {
        cout << "That was quite impressive. I have no doubt you deserve this." << endl;
        cout << "ASCII battery" << endl;
        wait(6000);
        system("cls");
        cout << "Continue your adventure, you are close to getting what you want." << endl;
        wait(3500);
        system("cls");
    } else if (resultado == 0) {
        cout << "Well well, that was intense!" << endl;
        cout << "I think you did a spectacular race, that's why I'll give you what you want." << endl;
        cout << "ASCII battery" << endl;
        wait(8000);
        system("cls");
        cout << "Continue your adventure, you are close to getting what you want." << endl;
    } else {
        cout << "You lost in the clutch time. You don't deserve this." << endl;
        cout << "Go back and try again if you want (or if you can)." << endl;
        wait(8000);
        system("cls");
        getch();
        return 0;
    }

    getch();
    return 1;
}
