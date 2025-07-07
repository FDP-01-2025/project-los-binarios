#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <cstdlib>

using namespace std;

const int WIDTH = 20;
const int HEIGHT = 12;
const int DEFENSE_LINE = HEIGHT - 2;
const int MAX_HEALTH = 10;

char board[HEIGHT][WIDTH];
int playerX = WIDTH / 2;
int softIA_health = MAX_HEALTH;

struct Enemy {
    int y, x;
    bool dodged = false;
};

vector<Enemy> enemies;
vector<pair<int, int>> bullets;

void sleepText(const string &text, int delay = 40) {
    for (char c : text) {
        cout << c << flush;
        Sleep(delay);
    }
    cout << endl;
}

void showIntro() {
    system("cls");
    sleepText("The Conveniently Convenient Manual says that the last piece of the OL KOI is in the weird-smelling building...");
    sleepText("Misko heads to the Computer Science Department...");
    sleepText("A robotic voice screams: INTRUDER INTRUDER INTRUDER...");
    sleepText("SoftIA tells him to help eliminate a virus that's corrupting her...");
    sleepText("Misko puts on the VR headset...");
    sleepText("The second-to-last game begins: THE BATTLE AGAINST THE VIRUS...");
    sleepText("Press any key to begin...");
    _getch();
}

void drawBoard() {
    system("cls");
    for (int i = 0; i < HEIGHT; ++i)
        for (int j = 0; j < WIDTH; ++j)
            board[i][j] = ' ';
    for (auto& e : enemies)
        if (e.y >= 0 && e.y < HEIGHT)
            board[e.y][e.x] = 'V';
    for (auto& b : bullets)
        if (b.first >= 0 && b.first < HEIGHT)
            board[b.first][b.second] = '|';
    for (int j = 0; j < WIDTH; ++j)
        board[DEFENSE_LINE][j] = '=';
    board[HEIGHT - 1][playerX] = '^';
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j)
            cout << board[i][j];
        cout << endl;
    }
    cout << "SoftIA: [";
    for (int i = 0; i < MAX_HEALTH; ++i)
        cout << (i < softIA_health ? '#' : ' ');
    cout << "]" << endl;
}

void updateBullets() {
    vector<pair<int, int>> updatedBullets;

    for (auto& b : bullets) {
        b.first -= 2;
        bool hit = false;

        for (size_t i = 0; i < enemies.size(); ++i) {
            if (enemies[i].y == b.first && enemies[i].x == b.second) {
                enemies.erase(enemies.begin() + i);
                hit = true;
                break;
            }
        }

        if (b.first >= 0 && !hit) {
            updatedBullets.push_back(b);
        }
    }

    bullets = updatedBullets;
}

void moveEnemiesDown() {
    for (auto& e : enemies)
        e.y++;
}

void checkDefenseLine() {
    vector<Enemy> remainingEnemies;
    for (auto& e : enemies) {
        if (e.y == DEFENSE_LINE) {
            softIA_health--;
        } else if (e.y < HEIGHT) {
            remainingEnemies.push_back(e);
        }
    }
    enemies = remainingEnemies;
}

void gameLoop() {
    int currentLevel = 1;

    while (currentLevel <= 3) {
        bullets.clear();
        enemies.clear();
        playerX = WIDTH / 2;

        int amount = 10 + (currentLevel - 1) * 5;
        for (int i = 0; i < amount; i++) {
            int randomX = rand() % WIDTH;
            enemies.push_back({1, randomX});
        }

        int counter = 0;
        int cyclesPerMove = max(5, 35 - currentLevel * 5);
        bool running = true;

        while (running) {
            drawBoard();

            if (counter % 8 == 0 && softIA_health > 0) {
                for (auto& e : enemies) {
                    if (e.y >= DEFENSE_LINE - 2) {
                        string quotes[] = {
                            "Help, Misko!",
                            "I'm being corrupted!",
                            "They're getting too close!",
                            "The defense is falling!",
                            "I can't take much more!",
                            "The OL KOI is affecting me!",
                            "Hold on, Misko Jhones!"
                        };
                        cout << "SoftIA: " << quotes[rand() % 7] << endl;
                        break;
                    }
                }
            }

            if (_kbhit()) {
                char key = _getch();
                if (key == 'a' && playerX > 0)
                    playerX--;
                else if (key == 'd' && playerX < WIDTH - 1)
                    playerX++;
                else if (key == 'w')
                    bullets.push_back({HEIGHT - 2, playerX});
                else if (key == 'q') {
                    running = false;
                    return;
                }
            }

            updateBullets();
            counter++;
            if (counter % cyclesPerMove == 0)
                moveEnemiesDown();

            checkDefenseLine();

            if (softIA_health <= 0) {
                drawBoard();
                cout << "\n💀 SoftIA has been corrupted... GAME OVER 💀\n";
                return;
            }

            if (enemies.empty()) {
                drawBoard();
                if (currentLevel < 3) {
                    cout << "\n✅ Level " << currentLevel << " completed. Get ready for the next one...\n";
                    Sleep(2000);
                }
                break;
            }

            Sleep(100);
        }

        currentLevel++;
    }

    drawBoard();
    cout << "\n🎉 SoftIA has been fully saved and the OL KOI is yours! 🎉\n";
    sleepText("Grateful, SoftIA gives you the 16K screen — the final piece of the OL KOI.");
}

int main() {
    showIntro();
    gameLoop();
    return 0;
}
