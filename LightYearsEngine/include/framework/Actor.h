#pragma once
#include <SFML/Graphics.hpp>

#include "framework/Core.h"
#include "framework/Object.h"

namespace ly
{

class World;
class Actor : public Object
{
public:
    Actor(World* owningWorld, const std::string& texturePath = "");
    // begin play of actor.
    void beginPlayInternal();
    // setter for texture.
    void setTexture(const std::string& texturePath);
    // setter for position.
    void setOffset(const float x, const float y);
    // render the actor.
    void render(sf::RenderWindow& window);
    // tick internal.
    void tickInternal(float deltaT);

    // begin play for child class.
    virtual void beginPlay();
    // tick for child class.
    virtual void tick(float deltaT);

    // destructor for child class.
    virtual ~Actor();

private:
    // owner world of actor.
    World* mOwningWorld;
    // flag for play is began.
    bool mHasBeganPlay;
    // transformable and can be rendered.
    sf::Sprite mSprite;
    // texture for sprite.
    sf::Texture mTexture;

};

    
} // namespace ly
