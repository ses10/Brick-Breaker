#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H

#include "GameState.h"
#include "LevelOne.h"
#include "Image.h"
#include "Input.h"
#include "Game.h"

class GameOverState : public GameState
{
private:
    Input* input;
    Image backgroundImage;
    Game* game;
public:
    GameOverState();
    GameOverState(Input* in, StateManager* m, Game* g);

    /**
        Sets up the input and StateManager for instance of a GameoverState
        and loads any assets for this state

        @param in, pointer to the Input class that will handle user input for this state
        @param m, pointer to the StateManager class that will handle this state

        @return true if successful, false otherwise
    */
    bool init(Input* in, StateManager* m, Game* g);

    /**
    Draw the frame for current State

    @param graphics, the Graphics object that will draw frame
    */
    void draw(Graphics* graphics);

    /**
    Checks whether the user has opted to restart
    the game by pressing "space"
    */
    void update();
};

#endif // GAMEOVERSTATE_H
