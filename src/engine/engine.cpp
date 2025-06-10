#include "engine.hpp"
#include <iostream>

// Khusus buat di Windows
#if defined(_WIN32)
#define WAIT_TIME 8
#endif
#if defined (unix)
#define WAIT_TIME 16
#endif

Engine *Engine_Create()
{
    Engine *engine = new Engine();

    engine->engineWindow = {
        .window = sf::RenderWindow(sf::VideoMode({1000u, 550u}), "Absurdia.Inc - Interview terakhir sebelum Gila", sf::Style::Titlebar | sf::Style::Close)};
    engine->engineWindow.window.setKeyRepeatEnabled(false);
    // engine->engineWindow.window.setVerticalSyncEnabled(false);
    // engine->engineWindow.window.setFramerateLimit(0);
    engine->renderTexture = sf::RenderTexture({1000u, 550u});

    engine->pageManager = PageManager_Create(&engine->engineWindow, &engine->renderTexture);

    return engine;
}

void Engine_Run(Engine *engine)
{
    int frameRendered = 0;
    sf::Clock fpsClock;
    sf::Clock clock;

    sf::Font font(GetExePath() + "fonts/Roboto-SemiBold.ttf");
    sf::Text fpsTextBlock(font);
    fpsTextBlock.setPosition({0, 0});
    fpsTextBlock.setFillColor(sf::Color::Red);
    fpsTextBlock.setString("");

    fpsClock.start();

    sf::Sprite textureSprite(engine->renderTexture.getTexture());

    while (engine->engineWindow.window.isOpen())
    {
        if (fpsClock.getElapsedTime().asMilliseconds() >= 1000)
        {
            fpsTextBlock.setString(std::to_string(frameRendered));
            frameRendered = 0;
            fpsClock.restart();
        }

        int waitTime = std::max(WAIT_TIME - clock.getElapsedTime().asMilliseconds(), 0);
        clock.restart();

        char inputtedText = engine->engineWindow.inputtedText;
        while (const std::optional event = engine->engineWindow.window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                engine->engineWindow.window.close();
            else if (const auto *textEvent = event->getIf<sf::Event::TextEntered>())
            {
                inputtedText = static_cast<char>(textEvent->unicode);
            }
        }
        if (inputtedText == engine->engineWindow.inputtedText)
            engine->engineWindow.inputtedText = '\0';
        else
            engine->engineWindow.inputtedText = inputtedText;

        engine->pageManager->update(engine->pageManager);

        engine->engineWindow.window.clear();
        engine->engineWindow.window.draw(textureSprite);
        engine->engineWindow.window.draw(fpsTextBlock);
        engine->engineWindow.window.display();
        frameRendered++;

        clock.stop();
        std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));
    }
}