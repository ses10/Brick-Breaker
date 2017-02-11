#include "LevelOne.h"

bool LevelOne::init(Input* in, StateManager* m)
{
    input = in;
    setManager(m);

    if(!backgroundImage.load("graphics/levelBackground.bmp"))
        return false;

    return true;
}

void LevelOne::draw(Graphics* graphics)
{
    backgroundImage.draw(0,0,graphics);
}
