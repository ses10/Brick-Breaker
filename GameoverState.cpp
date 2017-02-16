#include "GameoverState.h"

GameOverState::GameOverState()
{
}

GameOverState::GameOverState(Input* in, StateManager* m, Game* g)
{
    init(in, m, g);
}

bool GameOverState::init(Input* in, StateManager* m, Game* g)
{
    game = g;
    input = in;
    setManager(m);

    if(!backgroundImage.load("graphics/GameoverScreen.png"))
        return false;

    return true;
}

void GameOverState::draw(Graphics* graphics)
{
    backgroundImage.draw(0,0, graphics);
}

void GameOverState::update()
{
    if(input->keyHit(SDLK_SPACE))
    {
        getManager()->popState();
        getManager()->addState(new SplashState(input, getManager(), game));
    }
}
