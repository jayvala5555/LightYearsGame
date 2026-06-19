#include "framework/Actor.h"
#include "framework/Core.h"

namespace ly
{

Actor::Actor(World *owningWorld)
    : mOwningWorld{owningWorld},
    mHasBeganPlay{false}
{

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

} // namespace ly

