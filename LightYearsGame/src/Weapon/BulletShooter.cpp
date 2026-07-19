#include <framework/Core.h>
#include "Weapon/BulletShooter.h"

namespace ly
{

BulletShooter::BulletShooter(Actor *owner, float cooldownTime)
    : Shooter{owner},
    mCooldownClk{},
    mCooldownTime{cooldownTime}
{

}

//////////////////////////////////////////////////////////////////////

bool BulletShooter::isOnCooldown() const
{
    if (mCooldownClk.getElapsedTime().asSeconds() > mCooldownTime)
    {
        return false;
    }
    return true;
}

//////////////////////////////////////////////////////////////////////

void BulletShooter::shootImpl()
{
    mCooldownClk.restart();
    LOG("Shooting...");
} 

//////////////////////////////////////////////////////////////////////

} // namespace ly
