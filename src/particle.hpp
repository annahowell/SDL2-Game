#ifndef particle_hpp
#define particle_hpp
#include <cmath>
#include <stdio.h>
#include "vector.hpp"
#include "texture.hpp"


class Particle {

private:
    Texture* texture;

    float x, y, speed, friction, gravity, velocityX, velocityY, thrustX, thrustY;

public:
    Particle();
    Particle(int x, int y, float speed, float heading, float friction, float gravity);
    Particle(int x, int y, float speed, float heading, float friction, float gravity, Texture* texture);

    float getPositionX();
    float getPositionY();
    void setPositionX(float x);
    void setPositionY(float y);

    float getVelocityX();
    float getVelocityY();
    void setVelocityX(float velocityX);
    void setVelocityY(float velocityY);

    void setHeading(float radianOffset);
    void accelerate(float speed);
    void accelerate();

    void update();

};


#endif /* particle_hpp */
