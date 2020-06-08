#ifndef layer_hpp
#define layer_hpp

#include <SDL.h>
#include <SDL_image.h>
#include <string>


class Layer
{
private:
    SDL_Renderer *renderer;
    SDL_Texture *bg1, *bg2, *bg3, *bg4;
    SDL_Rect outputRect1a, outputRect1b, outputRect2a, outputRect2b, outputRect3a, outputRect3b, outputRect4a, outputRect4b;

    std::string file1, file2, file3, file4;
    int SCREEN_WIDTH, SCREEN_HEIGHT;
    int textures;

public:
    Layer(SDL_Renderer *renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT, std::string file1);
    Layer(SDL_Renderer *renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT, std::string file1, std::string file2);
    Layer(SDL_Renderer *renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT, std::string file1, std::string file2, std::string file3);
    Layer(SDL_Renderer *renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT, std::string file1, std::string file2, std::string file3, std::string file4);

    void setXoffsets(int bgOffset1, int bgOffset2, int bgOffset3, int bgOffset4);
    void setYoffsets(int bgOffset1, int bgOffset2, int bgOffset3, int bgOffset4);
    void render();
};


#endif /* layer_hpp */
