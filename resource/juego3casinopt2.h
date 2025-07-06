#ifndef juego3casinopt2_h
#define juego3casinopt2_h

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "juego3casinopt3.h"
using namespace std;

struct Slot {
    int number;
    string color; // "red" or "blue"
};

vector<Slot> generateRoulette() {
    vector<int> nums;
    for (int i = 1; i <= 35; i++) nums.push_back(i);
    random_shuffle(nums.begin(), nums.end());

    vector<Slot> wheel;
    for (int i = 0; i < 35; i++) {
        Slot s;
        s.number = nums[i];
        s.color = (i % 2 == 0) ? "red" : "blue";
        wheel.push_back(s);
    }
    return wheel;
}

// ✅ ESTA ES LA FUNCIÓN QUE INSERTASTE
Slot forceWinSlot(const vector<Slot>& wheel, const string& color, const vector<int>& numbers) {
    for (const Slot& s : wheel) {
        if (!color.empty() && s.color == color) return s;
        if (!numbers.empty() && find(numbers.begin(), numbers.end(), s.number) != numbers.end()) return s;
    }
    return wheel[rand() % wheel.size()];
}

void displayResult(const Slot& result) {
    cout << "\nResult: ";
    if (result.color == "red") {
        cout << "\033[31m" << result.number << "\033[0m\n";
    } else {
        cout << "\033[34m" << result.number << "\033[0m\n";
    }
}

void playRoulette(double& money) {
    srand(time(0));
    vector<Slot> wheel = generateRoulette();
    bool forceWin = false;
    double initialMoney = money;

    while (money > 0) {
        cout << "\nCurrent balance: $" << money << "\n";


        if (money - initialMoney >= 500) {
            cout << "\nYOU WON TOO MUCH, BRO! The casino can't pay you more than $500 in winnings, the economy is broken bro.\n";
            cout << "Here is your $500 profit. GO HOME AND STOP GAMBLING.\n";
            money = initialMoney + 500;
            break;
        }

        if (money - initialMoney >= 300) {
            char choice;
            cout << "You’ve won at least $300! Do you want to retire? (Yes or no): ";
            cin >> choice;
            if (toupper(choice) == 'Y') {
                cout << "You retired with $" << money << ". Nice move, bro.\n";
                break;
            }
        }

        cout << "Choose your bet:\n";
        cout << "1. Bet on specific numbers ($5 each)\n";
        cout << "2." << "\033[31m ALL ON RED ($25)\033[0m\n";
        cout << "3." << "\033[34m ALL ON BLUE ($25)\033[0m\n";
        cout << "Enter option: ";
        int option;
        cin >> option;

        if (cin.fail()) {
    cin.clear();                   // Limpia el estado de error
    cin.ignore(10000, '\n');       // Descarta caracteres inválidos
    cout << "Invalid input. Please enter a number between 1 and 3.\n";
    continue;
}

        vector<int> picks;
        string chosenColor;
        double bet = 0;

        if (option == 1) {
            int count;
            cout << "How many numbers do you want to bet on? ";
            cin >> count;
            bet = count * 5;
            if (bet > money || count <= 0) {
                cout << "Invalid count or insufficient funds.\n";
                continue;
            }

            cout << "Enter " << count << " numbers between 1 and 35:\n";
            int num;
            for (int i = 0; i < count; i++) {
                cin >> num;
                if (num >= 1 && num <= 35) {
                    picks.push_back(num);
                } else {
                    cout << "Invalid number. Try again.\n";
                    i--;
                }
            }
        } else if (option == 2 || option == 3) {
            bet = 25;
            if (bet > money) {
                cout << "Not enough money.\n";
                continue;
            }
            chosenColor = (option == 2) ? "red" : "blue";
        } else {
            cout << "Invalid option.\n";
            continue;
        }

        if (money <= 25) forceWin = true;
        money -= bet;

        cout << "\nSpinning the roulette...\n";
        waitSeconds(5);

        Slot result = forceWin
            ? forceWinSlot(wheel, chosenColor, picks)
            : wheel[rand() % wheel.size()];

        displayResult(result);

        bool won = false;
        if (option == 1) {
            if (find(picks.begin(), picks.end(), result.number) != picks.end()) {
                cout << "YOU WON $100!\n";
                money += 100;
                won = true;
            } else {
                cout << "You lost this bet.\n";
            }
        } else {
            if (result.color == chosenColor) {
                cout << "YOU WON $100!\n";
                money += 100;
                won = true;
            } else {
                cout << "You lost this bet.\n";
            }
        }

        if (forceWin && won) {
            cout << "\nThat was your comeback round!\n";
            break;
        }
    }

    if (money <= 0) {
        cout << "\nYou lost everything. GAME OVER.\n";
    }
}

#endif