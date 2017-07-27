#include "particle.hpp"


/**
 Create a vector based particle without a texture
 
 @param x        Position of the vector on the x axis
 @param y        Position of the vector on the y axis
 @param speed    Speed the vector moves, used to calculate length (magnitude)
 @param heading  Direction of vector, used to calculate angle
 @param friction Amount of friction acting on this particle (0.8 - 1 recommended)
 @param gravity  Gravity applied to particle (0.1 - 1 recommended)
 */
Particle::Particle(int x, int y, float speed, float heading, float friction, float gravity)
    : x(x), y(y), friction(friction), gravity(gravity)
{
    vx = cos(heading) * speed;
    vy = sin(heading) * speed;
}


/**
 Create a vector based particle with with a bound texture
 
 @param x          Position of the vector on the x axis
 @param y          Position of the vector on the y axi]s
 @param speed      Speed the vector moves, used to calculate length (magnitude)
 @param heading    Direction of vector, used to calculate angle
 @param friction   Amount of friction acting on this particle (0.8 - 1 recommended)
 @param gravity    Gravity applied to particle (0.1 - 1 recommended)
 @param texture    Texture to bind to this particle
 */
Particle::Particle(int x, int y, float speed, float heading, float friction, float gravity, Texture* texture)
    : Particle (x, y, speed, heading, friction, gravity)
{
    this-> texture = texture;
}


// ------------------------------------------
// ------------------------------------------


void Particle::setX(float x) { this->x = x; }
void Particle::setY(float y) { this->y = y; }

void Particle::setVX(float vx) { this->vx = vx; }
void Particle::setVY(float vy) { this->vy = vy; }

float Particle::getX() { return x; }
float Particle::getY() { return y; }

float Particle::getVX() { return vx; }
float Particle::getVY() { return vy; }


// ------------------------------------------
// ------------------------------------------



void Particle::setTheading(float heading)
{
    texture->setAngleInRadians(heading);
    
    float speed = sqrt(vx * vx + vy * vy);
    vx = cosf(heading) * speed;
    vy = sinf(heading) * speed;
}


// ------------------------------------------


void Particle::accelerate(float speed)
{
    float heading = atan2f(vy, vx);
    
    float ax = cosf(heading) * speed;
    float ay = sinf(heading) * speed;
    
    vx += ax;
    vy += ay;
}


// ------------------------------------------


void Particle::accelerate()
{
    vx += tx;
    vy += ty;
}


// ------------------------------------------
// ------------------------------------------


void Particle::update()
{
    vx *= friction;
    vy *= friction;
    vy += gravity;
    x += vx;
    y += vy;
    
    if (texture != nullptr)
    {
        texture->setLocation(x, y);
        texture->render();
    }
}



/*
void Particle::setHeading(float heading)
{
    float speed = sqrtf(vx * vx + vy * vy);
 
    vx = cosf(heading) * speed;
    vy = sinf(heading) * speed;
    
    texture->setAngleInRadians(heading);
}

 
void Particle::accelerate(float speed)
{
    float heading = atan2f(vy, vx);
 
    float ax = cosf(heading) * speed;
    float ay = sinf(heading) * speed;
 
    vx += ax;
    vy += ay;
}

*/



 
 


 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 











/*
 
 
 // ------------------------------------------


void Particle::accelerate(float speed)
{
    float heading = getHeading();

    float ax = cosf(heading) * speed;
    float ay = sinf(heading) * speed;
    
    vx += ax;
    vy += ay;
}


// ------------------------------------------


void Particle::brake(float strength)
{
    friction = strength;
}


// ------------------------------------------


void Particle::setSpeed(float speed)
{
    float heading = getHeading();
    
    vx = cosf(heading) * speed;
    vy = sinf(heading) * speed;
}


// ------------------------------------------


float Particle::getSpeed()
{
    return sqrtf(vx * vx + vy * vy);
}


// ------------------------------------------

void Particle::setHeading(float heading)
{
    float speed = this->getSpeed();
    
    vx = cosf(heading) * speed;
    vy = sinf(heading) * speed;
    
    texture->setAngleInRadians(heading);
}


// ------------------------------------------


float Particle::getHeading()
{
    return atan2f(vy, vx);
}


// ------------------------------------------


void Particle::update()
{
    vx *= friction;
    vy *= friction;
    vy += gravity;
    x += vx;
    y += vy;
    
    if (texture != nullptr)
    {
        texture->setLocation(x, y);
        texture->render();
    }
}


// ------------------------------------------


Texture* Particle::getTexture()
{
    return texture;
}

*/
