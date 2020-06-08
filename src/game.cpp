#include "game.hpp"

/** --------------------------------------------------------------------------------------
 Consructs a new game object and then calls the game loop function. In this case the game
 object consists of a collision detection object, a background object with 3 layers and a
 ship object which is a particle with a texture.

 @param renderer      SDL2 render object to pass to constructors which require an instance
 @param SCREEN_WIDTH  Width of the game screen
 @param SCREEN_HEIGHT Height of the game screen
 */
Game::Game(SDL_Renderer* renderer, int &SCREEN_WIDTH, int &SCREEN_HEIGHT)
  : renderer(renderer), SCREEN_WIDTH(SCREEN_WIDTH), SCREEN_HEIGHT(SCREEN_HEIGHT)
{
    colDet = new ColDet(SCREEN_WIDTH, SCREEN_HEIGHT);

    background = new Layer(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, "images" + DS + "bg1.png", "images" + DS + "bg2.png");

    // Create ship rect, ship texture and bind texture to a new particle for ship.
    SDL_Rect shipRect = {0, 0, 64, 64};
    Texture *shipTexture = new Texture(renderer, "images" + DS + "ship.png", shipRect);

    // M_PI * 1.5 makes the particles heading upwards. 0 is Right, .5 is Down, 1 is Left
    angle = M_PI * 1.5;
    //                   x position        y position         speed heading friction gravity
    shipP = new Particle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0,    angle,  0.97,    0, shipTexture);


    foreground = new Layer(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, "images" + DS + "fg1.png");

    runGame();
}



/** --------------------------------------------------------------------------------------
 Main game loop, gets events, calculates any collisions based on those (user) events and
 then renders the frame

 */
void Game::runGame()
{
    while (!quit)
    {
        getEvents();

        getCollisions();

        render();
    }
}



/** --------------------------------------------------------------------------------------
 Get events from the user, such as key strokes or closing the window

 */
void Game::getEvents()
{
    SDL_Event event;

    // If the window is closed or the esc key is pressed, exiit
    while (SDL_PollEvent(&event))
    {
        if (currentKeyStates[SDL_SCANCODE_ESCAPE] || event.type == SDL_QUIT)
        {
            quit = true;
        }
    }

    if (currentKeyStates[SDL_SCANCODE_UP])
    {
        thrusting = true;
    }
    else
    {
        thrusting = false;
    }

    if (currentKeyStates[SDL_SCANCODE_RIGHT])
    {
        turningRight = true;
    }
    else
    {
        turningRight = false;
    }

    if (currentKeyStates[SDL_SCANCODE_DOWN])
    {
        braking = true;
    }
    else
    {
        braking = false;
    }

    if (currentKeyStates[SDL_SCANCODE_LEFT])
    {
        turningLeft = true;
    }
    else
    {
        turningLeft = false;
    }
}



/** --------------------------------------------------------------------------------------
 Calculate collision detection for each collision enabled object on screen

 */
void Game::getCollisions()
{
    // Pass the ship with it's center value of 32 (it's 64 x 64)
    colDet->bounceScreen(shipP, 32);
}



/** --------------------------------------------------------------------------------------
 Render the current frame given any changes made by the game setup or user, such as
 changes to the background or the heading or velocity of the ship. This function also adds
 the 16ms delay to hit ~60fps

 */
void Game::render()
{
    // Clear the window
    SDL_RenderClear(renderer);

    // Make any modifications to the background and then render it
    background->setYoffsets(0, 1, 0, 0);
    background->render();

    // Make any modifications to the ships direction and set the new heading
    if(turningRight)
    {
        angle += 0.05;
    }

    if(turningLeft)
    {
        angle -= 0.05;
    }

    shipP->setHeading(angle);

    // Make any modifications to the ships velocity and then update the ship
    if (thrusting)
    {
        shipP->accelerate(0.2);
    }
    else
    {
        shipP->accelerate(0);
    }

    shipP->update();

    // Make any modifications to the foreground and then render it
    foreground->setXoffsets(1, 0, 0, 0);
    foreground->render();

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // Render the changes above
    SDL_RenderPresent(renderer);

    // Delay for 16ms before looping again
    SDL_Delay(16);
}
