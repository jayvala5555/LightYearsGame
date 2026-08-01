#pragma once

#include "Spaceship/Spaceship.h"
#include "Weapon/BulletShooter.h"

namespace ly
{

class PlayerSpaceship : public Spaceship
{

public:
    // constructor.
    PlayerSpaceship(World* owningWorld, const std::string& path = "SpaceShooterRedux/PNG/playerShip1_blue.png");

    // setter for speed.
    void setSpeed(float speed);
    // getter for speed.
    float getSpeed() const;
    
    // tick for player spaceship.
    virtual void tick(float deltaT) override;
    // shoot.
    virtual void shoot() override;

private:
    // handle user buttons input.
    void handleInput();
    // consuming inputs.
    void consumeInput(float deltaT);
    // normalize the input.
    void normalizeInput();
    // limit location in window boundry.
    void clampInputOnEdge();
    
    // shooter for spaceship.
    lyUP<BulletShooter> mShooter;
    // move input.
    sf::Vector2f mMoveInput;
    // speed of spaceship.
    float mSpeed;
};


} // namespace ly
