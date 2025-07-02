#ifndef JUEGO_LOGICA_H
#define JUEGO_LOGICA_H

#include <iostream>
#include <cstdlib>      // rand(), srand()
#include <ctime>        // time()
#include <conio.h>      // _kbhit(), _getch()
#include <chrono>
#include "juego_visual.h"

using namespace std;
using namespace std::chrono;

void iniciarJuego() {
    srand(time(0));
    int intentos = 3;
    const int duracionJuego = 45; // segundos
    auto inicio = high_resolution_clock::now();

    system("cls");
    cout << "=============================\n";
    cout << "     REACTION CHALLENGE\n";
    cout << "=============================\n";
    cout << "\nInstructions:\n";
    cout << "- REACT QUICKLY BY PRESSING THE CORRECT KEY.\n";
    cout << "\033[31m- [W] = UP\033[0m\n";
    cout << "\033[32m- [A] = LEFT\033[0m\n";
    cout << "\033[33m- [S] = DOWN\033[0m\n";
    cout << "\033[34m- [D] = RIGHT\033[0m\n";
    cout << "- YOU ONLY HAVE ONE SECOND TO ANSWER...\n";
    cout << "- YOU HAVE 3 ATTEMPTS TO SURVIVE IN 45 SECONDS\n";

    cout << "\nTHE GAME starts in: ";
    for (int i = 10; i >= 1; i--) {
        cout << i << "... ";
        esperar(1000);
    }

    system("cls");

    while (intentos > 0) {
        auto ahora = high_resolution_clock::now();
        auto tiempoPasado = duration_cast<seconds>(ahora - inicio).count();
        if (tiempoPasado >= duracionJuego) {
            cout << "\n LETS GOOOOOO!! You survived the 45 seconds cookie pookie \n";
            break;
        }

        char objetivo = flechas[rand() % 4];

        cout << "=========================\n";
        mostrarFlecha(objetivo);
        mostrarVidas(intentos);
        cout << "=========================\n";

        auto inicioFlecha = high_resolution_clock::now();
        bool presiono = false;
        bool fallo = false;

        while (duration_cast<milliseconds>(high_resolution_clock::now() - inicioFlecha).count() < 1250) {
            if (_kbhit()) {
                char tecla = toupper(_getch());
                presiono = true;
                if (tecla == objetivo) {
                    cout << "\n:) YEAH BRO!!\n";
                } else {
                    cout << "\n:( Almost bro!! That was not the correct direction.\n";
                    intentos--;
                    fallo = true;
                }
                break;
            }
        }

        if (!presiono) {
            cout << "\n:o TOO SLOW BRO!! You have to be faster if you wanna win.\n";
            intentos--;
            fallo = true;
        }

        if (fallo && intentos > 0) {
            contadorPerdida(5, intentos);
        } else {
            esperar(500);
            system("cls");
        }
    }

    if (intentos == 0) {
        cout << "\n Bro... im sorry... GAME OVER!!\n";
    }
}

#endif

/*#include "juego_logica.h"

int main() {
    iniciarJuego();
    return 0;
}