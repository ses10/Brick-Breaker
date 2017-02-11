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

void Player::setX(int x)
{
    rect.x = x;
}

void Player::setY(int y)
{
    rect.y = y;
}

void Player::setHeight(int height)
{
    rect.h = height;
}

void Player::setWidth(int width)
{
    rect.w = width;
}

void Player::setXVelocity(int x)
{
    xVelocity = x;
}

void Player::setYVelocity(int y)
{
    yVelocity = y;
}

int Player::getWidth()
{
    return rect.w;
}

int Player::getHeight()
{
    return rect.h;
}
int Player::getX()
{
    return rect.x;
}

int Player::getY()
{
    return rect.y;
}

int Player::getXVelocity()
{
    return xVelocity;
}

int Player::getYVelocity()
{
    return yVelocity;
}

