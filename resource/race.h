#define RACE_H
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "sleep.h"
using namespace std;


void track(int positionMiskho, int positionRival) {
    system("cls");
    const int finishLine = 50;
     cout << "---------------------RACE FOR THE BATTERY ---------------------\n";

    // Finish line to be print
    cout << "Finish line";
    for (int i = 0; i < finishLine; ++i) cout << "-";
    cout << "|\n";

    // Miskho
    cout << "Miskho:   |";
    for (int i = 0; i < positionMiskho; ++i) cout << " ";
    cout << "  ___/_____|___\\\\__\n";

    cout << "          |";
    for (int i = 0; i < positionMiskho; ++i) cout << " ";
    cout << " |   _     _   ___|\n";

    cout << "          |";
    for (int i = 0; i < positionMiskho; ++i) cout << " ";
    cout << " ='-( o )---( o )-'\n";

    // Guard
    cout << "Guardo:   |";
    for (int i = 0; i < positionRival; ++i) cout << " ";
    cout << "  ___/_____|___\\\\__\n";

    cout << "          |";
    for (int i = 0; i < positionRival; ++i) cout << " ";
    cout << " |   _     _   ___|\n";

    cout << "          |";
    for (int i = 0; i < positionRival; ++i) cout << " ";
    cout << " ='-( o )---( o )-'\n";

    cout << "\nPress [D] to advance!\n";
}

//takes input about speed to change dificulty of the game when the history advance
int raceGame(int rivalSpeed) {
    const int finishLine = 50; //position the character will have to get
    int positionMiskho = 0, positionRival = 0; //initial position of miskho and rasputin
    DWORD lastRivalMove = GetTickCount();
//prints the uptadet position of miskho and rasputin
    track(positionMiskho, positionRival);

    while (positionMiskho < finishLine && positionRival < finishLine) {
        if (_kbhit()) {
            char key = _getch();
            if (key == 'd' || key == 'D') {
                positionMiskho++;
                track(positionMiskho, positionRival);
            }
        }

        DWORD now = GetTickCount();
        if (now - lastRivalMove >= rivalSpeed) {
            positionRival++;
            lastRivalMove = now;
            track(positionMiskho, positionRival);
        }

        Sleep(20);
    }

    cout << "\n";
    if (positionMiskho >= finishLine && positionRival >= finishLine) {
        cout << "EPIC DRAW!\n";
        return 0;
    } else if (positionMiskho >= finishLine) {
        cout << "Miskho wins!\n";
        return 1;
    } else {
        cout << "You lost\n";
        return -1;
    }
}


