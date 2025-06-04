#include "scene_28.hpp"
#include <iostream>

void Scene28_DialogScene28(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene29 = Scene29_Create();
    SceneManager_GoToScene(scene->sceneManager, scene29);
}

void Scene28_Start(Scene *scene)
{
    Scene28Data *data = (Scene28Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "tiba_dikota.png");
    SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene28_DialogScene28, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene28_Update(Scene *scene)
{
    Scene28Data *data = (Scene28Data *)scene->data;
}

void Scene28_Destroy(Scene *scene)
{
}

Scene *Scene28_Create()
{
    Scene28Data *mainMenu = new Scene28Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene28_Start,
        .update = Scene28_Update,
        .destroy = Scene28_Destroy
    };
    return scene;
}
