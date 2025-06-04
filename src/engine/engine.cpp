#include "engine.hpp"
#include <iostream>

Engine *Engine_Create()
{
    Engine *engine = new Engine();

    engine->window = sf::RenderWindow(sf::VideoMode({1000u, 550u}), "Fuad dan Mita", sf::Style::Titlebar | sf::Style::Close);
    // window.setVerticalSyncEnabled(false);
    // engine->window.setFramerateLimit(60);
    engine->renderTexture = sf::RenderTexture({1000u, 550u});

    engine->pageManager = PageManager_Create(&engine->window, &engine->renderTexture);

    return engine;
}

void Engine_Run(Engine *engine)
{
    int frameRendered = 0;
    sf::Clock fpsClock;
    sf::Clock clock;

    sf::Font font(GetExePath() + "Roboto-SemiBold.ttf");
    sf::Text fpsTextBlock(font);
    fpsTextBlock.setPosition({0, 0});
    fpsTextBlock.setFillColor(sf::Color::Red);
    fpsTextBlock.setString("");

    fpsClock.start();

    while (engine->window.isOpen())
    {
        if (fpsClock.getElapsedTime().asMilliseconds() >= 1000)
        {
            fpsTextBlock.setString(std::to_string(frameRendered));
            frameRendered = 0;
            fpsClock.restart();
        }

        int waitTime = std::max(8 - clock.getElapsedTime().asMilliseconds(), 0);
        clock.restart();

        engine->pageManager->update(engine->pageManager);

        engine->window.clear();
        sf::Sprite sprite(engine->renderTexture.getTexture());
        engine->window.draw(sprite);
        engine->window.draw(fpsTextBlock);
        engine->window.display();
        frameRendered++;

        clock.stop();
        std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));
    }
}