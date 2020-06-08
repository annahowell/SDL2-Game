#ifndef coldet_hpp
#define coldet_hpp

#include <SDL.h>
#include <stdio.h>
#include "particle.hpp"


class ColDet {

private:
    const int SCREEN_WIDTH, SCREEN_HEIGHT;

public:
    ColDet();
    ColDet(const int& SCREEN_WIDTH, const int& SCREEN_HEIGHT);

    void wrapScreen(Particle *p, const float& midPoint);
    void bounceScreen(Particle *p, const float& midPoint);
};


#endif /* coldet_hpp */
