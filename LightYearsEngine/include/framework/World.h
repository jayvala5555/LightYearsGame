#pragma once

#include <SFML/Graphics.hpp>
#include "framework/Core.h"
#include "framework/Actor.h"

namespace ly
{

class Application;
class Actor;
class World
{
    
public:
    // constructor.
    World(Application* owningApp);

    // start play internal.
    void beginPlayInternal();
    // tick internal.
    void tickInternal(float deltaT);
    // render world and its components.
    void render(sf::RenderWindow& window);

    // getter for window size.
    sf::Vector2u getWindowSize() const;

    // spawn new actor of any custom type in this world.
    template<typename actorType>
    lyWP<actorType> spawnActor();
    
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
    // list of actors owned by world.
    lyList<lySP<Actor>> mActors;
    // list of actors pending to be updated.
    lyList<lySP<Actor>> mPendingActors;
};

template<typename actorType>
lyWP<actorType> World::spawnActor()
{
    lySP<actorType> newActor{ new actorType{this} };
    mPendingActors.push_back(newActor);
    return newActor;
}
    
} // namespace ly
