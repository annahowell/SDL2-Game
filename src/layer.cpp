#include "layer.hpp"

/** --------------------------------------------------------------------------------------
 Constructs a layer which acts as a container for an arbitrary number of textured inner
 layers

 @param renderer      Renderer to send the texture to
 @param SCREEN_WIDTH  The total width of the screen
 @param SCREEN_HEIGHT The total height of the screen
 */
Layer::Layer(SDL_Renderer *renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT)
    : renderer(renderer), SCREEN_WIDTH(SCREEN_WIDTH), SCREEN_HEIGHT(SCREEN_HEIGHT)
{
}



/** --------------------------------------------------------------------------------------
 Adds a new texture to the layer

 @param file1         Filename of first image used for the bottom image of layer
 */

void Layer::addLayer(const char* file)
{
    // Create output rectangle, 2 rectangles per layer, that each have the same texture
    // Second fills screen entirely as first is reset and first fills screen entirely as
    // second is reset and so on.
    SDL_Rect textureRectA = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_Rect textureRectB = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

    // Create SDL surface from image
    SDL_Surface* surface = IMG_Load(file);

    // Create hardware optimised SDL texture from the surface
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    // Free the surface after texture is made
    SDL_FreeSurface(surface);

    innerLayers.push_back(InnerLayer(texture, textureRectA, textureRectB));
}



/** --------------------------------------------------------------------------------------
 Deconstructs a layer consisting of an arbitrary amount of inner layers

 */
Layer::~Layer()
{
    //for(InnerLayer& innerLayer : innerLayers)
    //{
    //    innerLayer.~InnerLayer();
    //}
}



void Layer::offsetInnerLayer(int innerLayerNo, int xOffset, int yOffset)
{
    if (innerLayers.size() >= innerLayerNo)
    {
        if (xOffset != 0)
        {
            innerLayers.at(innerLayerNo - 1).setXoffset(xOffset, SCREEN_WIDTH, SCREEN_HEIGHT);
        }
        if (yOffset != 0)
        {
          innerLayers.at(innerLayerNo - 1).setYoffset(yOffset, SCREEN_WIDTH, SCREEN_HEIGHT);
        }
    }
}



/** --------------------------------------------------------------------------------------
 Render the layer with an arbitrary amount of inner layers
 */
void Layer::render()
{
  for(const InnerLayer& innerLayer : innerLayers)
  {
      innerLayer.render(renderer);
  }
}



/** ======================================================================================
 Constructs a new inner layer

 @param texture     Texture to use for the new inner layer
 @param textureRectA Primary texture rect which contains the texture
 @param textureRectB Secondary texture rect, follows the primary texture rect when it is
                     offset and fills what would otherwise be empty space with the texture
 */
InnerLayer::InnerLayer(SDL_Texture* texture, SDL_Rect textureRectA, SDL_Rect textureRectB)
    : texture(texture), textureRectA(textureRectA), textureRectB(textureRectB)
{
}



/** --------------------------------------------------------------------------------------
 Offsets the inner layer on the horizontal x axis

 @param yOffset         Horizontal offset to apply to the inner layer
 @param SCREEN_WIDTH    Width of the screen
 @param SCREEN_HEIGHT   Height of the screen
 */
void InnerLayer::setXoffset(int xOffset, int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
    // Move the primary texture rect of this inner layer by the specified amount, either
    // negatively (left) or positively (right)
    textureRectA.x += xOffset;

    // If the inner layer is being moved by a negative value (to the left)
    if (xOffset < 0)
    {
        // After negative (to left) offset is done, test to see if the right edge of the
        // primary texture srect is off the screen
        if (textureRectA.x + SCREEN_WIDTH < 0)
        {
            // If it is off the screen then add the width of the screen to the value,
            // essentially resetting its position
            textureRectA.x += SCREEN_WIDTH;
        }
        // We're using a negative value (moving inner layer left) so the second texture
        // rect needs to come in from the right
        textureRectB.x = (textureRectA.x + SCREEN_WIDTH);
    }
    // Otherwise the inner layer is being moved by a positive value (to the right)
    else
    {
        // After positive (to right) offset is done, test to see if the left edge of the
        // primary texture rect is off the screen
        if (textureRectA.x > SCREEN_WIDTH)
        {
            // If it is off the screen then subtract the width of the screen from the
            // value, essentially resetting its position
            textureRectA.x -= SCREEN_WIDTH;
        }
        // We're using a positive value (moving inner layer right) so the second texture
        // rect needs to come in from the left
        textureRectB.x = (textureRectA.x - SCREEN_WIDTH);
    }
}



/** --------------------------------------------------------------------------------------
 Offsets the inner layer on the vertical y axis

 @param yOffset         Horizontal offset to apply to the inner layer
 @param SCREEN_WIDTH    Width of the screen
 @param SCREEN_HEIGHT   Height of the screen
 */
void InnerLayer::setYoffset(int yOffset, int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
    textureRectA.y += yOffset;

    if (yOffset < 0)
    {
        if (textureRectA.y + SCREEN_HEIGHT < 0)
        {
            textureRectA.y += SCREEN_HEIGHT;
        }
        textureRectB.y = (textureRectA.y + SCREEN_HEIGHT);
    }
    else
    {
        if (textureRectA.y - SCREEN_HEIGHT > 0)
        {
            textureRectA.y -= SCREEN_HEIGHT;
        }
        textureRectB.y = (textureRectA.y - SCREEN_HEIGHT);
    }
}



/** --------------------------------------------------------------------------------------
 Render the layer with one, two, three or four textures.
 */
void InnerLayer::render(SDL_Renderer *renderer) const
{
    SDL_RenderCopy(renderer, texture, nullptr, &textureRectA);
    SDL_RenderCopy(renderer, texture, nullptr, &textureRectB);
}



/** --------------------------------------------------------------------------------------
 Deconstructs an inner layer

 */
InnerLayer::~InnerLayer()
{
    //SDL_DestroyTexture(texture);
    //texture = nullptr;
}
