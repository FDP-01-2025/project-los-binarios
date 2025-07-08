#ifndef SLEEP_H
#define SLEEP_H
#pragma once

#include <windows.h>
//This function is used in almost every game, it's for exactly its names says, wait seconds until do something else
void wait(int ms){
    Sleep(ms);
}

#endif 