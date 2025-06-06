#include "scene_19.hpp"
#include <iostream>

void Scene19_DialogScene19(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene20 = Scene20_Create();
    // // SceneManager_GoToSceneene(scene->sceneManager, scene20);
}

void Scene19_Start(Scene *scene)
{
    Scene19Data *data = (Scene19Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "tiba_dikota.png");
    // SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene19_DialogScene19, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene19_Update(Scene *scene)
{
    Scene19Data *data = (Scene19Data *)scene->data;
}

void Scene19_Destroy(Scene *scene)
{
}

Scene *Scene19_Create()
{
    Scene19Data *mainMenu = new Scene19Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene19_Start,
        .update = Scene19_Update,
        .destroy = Scene19_Destroy
    };
    return scene;
}
