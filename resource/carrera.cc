#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

void wait(int ms) {
    Sleep(ms);
}

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


void carrera() {
    const int META = 50;
    int posMiskho = 0, posRival = 0;
    int rivalVelocidadMs = 250;
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
    } else if (posMiskho >= META) {
        cout << "Miskho wins!\n";
    } else {
        cout << "You lost, Rasputin keeps the battery... for now.\n";
    }

    getch();
}

int main() {
    cout << "The conveniently convenient Ol Koi manual starts explaining to Miskho that only 2 parts are missing\n";
    cout << "and the Ol Koi will be his.\n";
    cout << "The next object is the **battery**, required to make the Ol Koi works.\n";
    cout << "It is located in the **Electrical Engineering Department**.\n";
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

    carrera();
    return 0;
}
