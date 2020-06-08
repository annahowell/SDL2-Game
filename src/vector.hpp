/**
 Simple vector class
 */

#ifndef vector_hpp
#define vector_hpp

#define PI 3.14159265

#include <cmath>

class Vector
{
private:
    float x, y;

public:
    Vector(float x, float y);

    void setX(float x);
    float getX();

    void setY(float y);
    float getY();

    void setLength(float length);
    float getLength();

    void setPositionByAngleInDegrees(float degrees);
    float getPositionByAngleInDegrees();

    void add(Vector &v2);
    Vector addTo(Vector &v2);

    void subtract(Vector &v2);
    Vector subtractFrom(Vector &v2);

    void multiply(float scalar);
    Vector multiplyBy(float scalar);

    void divide(float scalar);
    Vector divideBy(float scalar);
};


#endif /* vector_hpp */
