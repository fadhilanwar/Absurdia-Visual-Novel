#include "scene_10.hpp"
#include <iostream>

void Scene10_DialogScene10(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene11 = Scene11_Create();
    SceneManager_GoToScene(scene->sceneManager, scene11);
}

void Scene10_Start(Scene *scene)
{
    Scene10Data *data = (Scene10Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "tiba_dikota.png");
    SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene10_DialogScene10, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene10_Update(Scene *scene)
{
    Scene10Data *data = (Scene10Data *)scene->data;
}

void Scene10_Destroy(Scene *scene)
{
}

Scene *Scene10_Create()
{
    Scene10Data *mainMenu = new Scene10Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene10_Start,
        .update = Scene10_Update,
        .destroy = Scene10_Destroy
    };
    return scene;
}