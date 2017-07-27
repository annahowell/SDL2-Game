#ifndef coldet_hpp
#define coldet_hpp

#include <SDL2/SDL.h>
#include <stdio.h>
#include "particle.hpp"


class ColDet {
    
private:
    const int SCREEN_WIDTH, SCREEN_HEIGHT;
    
public:
    ColDet();
    ColDet(const int& SCREEN_WIDTH, const int& SCREEN_HEIGHT);
    
    void wrap(Particle *p, const float& halfTheSize);
    void recycle(Particle *p, const float& halfTheSide, const int& x, const int& y);
    void destroy(Particle *p);
    void bounce(Particle *p, const float& halfTheSize);
};

#endif
