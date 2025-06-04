#include "scene_12.hpp"
#include <iostream>

void Scene12_DialogScene12(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene13 = Scene13_Create();
    SceneManager_GoToScene(scene->sceneManager, scene13);
}

void Scene12_Start(Scene *scene)
{
    Scene12Data *data = (Scene12Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "tiba_dikota.png");
    SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene12_DialogScene12, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene12_Update(Scene *scene)
{
    Scene12Data *data = (Scene12Data *)scene->data;
}

void Scene12_Destroy(Scene *scene)
{
}

Scene *Scene12_Create()
{
    Scene12Data *mainMenu = new Scene12Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene12_Start,
        .update = Scene12_Update,
        .destroy = Scene12_Destroy
    };
    return scene;
}
