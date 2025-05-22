#pragma once

#include <SFML/Window.hpp>
#include <chrono>
#include <thread>

#include "page_manager.hpp"


struct Engine
{
    sf::RenderWindow window;
    sf::RenderTexture renderTexture;
    PageManager *pageManager;
};

Engine* Engine_Create();
void Engine_Run(Engine *engine);