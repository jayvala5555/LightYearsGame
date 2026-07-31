#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <framework/Core.h>
#include <framework/MathUtility.h>

#include "Player/PlayerSpaceship.h"


namespace ly
{
    
PlayerSpaceship::PlayerSpaceship(World *owningWorld, const std::string &path)
    : Spaceship{owningWorld, path},
    mMoveInput{},
    mSpeed{200.f},
    mShooter{new BulletShooter{this, 0.1f}}
{

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

void PlayerSpaceship::tick(float deltaT)
{
    Spaceship::tick(deltaT);
    handleInput();
    consumeInput(deltaT);
}

//////////////////////////////////////////////////////////////////////

void PlayerSpaceship::shoot()
{
    if (mShooter)
    {
        mShooter->shoot();
    }
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
    
    clampInputOnEdge();
    normalizeInput();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        shoot();
    }
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

void PlayerSpaceship::clampInputOnEdge()
{
    if ((getLocation().x + (getGlobalBounds().width / 2) > getWindowSize().x && mMoveInput.x == 1.f)
        || (getLocation().x - (getGlobalBounds().width / 2) < 0 && mMoveInput.x == -1.f))
    {
        mMoveInput.x = 0.f;
    }

    if ((getLocation().y + (getGlobalBounds().height / 2) > getWindowSize().y && mMoveInput.y == 1.f)
        || (getLocation().y - (getGlobalBounds().height / 2) < 0 && mMoveInput.y == -1.f))
    {
        mMoveInput.y = 0.f;
    }
} 

//////////////////////////////////////////////////////////////////////

} // namespace ly
