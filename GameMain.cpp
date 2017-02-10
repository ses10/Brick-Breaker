#include "GameMain.h"

bool GameMain::init()
{
    if(!initSystem("Game State Demo", 800, 600, false))
        return false;

    if(!splashState.init(getInput(), &manager))
        return false;

    manager.addState(&splashState);

    return true;
}
