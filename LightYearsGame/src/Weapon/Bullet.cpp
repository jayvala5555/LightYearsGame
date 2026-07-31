#include "Weapon/Bullet.h"

namespace ly
{

Bullet::Bullet(World *world, Actor *owner, const std::string& texturePath, float speed, float damage)
    : Actor{world, texturePath},
    mOwner{owner},
    mSpeed{speed},
    mDamage{damage}
{

}

//////////////////////////////////////////////////////////////////////

void Bullet::setSpeed(float speed)
{
    mSpeed = speed;
}

//////////////////////////////////////////////////////////////////////

void Bullet::setDamage(float damage)
{
    mDamage = damage;
}

////////////////////////////////////////////////////3//////////////////

float Bullet::getSpeed() const
{
    return mSpeed;
}

//////////////////////////////////////////////////////////////////////

float Bullet::getDamage() const
{
    return mDamage;
}

//////////////////////////////////////////////////////////////////////

void Bullet::tick(float deltaT)
{
    Actor::tick(deltaT);
    move(deltaT);

    if (isActorOutOfWinBounds())
    {
        destroy();
    }
}

//////////////////////////////////////////////////////////////////////

void Bullet::move(float deltaT)
{
    addLocationOffset(mOwner->getForwardDirection() * mSpeed * deltaT);
}

//////////////////////////////////////////////////////////////////////

} // namespace ly
