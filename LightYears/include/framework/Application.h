#pragma once

#include <SFML/Graphics.hpp> // Angular brackets for external library

namespace ly
{

class Application
{
public:
    Application();

    void run();

protected:
    virtual void render();
    
    virtual void tick(float deltaT);

private:
    void tickInternal(float deltaTime);

    void renderInternal();

    sf::RenderWindow mWindow;

    sf::Clock mTickClock;

    float mTargetFrameRate;
};

}