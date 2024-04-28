#include <iostream>
#include <easyx.h>
#include "game.h"

int main() {
    Game2048 game1;
    while (true) {
        game1.Move();
    }
    return 0;
}

