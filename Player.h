#ifndef PLAYER_H
#define PLAYER_H

#include <SDL/SDL.h>
#include "Entity.h"

class Player : public Entity
{
private:
    int lives;
    int xVelocity;
    int yVelocity;
public:
    Player();
    void subtractLives(int n);;
    int getXVelocity();
    int getYVelocity();
    int getLives();
    void setXVelocity(int x);
    void setYVelocity(int x);
    void setLives(int n);
};

#endif // PLAYER_H
