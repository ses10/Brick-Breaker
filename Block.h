#ifndef BLOCK_H
#define BLOCK_H

#include "Entity.h"

/**
    Represents the blocks the player
    breaks with the ball
*/
class Block : public Entity
{
private:
    bool alive;
public:
    bool isAlive();
    void setAlive(bool isAlive);
};

#endif // BLOCK_H