int race() {
    int rivalSpeed = 400, result;
    cout << "The conveniently convenient Ol Koi manual starts explaining to Miskho that only 2 parts are missing\n";
    cout << "and the Ol Koi will be his.\n";
    cout << "The next object is the battery, required to make the Ol Koi work.\n";
    cout << "It is located in the Electrical Engineering Department.\n";
    cout << "         ||        " << endl;
    cout << "        /||\\       " << endl;
    cout << "       /_||_\\      " << endl;
    cout << "      // || \\\\     " << endl;
    cout << "     //  ||  \\\\    " << endl;
    cout << "    ||   ||   ||   " << endl;
    cout << "    ||   ||   ||   " << endl;
    cout << "    ||   ||   ||   " << endl;
    cout << "    ||   ||   ||   " << endl;
    cout << "    ||   ||   ||   " << endl;
    cout << "   /_|___||___|_\\  " << endl;
    cout << "     |   ||   |    " << endl;
    cout << "     |   ||   |    " << endl;
    cout << "     |___||___|    " << endl;
    cout << "         ||        " << endl;
    cout << "        /__\\       " << endl;
    wait(13000);
    system("cls");

    cout << "      ______             O  " << endl;
    cout << "  ___//__|__\\___       /|\\ " << endl;
    cout << " |  _        _  `       / \\" << endl;
    cout << " '-(_)------(_)--'    Rasputin" << endl;

    cout << "Rasputin: Hey Miskho! I heard you're looking for this battery.\n";
    cout << "I'm Rasputin, an electrical engineer. I just built this car.\n";
    cout << "If you win a race against me, the battery is yours!\n";
    wait(11000);
    system("cls");
    cout << "       __________________________" << endl;
    cout << "      /|                        |\\ " << endl;
    cout << "     /_|________________________|_\\ " << endl;
    cout << "    |  _   ___   ____   ___   _   |" << endl;
    cout << "    | |_|_|__|_|_|__|_|_|__|_|_|__|" << endl;
    cout << "    |                            |" << endl;
    cout << "    |KILLER SOUL (almost it)     |" << endl;
    cout << "    |____________________________|" << endl;
    cout << "   (__)                      (__)" << endl;

    wait(2500);
    system("cls");

    result = raceGame(rivalSpeed);
    wait(1000);
    system("cls");

    if (result == 1) {
        cout << "Ok, you win this time, but it won't happen again." << endl;
        cout << "Now, you'll drive this:" << endl;
         cout << "        ____________________________________" << endl;
        cout << "        |  ___    ___    ___    ___    ___   |" << endl;
        cout << "        | |   |  |   |  |   |  |   |  |   |  |" << endl;
        cout << "        | |___|  |___|  |___|  |___|  |___|  |" << endl;
        cout << "        |   _____________________________    |__" << endl;
        cout << "        |  |       SCHOOL  BUS           |      |" << endl;
        cout << "        |  |_____________________________|       |" << endl;
        cout << "        |                                        |" << endl;
        cout << "        |_______________________________________|" << endl;
        cout << "               (_______)      (_______)      " << endl;
       
        wait(7000);
        system("cls");
        cout << "Get ready, because now I will use all I have!" << endl;
    } else if (result == 0) {
        cout << "Ok, I'll admit that it was a good race. Let's run again to break the draw." << endl;
        cout << "But now, you'll drive this:" << endl;
        cout << "        ____________________________________" << endl;
        cout << "        |  ___    ___    ___    ___    ___   |" << endl;
        cout << "        | |   |  |   |  |   |  |   |  |   |  |" << endl;
        cout << "        | |___|  |___|  |___|  |___|  |___|  |" << endl;
        cout << "        |   _____________________________    |__" << endl;
        cout << "        |  |       SCHOOL  BUS           |      |" << endl;
        cout << "        |  |_____________________________|       |" << endl;
        cout << "        |                                        |" << endl;
        cout << "        |_______________________________________|" << endl;
        cout << "               (_______)      (_______)      " << endl;
        wait(7000);
        system("cls");
        cout << "Get ready, because now I will use all I have!" << endl;
    } else {
        cout << "You lost, but I'll give you another chance." << endl;
        cout << "But now, you'll drive this:" << endl;
        cout << "        ____________________________________" << endl;
        cout << "        |  ___    ___    ___    ___    ___   |" << endl;
        cout << "        | |   |  |   |  |   |  |   |  |   |  |" << endl;
        cout << "        | |___|  |___|  |___|  |___|  |___|  |" << endl;
        cout << "        |   _____________________________    |__" << endl;
        cout << "        |  |       SCHOOL  BUS           |      |" << endl;
        cout << "        |  |_____________________________|       |" << endl;
        cout << "        |                                        |" << endl;
        cout << "        |_______________________________________|" << endl;
        cout << "               (_______)      (_______)      " << endl;
        wait(7000);
        system("cls");
        cout << "Get ready, because now I will use all I have!" << endl;
    }

    rivalSpeed = 100;
    cout << "NOW IT STARTS!";
    result = raceGame(rivalSpeed);

    if (result == 1) {
        cout << "That was quite impressive. I have no doubt you deserve this." << endl;
        cout << "  ___________" << endl;
        cout << " |           |" << endl;
        cout << " |   AA      |" << endl;
        cout << " |  _______  |" << endl;
        cout << " | |       | |" << endl;
        cout << " | |       | |" << endl;
        cout << " | |_______| |" << endl;
        cout << " |           |" << endl;
        cout << " |___________|" << endl;
        wait(6000);
        system("cls");
        cout << "Continue your adventure, you are close to getting what you want." << endl;
        wait(3500);
        system("cls");
    } else if (result == 0) {
        cout << "Well well, that was intense!" << endl;
        cout << "I think you did a spectacular race, that's why I'll give you what you want." << endl;
        cout << "  ___________" << endl;
        cout << " |           |" << endl;
        cout << " |   AA      |" << endl;
        cout << " |  _______  |" << endl;
        cout << " | |       | |" << endl;
        cout << " | |       | |" << endl;
        cout << " | |_______| |" << endl;
        cout << " |           |" << endl;
        cout << " |___________|" << endl;
        wait(8000);
        system("cls");
        cout << "Continue your adventure, you are close to getting what you want." << endl;
    } else {
        cout << "You lost in the clutch time. You don't deserve this." << endl;
        cout << "Go back and try again if you want (or if you can)." << endl;
        wait(8000);
        system("cls");
        cout<<"press any key to return to main menu...";
        getch();
        //if you lose the race retruns 0
        return 0;
    }
    cout<<"press any key to return to main menu...";
    getch();
    // wins return 1
    return 1;
}
