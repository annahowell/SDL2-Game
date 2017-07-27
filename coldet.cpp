#include "coldet.hpp"


ColDet::ColDet(const int& SCREEN_WIDTH, const int& SCREEN_HEIGHT)
: SCREEN_WIDTH(SCREEN_WIDTH), SCREEN_HEIGHT(SCREEN_HEIGHT)
{
}


// ------------------------------------------


void ColDet::wrap(Particle *p, const float& halfTheSize)
{
    if (p->getX() < (0 - halfTheSize))
    {
        p->setX(SCREEN_WIDTH + halfTheSize);
    }
    else if (p->getX() > SCREEN_WIDTH + halfTheSize)
    {
        p->setX(0 - halfTheSize);
    }
    else if (p->getY() < (0 - halfTheSize))
    {
        p->setY(SCREEN_HEIGHT + halfTheSize);
    }
    else if (p->getY() > SCREEN_HEIGHT + halfTheSize)
    {
        p->setY(0 - halfTheSize);
    }
}


// ------------------------------------------


//void ColDet::recycle(Particle *p)
//{
    
//}


// ------------------------------------------


void ColDet::destroy(Particle *p)
{
    
}


// ------------------------------------------


void ColDet::bounce(Particle *p, const float& halfTheSize)
{
    // If it goes off left edge
    if (p->getX() + halfTheSize > SCREEN_WIDTH)
    {
        // Move its position back to the
        p->setX(SCREEN_WIDTH - halfTheSize);
        p->setVX(p->getVX() * -1);
    }
    
    else if (p->getX() - halfTheSize < 0)
    {
        // Move to right edge
        p->setX(0 + halfTheSize);
        p->setVX(p->getVX() * -1);
    }
    
    // If it goes off left edge
    if (p->getY() + halfTheSize > SCREEN_HEIGHT)
    {
        // Move to right edge
        p->setY(SCREEN_HEIGHT - halfTheSize);
        p->setVY(p->getVY() * -1);
    }
    
    else if (p->getY() - halfTheSize < 0)
    {
        // Move to right edge
        p->setY(0 + halfTheSize);
        p->setVY(p->getVY() * -1);
    }
}

