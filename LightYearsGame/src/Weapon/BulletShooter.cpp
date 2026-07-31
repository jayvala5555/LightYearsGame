#include <framework/Core.h>
#include <framework/World.h>
#include "Weapon/BulletShooter.h"
#include "Weapon/Bullet.h"

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

    // LOG("Shooting...");

    lyWP<Bullet> newBullet = getOwner()->getWorld()->spawnActor<Bullet>(getOwner(), "SpaceShooterRedux/PNG/Lasers/laserBlue01.png");

    newBullet.lock()->setLocation(getOwner()->getLocation() - sf::Vector2f(0.f, getOwner()->getGlobalBounds().height / 2));
    newBullet.lock()->setRotation(getOwner()->getRotation());
} 

//////////////////////////////////////////////////////////////////////

} // namespace ly
