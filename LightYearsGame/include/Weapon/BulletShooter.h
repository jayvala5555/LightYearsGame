#pragma once
#include <SFML/System.hpp>
#include "Weapon/Shooter.h"

namespace ly
{

class BulletShooter : public Shooter
{
    
public:
    // constructor.
    BulletShooter(Actor* owner, float cooldownTime = 1.f);
    // is shooter cooled down.
    virtual bool isOnCooldown() const override;

private:
    // shoot process.
    virtual void shootImpl() override;
    
    // clock for cool down.
    sf::Clock mCooldownClk;
    // time for cool down.
    float mCooldownTime;
};
    
} // namespace ly
