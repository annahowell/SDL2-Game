#include "game.hpp"

/** --------------------------------------------------------------------------------------
 Consructs a new game object and then calls the game loop function. In this case the game
 object consists of a collision detection object, a background layer with 2 textures and
 a foreground layer with 1 texture

 @param renderer      SDL2 render object to pass to constructors which require an instance
 @param SCREEN_WIDTH  Width of the game screen
 @param SCREEN_HEIGHT Height of the game screen
 */
Game::Game(SDL_Renderer* renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT)
  : renderer(renderer), SCREEN_WIDTH(SCREEN_WIDTH), SCREEN_HEIGHT(SCREEN_HEIGHT)
{
    colDet = new ColDet(SCREEN_WIDTH, SCREEN_HEIGHT);

    background = new Layer(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    background->addLayer("images/bg1.png");
    background->addLayer("images/bg2.png");

    foreground = new Layer(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
    foreground->addLayer("images/fg1.png");
}



/** --------------------------------------------------------------------------------------
 Main game loop, gets events, calculates any collisions based on those (user) events and
 then renders a frame

 */
void Game::runGame()
{
    createShip();

    quit = false;

    while (!quit)
    {
        getEvents();

        getCollisions();

        render();
    }
}



/** --------------------------------------------------------------------------------------
 Creates a new particle with a space ship texture that the player can later control

 */
void Game::createShip()
{
    // Create ship rectangle and texture, then bind the texture to a new ship particle
    SDL_Rect shipRect = {0, 0, 64, 64};
    Texture *shipTexture = new Texture(renderer, "images" + DS + "ship.png", shipRect);

    // M_PI * 1.5 makes the particles heading upwards. 0 is Right, .5 is Down, 1 is Left
    angle = M_PI * 1.5;
    //                   x position        y position         speed heading friction gravity
    ship = new Particle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0,    angle,  0.97,    0, shipTexture);
}



/** --------------------------------------------------------------------------------------
 Get events from the user, such as key strokes or closing the window and update variables
 the game state uses accordingly

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

    thrusting = currentKeyStates[SDL_SCANCODE_UP];
    braking = currentKeyStates[SDL_SCANCODE_DOWN];

    turningRight = currentKeyStates[SDL_SCANCODE_RIGHT];
    turningLeft = currentKeyStates[SDL_SCANCODE_LEFT];
}



/** --------------------------------------------------------------------------------------
 Calculate collision detection for each collision enabled object on screen

 */
void Game::getCollisions()
{
    // Pass the ship with it's center value of 32 (it's 64 x 64)
    colDet->bounceScreen(ship, 32);
}



/** --------------------------------------------------------------------------------------
 Render the current frame after any changes made by the game setup or user, such as
 scrolling the background, or the heading / velocity of the ship. This function also adds
 the 16ms delay to hit ~60fps

 */
void Game::render()
{
    // Clear the window
    SDL_RenderClear(renderer);

    // Scroll the second inner layer positive 1 pixel on the y axis (downwards)
    background->offsetInnerLayer(2, 0, 1);
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

    ship->setHeading(angle);

    // Make any modifications to the ships velocity and then update the ship
    if (thrusting)
    {
        ship->accelerate(0.2);
    }
    else
    {
        ship->accelerate(0);
    }

    if (braking)
    {
        ship->decelerate(0.075);
    }

    ship->update();

    // Scroll the first inner layer positive 1 pixel on the x axis (right)
    foreground->offsetInnerLayer(1, 1, 0);
    foreground->render();

    // Render the frame with the above changes
    SDL_RenderPresent(renderer);
}
