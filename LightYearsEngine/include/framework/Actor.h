#pragma once

namespace ly
{

class World;
class Actor
{
public:
    Actor(World* owningWorld);
    // begin play of actor.
    void beginPlayInternal();

    // begin play for child class.
    virtual void beginPlay();
    // tick for child class.
    virtual void tick(float deltaT);

private:
    // owner world of actor.
    World* mOwningWorld;
    // flag for play is began.
    bool mHasBeganPlay;

};

    
} // namespace ly
