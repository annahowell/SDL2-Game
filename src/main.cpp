#ifndef main_hpp
#define main_hpp

#include <SDL.h>
#include "game.hpp"

#endif

int main( int argc, char* args[] )
{
    int SCREEN_WIDTH = 800;
    int SCREEN_HEIGHT = 600;

    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {

        printf( "Failed to initialize SDL: %s\n", SDL_GetError() );
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow( "SDL2_Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

    if (window == NULL) {

        printf( "Failed to create window %s\n", SDL_GetError());
        return -1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    if (renderer == NULL) {

        printf( "Failed to create renderer: %s\n", SDL_GetError());
        return -1;

    } else {

        // Set size of renderer to the same as window
        SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

        // Set base color of renderer
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    }

    Game(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}
