#include "coldet.hpp"

/** --------------------------------------------------------------------------------------
 Constructs a new collision detection object

 @param SCREEN_WIDTH   Width of current screen to use for screen based collision detection
 @param SCREEN_HEIGHT  Height of current screen to use for screen based colision detection
 */
ColDet::ColDet(const int& SCREEN_WIDTH, const int& SCREEN_HEIGHT)
: SCREEN_WIDTH(SCREEN_WIDTH), SCREEN_HEIGHT(SCREEN_HEIGHT)
{
}



/** --------------------------------------------------------------------------------------
 Wraps the particle around to the opposite edge of the screen when it collides with the
 edge of the screen.

 @param p             Particle on which to do collision detection
 @param midPoint      Midpoint of the particle for collision detection purposes, may not
                      Always actually be the middle in certain edge case particles
 */
void ColDet::wrapScreen(Particle *p, const float& midPoint)
{
    if (p->getPositionX() < (0 - midPoint))
    {
        p->setPositionX(SCREEN_WIDTH + midPoint);
    }
    else if (p->getPositionX() > SCREEN_WIDTH + midPoint)
    {
        p->setPositionX(0 - midPoint);
    }
    else if (p->getPositionY() < (0 - midPoint))
    {
        p->setPositionY(SCREEN_HEIGHT + midPoint);
    }
    else if (p->getPositionY() > SCREEN_HEIGHT + midPoint)
    {
        p->setPositionY(0 - midPoint);
    }
}



/** --------------------------------------------------------------------------------------
 Bounces the particle on the edge of the screen when it collides with that edge

 @param p             Particle on which to do collision detection
 @param midPoint      Midpoint of the particle for collision detection purposes, may not
                      Always actually be the middle in certain edge case particles
 */
void ColDet::bounceScreen(Particle *p, const float& midPoint)
{
    // If it goes off left edge
    if (p->getPositionX() + midPoint > SCREEN_WIDTH)
    {
        // Move its position back to the
        p->setPositionX(SCREEN_WIDTH - midPoint);
        p->setVelocityX(p->getVelocityX() * -1);
    }

    else if (p->getPositionX() - midPoint < 0)
    {
        // Move to right edge
        p->setPositionX(0 + midPoint);
        p->setVelocityX(p->getVelocityX() * -1);
    }

    // If it goes off left edge
    if (p->getPositionY() + midPoint > SCREEN_HEIGHT)
    {
        // Move to right edge
        p->setPositionY(SCREEN_HEIGHT - midPoint);
        p->setVelocityY(p->getVelocityY() * -1);
    }

    else if (p->getPositionY() - midPoint < 0)
    {
        // Move to right edge
        p->setPositionY(0 + midPoint);
        p->setVelocityY(p->getVelocityY() * -1);
    }
}
