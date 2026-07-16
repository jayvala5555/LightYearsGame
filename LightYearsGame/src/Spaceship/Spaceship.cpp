#include "Spaceship/Spaceship.h"

namespace ly
{

Spaceship::Spaceship(World *owningWorld, const std::string &texturePath)
    : Actor{owningWorld, texturePath},
    mVelocity{}
{

}

//////////////////////////////////////////////////////////////////////

void Spaceship::tick(float deltaT)
{
    Actor::tick(deltaT);
    addLocationOffset(getVelocity() * deltaT);
}

//////////////////////////////////////////////////////////////////////

void Spaceship::setVelocity(const sf::Vector2f &newVel)
{
    mVelocity = newVel;
}

//////////////////////////////////////////////////////////////////////

sf::Vector2f Spaceship::getVelocity() const
{
    return mVelocity;
}

//////////////////////////////////////////////////////////////////////


} // namespace ly

