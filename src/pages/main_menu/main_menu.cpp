#include "main_menu.hpp"
#include <iostream>


void MainMenuPG_OnButtonClick(void* parameter)
{
    Page *page = (Page*)parameter;
    MainMenuPageData *data = (MainMenuPageData*)page->data;

    Page *gamePage = GamePG_Create();
    PageManager_GoToScene(page->pageManager, gamePage);
}

void MainMenuPG_OnButtonClick2(void* parameter)
{
    Page *page = (Page*)parameter;
    MainMenuPageData *data = (MainMenuPageData*)page->data;

    Page *gamePage = AboutPG_Create();
    PageManager_GoToScene(page->pageManager, gamePage);
}

void MainMenuPG_Start(Page* page)
{
    MainMenuPageData *data = (MainMenuPageData*)page->data;

    UI_AddImage(page->ui, nullptr, 0, 0, 1000, 550, true, "Futon_Room.png");
    UI_AddButton(page->ui, nullptr, 50, 150, 200, 50, "Button test", 16, sf::Color::White, "nametag.png", MainMenuPG_OnButtonClick, page);
    UI_AddButton(page->ui, nullptr, 50, 220, 200, 50, "About", 16, sf::Color::White, "nametag.png", MainMenuPG_OnButtonClick2, page);
    UI_AddText(page->ui, nullptr, 10, 10, "Abc 123", TextStyle::NORMAL, 24, sf::Color::White);
}

void MainMenuPG_Update(Page* page)
{
    MainMenuPageData *data = (MainMenuPageData*)page->data;
}

void MainMenuPG_Destroy(Page* page)
{
    MainMenuPageData *data = (MainMenuPageData*)page->data;
    delete data;
}

Page *MainMenuPG_Create()
{
    MainMenuPageData *data = new MainMenuPageData {
    };
    Page *page = new Page {
        .data = data,
        .start = MainMenuPG_Start,
        .update = MainMenuPG_Update,
        .destroy = MainMenuPG_Destroy
    };
    return page;
}