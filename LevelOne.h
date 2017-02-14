#ifndef LEVELONE_H
#define LEVELONE_H

#include "Game.h"
#include "GameState.h"
#include "SplashState.h"
#include "Graphics.h"
#include "Image.h"
#include "Input.h"
#include "Sound.h"
#include "Player.h"
#include "Ball.h"
#include "Block.h"

const int BLOCK_COL = 16;
const int BLOCK_ROW = 5;

class LevelOne : public GameState
{
private:
    Input* input;
    Game* game;
    Image backgroundImage;
    Image playerSprite;
    Image ballSprite;
    Image blockSprite;
    Player player;
    Ball ball;
    int screenWidth;
    int screenHeight;
    Block blocks[BLOCK_COL * BLOCK_ROW];
public:
    LevelOne();
    LevelOne(Input* in, StateManager* m, Game* g);

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

    /**
        Update the frame for current State
    */
    void update();

    /**
        Checks whether the ball has collided with the Player paddle

        @param obj1, pointer to an Entity object in game
        @param obj2, pointer to an Entity object in game

        @return true if collision occurred, false otherwise
    */
    bool collision(Entity* obj1, Entity* obj2);

    /**
        Updates the Player object's position for current frame
    */
    void updatePlayer();

    /**
        Updates the Ball object's position for current frame
    */
    void updateBall();

    void setBlocks();
    void drawBlocks(Graphics* graphics);
};

#endif // LEVELONE_H
