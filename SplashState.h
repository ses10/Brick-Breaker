#ifndef SPLASH_STATE
#define SPLASH_STATE

#include "GameState.h"
#include "Graphics.h"
#include "Image.h"
#include "Input.h"
#include "Sound.h"

class SplashState : public GameState
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
};

#endif

