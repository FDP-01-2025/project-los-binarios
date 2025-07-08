#define ARCHERY_H
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include "sleep.h"
using namespace std;

//generates the random position of the arrow
int randomPosition() {
    return 1 + rand() % 3; 
}
//shows where the cube is
void background(int arrow, int square, string arrows[]) {
    system("cls");

    cout << "=============================\n";
    cout << (square == 1 ? "       ⬜" : "          ") << "\n";
    cout << "    " << arrows[arrow - 1];
    if (square == 2)
        cout << "    ⬜";
    cout << "\n";
    cout << (square == 3 ? "       ⬜" : "          ") << "\n";

    cout << "=============================\n";
    cout << "Press X when you consider the arrow points to the target\n";
}
//the principal game
bool game(int speed) {
    string arrows[] = { "↗", "→", "↘" };
    int arrow, square;
    bool done = false;

    int maxTime = 8;
    int time = 0;

    int steps = speed / 100;
    if(steps < 1) steps = 1;

    while (time < maxTime && !done) {
        arrow = randomPosition();
        square = randomPosition();

        background(arrow, square, arrows);

        for (int i = 0; i < steps; ++i) {
            if (_kbhit()) { //detects if any key was pressed, in case it was pressed, evaluated if the key pressed was x
                char tecla = _getch();
                if (tecla == 'x' || tecla == 'X') {
                    return arrow == square;
                }
            }
            wait(100);
        }
        //
        time++;
    }

    return false;
}

int archery(){
    srand(time(0));
    SetConsoleOutputCP(CP_UTF8);

    int instruction=1, aux=1;
    cout << "The Conveniently Convenient Manual tells Miskho that the first part of the Ol' Koi is in the UCA Sports Center." << endl;
    cout << "Miskho's adventure begins..." << endl;
    wait(8000);
    system("cls");
    cout << "        _________________________________________        \n";
    cout << "       |                                         |       \n";
    cout << "       |                                         |       \n";
    cout << "       |                                         |       \n";
    cout << "       |                                         |       \n";
    cout << "       |                                         |       \n";
    cout << "       |                                         |       \n";
    cout << "       |   ___                              ___  |       \n";
    cout << "       |  |   |                            |   | |       \n";
    cout << "       |  |   |                            |   | |       \n";
    cout << "       |  |___|                            |___| |       \n";
    cout << "       |                                         |       \n";
    cout << "       |   O       O                             |       \n";
    cout << "       |  /|\\    /|\\                           |       \n";
    cout << "       |  / \\    / \\                           |       \n";
    cout << "       |_________________________________________|       \n";
    cout << "                    UCA FUTBOL FIELD           \n";

    cout << "Manual: You'll have to face Mister T in an archery competition to get the golden joystick." << endl;
    Beep(1500,200);
    cout << "Mister T: Hey Miskho, I've been waiting for you." << endl;
    wait(7000);
    system("cls");
    cout << "Miskho: Who are you?" << endl;
    cout << "Mister T: I'm Oscar Tired, better known as Mister T. I suppose you know exactly what's about to happen." << endl;

    do {
        cout << "Mister T: Do you want me to explain the rules?" << endl;
        cout << "1. Yes\n2. No" << endl;
        cin >> instruction;
        if(instruction == 1){
            cout << "Well, I'll explain..." << endl;
            wait(1000);
            system("cls");
            cout << "Mister T: A few years ago, I was the national archery champion. I loved it — this means EVERYTHING to me." << endl;
            cout << "         )" << '\n';
            cout << "      //  |>" << '\n';
            cout << "     //   |" << '\n';
            cout << "    (     |" << '\n';
            cout << "     \\   |" << '\n';
            cout << "      \\  |>" << '\n';
            cout << "         )" << '\n';
            wait(6500);
            system("cls");
            cout << "The Emperor gave me this as a gift after I became champion:" << endl;
            cout << "      _______\n";
            cout << "     /       \\\n";
            cout << "    |         |\n";
            cout << "    |         |\n";
            cout << "     \\        /\n";
            cout << "      -------\n";
            cout << "         |\n";
            cout << "         |\n";
            cout << "        / \\\n";
            cout << "       /   \\\n";
            cout << "      /_____\\" << endl;
            cout<<"         JOYSTICK"<<endl;
            wait(5000);
            system("cls");
            cout << "Anyone who wants it must beat me in an archery match." << endl;
            cout << "It's not that hard — an arrow will appear on screen, moving constantly, and also a target." << endl;
            wait(7000);
            system("cls");
            cout << "You'll shoot by pressing 'x' at the perfect moment. You need to win 5 rounds." << endl;
            cout << "But if you lose even one, it's over." << endl;
            cout << "You'll have a maximum of five seconds to press 'x'." << endl;
            do {
                cout << "Everything clear? Or do you need another explanation?" << endl;
                cout << "1. Everything's clear\n2. I need another explanation" << endl;
                cin >> aux;
                if(aux != 1 && aux != 2){
                    cout << "Invalid option" << endl;
                }
                else if(aux == 2){
                    wait(1000);
                    cout << "...";
                    wait(1500);
                    cout << " Mister T: Well, there isn't another explanation!" << endl;
                    wait(3000);
                    system("cls");
                }
            } while(aux != 1 && aux != 2);
        }
        else if(instruction != 1 && instruction != 2){
            cout << "Invalid option" << endl;
        }
    } while(instruction != 1 && instruction != 2);

    cout << "Mister T: So, GET READY FOR AN INTENSE BATTLE!" << endl;
    wait(3000);
    //counter of wins
    int wins = 0;
    //state of the game
    bool perder = false;
    //speed of arrows changing position
    int velocidad = 700;

    while (wins < 5 && !perder) {
        cout << "\nRound " << (wins + 1) << " of 5. Get ready!" << endl;
        wait(1500);
        system("cls");

        if (game(velocidad)) {
            wins++;
            cout << "Well done! You won this round!\n";
            velocidad -= 50;
        } else {
            perder = true;
            cout << "You failed... Mister T wins this time.\n";
        }

        wait(2500);
        system("cls");
    }

    cout << "But..." << endl;
    cout << "Something's wrong... IT'S MISTER T HAVING A SUGAR LOW!" << endl;
    cout << "Random background character: Oh no, not again! Hurry, Miskho — get him a Coke!" << endl;
    wait(2000);
    cout << "     _______\n";
    cout << "    /       \\\n";
    cout << "   |         |\n";
    cout << "   |  C O L A|\n";
    cout << "   |         |\n";
    cout << "    \\_______/\n";
    cout << "    |       |\n";
    cout << "    |       |\n";
    cout << "    |       |\n";
    cout << "    |_______|\n";
    wait(9000);
    system("cls");
    cout << "Thanks, Miskho... I really get excited with this stuff." << endl;
    cout << "You really saved me this time. I don't care if you won or lost." << endl;
    cout << "I think I have something for you. Give me a second..." << endl;
    wait(8000);
    system("cls");
    cout << "Here's the golden joystick — you deserve it!" << endl;
    cout << "Now go, continue with your bizarre adventure." << endl;
    wait(5000);

    cout << "\nPress any key to exit...";
    getch();
    //retuns 1 because it menas game win and advance history
    return 1;
}
