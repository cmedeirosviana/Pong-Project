#include "Paddle.h"
#include <SDL2/SDL.h>
#include "Common_data.h"

Paddle::Paddle(bool side)
{
    if (side == SIDE::left)
    {
        paddle.x = PADDLE1::SIZE_X;
        paddle.y = PADDLE1::SIZE_Y;
        paddle.h = PADDLE1::SIZE_H;
        paddle.w = PADDLE1::SIZE_W;
    }
    else
    {
        paddle.x = PADDLE2::SIZE_X;
        paddle.y = PADDLE2::SIZE_Y;
        paddle.h = PADDLE2::SIZE_H;
        paddle.w = PADDLE2::SIZE_W;
    }
    
}
bool  Paddle::moveUp()
{
    paddle.y -= GLOBALS::stepPaddle;
}

bool  Paddle::modeDown()
{
    paddle.y += GLOBALS::stepPaddle;
}
double Paddle::get_x()
{
    return paddle.x;
}

double Paddle::get_y()
{
    return paddle.y;
}

void Paddle::set_x(float x)
{
    paddle.x = x;
}

void Paddle::set_y(float y)
{
    paddle.y = y;
}

SDL_Rect* Paddle::getForm()
{
    auto *out = &paddle; 
    return out;
}
