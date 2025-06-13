#pragma once


#include "../page.hpp"
#include "scene_manager.hpp"
#include "../../scenes/scene_1/scene_1_part2.hpp"
#include "../../scenes/scene_9/scene_9.hpp"

struct GamePageData
{
    SceneManager* sceneMg;

    std::string saveName;
    int loadFromScene = 0;
    UIElement *sceneImage;
};

Page* GamePG_Create();
Page* GamePG_CreateFromSave(std::string saveName);
