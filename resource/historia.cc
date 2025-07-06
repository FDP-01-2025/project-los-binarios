#include <iostream>
#include <fstream>
#include <conio.h>
#include <cctype>
#include "carrera.h"
#include "poli.h"
#include "prologo.h"
#include "menu.h"
using namespace std;

struct Player {
    int progress = 0;
    float money = 5;
};

Player jugador;

int historia(int progress) {
    switch (progress) {
        case 0:
            progress += pro(); break;
        case 1:
            progress += pro(); break;
        case 2:
            progress += archery(); break;
        case 3:
            progress += pro(); break;
        case 4:
            progress += pro(); break;
        case 5:
            progress += race(); break;
        case 6:
            progress += pro(); break;
        default:
            cout << "¡Has completado todas las misiones!\n";
            break;
    }
    return progress;
}




void save() {
    
}


bool load() {
    
}


int main() {
    int opcion;

    do {
        opcion = menu();

        switch (opcion) {
            case 1:
                jugador.progress = historia(jugador.progress);
                break;
            case 2:
                jugador.progress = historia(jugador.progress);
                break;
            case 3:
                if (load()) {
                    jugador.progress = historia(jugador.progress);
                }
                break;
            case 4:
                save();
                break;
        }

    } while (opcion != 5); 

    return 0;
}
