#include "coldet.hpp"

/** --------------------------------------------------------------------------------------
 Constructs a new collision detection object

 @param SCREEN_WIDTH  Width of current screen to use for screen based collision detection
 @param SCREEN_HEIGHT Height of current screen to use for screen based collision detection
 */
ColDet::ColDet(int SCREEN_WIDTH, int SCREEN_HEIGHT)
: SCREEN_WIDTH(SCREEN_WIDTH), SCREEN_HEIGHT(SCREEN_HEIGHT)
{
}



/** --------------------------------------------------------------------------------------
 Wraps the particle around to the opposite edge of the screen when it collides with the
 edge of the screen.

 @param p             Particle on which to do collision detection
 @param midPoint      Midpoint of the particle for collision detection purposes, may not
                      always actually be the middle in certain cases
 */
void ColDet::wrapScreen(Particle *p, const float& midPoint)
{
    // If it goes off the left side of the screen bring it back on the right side
    if (p->getPositionX() < (0 - midPoint))
    {
        p->setPositionX(SCREEN_WIDTH + midPoint);
    }
    // If it goes off the right side of the screen bring it back on the left side
    else if (p->getPositionX() > SCREEN_WIDTH + midPoint)
    {
        p->setPositionX(0 - midPoint);
    }
    // If it goes off the top of the screen bring it back on the bottom
    else if (p->getPositionY() < (0 - midPoint))
    {
        p->setPositionY(SCREEN_HEIGHT + midPoint);
    }
    // If it goes off the bottom of the screen bring it back on the top
    else if (p->getPositionY() > SCREEN_HEIGHT + midPoint)
    {
        p->setPositionY(0 - midPoint);
    }
}



/** --------------------------------------------------------------------------------------
 Bounces the particle on the edge of the screen when it collides with that edge

 @param p             Particle on which to do collision detection
 @param midPoint      Midpoint of the particle for collision detection purposes, may not
                      always actually be the middle in certain cases
 */
void ColDet::bounceScreen(Particle *p, const float& midPoint)
{
    // If it goes off left edge of the screen bring it back on the left edge of the screen
    // and kill its velocity
    if (p->getPositionX() - midPoint < 0)
    {
        p->setPositionX(0 + midPoint);
        p->setVelocityX(p->getVelocityX() * -1);
    }
    // If it goes off right edge of the screen bring it back on the right edge of the
    // screen and kill its velocity
    else if (p->getPositionX() + midPoint > SCREEN_WIDTH)
    {
        p->setPositionX(SCREEN_WIDTH - midPoint);
        p->setVelocityX(p->getVelocityX() * -1);
    }

    // If it goes off top edge of the screen bring it back on the top edge of the screen
    // and kill its velocity
    if (p->getPositionY() - midPoint < 0)
    {
        p->setPositionY(0 + midPoint);
        p->setVelocityY(p->getVelocityY() * -1);
    }
    // If it goes off bottom edge of the screen bring it back on the bottom edge of the
    // bottom and kill its velocity
    else if (p->getPositionY() + midPoint > SCREEN_HEIGHT)
    {
        p->setPositionY(SCREEN_HEIGHT - midPoint);
        p->setVelocityY(p->getVelocityY() * -1);
    }
}
