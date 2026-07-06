#pragma once

#include <framework/Application.h> // Angulare brackets because LightYearsEngine acts as external library

namespace ly
{
class Actor;
class GameApplication : public Application
{
public:
    GameApplication();
    // ~GameApplication();
    
    // test.
    virtual void tick(float deltaT) override;
private:
    // test.
    float counter;
    // test.
    lyWP<Actor> actorToDestroy;
};
    
} // namespace ly


