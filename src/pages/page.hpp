#pragma once

#include "../engine/page_manager.hpp"
#include "../engine/ui.hpp"

struct PageManager;

struct Page
{
    PageManager* pageManager;
    UI *ui;

    void* data;

    void (*start)(Page* page);
    void (*update)(Page* page);
    void (*destroy)(Page* page);

    ~Page()
    {
        delete ui;
    }
};