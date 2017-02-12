#ifndef PLAYER_H
#define PLAYER_H

#include <SDL/SDL.h>

class Player
{
private:
    SDL_Rect rect;
    int lives;
    int xVelocity;
    int yVelocity;
public:
    Player();
    void subtractLives(int n);
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    int getXVelocity();
    int getYVelocity();
    int getLives();
    void setX(int x);
    void setY(int y);
    void setWidth(int width);
    void setHeight(int height);
    void setXVelocity(int x);
    void setYVelocity(int x);
    void setLives(int n);
};

#endif // PLAYER_H
