#include "scene_32.hpp"
#include <iostream>

void Scene32_DialogScene32(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene32 = Scene32_Create();
    // // SceneManager_GoToScene(scene->sceneManager, scene32);
}

void Scene32_Start(Scene *scene)
{
    Scene32Data *data = (Scene32Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "tiba_dikota.png");
    // SceneManager_AddDialog(scene->sceneManager, true, "MC", "Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene32_DialogScene32, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene32_Update(Scene *scene)
{
    Scene32Data *data = (Scene32Data *)scene->data;
}

void Scene32_Destroy(Scene *scene)
{
}

Scene *Scene32_Create()
{
    Scene32Data *mainMenu = new Scene32Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene32_Start,
        .update = Scene32_Update,
        .destroy = Scene32_Destroy
    };
    return scene;
}