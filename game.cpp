#include "game.hpp"


/**
 fooT  = foo texture
 fooP  = foo particle
 fooIR = foo input rect
 fooOR = foo output rect
 */
Game::Game(SDL_Renderer* renderer, const int& SCREEN_WIDTH, const int& SCREEN_HEIGHT)
    : renderer(renderer), SCREEN_WIDTH(SCREEN_WIDTH), SCREEN_HEIGHT(SCREEN_HEIGHT)
{
    colDet = new ColDet(SCREEN_WIDTH, SCREEN_HEIGHT);
    background = new Background(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, "bg1.png", "bg2.png", "bg3.png");
    
    // Create ship rect, ship texture and bind texture to a new particle for ship.
    SDL_Rect shipOR = {0, 0, 64, 64};
    Texture* shipT = new Texture(renderer, "ship.png", shipOR);
    shipP = new Particle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0, 0, 0.99, 0, shipT);
    
    runGame();
}


// ------------------------------------------


void Game::runGame()
{
    while (!quit)
    {
        getEvents();

        getCollisions();

        render();
    }
}


// ------------------------------------------


void Game::getEvents()
{
    SDL_Event event;
    
    // If thr esc key is pressed, exit
    while (SDL_PollEvent(&event))
    {
        if ( event.type == SDL_QUIT )
        {
            quit = true;
        }
    }
    
    // If up key is pressed
    if( currentKeyStates[SDL_SCANCODE_UP])
    {
        thrusting = true;
    }
    else
    {
        thrusting = false;
    }
    
    // If right key is pressed
    if( currentKeyStates[SDL_SCANCODE_RIGHT])
    {
        angle += 0.075;
        newShipHeading = true;
    }
    
    // If the down key is pressed
    if( currentKeyStates[SDL_SCANCODE_DOWN])
    {
        braking = true;
    }
    else
    {
        braking = false;
    }
    
    // If left key is pressed
    if( currentKeyStates[SDL_SCANCODE_LEFT])
    {
        angle -= 0.075;
        newShipHeading = true;
    }
}


// ------------------------------------------


void Game::getCollisions()
{
    colDet->wrap(shipP, 32);
}


// ------------------------------------------


void Game::render()
{
    if (newShipHeading)
    {
        shipP->setHeading(angle);
        newShipHeading = false;
    }
    
    if (thrusting)
    {
        shipP->accelerate(0.2);
    }
 
    if (braking)
    {
        shipP->brake(0.96);
    }
    else
    {
        shipP->brake(0.99);
    }
    
    // Clear the window
    SDL_RenderClear(renderer);
    
    // Set offset of background and draw it
    background->setHorizontalOffsets(-3, -5, -7, 0);
    background->render();
    
    // Draw ship
    shipP->update();

    // Render the changes above
    SDL_RenderPresent(renderer);
    
    SDL_Delay(10);
}

