#pragma once

#include <Spaceship/Spaceship.h>

namespace ly
{

class PlayerSpaceship : public Spaceship
{

public:
    // constructor.
    PlayerSpaceship(World* owningWorld, const std::string& path = "SpaceShooterRedux/PNG/playerShip1_blue.png");

    // tick for player spaceship.
    virtual void tick(float deltaT) override;

    // setter for speed.
    void setSpeed(float speed);
    
    // getter for speed.
    float getSpeed() const;

private:
    // handle user buttons input.
    void handleInput();
    // consuming inputs.
    void consumeInput(float deltaT);
    // normalize the input.
    void normalizeInput();
    // limit location in window boundry.
    void clampInputOnEdge();
    
    // move input.
    sf::Vector2f mMoveInput;
    // speed of spaceship.
    float mSpeed;
};


} // namespace ly
