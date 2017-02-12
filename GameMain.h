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
    const static int SCREEN_WIDTH = 800;
    const static int SCREEN_HEIGHT = 600;
    StateManager manager;
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

    /**
        Updates the current state
    */
    void update();
};

#endif // GAMEMAIN_H
