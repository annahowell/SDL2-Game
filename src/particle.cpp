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
 Sets the position of the particle on the horiontal x axis

 @param x   New position of the particle on the horizontal x axis
 */
void Particle::setPositionX(float x) { this->x = x; }



/** --------------------------------------------------------------------------------------
 Sets the position of the particle on the vertical y axis

 @param y   New position of the particle on the vertical y axis
 */
void Particle::setPositionY(float y) { this->y = y; }



/** --------------------------------------------------------------------------------------
 Sets the velocity of the particle on the horiontal x axis

 @param velocityX  New velocity of the particle on the horizontal x axis
 */
void Particle::setVelocityX(float velocityX) { this->velocityX = velocityX; }



/** --------------------------------------------------------------------------------------
 Sets the velocity of the particle on the vertical y axis

 @param velocityY  New velocity of the particle on the vertical y axis
 */
void Particle::setVelocityY(float velocityY) { this->velocityY = velocityY; }



/** --------------------------------------------------------------------------------------
 Gets the position of the particle on the horiontal x axis

 @returns The position of the particle on either the horizontal axis
 */
float Particle::getPositionX() { return x; }



/** --------------------------------------------------------------------------------------
 Gets the position of the particle on either the vertical y axis

 @returns The position of the particle on the vertical y axis
 */
float Particle::getPositionY() { return y; }



/** --------------------------------------------------------------------------------------
 Gets the velocity of the particle on the horizontal x axis

 @returns The velocity of the particle on the horizontal x axis
 */
float Particle::getVelocityX() { return velocityX; }



/** --------------------------------------------------------------------------------------
 Gets the velocity of the particle on the vertical y axis

 @returns The velocity of the particle on the vertical y axis
 */
float Particle::getVelocityY() { return velocityY; }



/** --------------------------------------------------------------------------------------
 Sets a new heading for the particle by applying an offset in degrees

 @param degreeOffset Amount of offset to apply to the heading in degrees
 */
 void Particle::setHeading(float degreeOffset)
{
    texture->setAngleByDegrees(degreeOffset);

    float speed = sqrt(velocityX * velocityX + velocityY * velocityY);
    velocityX = cosf(degreeOffset) * speed;
    velocityY = sinf(degreeOffset) * speed;
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
 Decelerate the particles by an amount of force, which in turn translates to some amount
 of additional friction on the particle. Reasonable force values are 0.05 to 0.25 where
 (depending on speed) values above 0.2 will make the particle stop very quickly

 @param speed  Speed by which to accelerate the particle
 */
 void Particle::decelerate(float force)
{
    float additionalFriction = 1 - force;

    velocityX *= additionalFriction;
    velocityY *= additionalFriction;
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
