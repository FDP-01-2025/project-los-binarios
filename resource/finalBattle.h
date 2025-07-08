#ifndef FINALBATTLE_H
#define FINALBATTLE_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

// Maximum AURA value for both Misko and The Watcher
const int MAX_AURA = 150;

//  Clears the console screen
void clearScreen() {
    system("cls");
}

// 🔋Displays the AURA bar for a character using '#' and '-'
void showAuraBar(string name, int aura) {
    int totalBars = 40;
    int filledBars = (aura * totalBars) / MAX_AURA;

    cout << name << " [";
    for (int i = 0; i < totalBars; ++i) {
        cout << (i < filledBars ? '#' : '-');
    }
    cout << "] AURA: " << aura << "/" << MAX_AURA << endl;
}

//Clears any remaining keyboard input
void clearInputBuffer() {
    while (_kbhit()) _getch();
}

// Waits for a key press within the given time limit (in seconds)
char readKeyWithTimeout(int seconds) {
    char key = '\0';
    int attempts = seconds * 10;

    for (int i = 0; i < attempts; ++i) {
        Sleep(100);
        if (_kbhit()) {
            key = _getch();
            break;
        }
    }
    return key;
}

//  dodge a laser by pressing key '5' quickly
bool dodgeLaser() {
    SetConsoleOutputCP(CP_UTF8);
    cout << "THE WATCHER IS CHARGING A LASER BEAM!!! ⚠️⚡" << endl;
    Sleep(2000);
    cout << "DODGE IT! Press the key '5' quickly to avoid damage 🏃‍♂️💨" << endl;

    char c;
    bool dodged = false;

    for (int i = 0; i < 30; ++i) {
        Sleep(100);
        if (_kbhit()) {
            c = _getch();
            if (c == '5') {
                dodged = true;
                break;
            }
        }
    }
    return dodged;
}

// title screen
void showStartScreen() {
    clearScreen();
    SetConsoleOutputCP(CP_UTF8);
    cout << "\n🌀  PRESENTS: MISKO JHONES VS THE WATCHER 🕶️\n";
    cout << "\nPress any key to start..." << endl;
    _getch();
}

//  story intro
void showStory() {
    SetConsoleOutputCP(CP_UTF8);
    clearScreen();
    cout << "📜 STORY\n\n";
    cout << "The Watcher assigns Misko Jhones to mission: find the OL KOI." << endl;
    Sleep(4000);
    cout << "Misko finds it. It looks like a Nintendo Switch, but it isn't." << endl;
    Sleep(4000);
    cout << "As he starts assembling it, The Watcher appears, floating." << endl;
    Sleep(4000);
    cout << "\"Thank you, Misko... with this, I shall reset the universe,\" he says with a sorrowful smile." << endl;
    Sleep(4000);
    cout << "Misko throws a stone and retrieves the OL KOI. The final battle begins!" << endl;
    Sleep(4000);
    cout << "🔥 THE WATCHER'S RESET 🔥\n" << endl;
    cout << "Press any key to fight..." << endl;
    _getch();
}

//  Displays the ending depending on whether Misko won
void showGameEnding(bool miskoWon) {
    SetConsoleOutputCP(CP_UTF8);
    clearScreen();

    if (miskoWon) {
        cout << "Misko is badly wounded on the rooftop..." << endl;
        Sleep(3000);
        cout << "The OL KOI falls to the ground, still glowing." << endl;
        Sleep(3000);
        cout << "Misko crawls toward it with his last ounce of strength..." << endl;
        Sleep(4000);
        cout << "On its screen appears:\n" << endl;
        Sleep(4000);
        cout << "🌀 MISKO JHONES: The Missing Ol Koi 🌀" << endl;
        cout << "Play?" << endl;
    } else {
        cout << "💀 MISKO DEATH 💀" << endl;
        Sleep(2000);
    }
}

