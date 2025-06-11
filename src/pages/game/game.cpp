#include "game.hpp"
#include <iostream>

void GamePG_Start(Page *page)
{
    GamePageData *data = (GamePageData *)page->data;

    Canvas *canvas = Canvas_Create();
    SceneManager *sceneMg = SceneManager_Create(canvas, page->pageManager->engineWindow);
    data->sceneMg = sceneMg;

    Scene *mainMenuScene = Scene10_Create();
    SceneManager_GoToScene(sceneMg, mainMenuScene, SceneTransition::None);

    

    data->sceneImage = UI_AddImage(page->ui, nullptr, 0, 0, 1000, 550, false, "");
}

void GamePG_Update(Page *page)
{
    GamePageData *data = (GamePageData *)page->data;
    SceneManager *sceneMg = data->sceneMg;

    sceneMg->update(sceneMg);
    UI_CopyCanvasToImage(page->ui, (Image *)data->sceneImage->properties, sceneMg->canvas);
}

void GamePG_Destroy(Page *page)
{
    GamePageData *data = (GamePageData *)page->data;
    delete data->sceneImage;
    delete data->sceneMg;
}

Page *GamePG_Create()
{
    GamePageData *data = new GamePageData{};
    Page *page = new Page{
        .data = data,
        .start = GamePG_Start,
        .update = GamePG_Update,
        .destroy = GamePG_Destroy};
    return page;
}

Page *GamePG_CreateFromSave(const char *saveName)
{
    GamePageData *data = new GamePageData{};
    Page *page = new Page{
        .data = data,
        .start = GamePG_Start,
        .update = GamePG_Update,
        .destroy = GamePG_Destroy};
    return page;
}