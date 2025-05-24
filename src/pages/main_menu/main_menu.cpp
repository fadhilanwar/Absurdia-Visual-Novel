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

// Fungsi ketika si button diklik
void MainMenuPG_ButtonDiklik(void* parameter)
{
    // Cast variabel parameter ke Page
    Page *page = (Page*)parameter;
    // Cast variable data di page ke MainMenuPageData
    MainMenuPageData *data = (MainMenuPageData*)page->data;

    // Ubah isi teks jadi Button diklik
    // Text *dataText = (Text*)data->textAku->properties;
    // dataText->text = "Button diklik";

    // // Update ui
    // UI_RequestUpdate(page->ui);

    Page *gamePage = GamePG_Create();
    PageManager_GoToScene(page->pageManager, gamePage);
}

void MainMenuPG_Start(Page* page)
{
    MainMenuPageData *data = (MainMenuPageData*)page->data;
    
    // Nambahin foto
    UI_AddImage(page->ui, nullptr, 0, 0, 1000, 550, true, "Futon_Room.png");

    // Nambahin teks
    data->textAku = UI_AddText(page->ui, nullptr, 10, 20, "Abcasdsadasdasd", TextStyle::NORMAL, 16, sf::Color(50, 50, 50, 255));

    // Nambahin button
    UI_AddButton(page->ui, nullptr, 20, 50, 100, 50, "Pencet aku", 18, sf::Color::Blue, "fuad.png", MainMenuPG_ButtonDiklik, page);


    // UI_AddButton(page->ui, nullptr, 50, 150, 200, 50, "Button test", 16, sf::Color::White, "nametag.png", MainMenuPG_OnButtonClick, page);
    // UI_AddButton(page->ui, nullptr, 50, 220, 200, 50, "About", 16, sf::Color::White, "nametag.png", MainMenuPG_OnButtonClick2, page);
    // UI_AddText(page->ui, nullptr, 10, 10, "Abc 123", TextStyle::NORMAL, 24, sf::Color::White);
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