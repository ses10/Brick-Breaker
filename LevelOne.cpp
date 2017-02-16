#include "LevelOne.h"

LevelOne::LevelOne()
{

}

LevelOne::LevelOne(Input* in, StateManager* m, Game* g)
{
    init(in, m, g);
}

bool LevelOne::init(Input* in, StateManager* m, Game* g)
{
    input = in;
    setManager(m);
    game = g;

    screenWidth = game->getGraphics()->getWidth();
    screenHeight = game->getGraphics()->getHeight();

    if(!backgroundImage.load("graphics/levelBackground.bmp"))
        return false;

    if(!playerSprite.load("graphics/player.bmp"))
        return false;

    if(!ballSprite.load("graphics/ball.png"))
        return false;

    if(!blockSprite.load("graphics/block.bmp"))
        return false;

    if(!playerLifeSprite.load("graphics/playerLife.png"))
        return false;

    //set up player
    player.setX(screenWidth/2 - playerSprite.getWidth()/2);
    player.setY(550);
    player.setHeight(playerSprite.getHeight());
    player.setWidth(playerSprite.getWidth());
    player.setXVelocity(7);
    player.setLives(3);

    //set up ball
    ball.setX(player.getX() + player.getWidth()/2);
    ball.setY(player.getY()-player.getHeight()+4);
    ball.setHeight(ballSprite.getHeight());
    ball.setWidth(ballSprite.getWidth());
    ball.setXVelocity(5);
    ball.setYVelocity(-5);
    ball.setLocked(true);

    //set up the blocks
    setBlocks();

    return true;
}

void LevelOne::draw(Graphics* graphics)
{
    backgroundImage.draw(0,0,graphics);
    drawHUD(graphics);
    playerSprite.draw(player.getX(), player.getY(), graphics);
    ballSprite.draw(ball.getX(), ball.getY(), graphics);
    drawBlocks(graphics);
}

void LevelOne::update()
{
    updatePlayer();
    updateBall();

    if(player.getLives() <= 0)
    {
        getManager()->popState();
        getManager()->addState(new SplashState(input, getManager(),game));
    }
}

void LevelOne::updatePlayer()
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
}

void LevelOne::updateBall()
{
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
        if(collision(&ball, &player))
        {
            ball.setX(ball.getX()-ball.getXVelocity());
            ball.setXVelocity(ball.getXVelocity()*-1);
        }
        //check if ball hit any block on x-axis
        else
        {
            int numBlocks = BLOCK_COL * BLOCK_ROW;
            for(int i = 0; i < numBlocks; i++)
            {
                if(blocks[i].isAlive() && collision(&ball, &blocks[i]))
                {
                    ball.setX(ball.getX()-ball.getXVelocity());
                    ball.setXVelocity(ball.getXVelocity()*-1);
                    blocks[i].setAlive(false);
                }
            }
        }

        ball.setY(ball.getY()+ball.getYVelocity());

        //check if ball hit player on y-axis
        if(collision(&ball, &player))
        {
            ball.setY(ball.getY()-ball.getYVelocity());
            ball.setYVelocity(ball.getYVelocity()*-1);
        }
        //check if ball hit any block on y-axis
        else
        {
            int numBlocks = BLOCK_COL * BLOCK_ROW;
            for(int i = 0; i < numBlocks; i++)
            {
                if(blocks[i].isAlive() && collision(&ball, &blocks[i]))
                {
                    ball.setY(ball.getY()-ball.getYVelocity());
                    ball.setYVelocity(ball.getYVelocity()*-1);
                    blocks[i].setAlive(false);
                }
            }
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

        //check if player lost ball
        if(ball.getY() > screenHeight)
        {
            ball.setLocked(true);
            player.setLives(player.getLives() - 1);
        }
    }
}

bool LevelOne::collision(Entity* obj1, Entity* obj2)
{
    //check right
    if(obj1->getX() >= obj2->getX() + obj2->getWidth())
        return false;

    //check bottom
    if(obj1->getY() >= obj2->getY() + obj2->getHeight())
        return false;

    //check left
    if(obj2->getX() >= obj1->getX() + obj1->getWidth())
        return false;

    //check top
    if(obj2->getY() >= obj1->getY() + obj1->getHeight())
        return false;

    return true;
}

void LevelOne::setBlocks()
{
    int i = 0;
    int blockWidth = blockSprite.getWidth();
    int blockHeight = blockSprite.getHeight();

    for(int x = 0; x < BLOCK_COL; x++)
    {
        for(int y = 0; y < BLOCK_ROW; y++)
        {
            blocks[i].setAlive(true);
            blocks[i].setX(x*blockWidth);
            blocks[i].setY(y*blockHeight + 100);
            blocks[i].setWidth(blockWidth);
            blocks[i].setHeight(blockHeight);
            i++;
        }
    }
}

void LevelOne::drawBlocks(Graphics* graphics)
{
    int numBlocks = BLOCK_COL * BLOCK_ROW;
    for(int i = 0; i < numBlocks; i++)
    {
        if(blocks[i].isAlive())
            blockSprite.draw(blocks[i].getX(), blocks[i].getY(), graphics);
    }
}

void LevelOne::drawHUD(Graphics* graphics)
{
    for(int i=0; i < player.getLives(); i++)
    {
        playerLifeSprite.draw(i*playerLifeSprite.getWidth() + 10 + (i*5), 10, graphics);
    }
}
