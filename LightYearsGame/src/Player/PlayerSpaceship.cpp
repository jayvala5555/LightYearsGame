#include "Player/PlayerSpaceship.h"
#include <SFML/System.hpp>
#include <framework/Core.h>
#include <framework/MathUtility.h>

namespace ly
{
    
PlayerSpaceship::PlayerSpaceship(World *owningWorld, const std::string &path)
    : Spaceship{owningWorld, path},
    mMoveInput{},
    mSpeed{200.f}
{
    
}

//////////////////////////////////////////////////////////////////////

void PlayerSpaceship::tick(float deltaT)
{
    Spaceship::tick(deltaT);
    handleInput();
    consumeInput(deltaT);
}

//////////////////////////////////////////////////////////////////////

void PlayerSpaceship::setSpeed(float speed)
{
    mSpeed = speed;
}

//////////////////////////////////////////////////////////////////////

float PlayerSpaceship::getSpeed() const
{
    return mSpeed;
}

//////////////////////////////////////////////////////////////////////

void PlayerSpaceship::handleInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        mMoveInput.y = -1.f;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        mMoveInput.y = 1.f;
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        mMoveInput.x = -1.f;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        mMoveInput.x = 1.f;
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        mMoveInput.x = 0.f;
        mMoveInput.y = 0.f;
    }

    normalizeInput();
}

//////////////////////////////////////////////////////////////////////

void PlayerSpaceship::consumeInput(float deltaT)
{
    setVelocity(mMoveInput * mSpeed);
    mMoveInput.x = 0.f;
    mMoveInput.y = 0.f;
}

//////////////////////////////////////////////////////////////////////

void PlayerSpaceship::normalizeInput()
{
    float len = getVectorLength(mMoveInput);
    // if (len != 0.f)
    //     LOG("[Player Spaceship] : Move input before: %f, %f", mMoveInput.x, mMoveInput.y);
    
    normalizeVector(mMoveInput);
    
    if (len != 0.f)
        LOG("[Player Spaceship] : Move input now: %f, %f", mMoveInput.x, mMoveInput.y);
}

//////////////////////////////////////////////////////////////////////

} // namespace ly
