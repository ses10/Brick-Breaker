#ifndef BALL_H
#define BALL_H

#include <SDL/SDL.h>
#include "Entity.h"

class Ball : public Entity
{
private:
    int xVelocity;
    int yVelocity;
    bool isLocked;
public:
    Ball();
    int getXVelocity();
    int getYVelocity();
    bool locked();
    void setXVelocity(int x);
    void setYVelocity(int x);
    void setLocked(bool lock);
};


#endif // BALL_H
