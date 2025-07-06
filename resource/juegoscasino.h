#define JUEGOSCASINO_H
#include "juego1casinopt1.h"         // Primer juego (el de código)
#include "juego2casinologica.h"     // Segundo juego (el de reacción)
#include "juego3casinopt1.h"     // Tercer juego (la ruleta)

int casino() {
    double money = 100.0;  // Dinero inicial
    cout << "WELCOME TO EL CASINO JUGUETON\n";
    waitSeconds(2);
    cout << "HERE YOU HAVE THE OPPORTUNITY TO BE RICH... OR BE AS POOR AS DON BOSCO STUDENTS...\n";
    waitSeconds(3);
    cout << "DO YOUR BEST IN EACH GAME\n";
    waitSeconds(2);
    cout << "...\n";
    waitSeconds(2);
    cout << "QUE EMPIECE EL JUEGUETEO!!\n";
    waitSeconds(3);


    // Juego 1: Code Game
    startCodeGame(money);
    // Ahora money está actualizado según ganes o pierdas

    // Juego 2: Reaction Game
    startReactionGame(money);
    // El dinero sigue actualizado

    // Juego 3: Roulette Game
    startRouletteGame(money);

    // Al final puedes mostrar dinero total o hacer algo más
    std::cout << "\nFinal money after all games: $" << 100<<" (taxes always takes everyithing and only left you 100" "\n";

    return 1;
}