#pragma once

#include <framework/Actor.h>

namespace ly
{

class Bullet : public Actor
{
    
public:
    // constructor.
    Bullet(World* world, Actor* owner, const std::string& texturePath, float speed = 600.f, float damage = 10.f);

    // setter for speed.
    void setSpeed(float speed);
    // setter for damage.
    void setDamage(float damage);
    // getter for speed.
    float getSpeed() const;
    // getter for damage.
    float getDamage() const;

    // tick for bullet.
    virtual void tick(float deltaT) override;
    
private:
    // move the bullet.
    void move(float deltaT);

    // owner actor.
    Actor* mOwner;
    // speed of bullet.
    float mSpeed;
    // damage by bullet.
    float mDamage;
};

    
} // namespace ly