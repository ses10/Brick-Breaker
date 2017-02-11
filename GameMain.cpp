#include "GameMain.h"

bool GameMain::init()
{
    if(!initSystem("Breakout", 800, 600, false))
        return false;

    if(!splashState.init(getInput(), &manager))
        return false;

    if(!levelOne.init(getInput(), &manager))
        return false;

    manager.addState(&levelOne);
    manager.addState(&splashState);

    return true;
}

void GameMain::draw(Graphics* graphics)
{
    manager.draw(graphics);
}
