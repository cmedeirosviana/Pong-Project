#include "Ball.h"
#include <cstdlib>
#include <math.h> 

using namespace BALL;
using namespace GLOBALS;


Ball::Ball()
{
    ball.x = SIZE_X;
    ball.y = SIZE_Y;
    ball.h = SIZE_H;
    ball.w = SIZE_W;
}

void Ball::changeDirection(limits data)
{
    if(data == limits::PADDLE_LIMIT)
    {
        speed_x = - speed_x;
        speed_y = + speed_y;
    }
    else if(data == limits::UP_DOWN_LIMIT)
    {
        speed_x =   speed_x;
        speed_y = - speed_y;
    }
}

void Ball::resetBallPosition()
{
    setBallPosition(RESET_POSITION_X,RESET_POSITION_Y);
    speed_x = MAX_SPEED;
    speed_y = MAX_SPEED;
    angle = defineDirection();
}

float Ball::defineDirection()
{
    srand(time(NULL));
	int angle = rand() % 45;
    return angle ;
}

void Ball::DefineNewPosition()
{
    auto x = getBall_x() +  speed_x * cos(angle * 3.14 / 180.0);
    auto y = getBall_y() +  speed_y * sin(angle * 3.14 / 180.0);
    setBallPosition(x,y);
}

float Ball::getBall_x()
{
    return ball.x;
}

float Ball::getBall_y()
{
    return ball.y;
}

void Ball::setBallPosition(int x,int y)
{
    ball.x = x;
    ball.y = y;
}

SDL_Rect* Ball::getForm()
{
    auto *out = &ball; 
    return out;
}

