#include "background.hpp"

/**
 Create a parallax background with two layers
 
 @param renderer      Renderer to send the texture to
 @param SCREEN_WIDTH  The total width of the screen
 @param SCREEN_HEIGHT The total height of the screen
 @param file1         The filename of the first image used for the bottom layer of the background
 @param file2         The filename of the second image, used for the top layer of the background
 */
Background::Background(SDL_Renderer *renderer, const int &SCREEN_WIDTH, const int &SCREEN_HEIGHT, std::string file1, std::string file2)
    : renderer(renderer), SCREEN_WIDTH(SCREEN_WIDTH), SCREEN_HEIGHT(SCREEN_HEIGHT)
{
    // Background has 2 layers
    layers = 2;

    // Create output rectangles, 2 per layer, that each have the same texture
    // Second fills screen entirely as first is reset and first fills screen entirely as second is reset and so on.
    outputRect1a = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    outputRect1b = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    outputRect2a = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    outputRect2b = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    
    // Create SDL surfaces from images
    SDL_Surface* surface1 = IMG_Load(file1.c_str());
    SDL_Surface* surface2 = IMG_Load(file2.c_str());
    
    // Create hardware optimise SDL textures from the surfaces
    bg1 = SDL_CreateTextureFromSurface(renderer, surface1);
    bg2 = SDL_CreateTextureFromSurface(renderer, surface2);

    SDL_FreeSurface(surface1);
    SDL_FreeSurface(surface2);
}


/**
 Create a parallax background with three layers
 
 @param renderer      Renderer to send the texture to
 @param SCREEN_WIDTH  The total width of the screen
 @param SCREEN_HEIGHT The total height of the screen
 @param file1         The filename of the first image, used for the bottom layer of the background
 @param file2         The filename of the second image, used for the middle layer of the background
 @param file3         The filename of the third image, used for the top layer of the background
 */
Background::Background(SDL_Renderer *renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT, std::string file1, std::string file2, std::string file3)
    : Background (renderer, SCREEN_WIDTH, SCREEN_HEIGHT, file1, file2)
{
    // This background has 3 layers
    layers = 3;
    
    // So it needs 2 additional output rectangles for that layer
    outputRect3a = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    outputRect3b = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    
    // Create third SDL surface from image
    SDL_Surface* surface3 = IMG_Load(file3.c_str());
    
    // Create third hardware optimised SDL texture from the surface
    bg3 = SDL_CreateTextureFromSurface(renderer, surface3);

    // Free the surface after texture is made
    SDL_FreeSurface(surface3);
}


/**
 Create a parallax background with four layers
 
 @param renderer      Renderer to send the texture to
 @param SCREEN_WIDTH  The total width of the screen
 @param SCREEN_HEIGHT The total height of the screen
 @param file1         The filename of the first image, used for the bottom layer of the background
 @param file2         The filename of the second image, used for the middle-bottom layer of the background
 @param file3         The filename of the third image, used for the middle-top layer of the background
 @param file4         The filename of the fourth image, used for the top layer of the background
 */
Background::Background(SDL_Renderer *renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT, std::string file1, std::string file2, std::string file3, std::string file4)
    : Background (renderer, SCREEN_WIDTH, SCREEN_HEIGHT, file1, file2, file3)
{
    layers = 4;
    
    outputRect4a = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    outputRect4b = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    
    SDL_Surface* surface4 = IMG_Load(file4.c_str());
    
    bg4 = SDL_CreateTextureFromSurface(renderer, surface4);

    SDL_FreeSurface(surface4);
}


/**
 Increment the horizontal offsets for each layer. Always accepts 4 integers, 0 if layer doesn't exist or isn't required to move.
 Accepts both positve and negative values. Negative moves the image left, positive moves the image to the right.
 
 @param bgOffset1  The amount of offset to apply to the first (bottom) layer of the background
 @param bgOffset2  The amount of offset to apply to the second (middle-bottom) layer of the background
 @param bgOffset3  The amount of offset to apply to the third (middle-top) layer of the background
 @param bgOffset4  The amount of offset to apply to the fourth (top) layer of the background
 */
void Background::setXoffsets(int bgOffset1, int bgOffset2, int bgOffset3, int bgOffset4)
{
    // If the background has been moved
    if (bgOffset1 != 0)
    {
        // Move the primary background image on this layer by specified amount, either negatively(left) or positively(right)
        outputRect1a.x += bgOffset1;
    
        // If the background is being moved by a negative value (to the left)
        if (bgOffset1 < 0)
        {
            // After negative (to left) offset is done, test to see if the right edge of the first image is off the screen
            if (outputRect1a.x + SCREEN_WIDTH < 0)
            {
                // If it is then add the width of the screen to the value, essentially resetting its position
                outputRect1a.x += SCREEN_WIDTH;
            }
            // We're using a negative value (moving image left) so the second image needs to come in from the right
            outputRect1b.x = (outputRect1a.x + SCREEN_WIDTH);
        }
        // Otherwise the background is being moved by a positive value (to the right)
        else
        {
            // After positive (to right) offset is done, test to see if the left edge of the first image is off the screen
            if (outputRect1a.x > SCREEN_WIDTH)
            {
                // If it is then subtract the width of the screen from the value, essentially resetting its position
                outputRect1a.x -= SCREEN_WIDTH;
            }
            // We're using a positive value (moving image right) so the second image needs to come in from the left
            outputRect1b.x = (outputRect1a.x - SCREEN_WIDTH);
        }
    }
    
    if (bgOffset2 != 0)
    {
        outputRect2a.x += bgOffset2;
        
        if (bgOffset2 < 0)
        {
            if (outputRect2a.x + SCREEN_WIDTH < 0)
            {
                outputRect2a.x += SCREEN_WIDTH;
            }
            outputRect2b.x = (outputRect2a.x + SCREEN_WIDTH);
        }
        else
        {
            if (outputRect2a.x - SCREEN_WIDTH > 0)
            {
                outputRect2a.x -= SCREEN_WIDTH;
            }
            outputRect2b.x = (outputRect2a.x - SCREEN_WIDTH);
        }
    }
    
    if (bgOffset3 != 0)
    {
        outputRect3a.x += bgOffset3;
        
        if (bgOffset3 < 0)
        {
            if (outputRect3a.x + SCREEN_WIDTH < 0)
            {
                outputRect3a.x += SCREEN_WIDTH;
            }
            outputRect3b.x = (outputRect3a.x + SCREEN_WIDTH);
        }
        else
        {
            if (outputRect3a.x - SCREEN_WIDTH > 0)
            {
                outputRect3a.x -= SCREEN_WIDTH;
            }
            outputRect3b.x = (outputRect3a.x - SCREEN_WIDTH);
        }
    }
    
    if (bgOffset4 != 0)
    {
        outputRect4a.x += bgOffset4;
        
        if (bgOffset4 < 0)
        {
            if (outputRect4a.x + SCREEN_WIDTH < 0)
            {
                outputRect4a.x += SCREEN_WIDTH;
            }
            outputRect4b.x = (outputRect4a.x + SCREEN_WIDTH);
        }
        else
        {
            if (outputRect4a.x - SCREEN_WIDTH > 0)
            {
                outputRect4a.x -= SCREEN_WIDTH;
            }
            outputRect4b.x = (outputRect4a.x - SCREEN_WIDTH);
        }
    }
}


