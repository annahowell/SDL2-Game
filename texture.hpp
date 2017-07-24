#ifndef texture_hpp
#define texture_hpp

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <stdio.h>
#include <cmath>
#include <string>


class Texture
{
private:
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Rect rect;
    SDL_Point center;
    double angle = 0;
    
public:
    Texture(SDL_Renderer* renderer, std::string path, SDL_Rect &rect, int centerX, int centerY);
    Texture(SDL_Renderer* renderer, std::string path, SDL_Rect &rect);
    
    void setAngleInDegrees(float angle);
    void setAngleInRadians(float angle);
    void scrollHorizontally(int offset);
    void scrollVertically(int offset);
    void setLocation(float x, float y);
    void render();
};

#endif /* texture_hpp */
