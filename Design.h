#ifndef DESIGN_H
#define DESIGN_H

#include "Ball.h"
#include "Paddle.h"
#include <SDL2/SDL.h>


class Design
{   
    public:
        //Create the window and display the graphic elements using SDL library
        void createGame();
        //Create the Paddle and ball in the graphic interface
        void createForms(Ball &ball,Paddle &paddle1,Paddle &paddle2);
        //call the SDL functions responsible for destroy the objects
        void quitGame();
        //define and colect commands to move the paddle.
        void controlLogics(Paddle &Paddle1,Paddle &Paddle2,SDL_Event &event);
        // Define and collect commands when the players want to pause the game
        bool pointPause(SDL_Event &event);
    protected:

    private:
        Uint32 getColor();
        SDL_Surface *screen;
        SDL_Window *window;
        SDL_Renderer *renderer;
};

#endif