/**
 Increment the vertical offsets for each layer. Always accepts 4 integers, 0 if layer doesn't exist or isn't required to move.
 Accepts both positve and negative values. Negative moves the image up, positive moves the image down.
 
 @param bgOffset1  The amount of offset to apply to the first (bottom) layer of the background
 @param bgOffset2  The amount of offset to apply to the second (middle-bottom) layer of the background
 @param bgOffset3  The amount of offset to apply to the third (middle-top) layer of the background
 @param bgOffset4  The amount of offset to apply to the fourth (top) layer of the background
 */
void Background::setYoffsets(int bgOffset1, int bgOffset2, int bgOffset3, int bgOffset4)
{
    if (bgOffset1 != 0)
    {
        outputRect1a.y += bgOffset1;
        
        if (bgOffset1 < 0)
        {
            if (outputRect1a.y + SCREEN_HEIGHT < 0)
            {
                outputRect1a.y += SCREEN_HEIGHT;
            }
            outputRect1b.y = (outputRect1a.y + SCREEN_HEIGHT);
        }
        else
        {
            if (outputRect1a.y - SCREEN_HEIGHT > 0)
            {
                outputRect1a.y -= SCREEN_HEIGHT;
            }
            outputRect1b.y = (outputRect1a.y - SCREEN_HEIGHT);
        }
    }
    
    if (bgOffset2 != 0)
    {
        outputRect2a.y += bgOffset2;
        
        if (bgOffset2 < 0)
        {
            if (outputRect2a.y + SCREEN_HEIGHT < 0)
            {
                outputRect2a.y += SCREEN_HEIGHT;
            }
            outputRect2b.y = (outputRect2a.y + SCREEN_HEIGHT);
        }
        else
        {
            if (outputRect2a.y - SCREEN_HEIGHT > 0)
            {
                outputRect2a.y -= SCREEN_HEIGHT;
            }
            outputRect2b.y = (outputRect2a.y - SCREEN_HEIGHT);
        }
    }
    
    if (bgOffset3 != 0)
    {
        outputRect3a.y += bgOffset3;
        
        if (bgOffset3 < 0)
        {
            if (outputRect3a.y + SCREEN_HEIGHT < 0)
            {
                outputRect3a.y += SCREEN_HEIGHT;
            }
            outputRect3b.y = (outputRect3a.y + SCREEN_HEIGHT);
        }
        else
        {
            if (outputRect3a.y - SCREEN_HEIGHT > 0)
            {
                outputRect3a.y -= SCREEN_HEIGHT;
            }
            outputRect3b.y = (outputRect3a.y - SCREEN_HEIGHT);
        }
    }
    
    if (bgOffset4 != 0)
    {
        outputRect4a.y += bgOffset4;
        
        if (bgOffset4 < 0)
        {
            if (outputRect4a.y + SCREEN_HEIGHT < 0)
            {
                outputRect4a.y += SCREEN_HEIGHT;
            }
            outputRect4b.y = (outputRect4a.y + SCREEN_HEIGHT);
        }
        else
        {
            if (outputRect4a.y - SCREEN_HEIGHT > 0)
            {
                outputRect4a.y -= SCREEN_HEIGHT;
            }
            outputRect4b.y = (outputRect4a.y - SCREEN_HEIGHT);
        }
    }
}


/**
 Render the background with two, three or four layers.
 */
void Background::render()
{
    SDL_RenderCopy(renderer, bg1, nullptr, &outputRect1a);
    SDL_RenderCopy(renderer, bg1, nullptr, &outputRect1b);

    SDL_RenderCopy(renderer, bg2, nullptr, &outputRect2a);
    SDL_RenderCopy(renderer, bg2, nullptr, &outputRect2b);
    
    if (layers != 2)
    {
        SDL_RenderCopy(renderer, bg3, nullptr, &outputRect3a);
        SDL_RenderCopy(renderer, bg3, nullptr, &outputRect3b);
        
        if (layers == 4)
        {
            SDL_RenderCopy(renderer, bg4, nullptr, &outputRect4a);
            SDL_RenderCopy(renderer, bg4, nullptr, &outputRect4b);
        }
    }
}
