#ifndef particle_hpp
#define particle_hpp
#include <cmath>
#include <stdio.h>
#include "vector.hpp"
#include "texture.hpp"


class Particle {
    
private:
    Texture* texture;
    
    float x, y, speed, friction, gravity, vx, vy, tx, ty;

    //int counter = 0;
    //float x, y, vx, vy, baseFriction, friction, radius, gravity;
    //float mass = 1;
    //float bounce = -1;
    
public:
    Particle();
    Particle(int x, int y, float speed, float heading, float friction, float gravity);
    Particle(int x, int y, float speed, float heading, float friction, float gravity, Texture* texture);
    
    float getX();
    float getY();
    void setX(float x);
    void setY(float y);
    float getVX();
    float getVY();
    void setVX(float vx);
    void setVY(float vy);
    
    void setTheading(float heading);
    void accelerate(float speed);
    void accelerate();

    void update();

    
    /*
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
     */

};
#endif /* particle_hpp */
