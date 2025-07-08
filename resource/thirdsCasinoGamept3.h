#ifndef THIRDSCASINOGAMEPT3_H
#define THIRDSCASINOGAMEPT3_H
#pragma once

#include <ctime>
#include <iostream>
#include <vector>
using namespace std;


void waitSeconds(int seconds) {
    clock_t end = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < end) { /* wait */ }
}


#endif