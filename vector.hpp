//
//  vector.hpp
//  coldet
//
//  Created by Anna on 14/07/2017.
//  Copyright © 2017 Anna. All rights reserved.
//

#ifndef vector_hpp
#define vector_hpp

#define PI 3.14159265

#include <cmath>

class Vector
{
private:
    float x, y;
    float angle, length;
    
public:
    Vector(float x, float y);
    
    void setX(float x);
    float getX();
    
    void setY(float y);
    float getY();
    
    void setLength(float length);
    float getLength();
    
    void setAngle(float angle);
    float getAngle();
    
    Vector add(Vector &v2);
    Vector subtract(Vector &v2);
    Vector multiply(float scalar);
    Vector divide(float scalar);
    
    void addTo(Vector &v2);
    void subtractFrom(Vector &v2);
    void multiplyBy(float scalar);
    void divideBy(float scalar);
};

#endif /* vector_hpp */
