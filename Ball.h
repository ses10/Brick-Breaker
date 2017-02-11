#ifndef BALL_H
#define BALL_H

#include <SDL/SDL.h>

class Ball{
private:
    SDL_Rect rect;
    int xVelocity;
    int yVelocity;
    bool isLocked;
public:
    Ball();
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    int getXVelocity();
    int getYVelocity();
    bool locked();
    void setX(int x);
    void setY(int y);
    void setWidth(int width);
    void setHeight(int height);
    void setXVelocity(int x);
    void setYVelocity(int x);
    void setLocked(bool lock);
};


#endif // BALL_H
