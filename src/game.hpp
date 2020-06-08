#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <cmath>

#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#include "particle.hpp"
#include "texture.hpp"
#include "layer.hpp"
#include "coldet.hpp"

using std::string;

class Game
{
private:
    SDL_Renderer* renderer;

    Particle *shipP;
    ColDet *colDet;
    Layer *background, *foreground;

    float angle = 0;
    bool quit, thrusting, braking, turningRight, turningLeft;
    int &SCREEN_WIDTH, &SCREEN_HEIGHT;
    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

    void runGame();
    void getEvents();
    void getCollisions();
    void render();

    #ifdef _WIN32
      const string DS = "\\";
    #else
      const string DS = "/";
    #endif

public:
    Game(SDL_Renderer* renderer, int &SCREEN_WIDTH, int &SCREEN_HEIGHT);
};


#endif /* game_hpp */
