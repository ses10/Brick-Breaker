#include "GameMain.h"

bool GameMain::init()
{
    if(!initSystem("Breakout", SCREEN_WIDTH, SCREEN_HEIGHT, false))
        return false;

    manager.addState(new SplashState(getInput(), &manager, this));

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
