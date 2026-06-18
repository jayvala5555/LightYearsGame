#pragma once

namespace ly
{

class Application;
class World
{
    
public:
    World(Application* owningApp);

    // start play internal.
    void beginPlayInternal();
    // tick internal.
    void tickInternal(float deltaTime);

private:
    // hold owning app.
    Application* mOwningApp;
    // variable to toggle play.
    bool mBeginPlay;
};

    
} // namespace ly
