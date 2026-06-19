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
    loadWorld<World>();
}

} // namespace ly

