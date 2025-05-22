#include "game.hpp"
#include <iostream>


void GamePG_Start(Page* page)
{
    GamePageData *data = (GamePageData*)page->data;
    SceneManager *sceneMg = data->sceneMg;

    Scene* mainMenuScene = Scene1_Create();
    SceneManager_GoToScene(sceneMg, mainMenuScene);

    data->sceneImage = UI_AddImage(page->ui, 0, 0, 1000, 550, false, "");
    UI_AddText(page->ui, 10, 20, "Game", TextStyle::NORMAL, 24, sf::Color::White);
    UI_AddButton(page->ui, 500, 40, 50, 40, "Button", 24, sf::Color::White, "nametag.png", nullptr, nullptr);
}

void GamePG_Update(Page* page)
{
    GamePageData *data = (GamePageData*)page->data;
    SceneManager *sceneMg = data->sceneMg;

    sceneMg->update(sceneMg);
    UI_CopyCanvasToImage(page->ui, data->sceneImage, sceneMg->canvas);
}

void GamePG_Destroy(Page* page)
{
    GamePageData *data = (GamePageData*)page->data;
    delete data->sceneImage;
    // TODO: delete sceneManager
}

Page *GamePG_Create()
{
    Canvas *canvas = Canvas_Create();
    SceneManager* sceneMg = SceneManager_Create(canvas);

    GamePageData *data = new GamePageData {
        .sceneMg = sceneMg
    };
    Page *page = new Page {
        .data = data,
        .start = GamePG_Start,
        .update = GamePG_Update,
        .destroy = GamePG_Destroy
    };
    return page;
}