#pragma once

#include <SFML/Graphics.hpp> // Angular brackets for external library
#include "framework/Core.h"

namespace ly
{

class World;

class Application
{
public:
    Application();

    // run application.
    void run();

    template<typename worldType>
    lyWP<worldType> loadWorld();

protected:
    // render screen function for child class.
    virtual void render();
    // tick function for child class.
    virtual void tick(float deltaT);

private:
    // tick internal.
    void tickInternal(float deltaTime);
    // render screen internal.
    void renderInternal();

private:
    // main window disply. (SFML)
    sf::RenderWindow mWindow;
    // main clock. (SFML)
    sf::Clock mTickClock;
    // fixed target frame rate.
    float mTargetFrameRate;
    // current world.
    lySP<World> mCurrentWorld;
};

template<typename worldType>
lyWP<worldType> Application::loadWorld()
{
    lySP<worldType> newWorld { new worldType{this} };
    mCurrentWorld = newWorld;
    return newWorld;
}

} // namespace ly