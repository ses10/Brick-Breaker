#ifndef LEVELONE_H
#define LEVELONE_H

#include "GameState.h"
#include "Graphics.h"
#include "Image.h"
#include "Input.h"
#include "Sound.h"

class LevelOne : public GameState
{
private:
    Input* input;
    Image backgroundImage;
public:
    /**
        Sets up the input and StateManager for instance of a SplashState
        and loads any assets for this state

        @param in, pointer to the Input class that will handle user input for this state
        @param m, pointer to the StateManager class that will handle this state

        @return true if successful, false otherwise
    */
    bool init(Input* in, StateManager* m);

    /**
        Draw the frame for current State

        @param graphics, the Graphics object that will draw frame
    */
    void draw(Graphics* graphics);
};

#endif // LEVELONE_H
