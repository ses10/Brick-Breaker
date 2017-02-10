#ifndef GAMEMAIN_H
#define GAMEMAIN_H

#include "Game.h"
#include "StateManager.h"
#include "SplashState.h"

/**
    The main Game object that will handle all components of
    the game engine
*/
class GameMain : public Game
{
private:
    StateManager manager;
    SplashState splashState;
public:
    /**
        Start the game engine

        @return true if successful, false otherwise
    */
    bool init();
};

#endif // GAMEMAIN_H
