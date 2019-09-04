#ifndef COMMON_DATA_H
#define COMMON_DATA_H

//Define what type of restriction has limited the ball`s movement
enum limits
{
    UP_DOWN_LIMIT,
    POINT_LIMIT,
    PADDLE_LIMIT,
};

// Define the edges of the window
namespace bounds
{
    const float min_x = 0.0;
    const float max_x = 600;
    const float min_y = 0.0;
    const float max_y = 600;
}

//define the colors of the paddle and ball
namespace colors
{
   const  int rgb_1 = 0;
   const  int rgb_2 = 0;
   const  int rgb_3 = 0;
}

//define global variable applicable to the game
 namespace GLOBALS
{
    const int RESET_POSITION_X = 300;
    const int RESET_POSITION_Y = 200;
    float MAX_SPEED = 10.0;
    const float rate_sdl_speed = 25000.0;
    const int stepPaddle = 20;
}
//Define ball size and initial position
namespace BALL
{
    const int SIZE_X = 200;
    const int SIZE_Y = 300;
    const int SIZE_W = 10;
    const int SIZE_H = 10;
}
//define paddle size and initial position
namespace PADDLE1
{
    const int SIZE_X = 20;
    const int SIZE_Y = 200;
    const int SIZE_W = 20;
    const int SIZE_H = 200;
}
//define paddle size and initial position 
namespace PADDLE2
{
    const int SIZE_X = 560;
    const int SIZE_Y = 200;
    const int SIZE_W = 20;
    const int SIZE_H = 200;
}
// Define which side the paddle should be
namespace SIDE
{
    bool left = false;
    bool right = true;
}
// Define which side the paddles should appear in score output
namespace PLAYER
{
    bool PLAYER1 = false;
    bool PLAYER2 = true;
}

#endif

