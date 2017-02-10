#include "GameMain.h"

int main(int argc, char *argv[])
{
    GameMain game;

    if(!game.init())
        game.free();

    game.run();

    return 0;
}
