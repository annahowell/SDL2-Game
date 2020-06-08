#include "texture.hpp"

/**
 Constructs a hardware texture from an image with a custom center of rotation

 @param renderer  Renderer to send the texture to
 @param path      Path of the file to use when creating the texture
 @param rect      The rectangle we bind the texture to ready for sending to renderer
 @param centerX   Center X point of texture in the rect, used for rotation / offset
 @param centerY   Center Y point of the texture in the rect, used for rotation / offset
 */
Texture::Texture(SDL_Renderer* renderer, std::string path, SDL_Rect &rect, int centerX, int centerY)
    : renderer(renderer), rect(rect)
{
    center.x = centerX;
    center.y = centerY;

    // Create SDL surface from image
    SDL_Surface* surface = IMG_Load(path.c_str());

    // Create hardware optimise SDL texture from the surface
    texture = SDL_CreateTextureFromSurface(renderer, surface);

    // Free the surface after texture is made
    SDL_FreeSurface(surface);
}



/**
 Construct a hardware texture from image with a default centered rotation center
 rect.w / 2 and rect.h / 2 are half the width and height of the output image

 @param renderer Renderer to send the texture to
 @param path     Path of the file to use when creating the texture
 @param rect     The rectangle we bind the texture to ready for sending to renderer
 */
Texture::Texture(SDL_Renderer* renderer, std::string path, SDL_Rect &rect)
    :Texture(renderer, path, rect, rect.w / 2, rect.h / 2) {}



/** --------------------------------------------------------------------------------------
 Sets the angle of the texture in degrees

 @param angle   Angle in human-friendly degrees
 */
void Texture::setAngleInDegrees(float angle)
{
    this->angle = angle;
}



/** --------------------------------------------------------------------------------------
 Sets the angle of the texture in radians

 @param angle   Angle in human-friendly degrees
 */
void Texture::setAngleInRadians(float angle)
{
    this->angle = angle * (180.0 / M_PI);
}



/** --------------------------------------------------------------------------------------
 Scrolls the texture on either the x or y axis

 @param xOffset   Amount to scroll per tick on the x axis (horizontally)
 @param yOffset   Amount to scroll per tick on the y axis (vertically)
 */
void Texture::scroll(int xOffset, int yOffset)
{
    rect.x = xOffset;
    rect.x = yOffset;
}



/** --------------------------------------------------------------------------------------
 Sets the location of the texture relative to its center point

 @param x   Horizontal location relative to center point
 @param y   Vertical location relative to center point
 */
void Texture::setLocation(float x, float y)
{
    rect.x = x - rect.w / 2;
    rect.y = y - rect.h / 2;
}



/** --------------------------------------------------------------------------------------
 Copies the texture to the render and in so doing making it visibile on screen

 */
void Texture::render()
{
    SDL_RenderCopyEx(renderer, texture, nullptr, &rect, angle, &center, SDL_FLIP_NONE );
}
