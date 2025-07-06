#ifndef juego3casinopt3_h
#define juego3casinopt3_h

#include <ctime>
#include <iostream>
#include <vector>
using namespace std;


void waitSeconds(int seconds) {
    clock_t end = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < end) { /* wait */ }
}


#endif