#include "coldet.hpp"


ColDet::ColDet(const int SCREEN_WIDTH, const int SCREEN_HEIGHT)
    : SCREEN_WIDTH(SCREEN_WIDTH), SCREEN_HEIGHT(SCREEN_HEIGHT)
{
}

/**
 Check for a particle exiting the screen edge and wrap its place to the opposite edge
 
 @param p               Particle we're checking for screen edge collisions
 @param halfTheSize     Half the size of the particle, avoids particles blinking in and out of existence
 */
void ColDet::wrap(Particle *p, const float& halfTheSize)
{
    // If it goes off left edge
    if (p->getX() < (0 - halfTheSize))
    {
        // Move to right edge
        p->setX(SCREEN_WIDTH + halfTheSize);
    }
    // If it gos off right edge
    else if (p->getX() > SCREEN_WIDTH + halfTheSize)
    {
        // Move to left edge
        p->setX(0 - halfTheSize);
    }
    // If it goes off the top
    else if (p->getY() < (0 - halfTheSize))
    {
        // Move to the bottom
        p->setY(SCREEN_HEIGHT + halfTheSize);
    }
    // If it goes off the bottom
    else if (p->getY() > SCREEN_HEIGHT + halfTheSize)
    {
        // Move to the top
        p->setY(0 - halfTheSize);
    }
}


/**
 Check for a particle exiting the screen edge and then move it to a certain position
 
 @param p               Particle we're checking for screen edge collisions
 @param halfTheSize     Half the size of the particle, avoids particles blinking in and out of existence
 @param x               Position on x axis we're moving the particle to
 @param y               Position on y axis we're moving the particle to
 */
void ColDet::recycle(Particle *p, const float& halfTheSize, const int& x, const int& y)
{
    // If it goes off screen
    if ((p->getX()) < (0 - halfTheSize)               // Goes off left
     || (p->getX()) > (SCREEN_WIDTH + halfTheSize)    // Goes off right
     || (p->getY()) < (0 - halfTheSize)               // Goes off top
     || (p->getY()) > (SCREEN_HEIGHT + halfTheSize))  // Goes off bottom
    {
        // Recycle it back to origin
        p->setX(x - halfTheSize);
        p->setY(y - halfTheSize);
    }
}


// ------------------------------------------


void ColDet::destroy(Particle *p)
{
    if ((p->getX() > SCREEN_WIDTH) ||
        (p->getX() < 0) ||
        (p->getY() > SCREEN_HEIGHT) ||
        (p->getY() < 0))
    {
        //p->remove();
    }
}


// ------------------------------------------


void ColDet::bounce(Particle *p, const float& halfTheSize)
{
    // If it goes off left edge
    if (p->getX() + halfTheSize > SCREEN_WIDTH)
    {
        // Move its position back to the
        p->setX(SCREEN_WIDTH - halfTheSize);
        p->setX(p->getX() * -1);
    }
    
    else if (p->getX() - halfTheSize < 0)
    {
        // Move to right edge
        p->setX(0 + halfTheSize);
        p->setX(p->getX() * -1);
    }
    
    // If it goes off left edge
    if (p->getY() + halfTheSize > SCREEN_HEIGHT)
    {
        // Move to right edge
        p->setY(SCREEN_HEIGHT - halfTheSize);
        p->setY(p->getY() * -1);
    }
    
    else if (p->getY() - halfTheSize < 0)
    {
        // Move to right edge
        p->setY(0 + halfTheSize);
        p->setY(p->getY() * -1);
    }
}
