#include "new_game.hpp"
#include "../main_menu/main_menu.hpp"
#include "../game/game.hpp" 
#include "../../engine/ui.hpp"
#include <iostream>
#include <fstream>

void NewGamePG_OnStartClick(void* parameter) {
    Page* page = (Page*)parameter;
    NewGamePageData* data = (NewGamePageData*)page->data;

    std::string nama = UI_GetInputText(data->inputNamaKarakter);
    std::ofstream saveFile("save.txt");
    if (saveFile.is_open())
    {
        saveFile << nama << std:: endl;
        saveFile.close();
        std::cout << "Nama karakter disimpan ke save.txt";
    }
    else
    {
        std::cerr << "Gagal menyimpan nama karakter";
    }

    PageManager_StopMusic(page->pageManager);

    // simpan nama karakter atau oper ke game
    Page* gamePage = GamePG_Create(); 
    PageManager_GoToPage(page->pageManager, gamePage);
}

void NewGamePG_OnBackClick(void* parameter) {
    Page* page = (Page*)parameter;
    Page* mainMenu = MainMenuPG_Create();
    PageManager_GoToPage(page->pageManager, mainMenu);
}

void NewGamePG_Start(Page* page) {
    NewGamePageData* data = (NewGamePageData*)page->data;

    UI_AddImage(page->ui, nullptr, 0, 0, 1000, 550, true, "wp_loadgame.png");

    UI_AddText(page->ui, nullptr, 420, 120, "New Game", "fonts/Chonky Bunny.ttf", 36, sf::Color::White);

    data->inputNamaKarakter = UI_AddInputField(page->ui, nullptr, 350, 200, 300, 40, {10, 10}, {0, 0}, "Masukkan nama karakter", 20, "fonts/Chonky Bunny.ttf", sf::Color::Black, "ui/input_field.png", "ui/input_field_focused.png");

    UI_AddButton(page->ui, nullptr, 400, 260, 200, 40, {0, 0}, {0, 0}, "Start", "fonts/Chonky Bunny.ttf", 18, sf::Color::Black, "ui/button.png", NewGamePG_OnStartClick, page);

    UI_AddButton(page->ui, nullptr, 350, 120, 40, 40, {0, 0}, {0, 0}, " ", "fonts/Chonky Bunny.ttf", 18, sf::Color::Black, "ui/back.png", NewGamePG_OnBackClick, page);
}

void NewGamePG_Update(Page* page) 
{
    //
}

void NewGamePG_Destroy(Page* page) 
{
    NewGamePageData* data = (NewGamePageData*)page->data;
    delete data;
}

Page* NewGamePG_Create() {
    NewGamePageData* data = new NewGamePageData{};
    Page* page = new Page{
        .data = data,
        .start = NewGamePG_Start,
        .update = NewGamePG_Update,
        .destroy = NewGamePG_Destroy
    };
    return page;
}
