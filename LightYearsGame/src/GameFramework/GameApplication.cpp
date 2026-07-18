#include <framework/World.h>
#include <framework/Actor.h>
#include <framework/AssetManager.h>
#include <cmath>

#include "config.h"
#include "GameFramework/GameApplication.h"
#include "Spaceship/Spaceship.h"
#include "Player/PlayerSpaceship.h"

ly::Application* getApplication()
{
    return new ly::GameApplication{};
}

namespace ly
{

GameApplication::GameApplication()
    : Application{600, 980, "Light Years", sf::Style::Titlebar | sf::Style::Close}
{
    AssetManager::get().setAssetRootDir(getResourceDir());
    lyWP<World> newWorld = loadWorld<World>();
    newWorld.lock()->spawnActor<Actor>();
    testPlayerSpaceship = newWorld.lock()->spawnActor<PlayerSpaceship>();
    testPlayerSpaceship.lock()->setLocation(sf::Vector2f(300.f, 490.f));
    counter = 0;
}

void GameApplication::tick(float deltaT)
{
    // counter += deltaT;
    // if (counter > 50.f)
    // {
    //     if (!testPlayerSpaceship.expired())
    //     {
    //         testPlayerSpaceship.lock()->destroy();
    //     }
    // }
}

} // namespace ly
