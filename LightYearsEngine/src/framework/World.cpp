#include "framework/World.h"
#include "framework/Actor.h"

namespace ly
{

World::World(Application *owningApp)
    : mOwningApp{owningApp},
    mBeginPlay{false},
    mActors{},
    mPendingActors{}
{
    
}

//////////////////////////////////////////////////////////////////////

void World::tickInternal(float deltaT)
{
    for(lySP<Actor> actor : mPendingActors)
    {
        mActors.push_back(actor);
        actor->beginPlayInternal();
    }
    mPendingActors.clear();
    
    for(lySP<Actor> actor : mActors)
    {
        actor->tick(deltaT);
    }

    tick(deltaT);
}

//////////////////////////////////////////////////////////////////////

void World::beginPlayInternal()
{
    if (!mBeginPlay)
    {
        mBeginPlay = true;
        beginPlay();
    }    
}

//////////////////////////////////////////////////////////////////////

void World::beginPlay()
{
    LOG("Began the play");
}

//////////////////////////////////////////////////////////////////////

void World::tick(float deltaT)
{
    LOG("ticking at frame rate : %f", 1.f / deltaT);
}

//////////////////////////////////////////////////////////////////////

World::~World()
{

}

//////////////////////////////////////////////////////////////////////

} // namespace ly

