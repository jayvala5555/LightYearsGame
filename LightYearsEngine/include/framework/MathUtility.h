#pragma once
#include <SFML/Graphics.hpp>

namespace ly
{
    // convert rotation to vector.
    sf::Vector2f RotationToVector(float rotation);
    // convert degrees value to radians.
    float DegToRad(float degrees);
    // convert radians value to degrees.
    float RadToDeg(float radians);
    // value of pi.
    const float PI = 3.1415926535;
    
} // namespace ly