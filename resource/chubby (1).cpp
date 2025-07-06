#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <conio.h> 

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

const int WIDTH = 40;
const int TOTAL_FLOORS = 3;
int playerX, chaserX, jumpTurns, chaserCycles, currentFloor, goalX;
vector<int> obstacles;

void clearScreen() {
    system("cls"); 
}

void showStory() {
    clearScreen();
    cout << "Narrator:\n";
    sleep_for(seconds(1));
    cout << "Misko, now with enough money, enters Magna 7,\n";
    sleep_for(seconds(2));
    cout << "and asks to speak with José María.\n";
    sleep_for(seconds(2));
    cout << "He's taken to a room on the top floor where she is...\n";
    sleep_for(seconds(3));
    cout << "and upon opening the door, Misko sees her sitting at a desk,\n";
    sleep_for(seconds(3));
    cout << "from which the Joystick can be seen in a small glass dome.\n";
    sleep_for(seconds(3));
    cout << "Misko explains his need, but she refuses to give him the Joystick,\n";
    sleep_for(seconds(3));
    cout << "because it was the last thing her beloved husband Roberto left her,\n";
    sleep_for(seconds(3));
    cout << "before escaping and disappearing forever.\n";
    sleep_for(seconds(3));
    cout << "Misko tells her he knows Roberto...\n";
    sleep_for(seconds(2));
    cout << "but she gets upset for meddling with her feelings and gordis illusions 😡,\n";
    sleep_for(seconds(3));
    cout << "and kicks him out of her room!\n";
    sleep_for(seconds(2));
    cout << "Misko breaks the glass, grabs the Joystick and starts running...\n";
    sleep_for(seconds(3));
    cout << "This is where the chase begins: ESCAPE FROM THE CHUBBY! 🚓🏃‍♂️\n";
    sleep_for(seconds(3));
}

void showInstructions() {
    clearScreen();
    cout << "🕹️  Game Instructions:\n\n";
    cout << "➡️  Press 'd' to move forward\n";
    cout << "🥴️  Press 'w' to JUMP over obstacles (jump two spaces forward)\n";
    cout << "🪨  If you hit a rock without jumping, you lose\n";
    cout << "🚓  If the evil chubby catches you... you lose 😭\n";
    cout << "🏋  Reach the goal to descend to the next floor!\n\n";
    cout << "Press Enter to start the chase...\n";
    cin.ignore();
}

void draw(int player, int chaser, const vector<int>& obs, bool jumping) {
    clearScreen();
    cout << "🏢 Floor " << currentFloor << " of " << TOTAL_FLOORS << endl;

    for (int i = 0; i < WIDTH; ++i) {
        if (jumping && i == player)
            cout << "🥴️";
        else
            cout << " ";
    }
    cout << endl;

    for (int i = 0; i < WIDTH; ++i) {
        if (i == player && i == chaser)
            cout << "💥";
        else if (i == player && !jumping)
            cout << "🏃";
        else if (i == chaser)
            cout << "🚓";
        else if (i == goalX)
            cout << "🏋";
        else if (find(obs.begin(), obs.end(), i) != obs.end())
            cout << "🪨";
        else
            cout << "-";
    }
    cout << endl;

    if (jumping)
        cout << "JUMPING! 🥴️ (long jump)\n";
    else
        cout << "Press 'd' to move ➡️ | 'w' to JUMP 🥴️\n";
}

void countdown() {
    clearScreen();
    for (int i = 3; i > 0; --i) {
        cout << "\nStarting in... " << i << " ⏳" << endl;
        sleep_for(seconds(1));
        clearScreen();
    }
    cout << "\nRUN! 🏋🏃‍♂️💨\n";
    sleep_for(seconds(1));
}

void generateObstacles(int amount) {
    obstacles.clear();
    srand((unsigned)time(0) + currentFloor);
    while (obstacles.size() < amount) {
        int pos = rand() % (WIDTH - 2) + 1;
        bool valid =
            pos != playerX &&
            pos != chaserX &&
            pos != goalX &&
            find(obstacles.begin(), obstacles.end(), pos) == obstacles.end() &&
            find(obstacles.begin(), obstacles.end(), pos - 1) == obstacles.end() &&
            find(obstacles.begin(), obstacles.end(), pos + 1) == obstacles.end();

        if (valid) {
            obstacles.push_back(pos);
        }
    }
}

bool playFloor() {
    playerX = WIDTH / 4;
    chaserX = 2;
    goalX = WIDTH - 1;
    chaserCycles = 0;
    jumpTurns = 0;
    generateObstacles(6 + currentFloor);
    countdown();

    while (true) {
        char ch = '\0';
        if (_kbhit()) {
            ch = _getch();
            if (ch == 'd' && playerX < goalX)
                playerX++;
            else if (ch == 'w' && jumpTurns == 0) {
                jumpTurns = 2;
                playerX = min(playerX + 2, goalX);
            }
        }

        bool isJumping = (jumpTurns > 0);

        if (!isJumping && find(obstacles.begin(), obstacles.end(), playerX) != obstacles.end()) {
            draw(playerX, chaserX, obstacles, isJumping);
            cout << "\nYou tripped over a rock! 🪨😟 GAME OVER\n";
            return false;
        }

        chaserCycles++;
        if (chaserCycles % 2 == 0 && chaserX < playerX)
            chaserX++;

        draw(playerX, chaserX, obstacles, isJumping);

        if (playerX == chaserX) {
            cout << "\nThe evil chubby caught you! 😡 GAME OVER\n";
            return false;
        } else if (playerX >= goalX) {
            cout << "\nYou reached the next floor! 🏢👇\n";
            sleep_for(seconds(2));
            return true;
        }

        if (jumpTurns > 0)
            jumpTurns--;

        sleep_for(milliseconds(150));
    }
}

int main() {
    bool showIntro = true;

    while (true) {
        currentFloor = 1;
        bool won = false;

        if (showIntro)
            showStory();

        showInstructions();

        while (currentFloor <= TOTAL_FLOORS) {
            bool passed = playFloor();
            if (!passed) {
                cout << "\nTry again, but slimmer 😤\n";
                break;
            }
            currentFloor++;
        }

        if (currentFloor > TOTAL_FLOORS) {
            clearScreen();
            cout << "\nTHE CHUBBY GOT STUCK IN THE DOOR, SHE CAN'T CHASE YOU ANYMORE.\n";
            cout << "YOU DID IT, MISKO! 🎉🌟\n";
            sleep_for(seconds(2));
            cout << "\nMisko manages to escape because José María doesn't fit through the exit door,\n";
            sleep_for(seconds(3));
            cout << "but Misko leaves her the rosary, saying Roberto would've wanted her to have it...\n";
            sleep_for(seconds(3));
            cout << "Through tears, the chubby, before he leaves, grants him a useless wooden shield.\n";
            sleep_for(seconds(3));
            cout << "\n🎁 You obtained: Useless Wooden Shield 🪵\n";
            won = true;
        }

        cout << "\nDo you want to try again? (s = yes / any other key = exit): ";
        char option;
        cin >> option;
        cin.ignore();
        if (option != 's' && option != 'S') break;
        showIntro = false;
    }

    return 0;
}
