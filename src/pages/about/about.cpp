#include "about.hpp"
#include <iostream>


void AboutPG_OnButtonClick(void* parameter)
{
    Page *page = (Page*)parameter;
    AboutPageData *data = (AboutPageData*)page->data;

    // std::cout << "Clicked!";
    // data->heading->text = "Button clicked";
    // UI_RequestUpdate(page->ui);

    // Page *gamePage = GamePG_Create();
    // PageManager_GoToScene(page->pageManager, gamePage);
}

void AboutPG_Start(Page* page)
{
    AboutPageData *data = (AboutPageData*)page->data;

    UI_AddImage(page->ui, nullptr, 0, 0, 1000, 550, true, "emoji.png");
    UI_AddText(page->ui, nullptr, 50, 10, "About", TextStyle::NORMAL, 24, sf::Color::White);
    // UI_AddButton(page->ui, 50, 150, 200, 50, "Button test", 16, sf::Color::White, "", MainMenuPG_OnButtonClick, page);
}

void AboutPG_Update(Page* page)
{
    AboutPageData *data = (AboutPageData*)page->data;
}

Page *AboutPG_Create()
{
    AboutPageData *data = new AboutPageData {
    };
    Page *page = new Page {
        .data = data,
        .start = AboutPG_Start,
        .update = AboutPG_Update,
    };
    return page;
}