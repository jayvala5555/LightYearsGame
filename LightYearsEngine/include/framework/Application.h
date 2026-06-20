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
    // load new world of any custom type in this application.
    template<typename worldType>
    lyWP<worldType> loadWorld();

private: // can be protected. may be required to change
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