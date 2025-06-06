#pragma once

#include <SFML/Window.hpp>
#include <chrono>
#include <thread>

#include "engine_window.hpp"
#include "page_manager.hpp"

struct Engine
{
    EngineWindow engineWindow;
    sf::RenderTexture renderTexture;
    PageManager *pageManager;
};

Engine* Engine_Create();
void Engine_Run(Engine *engine);