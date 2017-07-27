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
    angle = M_PI * 1.5;
    SDL_Rect shipOR = {0, 0, 64, 64};
    Texture *shipT = new Texture(renderer, "ship.png", shipOR);
    shipP = new Particle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0, angle, 0.99, 0, shipT);

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
        turningRight = true;
    }
    else
    {
        turningRight = false;
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
        turningLeft = true;
    }
    else
    {
        turningLeft = false;
    }
}


// ------------------------------------------


void Game::getCollisions()
{
    colDet->bounce(shipP, 32);
}


// ------------------------------------------


void Game::render()
{
    // Clear the window
    SDL_RenderClear(renderer);
    
    // Set offset of background and draw it
    //background->setYoffsets(3, 5, 7, 0);
    //background->render();
    
    if(turningRight)
    {
        angle += 0.05;
    }
    
    if(turningLeft)
    {
        angle -= 0.05;
    }
    
    shipP->setTheading(angle);
    
    if (thrusting)
    {
        shipP->accelerate(0.2);
    }
    else
    {
        shipP->accelerate(0);
    }
    
    //shipP->accelerate();
    
    // Draw ship
    shipP->update();

    
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // Render the changes above
    SDL_RenderPresent(renderer);
    
    SDL_Delay(10);
}

