#pragma once

#include <SFML/Graphics.hpp>

#include "canvas.hpp"
#include "../pages/page.hpp"

struct Page;

struct PageManager
{
    sf::Window *window;
    Canvas *canvas;

    Page *currentPage = nullptr;
    Page *pendingPage = nullptr;
    bool isTransitioningPage = false;
    bool isPendingPageHasEntered = false;
    Canvas *lastPageCanvas = nullptr;
    float pageTransitionProgress = 0.0f;

    void (*update)(PageManager *pageMg);
};

PageManager *PageManager_Create(sf::Window *window, sf::RenderTexture *engineRenderTexture);
void PageManager_GoToScene(PageManager *pageMg, Page *page);