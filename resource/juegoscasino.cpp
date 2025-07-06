#include "juego1casinopt1.h"         // Primer juego (el de código)
#include "juego2casinologica.h"     // Segundo juego (el de reacción)
#include "juego3casinopt1.h"     // Tercer juego (la ruleta)

int main() {
    double money = 100.0;  // Dinero inicial

    // Juego 1: Code Game
    startCodeGame(money);
    // Ahora money está actualizado según ganes o pierdas

    // Juego 2: Reaction Game
    startReactionGame(money);
    // El dinero sigue actualizado

    // Juego 3: Roulette Game
    startRouletteGame(money);

    // Al final puedes mostrar dinero total o hacer algo más
    std::cout << "\nFinal money after all games: $" << money << "\n";

    return 0;
}