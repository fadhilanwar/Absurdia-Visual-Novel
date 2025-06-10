#pragma once


#include "../page.hpp"
#include "scene_manager.hpp"
#include "../../scenes/scene_1/scene_1.hpp"
#include "../../scenes/scene_9/scene_9.hpp"

struct GamePageData
{
    SceneManager* sceneMg;

    UIElement *sceneImage;
};

Page* GamePG_Create();
Page* GamePG_CreateFromSave(const char* saveName);
