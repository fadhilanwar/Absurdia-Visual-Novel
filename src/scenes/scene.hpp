#pragma once

#include "../engine/canvas.hpp"
#include "../pages/game/scene_manager.hpp"

struct SceneManager;

struct Scene
{
    SceneManager *sceneManager = nullptr;

    void* data;

    void (*start)(Scene* scene);
    void (*update)(Scene* scene);
    void (*destroy)(Scene* scene);
};