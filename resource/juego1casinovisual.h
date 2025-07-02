#ifndef JUEGO_VISUAL_H
#define JUEGO_VISUAL_H

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

char flechas[] = {'W', 'A', 'S', 'D'};

// Muestra qué letra representa qué dirección
void mostrarFlecha(char f) {
    cout << "\nPress the correct key: ";
    switch (f) {
        case 'W': cout << "\033[31m- [W] = UP\033[0m\n"; break;
        case 'A': cout << "\033[32m- [A] = LEFT\033[0m\n"; break;
        case 'S': cout << "\033[33m- [S] = DOWN\033[0m\n"; break;
        case 'D': cout << "\033[34m- [D] = RIGHT\033[0m\n"; break;
    }
    cout << "\n";
}

// Muestra los corazones de vida
void mostrarVidas(int intentos) {
    cout << "\nATTEMPTS: ";
    for (int i = 0; i < intentos; i++) cout << "<3 ";
    cout << "\n";
}

// Espera activa (sin dormir el hilo)
void esperar(int milisegundos) {
    auto inicio = high_resolution_clock::now();
    while (duration_cast<milliseconds>(high_resolution_clock::now() - inicio).count() < milisegundos) {
        // espera pasiva
    }
}

// Muestra el mensaje de error y una cuenta regresiva
void contadorPerdida(int segundos, int vidasRestantes) {
    cout << "\n You lost an attempt bro...\n";
    cout << " you have " << vidasRestantes << " attempt(s) left bro, YOU GOT IT.\n";
    cout << "\nResuming in: ";
    for (int i = segundos; i >= 1; i--) {
        cout << i << "... ";
        esperar(1000);
    }
    cout << "\n";
    system("cls");
}

#endif