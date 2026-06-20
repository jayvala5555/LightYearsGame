#include "GameFramework/GameApplication.h"
#include "framework/World.h"

ly::Application* getApplication()
{
    return new ly::GameApplication{};
}

namespace ly
{

GameApplication::GameApplication()
{
    lyWP<World> newWorld = loadWorld<World>();
    newWorld.lock()->spawnActor<Actor>();
}

} // namespace ly

