#include "GameFramework/GameApplication.h"
#include "framework/World.h"
#include "framework/Actor.h"
#include "config.h"

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
    actorToDestroy.lock()->setTexture(getResourceDir() + "SpaceShooterRedux/PNG/playerShip1_blue.png");
    actorToDestroy.lock()->setLocation(sf::Vector2f(300.f, 490.f));
    actorToDestroy.lock()->setRotation(90.f);
    counter = 0;
}

void GameApplication::tick(float deltaT)
{
    counter += deltaT;
    if (counter > 5.f)
    {
        if (!actorToDestroy.expired())
        {
            actorToDestroy.lock()->destroy();
        }
    }
}

} // namespace ly
