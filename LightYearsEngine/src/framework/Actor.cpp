#include "framework/Actor.h"
#include "framework/Core.h"
#include "framework/AssetManager.h"
#include "framework/MathUtility.h"
#include "framework/World.h"

namespace ly
{

Actor::Actor(World *owningWorld, const std::string& texturePath)
    : mOwningWorld{owningWorld},
    mHasBeganPlay{false},
    mSprite{},
    mTexture{}
{
    if (texturePath != "")
        setTexture(texturePath);
}

//////////////////////////////////////////////////////////////////////

Actor::~Actor()
{
    LOG("Actor Destroyed.");
}

//////////////////////////////////////////////////////////////////////

void Actor::beginPlay()
{
    // LOG("Actor began play");
}

//////////////////////////////////////////////////////////////////////

void Actor::beginPlayInternal()
{
    if (!mHasBeganPlay)
    {
        mHasBeganPlay = true;
        beginPlay();
    }
}

//////////////////////////////////////////////////////////////////////

void Actor::tick(float deltaT)
{
    // LOG("Actor is ticking");
}

//////////////////////////////////////////////////////////////////////

void Actor::tickInternal(float deltaT)
{
    if (!isPendingDestroy())
        tick(deltaT);
}

//////////////////////////////////////////////////////////////////////

void Actor::render(sf::RenderWindow &window)
{
    if (isPendingDestroy())
        return;
    window.draw(mSprite);
}

//////////////////////////////////////////////////////////////////////

void Actor::setTexture(const std::string &texturePath)
{
    // load texture via assets using asset manager
    mTexture = AssetManager::get().loadTexture(texturePath);
    if (!mTexture)
        return;
    mSprite.setTexture(*mTexture);

    int textureWidth = mTexture->getSize().x;
    int textureHeight = mTexture->getSize().y;
    mSprite.setTextureRect(sf::IntRect( sf::Vector2i{}, sf::Vector2i{textureWidth, textureHeight} ));
    centerPivot();
}

//////////////////////////////////////////////////////////////////////

void Actor::setLocation(const sf::Vector2f& newLocation)
{
    mSprite.setPosition(newLocation);
}

//////////////////////////////////////////////////////////////////////

void Actor::setRotation(float newRotation)
{
    mSprite.setRotation(newRotation);
}

//////////////////////////////////////////////////////////////////////

void Actor::addLocationOffset(const sf::Vector2f& offsetLoc)
{
    setLocation(getLocation() + offsetLoc);
}

//////////////////////////////////////////////////////////////////////

void Actor::addRotationOffset(float offsetRot)
{
    setRotation(getRotation() + offsetRot);
}

//////////////////////////////////////////////////////////////////////

sf::Vector2f Actor::getLocation() const
{
    return mSprite.getPosition();
}

//////////////////////////////////////////////////////////////////////

float Actor::getRotation() const
{
    return mSprite.getRotation();
}

//////////////////////////////////////////////////////////////////////

sf::Vector2f Actor::getForwardDirection() const
{
    // Coordinate System (SFML):
    //   Origin (0,0)
    //        +---------> +X
    //        |
    //        |
    //        v
    //       +Y (Down)

    // reducing by 90 because Y-axis is inverted.
    return RotationToVector(getRotation() - 90.f);
}

//////////////////////////////////////////////////////////////////////

sf::Vector2f Actor::getRightDirection() const
{
    return RotationToVector(getRotation());
}

//////////////////////////////////////////////////////////////////////

sf::Vector2u Actor::getWindowSize() const
{
    return mOwningWorld->getWindowSize();
}

//////////////////////////////////////////////////////////////////////

sf::FloatRect Actor::getGlobalBounds() const
{
    return mSprite.getGlobalBounds();
}

//////////////////////////////////////////////////////////////////////

World* Actor::getWorld() const
{
    return mOwningWorld;
}

//////////////////////////////////////////////////////////////////////

bool Actor::isActorOutOfWinBounds() const
{
    if ((getLocation().x - (getGlobalBounds().width / 2) > getWindowSize().x)
        || (getLocation().x + (getGlobalBounds().width / 2) < 0))
    {
        return true;
    }

    if ((getLocation().y - (getGlobalBounds().height / 2) > getWindowSize().y)
        || (getLocation().y + (getGlobalBounds().height / 2) < 0))
    {
        return true;
    }

    return false;
} 

//////////////////////////////////////////////////////////////////////

void Actor::centerPivot()
{
    sf::FloatRect bound = mSprite.getGlobalBounds();
    mSprite.setOrigin(bound.width/2.f, bound.height/2.f);
}

//////////////////////////////////////////////////////////////////////

} // namespace ly

