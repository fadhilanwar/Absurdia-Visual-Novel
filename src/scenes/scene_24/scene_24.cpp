#include "scene_24.hpp"
#include <iostream>

void Scene24_DialogScene24(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene25 = Scene25_Create();
    SceneManager_GoToScene(scene->sceneManager, scene25);
}

void Scene24_Start(Scene *scene)
{
    Scene24Data *data = (Scene24Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "tiba_dikota.png");
    SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene24_DialogScene24, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene24_Update(Scene *scene)
{
    Scene24Data *data = (Scene24Data *)scene->data;
}

void Scene24_Destroy(Scene *scene)
{
}

Scene *Scene24_Create()
{
    Scene24Data *mainMenu = new Scene24Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene24_Start,
        .update = Scene24_Update,
        .destroy = Scene24_Destroy
    };
    return scene;
}
