#include "load_game.hpp"
#include <iostream>
#include <fstream>
#include <filesystem>
#include "../main_menu/main_menu.hpp"
#include "../game/game.hpp"
#include "../../engine/page_manager.hpp"

namespace fs = std::filesystem;

std::vector<std::string> LoadSaveCharacterName(Page *page)
{
    std::vector<std::string> fileNames;
    std::string directoryPath = "./saves";

    if (fs::exists(directoryPath) && fs::is_directory(directoryPath))
    {
        // Iterate through the directory
        for (const auto &entry : fs::directory_iterator(directoryPath))
        {
            if (fs::is_regular_file(entry))
            {                                                          // Check if it's a regular file
                fileNames.push_back(entry.path().filename().string()); // Store the file name
            }
        }

        // Print the file names
        std::cout << "Files in directory: " << directoryPath << std::endl;
        for (const auto &fileName : fileNames)
        {
            std::cout << fileName << std::endl;
        }
    }
    else
    {
        if (fs::create_directory(directoryPath))
        {
            std::cout << "Folder save dibuat" << std::endl;
        }
        else
        {
            throw std::invalid_argument("Gagal buat folder save");
        }
    }

    return fileNames;
}

void LoadGamePG_OnButtonClick(Page *page, std::string saveName)
{
    Page *gamePage = GamePG_CreateFromSave(saveName);
    PageManager_StopMusic(page->pageManager);
    PageManager_GoToPage(page->pageManager, gamePage);
}

void LoadGamePG_OnBack(void *parameter)
{
    Page *page = (Page *)parameter;
    Page *mainMenu = MainMenuPG_Create();
    PageManager_StopMusic(page->pageManager);
    PageManager_GoToPage(page->pageManager, mainMenu);
}

void LoadGamePG_Start(Page *page)
{
    LoadGamePageData *data = (LoadGamePageData *)page->data;

    UI_AddImage(page->ui, nullptr, 0, 0, 1000, 550, true, "wp_loadgame.png");
    UI_AddText(page->ui, nullptr, 400, 90, "Load Game", "fonts/Chonky Bunny.ttf", 50, sf::Color::White);

    // baca nama karakter dari file save
    //  std::ifstream saveFile("save.txt");
    //  std::string savedName = "Slot kosong" ;
    //  if (saveFile.is_open() && std::getline(saveFile, savedName))
    //  {
    //      saveFile.close();
    //  }

    // menampilkan nama karakter yang disimpan
    // UI_AddButton(page->ui, nullptr, 380,180, 240, 40, {0, 0}, {4, 10}, savedName, "fonts/Chonky Bunny.ttf", 20, sf::Color::Black, "button.png", LoadGamePG_OnButtonClick, page);

    std::vector<std::string> saveFiles = LoadSaveCharacterName(page);

    int i = 0;
    for (auto saveName : saveFiles)
    {
        int y = 180 + (50 * i);
        UI_AddButton(page->ui, nullptr, 380, y, 240, 40, {0, 0}, {0, 0}, saveName, "fonts/Chonky Bunny.ttf", 20, sf::Color::Black, "ui/button.png", [=](void *param) {
            LoadGamePG_OnButtonClick(page, saveName);
        },
                     page);
        i++;
    }

    // Contoh beberapa slot save
    // UI_AddButton(page->ui, nullptr, 380, 240, 240, 40, {0, 0}, {0, 0}, "Masda", "fonts/Chonky Bunny.ttf", 20, sf::Color::Black, "ui/button.png", LoadGamePG_OnButtonClick, page);
    // UI_AddButton(page->ui, nullptr, 380, 300, 240, 40, {0, 0}, {0, 0}, "Virgi", "fonts/Chonky Bunny.ttf", 20, sf::Color::Black, "ui/button.png", LoadGamePG_OnButtonClick, page);

    // Tombol kembali
    UI_AddButton(page->ui, nullptr, 350, 400, 35, 35, {0, 0}, {0, 0}, " ", "fonts/Chonky Bunny.ttf", 20, sf::Color::White, "ui/back.png", LoadGamePG_OnBack, page);
}

void LoadGamePG_Update(Page *page)
{
}

void LoadGamePG_Destroy(Page *page)
{
    LoadGamePageData *data = (LoadGamePageData *)page->data;
    delete data;
}

Page *LoadGamePG_Create()
{
    LoadGamePageData *data = new LoadGamePageData{};
    Page *page = new Page{
        .pageManager = nullptr,
        .ui = UI_Create(),
        .data = data,
        .start = LoadGamePG_Start,
        .update = LoadGamePG_Update,
        .destroy = LoadGamePG_Destroy};
    return page;
}