#include "GameMain.h"

bool GameMain::init()
{
    if(!initSystem("Breakout", SCREEN_WIDTH, SCREEN_HEIGHT, false))
        return false;

    if(!splashState.init(getInput(), &manager))
        return false;

    if(!levelOne.init(getInput(), &manager, this))
        return false;

    manager.addState(&levelOne);
    manager.addState(&splashState);

    return true;
}

void GameMain::draw(Graphics* graphics)
{
    manager.draw(graphics);
}

void GameMain::update()
{
    if(manager.isEmpty())
    {
        end();
        return;
    }

    manager.update();
}
