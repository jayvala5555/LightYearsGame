#include "framework/Actor.h"
#include "framework/Core.h"

namespace ly
{

Actor::Actor(World *owningWorld, const std::string& texturePath)
    : mOwningWorld{owningWorld},
    mHasBeganPlay{false},
    mSprite{},
    mTexture{}
{
    setTexture(texturePath);
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

void Actor::setTexture(const std::string &texturePath)
{
    mTexture.loadFromFile(texturePath);
    mSprite.setTexture(mTexture);

    int textureWidth = mTexture.getSize().x;
    int textureHeight = mTexture.getSize().y;
    mSprite.setTextureRect(sf::IntRect( sf::Vector2i{}, sf::Vector2i{textureWidth, textureHeight} ));
}


//////////////////////////////////////////////////////////////////////

void Actor::setOffset(const float x, const float y)
{
    mSprite.move(sf::Vector2f(x, y));
}

//////////////////////////////////////////////////////////////////////

void Actor::render(sf::RenderWindow &window)
{
    if (isPendingDestroy())
        return;
    window.draw(mSprite);
} 

//////////////////////////////////////////////////////////////////////

void Actor::beginPlay()
{
    LOG("Actor began play");
}

//////////////////////////////////////////////////////////////////////

void Actor::tick(float deltaT)
{
    LOG("Actor is ticking");
}

//////////////////////////////////////////////////////////////////////

void Actor::tickInternal(float deltaT)
{
    if (!isPendingDestroy())
        tick(deltaT);
}

//////////////////////////////////////////////////////////////////////

Actor::~Actor()
{
    LOG("Actor Destroyed.");
}

//////////////////////////////////////////////////////////////////////

} // namespace ly

