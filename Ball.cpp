#include "Ball.h"

Ball::Ball()
{
    xVelocity = 0;
    yVelocity = 0;
}

void Ball::setX(int x)
{
    rect.x = x;
}

void Ball::setY(int y)
{
    rect.y = y;
}

void Ball::setHeight(int height)
{
    rect.h = height;
}

void Ball::setWidth(int width)
{
    rect.w = width;
}

void Ball::setXVelocity(int x)
{
    xVelocity = x;
}

void Ball::setYVelocity(int y)
{
    yVelocity = y;
}

int Ball::getWidth()
{
    return rect.w;
}

int Ball::getHeight()
{
    return rect.h;
}
int Ball::getX()
{
    return rect.x;
}

int Ball::getY()
{
    return rect.y;
}

int Ball::getXVelocity()
{
    return xVelocity;
}

int Ball::getYVelocity()
{
    return yVelocity;
}

bool Ball::locked()
{
    return isLocked;
}

void Ball::setLocked(bool lock)
{
    isLocked = lock;
}
