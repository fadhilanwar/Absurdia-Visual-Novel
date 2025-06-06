#include "scene_31.hpp"
#include <iostream>

void Scene31_DialogScene31(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene32 = Scene32_Create();
    // SceneManager_GoToScene(scene->sceneManager, scene32);
}

void Scene31_Start(Scene *scene)
{
    Scene31Data *data = (Scene31Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "tiba_dikota.png");
    // SceneManager_AddDialog(scene->sceneManager, true, "MC", "Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene31_DialogScene31, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene31_Update(Scene *scene)
{
    Scene31Data *data = (Scene31Data *)scene->data;
}

void Scene31_Destroy(Scene *scene)
{
}

Scene *Scene31_Create()
{
    Scene31Data *mainMenu = new Scene31Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene31_Start,
        .update = Scene31_Update,
        .destroy = Scene31_Destroy
    };
    return scene;
}