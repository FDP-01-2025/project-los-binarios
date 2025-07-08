#include <iostream>
#include <fstream>
#include <conio.h>
#include <cctype>
#include "carrera.h"
#include "archery.h"
#include "prologue.h"
#include "menu.h"
#include "juegoscasino.h"
#include "statues.h"
#include "finalBattle.h"
#include "softia.h"
#include "chubby.h"
using namespace std;

struct Player {
    int progress = 0;
    float money = 5;
};

Player jugador;

int historia(int progress) {
    switch (progress) {
        case 0:
            progress += prologue(); break;
        case 1:
            progress += statues(); break;
        case 2:
            progress += archery();
            jugador.money -= 4; 
            break;
        case 3:
            progress += casino(); 
            if(progress>3){
                jugador.money += 100;
            } 
            break;
        case 4:
            progress += chubby(); break;
        case 5:
            progress += race(); break; 
        case 6: 
            progress += softia(); break;
        case 7:
            progress += battle(); break;
        default:
            cout << "You have completed the game!\n";
            break;
    }
    return progress;
}

bool nombreValido(const string& nombre) {
    for (char c : nombre) {
        if (!isalnum(c)) return false;
    }
    return true;
}




void save() {
    string nameGame;
    cout << "File name: ";
    cin >> nameGame;

    if (!nombreValido(nameGame)) {
        cout << "Invalid file name, please use only numbers and letters\n";
        return;
    }

    ofstream archivo(nameGame + ".txt");
    if (archivo.is_open()) {
        archivo << nameGame << " "
                << jugador.progress << " "
                << jugador.money << "\n";

        archivo.close();
        cout << "Game saved successfully.\n\n";
    } else {
        cout << "Failed to save the game. :(\n";
    }
    
}


bool load() {
    string fileName;
    cout << "File name (without .txt): ";
    cin >> fileName;

    ifstream archivo(fileName + ".txt");
    string nameGame;

    if (archivo.is_open()) {
        if (archivo >> nameGame >> jugador.progress >> jugador.money) {
            cout << "Loaded: Level = " << jugador.progress << ", Money = $" << jugador.money << endl;
            archivo.close();
            return true;
        } else {
            cout << "Error\n";
            archivo.close();
            return false;
        }
    } else {
        cout << "File could not be opened.\n";
        return false;
    }
    
}


int main() {
    int opcion;

    do {
        opcion = menu();

        switch (opcion) {
            case 1:
                jugador.progress = 0;
                jugador.money = 5;
                jugador.progress = historia(jugador.progress);
                break;
            case 2:
                if(jugador.progress == 0){
                    cout<<"Game hasn't been played yet. Starting now...\n";
                    wait(1000);
                    system("cls");
                }
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
