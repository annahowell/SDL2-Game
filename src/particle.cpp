#include "particle.hpp"

/** --------------------------------------------------------------------------------------
 Constructs a vector based particle without a texture

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
    velocityX = cos(heading) * speed;
    velocityY = sin(heading) * speed;
}



/** --------------------------------------------------------------------------------------
 Constructs a vector based particle with with a bound texture

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



/** --------------------------------------------------------------------------------------
 Sets the position of the particle on either the horiontal x axis or the vertical y axis

 @param x   New position of the particle on the horizontal x axis
 @param y   New position of the particle on the vertical y axis
 */
void Particle::setPositionX(float x) { this->x = x; }
void Particle::setPositionY(float y) { this->y = y; }



/** --------------------------------------------------------------------------------------
 Sets the velocity of the particle on either the horiontal x axis or the vertical y axis

 @param velocityX  New velocity of the particle on the horizontal x axis
 @param velocityY  New velocity of the particle on the vertical y axis
 */
void Particle::setVelocityX(float velocityX) { this->velocityX = velocityX; }
void Particle::setVelocityY(float velocityY) { this->velocityY = velocityY; }



/** --------------------------------------------------------------------------------------
 Gets the position of the particle on either the horiontal x axis or the vertical y axis

 @returns The position of the particle on either the horizontal x or vertical y axis
 */
float Particle::getPositionX() { return x; }
float Particle::getPositionY() { return y; }



/** --------------------------------------------------------------------------------------
 Gets the velocity of the particle on either the horiontal x axis or the vertical y axis

 @returns The velocity of the particle on either the horizontal x or vertical y axis
 */
float Particle::getVelocityX() { return velocityX; }
float Particle::getVelocityY() { return velocityY; }



/** --------------------------------------------------------------------------------------
 Sets a new heading for the particle

 @param radianOffset The amount of offset to apple to the current radian value
 */
 void Particle::setHeading(float radianOffset)
{
    texture->setAngleInRadians(radianOffset);

    float speed = sqrt(velocityX * velocityX + velocityY * velocityY);
    velocityX = cosf(radianOffset) * speed;
    velocityY = sinf(radianOffset) * speed;
}



/** --------------------------------------------------------------------------------------
 Accelerates the particles by an amount of speed, reasonable speed values are 0 to 0.5
 where 0 will eventually stop the particle assuming it has some degree of fricition set

 @param speed  Speed by which to accelerate the particle
 */
 void Particle::accelerate(float speed)
{
    float heading = atan2f(velocityY, velocityX);

    float accelerationX = cosf(heading) * speed;
    float accelerationY = sinf(heading) * speed;

    velocityX += accelerationX;
    velocityY += accelerationY;
}



/** --------------------------------------------------------------------------------------
 Accelerates the particle by an amount of thrust (thrust is currently not currently
 implemented)

 */
 void Particle::accelerate()
{
    velocityX += thrustX;
    velocityY += thrustY;
}



/** --------------------------------------------------------------------------------------
 Updates the particle based on any amendments to the particles characteristics and renders
 then renders any associated texture the particle uses

 */
void Particle::update()
{
    velocityX *= friction;
    velocityY *= friction;
    velocityY += gravity;
    x += velocityX;
    y += velocityY;

    if (texture != nullptr)
    {
        texture->setLocation(x, y);
        texture->render();
    }
}
