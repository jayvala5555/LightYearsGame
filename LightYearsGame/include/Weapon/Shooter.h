#pragma once
#include <framework/Actor.h>

namespace ly
{

class Actor;
class Shooter
{
public:
    // shoot something.
    void shoot();

    // weapon can shoot or not.
    virtual bool canShoot() const;
    // weapon on cooldown or not.
    virtual bool isOnCooldown() const;
    // getter for owner.
    Actor* getOwner() const;

protected:
    // constructor.
    Shooter(Actor* owner);

private:
    // shoot implementation.
    virtual void shootImpl() = 0;
    // owning actor.
    Actor* mOwner;
};

    
} // namespace ly
