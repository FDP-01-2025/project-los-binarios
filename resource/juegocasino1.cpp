#include <iostream>
#include <conio.h>      // _kbhit(), _getch()
#include <cstdlib>      // rand(), srand()
#include <ctime>        // time()
#include <chrono>       // chrono

using namespace std;
using namespace std::chrono;

char flechas[] = {'W', 'A', 'S', 'D'};

// Muestra qué letra representa qué dirección
void mostrarFlecha(char f) {
    cout << "\nPresiona la tecla correcta: ";
    switch (f) {
        case 'W': cout << "\033[31m- [W] = ARRIBA\033[0m\n"; break;
        case 'A': cout << "\033[32m- [A] = IZQUIERDA\033[0m\n"; break;
        case 'S': cout << "\033[33m- [S] = ABAJO\033[0m\n"; break;
        case 'D': cout << "\033[34m- [D] = DERECHA\033[0m\n"; break;
    }
    cout << "\n";
}

// Muestra los corazones de vida
void mostrarVidas(int intentos) {
    cout << "\nIntentos restantes: ";
    for (int i = 0; i < intentos; i++) cout << "<3 ";
    cout << "\n";
}

// Función de espera manual
void esperar(int milisegundos) {
    auto inicio = high_resolution_clock::now();
    while (duration_cast<milliseconds>(high_resolution_clock::now() - inicio).count() < milisegundos) {
        // espera pasiva
    }
}

// Muestra un contador regresivo de X segundos con mensaje personalizado
void contadorPerdida(int segundos, int vidasRestantes) {
    cout << "\n Perdiste un intento bro...\n";
    cout << " Te quedan " << vidasRestantes << " intento(s) bro, vos podes.\n";
    cout << "\nReanudando en: ";
    for (int i = segundos; i >= 1; i--) {
        cout << i << "... ";
        esperar(1000);
    }
    cout << "\n";
    system("cls");
}

int main() {
    srand(time(0));
    int intentos = 3;
    const int duracionJuego = 45; // segundos
    auto inicio = high_resolution_clock::now();

    // INSTRUCCIONES Y CUENTA REGRESIVA
    system("cls");
    cout << "=============================\n";
    cout << "     DESAFIO DE REACCION\n";
    cout << "=============================\n";
    cout << "\nInstrucciones:\n";
    cout << "- REACCIONA RAPIDAMEDENTE PRESIONNDO LA TECLA CORRECTA.\n";
    cout << "\033[31m- [W] = ARRIBA\033[0m\n";
    cout << "\033[32m- [A] = IZQUIERDA\033[0m\n";
    cout << "\033[33m- [S] = ABAJO\033[0m\n";
    cout << "\033[34m- [D] = DERECHA\033[0m\n";
    cout << "- SOLO TIENES UN SEGUNDO PARA RESPONDER...\n";
    cout << "- Tienes 3 intentos para sobrevivir 45 segundos\n";

    cout << "\nEl juego comienza en: ";
    for (int i = 10; i >= 1; i--) {
        cout << i << "... ";
        esperar(1000);
    }

    system("cls");

    // JUEGO PRINCIPAL
    while (intentos > 0) {
        auto ahora = high_resolution_clock::now();
        auto tiempoPasado = duration_cast<seconds>(ahora - inicio).count();
        if (tiempoPasado >= duracionJuego) {
            cout << "\n EXCELSIOR!! Sobreviviste los 45 segundos pinchipe \n";
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
                    cout << "\n:) BIEN BRO!!\n";
                } else {
                    cout << "\n:( Casi bro!! Esa no era la dirección correcta.\n";
                    intentos--;
                    fallo = true;
                }
                break;
            }
        }

        if (!presiono) {
            cout << "\n:o Muy lento bro!! Echale mas ganitas porfa.\n";
            intentos--;
            fallo = true;
        }

        if (fallo && intentos > 0) {
            contadorPerdida(5, intentos);  // mensaje y cuenta regresiva
        } else {
            esperar(500); // pausa corta antes de seguir
            system("cls");
        }
    }

    if (intentos == 0) {
        cout << "\n La regaste bro, se te fueron los 3 intentos. JUEGO TERMINDO!!\n";
    }

    return 0;
}