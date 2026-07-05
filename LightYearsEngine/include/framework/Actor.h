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
    // constructor.
    Actor(World* owningWorld, const std::string& texturePath = "");

    // begin play of actor.
    void beginPlayInternal();
    // tick internal.
    void tickInternal(float deltaT);
    // render the actor.
    void render(sf::RenderWindow& window);

    // setter for texture.
    void setTexture(const std::string& texturePath);
    // set position.
    void setLocation(const sf::Vector2f& newLocation);
    // set rotation.
    void setRotation(float newRotation);
    // add offset in current position.
    void addLocationOffset(const sf::Vector2f& offsetLoc);
    // add offset in current rotation.
    void addRotationOffset(float offsetRot);

    // get current position.
    sf::Vector2f getLocation() const;
    // get rotation.
    float getRotation() const;
    // get actor front direction.
    sf::Vector2f getForwardDirection() const;
    // get actor right direction.
    sf::Vector2f getRightDirection() const;

    // begin play for child class.
    virtual void beginPlay();
    // tick for child class.
    virtual void tick(float deltaT);

    // destructor for child class.
    virtual ~Actor();

private:
    // change privot at center of actor.
    void centerPivot();

    // owner world of actor.
    World* mOwningWorld;
    // flag for play is began.
    bool mHasBeganPlay;
    // transformable and can be rendered.
    sf::Sprite mSprite;
    // texture for sprite.
    lySP<sf::Texture> mTexture;

};

    
} // namespace ly
