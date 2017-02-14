#include "Ball.h"

Ball::Ball()
{
    xVelocity = 0;
    yVelocity = 0;
}

void Ball::setXVelocity(int x)
{
    xVelocity = x;
}

void Ball::setYVelocity(int y)
{
    yVelocity = y;
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
