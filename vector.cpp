//
//  vector.cpp
//  coldet
//
//  Created by Anna on 14/07/2017.
//  Copyright © 2017 Anna. All rights reserved.
//

#include "vector.hpp"

Vector::Vector(float x, float y)
{
    this->x = x;
    this->y = y;
}


// ------------------------------------------


void Vector::setX(float x)
{
    this->x = x;
}


// ------------------------------------------


float Vector::getX()
{
    return x;
}


// ------------------------------------------


void Vector::setY(float y)
{
    this->y = y;
}


// ------------------------------------------


float Vector::getY()
{
    return y;
}


// ------------------------------------------


void Vector::setAngle(float angle)
{
    float length = getLength();
    x = cos(angle) * length;
    y = sin(angle) * length;
}


// ------------------------------------------


float Vector::getAngle()
{
    return atan2f(y, x);
}


// ------------------------------------------


void Vector::setLength(float length)
{
    float angle = getAngle();
    x = cos(angle) * length;
    y = sin(angle) * length;
}


// ------------------------------------------


float Vector::getLength()
{
    return sqrt(x * x + y * y);
}


// ------------------------------------------


Vector Vector::add(Vector &v2)
{
    return Vector(x + v2.getX(), y + v2.getY());
}


// ------------------------------------------


Vector Vector::subtract(Vector &v2)
{
    return Vector(x - v2.getX(), y - v2.getY());
}


// ------------------------------------------


Vector Vector::multiply(float scalar)
{
    return Vector(x * scalar, y * scalar);
}


// ------------------------------------------


Vector Vector::divide(float scalar)
{
    return Vector(x / scalar, y / scalar);
}


// ------------------------------------------


void Vector::addTo(Vector &v2)
{
    x += v2.getX();
    y += v2.getY();
}


// ------------------------------------------


void Vector::subtractFrom(Vector &v2)
{
    x -= v2.getX();
    y -= v2.getY();
}


// ------------------------------------------


void Vector::multiplyBy(float scalar)
{
    x *= scalar;
    y *= scalar;
}


// ------------------------------------------


void Vector::divideBy(float scalar)
{
    x /= scalar;
    y /= scalar;
}


