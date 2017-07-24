//
//  particle.hpp
//  coldet
//
//  Created by Anna on 14/07/2017.
//  Copyright © 2017 Anna. All rights reserved.
//

#ifndef particle_hpp
#define particle_hpp
#include <cmath>
#include <stdio.h>
#include "texture.hpp"

class Particle {
    
private:
    Texture* texture;
    
    int counter = 0;
    float x, y, vx, vy, baseFriction, friction, radius, gravity;
    float mass = 1;
    float bounce = -1;
    
public:
    Particle();
    Particle(float x, float y, float speed, float angle, float friction, float gravity);
    Particle(float x, float y, float speed, float angle, float friction, float gravity, Texture* texture);
    
    void setX(float x);
    void setY(float y);
    float getX();
    float getY();
    void accelerate(float speed);
    void brake(float strength);
    void offBrake();
    void setSpeed(float speed);
    float getSpeed();
    void setHeading(float heading);
    float getHeading();
    void update();
    Texture* getTexture();


};
#endif /* particle_hpp */
