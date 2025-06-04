#include "scene_14.hpp"
#include <iostream>

void Scene14_DialogScene14(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene15 = Scene15_Create();
    SceneManager_GoToScene(scene->sceneManager, scene15);
}

void Scene14_Start(Scene *scene)
{
    Scene14Data *data = (Scene14Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "tiba_dikota.png");
    SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene14_DialogScene14, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene14_Update(Scene *scene)
{
    Scene14Data *data = (Scene14Data *)scene->data;
}

void Scene14_Destroy(Scene *scene)
{
}

Scene *Scene14_Create()
{
    Scene14Data *mainMenu = new Scene14Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene14_Start,
        .update = Scene14_Update,
        .destroy = Scene14_Destroy
    };
    return scene;
}