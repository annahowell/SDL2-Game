#include "vector.hpp"

/** --------------------------------------------------------------------------------------
 Constructs a new vector

 @param x   The horizontal x position of the head of the vector (tail is at 0)
 @param y   The vertical y position of the head of the vector (tail is at 0)
 */
Vector::Vector(float x, float y)
{
    this->x = x;
    this->y = y;
}



/** --------------------------------------------------------------------------------------
 Sets the horizontal x or vertical y position of the head of the vector (tail is at 0)

 @param     Horizontal x or vertical y position to set for the vectors head (tail is at 0)
 */
void Vector::setX(float x) { this->x = x; }
void Vector::setY(float y) { this->y = y; }



/** --------------------------------------------------------------------------------------
 Gets the horizontal x or vertical y position of the head of the vector (tail is at 0)

 @returns   Current horizontal x or vertical y position of the head of the vector
 */
float Vector::getX() { return x; }
float Vector::getY() { return y; }



/** --------------------------------------------------------------------------------------
 Sets the position of the head of the vector based on an angle in degrees

 @param angle   New angle in degrees
 */
void Vector::setPositionByAngleInDegrees(float degrees)
{
    float length = getLength();
    x = cos(degrees) * length;
    y = sin(degrees) * length;
}



/** --------------------------------------------------------------------------------------
 Gets the angle of the vector in degrees

 @returns   Current angle of the vector in degrees
 */
float Vector::getPositionByAngleInDegrees()
{
    return atan2f(y, x);
}



/** --------------------------------------------------------------------------------------
 Gets the length (magnitude) of the vector

 @returns   Current length (magnitude) of the vector
 */
float Vector::getLength()
{
    return sqrt(x * x + y * y);
}



/** --------------------------------------------------------------------------------------
 Sets the length (magnitude) of the vector

 @params  length  New length of the vector
 */
void Vector::setLength(float length)
{
    float angle = getPositionByAngleInDegrees();
    x = cos(angle) * length;
    y = sin(angle) * length;
}



/** --------------------------------------------------------------------------------------
 Adds a second vector to this vector, thereby amending the current vectors magnitude and
 the position of its head

 @params  v2  Vector to add to the current vector
 */
void Vector::add(Vector &v2)
{
    x += v2.getX();
    y += v2.getY();
}



/** --------------------------------------------------------------------------------------
 Adds this vector to the passed vector and returns the result, does not amend this vector

 @params  v2  Vector to use for the calculation
 @returns     A new vector at a position that equals this vector plus the passed vector
 */
Vector Vector::addTo(Vector &v2)
{
    return Vector(v2.getX() + x, v2.getY() + y);
}



/** --------------------------------------------------------------------------------------
 Subtracts a second vector from this vector, thereby amending the current vectors
 magnitude and the position of its head

 @params  v2  Vector to subtract from the current vector
 */
void Vector::subtract(Vector &v2)
{
    x -= v2.getX();
    y -= v2.getY();
}



/** --------------------------------------------------------------------------------------
 Subtracts this vector from the passed vector and returns the result, does not amend this
 vector

 @params  v2  Vector to use for the calculation
 @returns     A new vector at a position that equals this vector minus the passed vector
*/
Vector Vector::subtractFrom(Vector &v2)
{
    return Vector(x - v2.getX(), y - v2.getY());
}



/** --------------------------------------------------------------------------------------
 Multiplies this vector by a scalar value, thus amending the current vectors head position
 and thereby its magnitude

 @params  scalar  The scalar value by which to multiple this vectors horizontal x and
                  vertical y head position
 */
void Vector::multiply(float scalar)
{
    x *= scalar;
    y *= scalar;
}



/** --------------------------------------------------------------------------------------
 Multiplies this vector by the passed scalar value and returns the result, does not amend
 this vector

 @params  scalar  The scalar value by which to multiple this vectors horizontal x and
                  vertical y head position
 @returns         A new vector at a position that equals this vector multiplied by the
                  passed vector
 */
Vector Vector::multiplyBy(float scalar)
{
    return Vector(x * scalar, y * scalar);
}



/** --------------------------------------------------------------------------------------
 Divides this vector by a scalar value, thus amending the current vectors head position
 and thereby its magnitude

 @params  scalar  The scalar value by which to divide this vectors horizontal x and
                  vertical y head position
 */
void Vector::divide(float scalar)
{
    x /= scalar;
    y /= scalar;
}



/** --------------------------------------------------------------------------------------
 Divides this vector by the passed scalar value and returns the result, does not amend
 this vector

 @params  scalar  The scalar value by which to divide this vectors horizontal x and
                  vertical y head position
 @returns         A new vector at a position that equals this vector divided by the
                  passed vector
 */
Vector Vector::divideBy(float scalar)
{
    return Vector(x / scalar, y / scalar);
}
