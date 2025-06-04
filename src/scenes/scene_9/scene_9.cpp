#include "scene_9.hpp"
#include <iostream>

void Scene9_DialogScene9(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene10 = Scene10_Create();
    SceneManager_GoToScene(scene->sceneManager, scene10);
}

void Scene9_Start(Scene *scene)
{
    Scene9Data *data = (Scene9Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "tiba_dikota.png");
    SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene9_DialogScene9, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene9_Update(Scene *scene)
{
    Scene9Data *data = (Scene9Data *)scene->data;
}

void Scene9_Destroy(Scene *scene)
{
}

Scene *Scene9_Create()
{
    Scene9Data *mainMenu = new Scene9Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene9_Start,
        .update = Scene9_Update,
        .destroy = Scene9_Destroy
    };
    return scene;
}