#pragma once

#include <SFML/Graphics.hpp> // Angular brackets for external library
#include "framework/Core.h"

namespace ly
{

class World;

class Application
{
public:
    // constructor.
    Application(const unsigned int winWidth, const unsigned int winHeight, const std::string& title, sf::Uint32 style);

    // run application.
    void run();
    // getter for window size.
    sf::Vector2u getWindowSize() const;
    
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
    void tickInternal(float deltaT);
    // render screen internal.
    void renderInternal();

    // main window disply. (SFML)
    sf::RenderWindow mWindow;
    // main clock. (SFML)
    sf::Clock mTickClock;
    // fixed target frame rate.
    float mTargetFrameRate;
    // current world.
    lySP<World> mCurrentWorld;
    // clean cycle clock.
    sf::Clock mCleanCycleClk;
    // time between consecutive clean cycle.
    float mCleanCycleInterval;
};

template<typename worldType>
lyWP<worldType> Application::loadWorld()
{
    lySP<worldType> newWorld { new worldType{this} };
    mCurrentWorld = newWorld;
    return newWorld;
}

} // namespace ly