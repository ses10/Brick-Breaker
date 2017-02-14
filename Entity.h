#ifndef ENTITY_H
#define ENTITY_H

#include <SDL/SDL.h>

/**
    This is the base class for all Game objects
*/
class Entity
{
private:
    SDL_Rect rect;
public:
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    void setX(int x);
    void setY(int y);
    void setWidth(int width);
    void setHeight(int height);
};

#endif // ENTITY_H
