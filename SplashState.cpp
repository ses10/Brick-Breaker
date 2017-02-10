#include "SplashState.h"

bool SplashState::init(Input* in, StateManager* m)
{
    //Set this object's Input and StateManger to point to the ones given
    //in parameters
    input = in;
    setManager(m);

    if(!backgroundImage.load("graphics/splashBackground.bmp"))
        return false;

    return true;
}

void SplashState::draw(Graphics* graphics)
{
    backgroundImage.draw(0,0,graphics);
}
