#include "LevelOne.h"

bool LevelOne::init(Input* in, StateManager* m, Game* g)
{
    input = in;
    setManager(m);
    screenWidth = g->getGraphics()->getWidth();
    screenHeight = g->getGraphics()->getHeight();

    if(!backgroundImage.load("graphics/levelBackground.bmp"))
        return false;

    if(!playerSprite.load("graphics/player.bmp"))
        return false;

    if(!ballSprite.load("graphics/ball.png"))
        return false;

    //set up player
    player.setX(screenWidth/2 - playerSprite.getWidth()/2);
    player.setY(550);
    player.setHeight(playerSprite.getHeight());
    player.setWidth(playerSprite.getWidth());
    player.setXVelocity(7);

    //set up ball
    ball.setX(player.getX() + player.getWidth()/2);
    ball.setY(player.getY()-player.getHeight()+4);
    ball.setHeight(ballSprite.getHeight());
    ball.setWidth(ballSprite.getWidth());
    ball.setXVelocity(5);
    ball.setYVelocity(-5);
    ball.setLocked(true);

    return true;
}

void LevelOne::draw(Graphics* graphics)
{
    backgroundImage.draw(0,0,graphics);
    playerSprite.draw(player.getX(), player.getY(), graphics);
    ballSprite.draw(ball.getX(), ball.getY(), graphics);
}

void LevelOne::update()
{
    //handle player movement
    if(input->keyDown(SDLK_RIGHT))
        player.setX(player.getX() + player.getXVelocity());
    if(input->keyDown(SDLK_LEFT))
        player.setX(player.getX() - player.getXVelocity());
    if(input->keyHit(SDLK_SPACE))
        ball.setLocked(false);

    //check if player is out of bounds
    if(player.getX() < 0)
        player.setX(0);
    if(player.getX() + player.getWidth() >= screenWidth )
        player.setX(screenWidth-player.getWidth());

    //update ball movement
    if(ball.locked())
    {
        ball.setX(player.getX() + player.getWidth()/2);
        ball.setY(player.getY()-ball.getHeight());
    }
    else
    {
        ball.setX(ball.getX()+ball.getXVelocity());

        //check if ball hit player on x-axis
        if(playerBallCollision())
        {
            ball.setX(ball.getX()-ball.getXVelocity());
            ball.setXVelocity(ball.getXVelocity()*-1);
        }

        ball.setY(ball.getY()+ball.getYVelocity());

        //check if ball hit player on y-axis
        if(playerBallCollision())
        {
            ball.setY(ball.getY()-ball.getYVelocity());
            ball.setYVelocity(ball.getYVelocity()*-1);
        }

        //check if ball hits boundaries
        //check top
        if(ball.getY() < 0)
        {
            ball.setY(0);
            ball.setYVelocity(ball.getYVelocity()*-1);
        }
        //check right
        if(ball.getX() > screenWidth - ball.getWidth())
        {
            ball.setX(screenWidth - ball.getWidth());
            ball.setXVelocity(ball.getXVelocity()*-1);
        }
        //check left
        if(ball.getX() < 0)
        {
            ball.setX(0);
            ball.setXVelocity(ball.getXVelocity()*-1);
        }
    }

}

bool LevelOne::playerBallCollision()
{
    //check right
    if(ball.getX() >= player.getX() + player.getWidth())
        return false;

    //check bottom
    if(ball.getY() >= player.getY() + player.getHeight())
        return false;

    //check left
    if(player.getX() >= ball.getX() + ball.getWidth())
        return false;

    //check top
    if(player.getY() >= ball.getY() + ball.getHeight())
        return false;

    return true;
}
