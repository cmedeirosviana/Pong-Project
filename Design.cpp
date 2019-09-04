#include "Design.h"
#include "Common_data.h"
#include <SDL2/SDL.h>

using namespace std;

void Design::createGame()   
{
    SDL_Init(SDL_INIT_EVERYTHING);
    
    window = SDL_CreateWindow(
			"PONG GAME",
			SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
			600, 600,
			SDL_WINDOW_SHOWN
			);

  if (window == NULL)
   {
        fprintf(stderr, "could not create window: %s\n", SDL_GetError());
   }

   screen = SDL_GetWindowSurface(window);

    if (screen == NULL)
    {
        fprintf(stderr, "could not get window: %s\n", SDL_GetError());
    }

    SDL_UpdateWindowSurface(window);

    renderer = SDL_CreateRenderer(window, 2, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {
      SDL_Log("Could not create a renderer: %s", SDL_GetError());
    }

}

void Design::createForms(Ball &ball,Paddle &paddle1,Paddle &paddle2)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawLine(renderer,0,599,599,599);
    SDL_RenderDrawLine(renderer,0,0,600,0);
    SDL_RenderFillRect(renderer, ball.getForm());
    SDL_RenderFillRect(renderer, paddle1.getForm());
    SDL_RenderFillRect(renderer, paddle2.getForm());
    SDL_RenderPresent(renderer);
}

void Design::quitGame()
{   
    SDL_FreeSurface(screen); screen = NULL;
    SDL_DestroyWindow(window); window = NULL;
    SDL_DestroyRenderer(renderer); renderer =NULL;
    SDL_Quit();
}

void Design::controlLogics(Paddle &Paddle1,Paddle &Paddle2,SDL_Event &event)
{

    if(event.type == SDL_KEYDOWN)
    {
        if(event.key.keysym.sym == SDLK_u)
        {
            Paddle2.moveUp();
        }
        if(event.key.keysym.sym == SDLK_j)
        {
            Paddle2.modeDown();
        }
        if(event.key.keysym.sym == SDLK_w)
        {
            Paddle1.moveUp();
        }
        if(event.key.keysym.sym == SDLK_s)
        {
            Paddle1.modeDown();
        }
    }
}

Uint32 Design::getColor()
{
    auto color = SDL_MapRGB(screen->format,colors::rgb_1,colors::rgb_1,colors::rgb_1);
    return color;
}

bool Design::pointPause(SDL_Event &event)
{
    if(event.key.keysym.sym == SDLK_SPACE)
    {
        return true;
    }
    return false;
}