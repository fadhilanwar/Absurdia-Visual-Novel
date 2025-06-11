#include "main_menu.hpp"
#include "../load_game/load_game.hpp"
#include "../new_game/new_game.hpp"
#include <iostream>


void MainMenuPG_OnButtonClick(void* parameter)
{
    Page *page = (Page*)parameter;
    MainMenuPageData *data = (MainMenuPageData*)page->data;

    // PageManager_PlaySound(page->pageManager, "hidup-jokowi.mp3");

    Page *gamePage = NewGamePG_Create();
    PageManager_GoToPage(page->pageManager, gamePage);
}

void MainMenuPG_OnButtonClick2(void* parameter)
{
    Page *page = (Page*)parameter;
    MainMenuPageData *data = (MainMenuPageData*)page->data;

    // PageManager_PlaySound(page->pageManager, "hidup-jokowi.mp3");

    Page *gamePage = LoadGamePG_Create();
    PageManager_GoToPage(page->pageManager, gamePage);
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
    PageManager_GoToPage(page->pageManager, gamePage);
}

void MainMenuPG_Start(Page* page)
{
    MainMenuPageData *data = (MainMenuPageData*)page->data;
    
    // Nambahin background
    UI_AddImage(page->ui, nullptr, 0, 0, 1000, 550, true, "walpaper_menu.png");

   // UI_AddImage(page->ui, nullptr, 0, 0, 1000, 550, true, "Futon_Room.png");

    // Nambahin teks
    UI_AddText(page->ui, nullptr, 520, 320, "Interview terakhir sebelum gila", "fonts/Chonky Bunny.ttf", 20, sf::Color::White);

    // Nambahin heading utama
    UI_AddText(page->ui, nullptr, 380, 140, "Absurdia Inc", "fonts/Blugie.ttf", 170, sf::Color::White);

    //data->textAku = UI_AddText(page->ui, nullptr, 10, 20, "Abcasdsadasdasd", TextStyle::NORMAL, 16, sf::Color(50, 50, 50, 255));

    // Nambahin button
    UI_AddButton(page->ui, nullptr, 75, 246, 238, 36, {0, 0}, {0, 0}, "New Game", "fonts/Chonky Bunny.ttf", 18, sf::Color::Black, "ui/button.png", MainMenuPG_OnButtonClick, page);
    UI_AddButton(page->ui, nullptr, 75, 292, 238, 36, {0, 0}, {0, 0}, "Load Game", "fonts/Chonky Bunny.ttf", 18, sf::Color::Black, "ui/button.png", MainMenuPG_OnButtonClick2, page);
    UI_AddButton(page->ui, nullptr, 75, 338, 238, 36, {0, 0}, {0, 0}, "Quit", "fonts/Chonky Bunny.ttf", 18, sf::Color::Black, "ui/button.png",
        [](void* param) {
            std::exit(0);
        }, page);

    PageManager_PlayMusic(page->pageManager, "InDreamland.mp3");

   // UI_AddButton(page->ui, nullptr, 20, 50, 100, 50, "Pencet aku", 18, sf::Color::Blue, "fuad.png", MainMenuPG_ButtonDiklik, page);


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