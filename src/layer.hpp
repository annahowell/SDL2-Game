#ifndef layer_hpp
#define layer_hpp

#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <string>


class InnerLayer
{
private:
    SDL_Texture *texture;
    SDL_Rect textureRectA, textureRectB;

public:
    InnerLayer(SDL_Texture* texture, SDL_Rect textureRectA, SDL_Rect textureRectB);
    ~InnerLayer();

    void render(SDL_Renderer *renderer) const;
    void setXoffset(int SCREEN_WIDTH, int SCREEN_HEIGHT, int xOffset);
    void setYoffset(int SCREEN_WIDTH, int SCREEN_HEIGHT, int yOffset);
};


class Layer
{
private:
    SDL_Renderer *renderer;
    int SCREEN_WIDTH, SCREEN_HEIGHT;
    std::vector<InnerLayer> innerLayers;

public:
    Layer(SDL_Renderer *renderer, int SCREEN_WIDTH, int SCREEN_HEIGHT);
    ~Layer();

    void offsetInnerLayer(int innerLayerNo, int xOffset, int yOffset);
    void addLayer(const char* file);
    void render();
};


#endif /* layer_hpp */
