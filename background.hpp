#ifndef background_hpp
#define background_hpp

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <string>


class Background
{
private:
    SDL_Renderer *renderer;
    SDL_Texture *bg1, *bg2, *bg3, *bg4;
    SDL_Rect outputRect1a, outputRect1b, outputRect2a, outputRect2b, outputRect3a, outputRect3b, outputRect4a, outputRect4b;
    
    std::string file1, file2, file3, file4;
    const int SCREEN_WIDTH, SCREEN_HEIGHT;
    int layers;

public:
    Background(SDL_Renderer *renderer, const int &SCREEN_WIDTH, const int &SCREEN_HEIGHT, std::string file1, std::string file2);
    Background(SDL_Renderer *renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT, std::string file1, std::string file2, std::string file3);
    Background(SDL_Renderer *renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT, std::string file1, std::string file2, std::string file3, std::string file4);
    
    void setXoffsets(int bgOffset1, int bgOffset2, int bgOffset3, int bgOffset4);
    void setYoffsets(int bgOffset1, int bgOffset2, int bgOffset3, int bgOffset4);
    void render();
};


#endif /* background_hpp */
