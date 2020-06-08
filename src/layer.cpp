#include "layer.hpp"

/** --------------------------------------------------------------------------------------
 Construct a layer consisting of a single texture

 @param renderer      Renderer to send the texture to
 @param SCREEN_WIDTH  The total width of the screen
 @param SCREEN_HEIGHT The total height of the screen
 @param file1         Filename of first image used for the bottom image of layer
 */
Layer::Layer(SDL_Renderer *renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT, std::string file1)
    : renderer(renderer), SCREEN_WIDTH(SCREEN_WIDTH), SCREEN_HEIGHT(SCREEN_HEIGHT)
{
    // Layer has 1 texture
    textures = 1;

    // Create output rectangle, 2 rectangles per layer, that each have the same texture
    // Second fills screen entirely as first is reset and first fills screen entirely as
    // second is reset and so on.
    outputRect1a = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    outputRect1b = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

    // Create SDL surfaces from images
    SDL_Surface* surface1 = IMG_Load(file1.c_str());

    // Create hardware optimise SDL textures from the surfaces
    bg1 = SDL_CreateTextureFromSurface(renderer, surface1);

    SDL_FreeSurface(surface1);
}



/** --------------------------------------------------------------------------------------
 Construct a layer consisting of two textures

 @param renderer        Renderer to send the texture to
 @param SCREEN_WIDTH    The total width of the screen
 @param SCREEN_HEIGHT   The total height of the screen
 @param file1           Filename of first image, used for bottom image of the layer
 @param file2           Filename of second image, used for middle image of the layer
 */
Layer::Layer(SDL_Renderer *renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT, std::string file1, std::string file2)
    : Layer (renderer, SCREEN_WIDTH, SCREEN_HEIGHT, file1)
{
    // This layer has 2 textures
    textures = 2;

    // So it needs 2 additional output rectangles for that layer
    outputRect2a = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    outputRect2b = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

    // Create third SDL surface from image
    SDL_Surface* surface2 = IMG_Load(file2.c_str());

    // Create third hardware optimised SDL texture from the surface
    bg2 = SDL_CreateTextureFromSurface(renderer, surface2);

    // Free the surface after texture is made
    SDL_FreeSurface(surface2);
}


/** --------------------------------------------------------------------------------------
 Constructs a layer consisting of three textures

 @param renderer        Renderer to send the texture to
 @param SCREEN_WIDTH    The total width of the screen
 @param SCREEN_HEIGHT   The total height of the screen
 @param file1           Filename of first image, used for bottom image of the layer
 @param file2           Filename of second image, used for middle image of the layer
 @param file3           Filename of third image, used for top image of the layer
 */
Layer::Layer(SDL_Renderer *renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT, std::string file1, std::string file2, std::string file3)
    : Layer (renderer, SCREEN_WIDTH, SCREEN_HEIGHT, file1, file2)
{
    textures = 3;

    outputRect3a = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    outputRect3b = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

    SDL_Surface* surface3 = IMG_Load(file3.c_str());

    bg3 = SDL_CreateTextureFromSurface(renderer, surface3);

    SDL_FreeSurface(surface3);
}



/** --------------------------------------------------------------------------------------
 Constructs a layer consisting of four textures

 @param renderer        Renderer to send the texture to
 @param SCREEN_WIDTH    The total width of the screen
 @param SCREEN_HEIGHT   The total height of the screen
 @param file1           Filename of first image, used for bottom image of layer
 @param file2           Filename of second image, used for middle-bottom image of layer
 @param file3           Filename of third image, used for middle-top image of layer
 @param file4           Filename offourth image, used for top image of layer
 */
Layer::Layer(SDL_Renderer *renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT, std::string file1, std::string file2, std::string file3, std::string file4)
    : Layer (renderer, SCREEN_WIDTH, SCREEN_HEIGHT, file1, file2, file3)
{
    textures = 4;

    outputRect4a = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    outputRect4b = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

    SDL_Surface* surface4 = IMG_Load(file4.c_str());

    bg4 = SDL_CreateTextureFromSurface(renderer, surface4);

    SDL_FreeSurface(surface4);
}



