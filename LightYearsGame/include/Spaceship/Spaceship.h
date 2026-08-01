#pragma once
#include <framework/Actor.h>

namespace ly
{

class Spaceship : public Actor
{

public:
    // constructor.
    Spaceship(World* owningWorld, const std::string& texturePath = "");

    // set velocity of spaceship.
    void setVelocity(const sf::Vector2f& newVel);
    // get velocity of spaceship.
    sf::Vector2f getVelocity() const;
    
    // tick for spaceship.
    virtual void tick(float deltaT) override;
    // shoot.
    virtual void shoot();
private:
    // velocity of spaceship.
    sf::Vector2f mVelocity;

};

    
} // namespace ly
