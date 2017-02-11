#include "Player.h"

Player::Player()
{
    lives = 3;
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
