#include "Entity.h"

void Entity::setX(int x)
{
    rect.x = x;
}

void Entity::setY(int y)
{
    rect.y = y;
}

void Entity::setHeight(int height)
{
    rect.h = height;
}

void Entity::setWidth(int width)
{
    rect.w = width;
}

int Entity::getWidth()
{
    return rect.w;
}

int Entity::getHeight()
{
    return rect.h;
}
int Entity::getX()
{
    return rect.x;
}

int Entity::getY()
{
    return rect.y;
}
