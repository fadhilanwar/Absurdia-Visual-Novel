#include "engine.hpp"
#include <iostream>

Engine* Engine_Create()
{
    Engine *engine = new Engine();

    engine->window = sf::RenderWindow(sf::VideoMode({1000u, 550u}), "Fuad dan Mita", sf::Style::Titlebar | sf::Style::Close);
    // window.setVerticalSyncEnabled(false);
    // engine->window.setFramerateLimit(60);
    engine->renderTexture = sf::RenderTexture({1000u, 550u});

    engine->pageManager = PageManager_Create(&engine->window, &engine->renderTexture);

    return engine;
}

void Engine_Run(Engine* engine)
{
    int i = 0;
    sf::Clock clock;
    // sf::Time timeElapsed = sf::Time::Zero;
    int32_t timePerFrame = 16;
    // int waitTime = 16;

    while (engine->window.isOpen())
    {
        // if (clock.getElapsedTime().asMilliseconds() > timePerFrame)
        // {
            int waitTime = std::max(16 - clock.getElapsedTime().asMilliseconds(), 0);
            clock.restart();
            // timeElapsed = sf::Time::Zero;

            while (const std::optional event = engine->window.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                {
                    engine->window.close();
                }
            }

            
            engine->pageManager->update(engine->pageManager);
            
            sf::Sprite sprite(engine->renderTexture.getTexture());
            engine->window.draw(sprite);
            engine->window.display();

            clock.stop();
            std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));
        // }
    }
}