/** --------------------------------------------------------------------------------------
 Increment the horizontal offsets for each layer. Always accepts 4 integers, 0 if layer
 doesn't exist or isn't required to move. Accepts both positve and negative values.
 Negative moves the image left, positive moves the image to the right.

 @param bgOffset1  Horizontal offset to apply to first (bottom) image of the layer
 @param bgOffset2  Horizontal offset to apply to second (middle-bottom) image of the layer
 @param bgOffset3  Horizontal offset to apply to third (middle-top) image of the layer
 @param bgOffset4  Horizontal offset to apply to fourth (top) image of the layer
 */
void Layer::setXoffsets(int bgOffset1, int bgOffset2, int bgOffset3, int bgOffset4)
{
    // If the texture has been moved
    if (bgOffset1 != 0)
    {
        // Move the primary texture rect of this texture by the specified amount, either
        // negatively (left) or positively (right)
        outputRect1a.x += bgOffset1;

        // If the texture is being moved by a negative value (to the left)
        if (bgOffset1 < 0)
        {
            // After negative (to left) offset is done, test to see if the right edge of
            // the first texture rect is off the screen
            if (outputRect1a.x + SCREEN_WIDTH < 0)
            {
                // If it is then add the width of the screen to the value, essentially
                // resetting its position
                outputRect1a.x += SCREEN_WIDTH;
            }
            // We're using a negative value (moving rect left) so the second rect needs
            // to come in from the right
            outputRect1b.x = (outputRect1a.x + SCREEN_WIDTH);
        }
        // Otherwise the texture is being moved by a positive value (to the
        // right)
        else
        {
            // After positive (to right) offset is done, test to see if the left edge of
            // the first texture rect is off the screen
            if (outputRect1a.x > SCREEN_WIDTH)
            {
                // If it is then subtract the width of the screen from the value,
                // essentially resetting its position
                outputRect1a.x -= SCREEN_WIDTH;
            }
            // We're using a positive value (moving texture rect right) so the second rect
            // needs to come in from the left
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
 Increment the vertical offsets for each layer. Always accepts 4 integers, 0 if texture
 doesn't exist or isn't required to move. Accepts both positve and negative values.
 Negative moves the texture up, positive moves the texture down

 @param bgOffset1  Vertical offset to apply to first (bottom) texture of the layer
 @param bgOffset2  Vertical offset to apply to second (middle-bottom) texture of the layer
 @param bgOffset3  Vertical offset to apply to third (middle-top) texture of the layer
 @param bgOffset4  Vertical offset to apply to fourth (top) texture of the layer
 */
void Layer::setYoffsets(int bgOffset1, int bgOffset2, int bgOffset3, int bgOffset4)
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



/** --------------------------------------------------------------------------------------
 Render the layer with one, two, three or four textures.
 */
void Layer::render()
{
    SDL_RenderCopy(renderer, bg1, nullptr, &outputRect1a);
    SDL_RenderCopy(renderer, bg1, nullptr, &outputRect1b);

    if (textures > 1)
    {
        SDL_RenderCopy(renderer, bg2, nullptr, &outputRect2a);
        SDL_RenderCopy(renderer, bg2, nullptr, &outputRect2b);

        if (textures > 2)
        {
            SDL_RenderCopy(renderer, bg3, nullptr, &outputRect3a);
            SDL_RenderCopy(renderer, bg3, nullptr, &outputRect3b);

            if (textures > 3)
            {
                SDL_RenderCopy(renderer, bg4, nullptr, &outputRect4a);
                SDL_RenderCopy(renderer, bg4, nullptr, &outputRect4b);
            }
        }
    }
}
