#pragma once

#include <SFML/Graphics.hpp> // Angular brackets for external library
#include "framework/Core.h"

namespace ly
{

class Application
{
public:
    Application();

    // run application.
    void run();

protected:
    // render screen function for child classes.
    virtual void render();
    // tick function for child classes.
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
};

} // namespace ly