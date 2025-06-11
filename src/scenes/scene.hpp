#pragma once

#include "../engine/canvas.hpp"
#include "../pages/game/scene_manager.hpp"

struct SceneManager;

struct Scene
{
    SceneManager *sceneManager = nullptr;
    Canvas *canvas;
    UI *ui;

    std::vector<int> connectedSceneNumbers;

    void* data;

    void (*start)(Scene* scene);
    void (*update)(Scene* scene);
    void (*updateAfterPersons)(Scene* scene);
    void (*destroy)(Scene* scene);

    ~Scene()
    {
        delete canvas;
        delete ui;
    }
};