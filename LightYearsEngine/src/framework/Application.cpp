#include "framework/Application.h"
#include "framework/World.h"

namespace ly
{

Application::Application()
    : mWindow{sf::VideoMode(1024,1440), "Light Years"},
    mTargetFrameRate{60.f},
    mTickClock{},
    mCurrentWorld{nullptr}
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

void Application::tickInternal(float deltaTime)
{
    tick(deltaTime);
    if (mCurrentWorld)
    {
        mCurrentWorld->beginPlayInternal();
        mCurrentWorld->tickInternal(deltaTime);
    }
    // std::cout << "ticking at frame rate : " << 1.f/deltaTime << std::endl;
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
    sf::RectangleShape rect{ sf::Vector2f{100,200} };
    rect.setFillColor(sf::Color::Green);
    rect.setOrigin(50, 100);
    rect.setPosition(mWindow.getSize().x/2.f, mWindow.getSize().y/2.f);
    mWindow.draw(rect);

    sf::CircleShape circ{ 100 };
    circ.setFillColor(sf::Color::White);
    circ.setPosition(mWindow.getSize().x/4.f, mWindow.getSize().y/4.f);
    mWindow.draw(circ);
}


//////////////////////////////////////////////////////////////////////

void Application::tick(float deltaT)
{
    // std::cout << "ticking at frame rate : " << 1.f/deltaTime << std::endl;
}

//////////////////////////////////////////////////////////////////////

} // namespace ly