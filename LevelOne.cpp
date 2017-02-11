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

    player.setX(screenWidth/2 - playerSprite.getWidth()/2);
    player.setY(550);
    player.setHeight(playerSprite.getHeight());
    player.setWidth(playerSprite.getWidth());
    player.setXVelocity(7);

    return true;
}

void LevelOne::draw(Graphics* graphics)
{
    backgroundImage.draw(0,0,graphics);
    playerSprite.draw(player.getX(), player.getY(), graphics);
}

void LevelOne::update()
{
    //handle player movement
    if(input->keyDown(SDLK_RIGHT))
        player.setX(player.getX() + player.getXVelocity());
    if(input->keyDown(SDLK_LEFT))
        player.setX(player.getX() - player.getXVelocity());

    //check if player is out of bounds
    if(player.getX() < 0)
        player.setX(0);
    if(player.getX() + player.getWidth() >= screenWidth )
        player.setX(screenWidth-player.getWidth());
}
