#ifndef PADDLE_H
#define PADDLE_H
#include <SDL2/SDL.h>

class Paddle
{
    public:
    //Define which paddle is 1 and 2
        Paddle(bool side);
        //move the paddle up
        bool  moveUp();
         //move the paddle down
        bool  modeDown();
        // pointer of the SDL object(Paddle form) to be used in Design methods
        SDL_Rect* getForm();
        double get_x();
        double get_y();
        void set_x(float x);
        void set_y(float y);

    protected:

    private:

        SDL_Rect paddle;
};
#endif
