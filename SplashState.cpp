#include "SplashState.h"

SplashState::SplashState()
{

}

SplashState::SplashState(Input* in, StateManager* m, Game* g)
{
    init(in, m, g);
}

bool SplashState::init(Input* in, StateManager* m, Game* g)
{
    //Set this object's Input and StateManger to point to the ones given
    //in parameters
    input = in;
    setManager(m);
    game = g;

    if(!backgroundImage.load("graphics/splashBackground.bmp"))
        return false;

    return true;
}

void SplashState::draw(Graphics* graphics)
{
    backgroundImage.draw(0,0,graphics);
}

void SplashState::update()
{
    if(input->keyHit(SDLK_SPACE))
    {
        getManager()->popState();
        getManager()->addState(new LevelOne(input, getManager(), game));
    }
}
