#include "framework/Application.h"
#include "framework/World.h"
#include "framework/AssetManager.h"

namespace ly
{

Application::Application(const unsigned int winWidth, const unsigned int winHeight, const std::string &title, sf::Uint32 style)
    : mWindow{sf::VideoMode(winWidth, winHeight), title, style},
    mTargetFrameRate{60.f},
    mTickClock{},
    mCurrentWorld{nullptr},
    mCleanCycleClk{},
    mCleanCycleInterval{2.f}
{
    // mWindow.create(sf::VideoMode(1024,1440), "Light Years");
}

//////////////////////////////////////////////////////////////////////

void Application::run()
{
    mTickClock.restart();
    float accumulatedTime = 0.f;
    float targetDeltaTime = 1.f / mTargetFrameRate;
    while(mWindow.isOpen())
    {
        sf::Event windowEvent; 
        while (mWindow.pollEvent(windowEvent))
        {
            if (windowEvent.type == sf::Event::EventType::Closed)
            {
                mWindow.close();
            }   
        }

        float frameDeltaTime = mTickClock.restart().asSeconds();
        accumulatedTime += frameDeltaTime;

        while (accumulatedTime > targetDeltaTime)
        {
            accumulatedTime -= targetDeltaTime;
            tickInternal(targetDeltaTime);
            renderInternal();
        }
        // LOG("ticking at frame rate : %f", 1.f / frameDeltaTime);
    }
}

//////////////////////////////////////////////////////////////////////

void Application::tickInternal(float deltaT)
{
    tick(deltaT);
    if (mCurrentWorld)
    {
        mCurrentWorld->beginPlayInternal();
        mCurrentWorld->tickInternal(deltaT);
    }
    // std::cout << "ticking at frame rate : " << 1.f/deltaT << std::endl;

    if (mCleanCycleClk.getElapsedTime().asSeconds() >= mCleanCycleInterval)
    {
        mCleanCycleClk.restart();
        AssetManager::get().cleanCycle();
    }
}

//////////////////////////////////////////////////////////////////////

void Application::renderInternal()
{
    mWindow.clear();

    render();

    mWindow.display();
}

//////////////////////////////////////////////////////////////////////

void Application::render()
{
    if (mCurrentWorld)
    {
        mCurrentWorld->render(mWindow);
    }
}

//////////////////////////////////////////////////////////////////////

void Application::tick(float deltaT)
{
    // std::cout << "ticking at frame rate : " << 1.f/deltaT << std::endl;
}

//////////////////////////////////////////////////////////////////////

sf::Vector2u Application::getWindowSize() const
{
    return sf::Vector2u(mWindow.getSize());
}

//////////////////////////////////////////////////////////////////////


} // namespace ly