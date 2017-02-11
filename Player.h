#ifndef PLAYER_H
#define PLAYER_H

#include <SDL/SDL.h>

class Player
{
private:
    SDL_Rect rect;
    int lives;
public:
    Player();
    void subtractLives(int n);
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    void setX(int x);
    void setY(int y);
    void setWidth(int width);
    void setHeight(int height);

};

#endif // PLAYER_H
