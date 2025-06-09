#include "load_game.hpp"
#include <iostream>
#include <fstream>
#include "../main_menu/main_menu.hpp"
#include "../game/game.hpp"
#include "../../engine/page_manager.hpp"

void LoadSaveCharacterName(Page* page)
{
    std::ifstream saveFile("save.txt");
    std::string savedName;
    if (saveFile.is_open() && std::getline(saveFile, savedName))
    {
        // InputField *inputField = page->ui->inputFieldAktif;
        // if (inputField)
        // {
        //     inputField->text = savedName;
        //     UI_RequestUpdate(page->ui);     
        // }
    }
}

void LoadGamePG_OnButtonClick(void* parameter)
{
    Page *page = (Page*)parameter;
    Page *gamePage = GamePG_CreateFromSave("Ahmad");
    PageManager_StopMusic(page->pageManager);
    PageManager_GoToPage(page->pageManager, gamePage);
}

void LoadGamePG_OnBack(void* parameter)
{
    Page *page = (Page*)parameter;
    Page *mainMenu = MainMenuPG_Create();
    PageManager_StopMusic(page->pageManager);
    PageManager_GoToPage(page->pageManager, mainMenu);
}

void LoadGamePG_Start(Page* page)
{
    LoadGamePageData *data = (LoadGamePageData*)page->data;

    UI_AddImage(page->ui, nullptr, 0, 0, 1000, 550, true, "wp_loadgame.png");
    UI_AddText(page->ui, nullptr, 400, 90, "Load Game", "fonts/Chonky Bunny.ttf", 50, sf::Color::White);

    //baca nama karakter dari file save
    // std::ifstream saveFile("save.txt");
    // std::string savedName = "Slot kosong" ;
    // if (saveFile.is_open() && std::getline(saveFile, savedName))
    // {
    //     saveFile.close();
    // }

    //menampilkan nama karakter yang disimpan
   // UI_AddButton(page->ui, nullptr, 380,180, 240, 40, {0, 0}, {4, 10}, savedName, "fonts/Chonky Bunny.ttf", 20, sf::Color::Black, "button.png", LoadGamePG_OnButtonClick, page);


    // Contoh beberapa slot save
    UI_AddButton(page->ui, nullptr, 380, 180, 240, 40, {0, 0}, {4, 10}, "Ahmad", "fonts/Chonky Bunny.ttf", 20, sf::Color::Black, "button.png", LoadGamePG_OnButtonClick, page);
    UI_AddButton(page->ui, nullptr, 380, 240, 240, 40, {0, 0}, {4, 10}, "Masda", "fonts/Chonky Bunny.ttf", 20, sf::Color::Black, "button.png", LoadGamePG_OnButtonClick, page);
    UI_AddButton(page->ui, nullptr, 380, 300, 240, 40, {0, 0}, {4, 10}, "Virgi", "fonts/Chonky Bunny.ttf", 20, sf::Color::Black, "button.png", LoadGamePG_OnButtonClick, page);

    // Tombol kembali
    UI_AddButton(page->ui, nullptr, 350, 400, 35, 35, {0, 0}, {0, 0}, " ", "fonts/Chonky Bunny.ttf", 20, sf::Color::White, "back.png", LoadGamePG_OnBack, page);
}

void LoadGamePG_Update(Page* page)
{
    
}

void LoadGamePG_Destroy(Page* page)
{
    LoadGamePageData *data = (LoadGamePageData*)page->data;
    delete data;
}

Page *LoadGamePG_Create()
{
    LoadGamePageData *data = new LoadGamePageData {};
    Page *page = new Page {
        .pageManager = nullptr,
        .ui = UI_Create(),
        .data = data,
        .start = LoadGamePG_Start,
        .update = LoadGamePG_Update,
        .destroy = LoadGamePG_Destroy
    };
    return page;
}