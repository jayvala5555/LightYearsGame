#include <cmath>
#include "framework/MathUtility.h"

namespace ly
{

sf::Vector2f RotationToVector(float rotation)
{
    float rotationRad = DegToRad(rotation);
    return sf::Vector2f(std::cos(rotationRad), std::sin(rotationRad));
}

//////////////////////////////////////////////////////////////////////

float DegToRad(float degrees)
{
    return degrees * (PI/180.f);
}

//////////////////////////////////////////////////////////////////////

float RadToDeg(float radians)
{
    return radians * (180.f/PI);
}

//////////////////////////////////////////////////////////////////////

} // namespace ly
