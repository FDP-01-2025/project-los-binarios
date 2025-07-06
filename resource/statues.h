#define STATUES_H
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

void narrateIntro() {
    cout << "=== Misko Jhones and the Conveniently Convenient Trial of the Glowing Statues ===\n";
    Sleep(2000);
    cout << "\nNarrator: You find yourself in the dark, dusty basement of the university library...\n";
    Sleep(3000);
    cout << "Narrator: In front of you stand ancient statues...\n";
    Sleep(2000);
    cout << "Narrator: Their glowing eyes seem to follow your every move.\n";
    Sleep(3000);
    cout << "Narrator: You must sneak past them to reach the legendary manual...\n";
    Sleep(3000);
    cout << "\nNarrator: Listen carefully.\n";
    Sleep(2000);
    cout << "Narrator: Move by pressing 'w' repeatedly... but only when the statues close their eyes.\n";
    Sleep(4000);
    cout << "Narrator: If they see you move... they will turn you to stone instantly.\n";
    Sleep(4000);
    cout << "Narrator: Do not press any key when their eyes are watching.\n";
    Sleep(3000);
    cout << "Narrator: You only have 30 total chances to move. Use them wisely.\n";
    Sleep(3000);
    cout << "\nNarrator: Your trial begins... now.\n\n";
    Sleep(3000);
}

bool playStatueGame(bool showIntro) {
    const int maxSteps = 30;
    const int requiredSteps = 30;
    int steps = 0;
    int totalKeyPresses = 0;

    if (showIntro) narrateIntro();

    while (true) {
        if (totalKeyPresses >= maxSteps) {
            cout << "\nYou've exhausted your 30 steps without reaching the end.\n";
            cout << "The statues awaken and turn you to stone.\n";
            cout << "\n===🥀💀 MISKO-DEATH 💀🥀===\n";
            return false;
        }

        bool eyesClosed = rand() % 2 == 0;
        if (eyesClosed)
            cout << "The statues' eyes are closed... Move now! (press 'w' multiple times)\n";
        else
            cout << "The statues are watching! DO NOT MOVE!\n";

        int duration = 4000;
        int interval = 50;

        for (int i = 0; i < duration / interval; ++i) {
            if (totalKeyPresses >= maxSteps) break;

            if (_kbhit()) {
                char key = _getch();
                if (key == 'w' || key == 'W') {
                    totalKeyPresses++;
                    if (eyesClosed) {
                        if (steps < requiredSteps) {
                            steps++;
                            cout << "Step taken! Progress: " << steps << "/" << requiredSteps << "\n";
                        }
                    } else {
                        cout << "\n===🥀💀 MISKO-DEATH 💀🥀===\n";
                        cout << "You moved while the statues were watching. You are now a stone decoration.\n";
                        return false;
                    }
                }
            }
            Sleep(interval);
        }

        if (steps >= requiredSteps) {
            cout << "\nYou have passed the trial of the statues.\n";
            return true;
        }

        Sleep(1000);
        cout << "-----------------------------\n";
    }
}

bool finalBookPuzzle() {
    cout << "\nA mysterious glowing figure appears...\n";
    Sleep(2000);
    cout << "\"...You did it, Misko...\"\n";
    Sleep(2000);
    cout << "\"I am the Conveniently Convenient Guardian of the Ol' Koi Manual, but you can call me Roberto.\"\n";
    Sleep(3000);
    cout << "\"You have completed the trial of the glowing statues.\"\n";
    Sleep(3000);
    cout << "\"Now, only one task remains.\"\n";
    Sleep(2000);
    cout << "\"Before you are four books. One of them contains the knowledge of the Ol' Koi...\"\n";
    Sleep(3000);
    cout << "Choose a book:\n";
    cout << "1. Cooking with Koi\n2. The History of Convenient Things\n3. Ol' Koi Manual: Possibly Real Edition\n4. Gardening for the Lazy\nYour choice: ";

    int choice;
    cin >> choice;

    if (cin.fail() || choice < 1 || choice > 4) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\n\"That... was not a valid book. Try again from the beginning.\"\n";
        return false;
    }

    if (choice == 3) {
        Sleep(2000);
        cout << "\n\"You have chosen... wisely.\"\n";
        Sleep(3000);
        cout << "\nThe floor begins to shake violently...\n";
        Sleep(2000);
        cout << "\"Misko! You must escape!\"\n";
        Sleep(2000);
        cout << "\"No... I shall stay. I owe 24 years of child support. This is my destiny.\"\n";
        Sleep(3000);
        cout << "\nMisko: \"ROBERTOOOOO!! I will find the Ol' Koi... for you.\"\n";
        Sleep(2000);
        cout << "*Tears stream down Misko's face as the library crumbles...*\n";
        return true;
    } else {
        cout << "\n\"Incorrect. The true path must be walked again...\"\n";
        return false;
    }
}

int statues() {
    srand(time(0));
    bool won = false;
    bool firstTime = true;
    char retry;

    while (!won) {
        bool passedStatues = playStatueGame(firstTime);
        firstTime = false;

        if (!passedStatues) {
            cout << "\n===🥀💀 MISKO-DEATH 💀🥀===\n";
            cout << "You died. Would you like to try again? (y/n): ";
            cin >> retry;
            if (retry == 'n' || retry == 'N') {
                cout << "Returning to the main menu...\n";
                return 0;
            }
            continue;
        }

        cout << "\n===========================\n";
        cout << "Now preparing for the final challenge...\n";
        Sleep(2000);

        if (finalBookPuzzle()) {
            won = true;
            return 1;
        } else {
            cout << "\nYou failed to choose the correct book. The trial begins anew...\n\n";
            Sleep(2000);
        }
    }

    return 0; 
}
