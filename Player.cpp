#include "Player.h"

Player::Player()
{
    lives = 3;
    xVelocity = 0;
    yVelocity = 0;
}

void Player::subtractLives(int n)
{
    lives -= n;
}

void Player::setXVelocity(int x)
{
    xVelocity = x;
}

void Player::setYVelocity(int y)
{
    yVelocity = y;
}

void Player::setLives(int n)
{
    lives = n;
}

int Player::getXVelocity()
{
    return xVelocity;
}

int Player::getYVelocity()
{
    return yVelocity;
}

int Player::getLives()
{
    return lives;
}
