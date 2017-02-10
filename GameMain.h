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

    /**
        Draw the frame for current State

        @param graphics, the Graphics object that will draw frame
    */
    void draw(Graphics* graphics);
};

#endif // GAMEMAIN_H
