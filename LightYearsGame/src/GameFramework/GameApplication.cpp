#include "GameFramework/GameApplication.h"
#include "framework/World.h"
#include "framework/Actor.h"

ly::Application* getApplication()
{
    return new ly::GameApplication{};
}

namespace ly
{

GameApplication::GameApplication()
    : Application{600, 980, "Light Years", sf::Style::Titlebar | sf::Style::Close}
{
    lyWP<World> newWorld = loadWorld<World>();
    newWorld.lock()->spawnActor<Actor>();
    actorToDestroy = newWorld.lock()->spawnActor<Actor>();
    actorToDestroy.lock()->setTexture("/home/jay/Cpp_Game/LightYears/LightYearsGame/assets/SpaceShooterRedux/PNG/playerShip1_blue.png");
    actorToDestroy.lock()->setOffset(50.0, 50.0);
    counter = 0;
}

void GameApplication::tick(float deltaT)
{
    counter += deltaT;
    if (counter > 10.f)
    {
        if (!actorToDestroy.expired())
        {
            actorToDestroy.lock()->destroy();
        }
    }
}

} // namespace ly
