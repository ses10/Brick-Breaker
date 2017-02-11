#ifndef LEVELONE_H
#define LEVELONE_H

#include "Game.h"
#include "GameState.h"
#include "Graphics.h"
#include "Image.h"
#include "Input.h"
#include "Sound.h"
#include "Player.h"
#include "Ball.h"

class LevelOne : public GameState
{
private:
    Input* input;
    Image backgroundImage;
    Image playerSprite;
    Image ballSprite;
    Player player;
    Ball ball;
    int screenWidth;
    int screenHeight;
public:
    /**
        Sets up the input and StateManager for instance of a SplashState
        and loads any assets for this state

        @param in, pointer to the Input class that will handle user input for this state
        @param m, pointer to the StateManager class that will handle this state
        @param g, pointer to the Game object containing this state

        @return true if successful, false otherwise
    */
    bool init(Input* in, StateManager* m, Game* g);

    /**
        Draw the frame for current State

        @param graphics, the Graphics object that will draw frame
    */
    void draw(Graphics* graphics);

    void update();
};

#endif // LEVELONE_H
