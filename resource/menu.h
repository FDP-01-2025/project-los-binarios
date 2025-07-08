#define MENU_H
#pragma once
#include <iostream>
#include <windows.h>
#include "sleep.h"
using namespace std;

//will show this after every part of the history
int menu() {
    int option;
    do{
    system("cls"); 
    cout << "\n\n";
    cout << "================================================\n";
    cout << "        Miskho Jhones: The Missing Ol Koi\n";
    cout << "================================================\n\n";
    wait(500);
    cout << "               [1] New Game\n";
    wait(500);
    cout << "               [2] Continue Game\n";
    wait(500);
    cout << "               [3] Load Game\n";
    wait(500);
    cout << "               [4] Save Game\n";
    wait(500);
    cout << "               [5] Exit\n";
    cout << "\n                    ";
    cin >> option;

    switch(option) {
        case 1:
            cout << "\nStarting new game...\n";
            wait(1000);
            system("cls");
            break;
        case 2:
            cout << "\nContinue Playing...\n";
            wait(1000);
            system("cls");
            break;
        case 3:
            cout << "\nLoading game...\n";
            wait(1000);
            system("cls");
            break;
        case 4:
            cout << "\nSaving game...\n";
            wait(1000);
            system("cls");
            break;
        case 5:
            cout << "\nExiting game. Goodbye!\n";
            wait(1000);
            system("cls");
            break;
        default:
            cout << "\nInvalid option.\n";
            wait(1000);
            break;
    }
}while(option<1||option>5);
    //returns option because thats decide what is the main gonna do
    return option;
}
