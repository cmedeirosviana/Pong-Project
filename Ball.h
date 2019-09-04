#ifndef BALL_H
#define BALL_H

#include <SDL2/SDL.h>
#include "Common_data.h"

class Ball
{
    public:
        //Set the ball size 
        Ball();
        //define a new direction depending on where the ball will hit
        void changeDirection(limits data);
        //define where the ball should be throw when the has a point
        void resetBallPosition();
        //Create the X and Y component to define the ball`s position
        void DefineNewPosition();
        float getBall_x();
        float getBall_y();
        SDL_Rect* getForm();
    protected:

    private:
        //set the ball position
        void setBallPosition(int x,int y);

        //Sets a random angle value for the ball to be released
        float defineDirection();

        SDL_Rect ball;
        float angle = 0;
        float speed_x = 0;
        float speed_y = 0;
};

#endif