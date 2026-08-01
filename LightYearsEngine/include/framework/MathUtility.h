#pragma once
#include <cmath>
#include <SFML/Graphics.hpp>

#include "framework/Core.h"

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

    // calculate vector length.
    template <typename T>
    float getVectorLength(const sf::Vector2<T>& vector)
    {
        return std::sqrt(vector.x * vector.x + vector.y * vector.y);
    }

    // scale vector by specified amount.
    template<typename T>
    sf::Vector2<T>& scaleVector(sf::Vector2<T>& vectorToScale, float amount)
    {
        vectorToScale.x *= amount;
        vectorToScale.y *= amount;
        return vectorToScale;
    }

    // normalization of vector.
    template<typename T>
    sf::Vector2<T>& normalizeVector(sf::Vector2<T>& vector)
    {
        float vectorLen = getVectorLength<T>(vector);

        if (vectorLen == 0.f)
        {
            // LOG("[Math] : Empty vector can't be normalized.");
            return vector;
        }
        
        return scaleVector(vector, 1.0 / vectorLen);
    }

} // namespace ly