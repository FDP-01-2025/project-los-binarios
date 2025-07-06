#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// Slot with number and color
struct Slot {
    int number;
    string color;  // "red" or "blue"
};

// Create roulette with alternating red and blue colors
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

// Wait function using clock()
void waitSeconds(int seconds) {
    clock_t end = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < end) { /* busy wait */ }
}

// Force a win if money is too low
Slot forceWinSlot(const vector<Slot>& wheel, const string& color, const vector<int>& numbers) {
    for (const Slot& s : wheel) {
        if (!color.empty() && s.color == color) return s;
        if (!numbers.empty() && find(numbers.begin(), numbers.end(), s.number) != numbers.end()) return s;
    }
    return wheel[rand() % wheel.size()];
}

int main() {
    srand(time(0));
    double money = 100.0;
    vector<Slot> wheel = generateRoulette();
    bool forceWin = false;

    while (money > 0) {
        cout << "\nCurrent balance: $" << money << "\n";
        cout << "Choose your bet:\n";
        cout << "1. Bet on specific numbers ($5 each)\n";
        cout << "2. Bet on RED ($25)\n";
        cout << "3. Bet on BLUE ($25)\n";
        cout << "Enter option: ";
        int option;
        cin >> option;

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

        cout << "\nResult: ";
        if (result.color == "red") {
            cout << "\033[31m" << result.number << "\033[0m\n";
        } else {
            cout << "\033[34m" << result.number << "\033[0m\n";
        }

        bool won = false;

        if (option == 1) {
            if (find(picks.begin(), picks.end(), result.number) != picks.end()) {
                cout << "You WON $100!\n";
                money += 100;
                won = true;
            } else {
                cout << "You lost this bet.\n";
            }
        } else {
            if (result.color == chosenColor) {
                cout << "You WON $100!\n";
                money += 100;
                won = true;
            } else {
                cout << "You lost this bet.\n";
            }
        }

        if (won) {
            cout << "\nGAME OVER. Final balance: $" << money << "\n";
            break;
        }
    }

    if (money <= 0) {
        cout << "\nYou lost all your money. Game over.\n";
    }

    return 0;
}