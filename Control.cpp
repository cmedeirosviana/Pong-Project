#include "Control.h"
#include "Design.h"
#include <unistd.h>
#include <chrono>
#include <iostream>
#include "Common_data.h"

using namespace std;

Paddle paddle1(false);
Paddle paddle2(true);

Control::Control()
{
    design.createGame();
    design.createForms(ball,paddle1,paddle2);
}

Control::~Control()
{
    design.quitGame();
}

void Control::play()
{
    target_frame_duration = GLOBALS::rate_sdl_speed;
    bool status = true;
    update();
    
    while(running == true)
    {
        SDL_PollEvent(&event);

        if (event.type == SDL_QUIT)
        {
            running = false;

            break;
        }

        auto frame_start = chrono::steady_clock::now();
        design.controlLogics(paddle1,paddle2,event);
        setPaddleLimits(paddle1,paddle2);

        status = design.pointPause(event);

        if (status == false)
        {
            ball.DefineNewPosition();
            checkBallLimits(ball);
            design.createForms(ball,paddle1,paddle2);
        }

        auto frame_end = chrono::steady_clock::now();
        auto frame_duration = chrono::duration_cast<chrono::microseconds>(frame_end  - frame_start).count();

        if (frame_duration < target_frame_duration )
        {
            usleep(target_frame_duration - frame_duration);
        }
    }
}

void Control::checkBallLimits(Ball & ball)
{
    if ((ball.getBall_y()) > (bounds::max_y - BALL::SIZE_H) || (ball.getBall_y() + BALL::SIZE_H) < bounds::min_y)
    { 
        ball.changeDirection(limits::UP_DOWN_LIMIT);
    }
    if((paddle2.get_y() < (ball.getBall_y() + BALL::SIZE_H)) && ((paddle2.get_y() + PADDLE2::SIZE_H) >  ball.getBall_y()))
    {
        if((paddle2.get_x() > ball.getBall_x() ) && (paddle2.get_x() < (ball.getBall_x() + BALL::SIZE_W)))
        {
            ball.changeDirection(limits::PADDLE_LIMIT);  
        }
    }
    if ((paddle1.get_y() < (ball.getBall_y() + BALL::SIZE_H)) && ((paddle1.get_y() + PADDLE1::SIZE_H) >  ball.getBall_y()))
    {
        if((paddle1.get_x() < ball.getBall_x()) && ((paddle1.get_x() + PADDLE1::SIZE_W) > ball.getBall_x()))
        {
            ball.changeDirection(limits::PADDLE_LIMIT);
        }
    }
    if ((ball.getBall_x() > bounds::max_x) || ball.getBall_x() < bounds::min_x)
    {
        if (ball.getBall_x() > bounds::max_x)
        {
            countPoint(PLAYER::PLAYER1);
        }
        else
        {
            countPoint(PLAYER::PLAYER2);
        }

        ball.resetBallPosition();
    }
}

void Control::setPaddleLimits(Paddle &Paddle1,Paddle &Paddle2)
{   
    if ((Paddle1.get_y()) > (bounds::max_y - PADDLE1::SIZE_H)) Paddle1.set_y(bounds::max_y - PADDLE1::SIZE_H);
    if (Paddle1.get_y() < bounds::min_y) Paddle1.set_y(bounds::min_y);
    if ((Paddle2.get_y()) > (bounds::max_y - PADDLE2::SIZE_H)) Paddle2.set_y(bounds::max_y - PADDLE2::SIZE_H); 
    if (Paddle2.get_y() < bounds::min_y) Paddle2.set_y(bounds::min_y);
}

void Control::update()
{  
    ball.resetBallPosition();
}

void Control::countPoint(bool player)
{
    if(player == PLAYER::PLAYER1)
    {
        pointPlayer1 ++;
    }
    else
    {
        pointPlayer2 ++;
    }
    cout << "PLAYER_1: " << pointPlayer1 << " X " << pointPlayer2 << " :PLAYER_2" << endl;;
}