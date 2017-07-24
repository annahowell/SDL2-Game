#include "texture.hpp"


/**
 Create a hardware texture from image with a custom center of rotation
 
 @param renderer Renderer to send the texture to
 @param path     Path of the file to use when creating the texture
 @param rect     The rectangle we bind the texture to ready for sending to renderer
 @param centerX  The center X point of the texture within the rect, used for rotation and/or offset
 @param centerY  The center Y point of the texture within the rect, used for rotation and/or offset
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
 Create a hardware texture from image with a default centered rotation center
 rect.w / 2 and rect.h / 2 are half the width and height of the output image

 @param renderer Renderer to send the texture to
 @param path     Path of the file to use when creating the texture
 @param rect     The rectangle we bind the texture to ready for sending to renderer
 */
Texture::Texture(SDL_Renderer* renderer, std::string path, SDL_Rect &rect)
    :Texture(renderer, path, rect, rect.w / 2, rect.h / 2) {}


// ------------------------------------------


void Texture::setAngleInDegrees(float angle)
{
    this->angle = angle;
}


// ------------------------------------------


void Texture::setAngleInRadians(float angle)
{
    this->angle = angle * (180.0 / M_PI);
}


// ------------------------------------------


void Texture::scrollHorizontally(int offset)
{
    rect.x = offset;
}


// ------------------------------------------


void Texture::scrollVertically(int offset)
{
    rect.y = offset;
}


// ------------------------------------------


void Texture::setLocation(float x, float y)
{
    rect.x = x - rect.w / 2;
    rect.y = y - rect.h / 2;
}


// ------------------------------------------


void Texture::render()
{
    SDL_RenderCopyEx(renderer, texture, nullptr, &rect, angle, &center, SDL_FLIP_NONE );
}
