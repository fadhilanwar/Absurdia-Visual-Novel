#include "scene_29.hpp"
#include <iostream>

void Scene29_DialogScene29(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene30 = Scene30_Create();
    SceneManager_GoToScene(scene->sceneManager, scene30);
}

void Scene29_Start(Scene *scene)
{
    Scene29Data *data = (Scene29Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "tiba_dikota.png");
    SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene29_DialogScene29, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene29_Update(Scene *scene)
{
    Scene29Data *data = (Scene29Data *)scene->data;
}

void Scene29_Destroy(Scene *scene)
{
}

Scene *Scene29_Create()
{
    Scene29Data *mainMenu = new Scene29Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene29_Start,
        .update = Scene29_Update,
        .destroy = Scene29_Destroy
    };
    return scene;
}
