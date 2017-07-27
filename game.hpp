#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <SDL2_gfx/SDL2_gfxPrimitives.h>
#include <cmath>
#include "particle.hpp"
#include "texture.hpp"
#include "background.hpp"
#include "coldet.hpp"


class Game
{
private:
    SDL_Renderer* renderer;
    
    Particle *shipP;
    ColDet *colDet;
    Background *background;
    
    float angle = 0;
    bool playing, quit, newShipHeading, thrusting, braking, turningRight, turningLeft;
    const int SCREEN_WIDTH, SCREEN_HEIGHT;
    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
    
    void runGame();
    void getEvents();
    void getCollisions();
    void render();
    
public:
    Game(SDL_Renderer* renderer, const int &SCREEN_WIDTH, const int& SCREEN_HEIGHT);
};


#endif
