#include "engine.hpp"
#include <iostream>

Engine *Engine_Create()
{
    Engine *engine = new Engine();

    engine->engineWindow = {
        .window = sf::RenderWindow(sf::VideoMode({1000u, 550u}), "Fuad dan Mita", sf::Style::Titlebar | sf::Style::Close)};
    engine->engineWindow.window.setKeyRepeatEnabled(false);
    // window.setVerticalSyncEnabled(false);
    // engine->window.setFramerateLimit(60);
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

    while (engine->engineWindow.window.isOpen())
    {
        if (fpsClock.getElapsedTime().asMilliseconds() >= 1000)
        {
            fpsTextBlock.setString(std::to_string(frameRendered));
            frameRendered = 0;
            fpsClock.restart();
        }

        int waitTime = std::max(16 - clock.getElapsedTime().asMilliseconds(), 0);
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
        // if (engine->engineWindow.inputtedText != '\0')
        // std::cout << "Key: " << engine->engineWindow.inputtedText << "\n";

        engine->pageManager->update(engine->pageManager);

        engine->engineWindow.window.clear();
        sf::Sprite sprite(engine->renderTexture.getTexture());
        engine->engineWindow.window.draw(sprite);
        engine->engineWindow.window.draw(fpsTextBlock);
        engine->engineWindow.window.display();
        frameRendered++;

        clock.stop();
        std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));
    }
}