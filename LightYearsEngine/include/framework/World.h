#pragma once

#include "framework/Core.h"

namespace ly
{

class Application;
class Actor;
class World
{
    
public:
    World(Application* owningApp);

    // start play internal.
    void beginPlayInternal();
    // tick internal.
    void tickInternal(float deltaT);

    // destructor for child class.
    virtual ~World();

private:
    // play internal for child class.
    void beginPlay();
    // tick function for child class.
    void tick(float deltaT);
    // hold owning app.
    Application* mOwningApp;
    // toggle play.
    bool mBeginPlay;
    // list of actor world is containing.
    lyList<lySP<Actor>> mActors;
    // list of actors pending to be updated.
    lyList<lySP<Actor>> mPendingActors;
};

    
} // namespace ly
