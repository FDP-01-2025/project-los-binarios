#include <iostream>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <cstdlib>
#include <ctime>

using namespace std;

void setNonBlockingMode() {
    termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void resetTerminalMode() {
    termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

int keyPressed() {
    int oldf = fcntl(STDIN_FILENO, F_GETFL);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    int c = getchar();
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    if (c != EOF) {
        ungetc(c, stdin);
        return 1;
    }
    return 0;
}

void narrateIntro() {
    cout << "=== Misko Jhones and the Conveniently Convenient Trial of the Glowing Statues ===\n";
    sleep(2);
    cout << "\nNarrator: You find yourself in the dark, dusty basement of the university library...\n";
    sleep(3);
    cout << "Narrator: In front of you stand ancient statues...\n";
    sleep(2);
    cout << "Narrator: Their glowing eyes seem to follow your every move.\n";
    sleep(3);
    cout << "Narrator: You must sneak past them to reach the legendary manual...\n";
    sleep(3);
    cout << "\nNarrator: Listen carefully.\n";
    sleep(2);
    cout << "Narrator: Move by pressing 'w' repeatedly... but only when the statues close their eyes.\n";
    sleep(4);
    cout << "Narrator: If they see you move... they will turn you to stone instantly.\n";
    sleep(4);
    cout << "Narrator: Do not press any key when their eyes are watching.\n";
    sleep(3);
    cout << "Narrator: You only have 30 total chances to move. Use them wisely.\n";
    sleep(3);
    cout << "\nNarrator: Your trial begins... now.\n\n";
    sleep(3);
}

bool playStatueGame(bool showIntro) {
    const int maxSteps = 30;
    const int requiredSteps = 30;
    int steps = 0;
    int totalKeyPresses = 0;
    bool playing = true;

    if (showIntro) {
        narrateIntro();
    }

    while (playing) {
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

        int duration = 4000000; // 4 seconds
        int interval = 50000;   // 0.05 seconds

        for (int i = 0; i < duration / interval; ++i) {
            if (totalKeyPresses >= maxSteps) break;

            if (keyPressed()) {
                char key = getchar();
                if ((key == 'w' || key == 'W')) {
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
            usleep(interval);
        }

        if (steps >= requiredSteps) {
            cout << "\nYou have passed the trial of the statues.\n";
            return true;
        }

        sleep(1);
        cout << "-----------------------------\n";
    }
    return false;
}

bool finalBookPuzzle() {
    cout << "\nA mysterious glowing figure appears...\n";
    sleep(2);
    cout << "\"...You did it, Misko...\"\n";
    sleep(2);
    cout << "\"I am the Conveniently Convenient Guardian of the Ol' Koi Manual, but you can call me Roberto.\"\n";
    sleep(3);
    cout << "\"You have completed the trial of the glowing statues.\"\n";
    sleep(3);
    cout << "\"Now, only one task remains.\"\n";
    sleep(2);
    cout << "\"Before you are four books. One of them contains the knowledge of the Ol' Koi...\"\n";
    sleep(3);
    cout << "Choose a book:\n";
    cout << "1. Cooking with Koi\n2. The History of Convenient Things\n3. Ol' Koi Manual: Possibly Real Edition\n4. Gardening for the Lazy\nYour choice: ";

    int choice;
    cin >> choice;

    if (choice == 3) {
        sleep(2);
        cout << "\n\"You have chosen... wisely.\"\n";
        sleep(3);
        cout << "\nThe floor begins to shake violently...\n";
        sleep(2);
        cout << "\"Misko! You must escape!\"\n";
        sleep(2);
        cout << "\"No... I shall stay. I owe 24 years of child support. This is my destiny.\"\n";
        sleep(3);
        cout << "\nMisko: \"ROBERTOOOOO!! I will find the Ol' Koi... for you.\"\n";
        sleep(2);
        cout << "*Tears stream down Misko's face as the library crumbles...*\n";
        return true;
    } else {
        cout << "\n\"Incorrect. The true path must be walked again...\"\n";
        return false;
    }
}

int main() {
    srand(time(0));
    bool won = false;
    bool firstTime = true;
    char retry;

    while (!won) {
        setNonBlockingMode();
        bool passedStatues = playStatueGame(firstTime);
        resetTerminalMode();
        firstTime = false;

        if (!passedStatues) {
            cout << "\n===🥀💀 MISKO-DEATH 💀🥀===\n";
            cout << "You died. Would you like to try again? (y/n): ";
            cin >> retry;
            if (retry == 'n' || retry == 'N') {
                cout << "Returning to the main menu...\n";
                break;
            }
            continue;
        }

        cout << "\n===========================\n";
        cout << "Now preparing for the final challenge...\n";
        sleep(2);

        if (finalBookPuzzle()) {
            won = true;
        } else {
            cout << "\nYou failed to choose the correct book. The trial begins anew...\n\n";
            sleep(2);
        }
    }

    return 0;
}
