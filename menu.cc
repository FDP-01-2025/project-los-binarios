#include <iostream>
#include <windows.h>
using namespace std;

void wait(int ms) {
    Sleep(ms);
}

int main() {
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
    cout << "               [2] Load Game\n";
    wait(500);
    cout << "               [3] Save Game\n";
    wait(500);
    cout << "               [4] Exit\n";
    cout << "\n                    ";
    cin >> option;

    switch(option) {
        case 1:
            cout << "\nStarting new game...\n";
            break;
        case 2:
            cout << "\nLoading game...\n";
            break;
        case 3:
            cout << "\nSaving game...\n";
            break;
        case 4:
            cout << "\nExiting game. Goodbye!\n";
            break;
        default:
            cout << "\nInvalid option.\n";
            break;
    }
}while(option<1||option>4);

    return 0;
}
