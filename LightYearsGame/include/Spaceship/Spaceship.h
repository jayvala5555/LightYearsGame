#pragma once
#include <framework/Actor.h>

namespace ly
{

class Spaceship : public Actor
{
    
public:
    // constructor.
    Spaceship(World* owningWorld, const std::string& texturePath = "");
    // tick for spaceship.
    virtual void tick(float deltaT) override;
    // set velocity of spaceship.
    void setVelocity(const sf::Vector2f& newVel);
    // get velocity of spaceship.
    sf::Vector2f getVelocity() const;
private:
    // velocity of spaceship.
    sf::Vector2f mVelocity;

};

    
} // namespace ly