bool startGame() {
    SetConsoleOutputCP(CP_UTF8);
    srand(static_cast<unsigned int>(time(nullptr)));

    string player = "Misko Jhones";
    string enemy = "The Watcher";
    int playerAura = MAX_AURA;
    int enemyAura = MAX_AURA;
    bool chargingAttack = false;
    bool defending = false;

    showStartScreen();
    showStory();

    while (playerAura > 0 && enemyAura > 0) {
        clearScreen();
        showAuraBar(player, playerAura);
        showAuraBar(enemy, enemyAura);

        // Player turn
        cout << "\n--- " << player << " ---" << endl;
        cout << "1. Hit | 2. Defend | 3. Charge Attack | 4. Heal" << endl;
        cout << "Press a key (1-4) within 3 seconds: ";

        clearInputBuffer();
        char option = readKeyWithTimeout(3);
        cout << option << endl;
        Sleep(1000);
        clearScreen();

        if (option == '\0') {
            cout << "You took too long! The Watcher is preparing to attack..." << endl;
        } else {
            // Player action
            switch (option) {
                case '1': {
                    int damage = rand() % 15 + 5;
                    if (chargingAttack) {
                        damage *= 2;
                        chargingAttack = false;
                        cout << "Charged attack! 💥" << endl;
                    }
                    cout << "You dealt a blow of " << damage << " to " << enemy << "." << endl;
                    enemyAura -= damage;
                    break;
                }
                case '2':
                    defending = true;
                    cout << "Shield activated! You are protected. 🛡️" << endl;
                    break;
                case '3':
                    chargingAttack = true;
                    cout << "Charging attack! ⚡" << endl;
                    break;
                case '4': {
                    int healing = rand() % 15 + 10;
                    playerAura += healing;
                    if (playerAura > MAX_AURA) playerAura = MAX_AURA;
                    cout << "You recovered " << healing << " of AURA. ✨" << endl;
                    break;
                }
                default:
                    cout << "Invalid option. You lost your turn." << endl;
                    break;
            }
        }

        Sleep(2000);
        clearScreen();

        if (enemyAura <= 0) break;

        // Enemy turn
        showAuraBar(player, playerAura);
        showAuraBar(enemy, enemyAura);
        cout << "\n--- " << enemy << " ---" << endl;

        if (defending) {
            cout << "AN ATTACK IS INCOMING... 💨" << endl;
            Sleep(1500);
            cout << "Shield completely blocked the attack! 🛡️✨" << endl;
            defending = false;
        } else {
            // 20% chance of laser attack
            if (rand() % 100 < 20) {
                bool dodged = dodgeLaser();
                if (dodged) {
                    cout << "YOU DODGED THE LASER LIKE A PRO! 😎🔥" << endl;
                } else {
                    int laserDamage = rand() % 25 + 15;
                    cout << "ZAAAP!!! LASER BEAM: -" << laserDamage << " AURA 💀" << endl;
                    playerAura -= laserDamage;
                }
            } else {
                cout << "AN ATTACK IS INCOMING... 💨" << endl;
                Sleep(1500);
                int enemyDamage = rand() % 15 + 5;
                cout << "The Watcher hits you and takes away " << enemyDamage << " AURA. 💢" << endl;
                playerAura -= enemyDamage;
            }
        }

        if (playerAura < 0) playerAura = 0;
        Sleep(2000);
    }

    bool miskoWon = playerAura > 0;
    showGameEnding(miskoWon);
    return miskoWon;
}

// 🔁 Main game loop allowing retries if the player loses
// Returns 1 if the player wins, 0 if they lose and choose not to retry
int loopGame() {
    while (true) {
        bool won = startGame();

        if (won) {
            return 1; //  Won at least one game
        }

        //  Lost, ask to retry
        if (_kbhit()) _getch(); // Clear key buffer
        cout << "\nDo you want to try again? (Y/N): ";
        char response;
        cin >> response;

        if (response != 'Y' && response != 'y') {
            cout << "\nThe universe has been reset. The Watcher has fulfilled his purpose..." << endl;
            Sleep(3000);
            cout << "But in the new world... someone awakens.\nName: MISKO JHONES" << endl;
            cout << "\nAnd the cycle starts again..." << endl;
            return 0; //  Lost and chose not to continue
        }
    }
}

// 
int battle() {
    return loopGame();
}

#endif
