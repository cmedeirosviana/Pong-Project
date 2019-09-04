#ifndef CONTROL_H
#define CONTROL_H
#include "IPONG.h"
#include "Paddle.h"
#include "Ball.h"
#include "Design.h"
#include <SDL2/SDL.h>

class Control: Ipong
{
    public:
        Control();
        ~Control();
        // Implements the loop that has the core game. 
        void play();
    protected:

    private:
        //Define the paddle limits according the display
        void setPaddleLimits(Paddle &Paddle1,Paddle &Paddle2);
        //Check if the ball has reached a limitiation and calls the change direction or count the point
        void checkBallLimits(Ball & ball);
        //Reset the position of the ball
        void update();
        // Keep the score of the players and show in the terminal the result
        void countPoint(bool player);
        bool running = true;
        float target_frame_duration = 0;
        SDL_Event event;
        Ball ball;
        Design design;
        int pointPlayer1 = 0;
        int pointPlayer2 = 0;
};

#endif
