#define JUEGOSCASINO_H
#include "firstCasinoGamept1.h"         
#include "secondCasinoGamept1.h"    
#include "thirdsCasinoGamept1.h"    
#include "sleep.h" 

int casino() {
    double money = 100.0;  // money
    cout << "WELCOME TO EL CASINO JUGUETON\n";
    waitSeconds(2);
    cout << "HERE YOU HAVE THE OPPORTUNITY TO BE RICH... OR BE AS POOR AS THE DEVELOPERS OF THIS GAME...\n";
    waitSeconds(3);
    cout << "DO YOUR BEST IN EACH GAME\n";
    waitSeconds(2);
    cout << "...\n";
    waitSeconds(2);
    cout << "QUE EMPIECE EL JUEGUETEO!!\n";
    waitSeconds(3);


    // Game 1: Code Game
    startCodeGame(money);
    // Money is uptading depending if you win or lose

    // Game 2: Reaction Game
    startReactionGame(money);
    // The money is still updated

    // Game 3: Roulette Game
    startRouletteGame(money);
    std::cout << "\nFinal money after all games: $" << 100<<" (taxes always takes everyithing and only left you 100" "\n";
    wait(3500);

    return 1;
}