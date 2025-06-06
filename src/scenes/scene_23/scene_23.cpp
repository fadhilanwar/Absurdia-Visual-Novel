#include "scene_23.hpp"
#include <iostream>

void Scene23_DialogScene23(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene24 = Scene24_Create();
    // // // SceneManager_GoToScene(scene->sceneManager, scene24);
}

void Scene23_Start(Scene *scene)
{
    Scene23Data *data = (Scene23Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "tiba_dikota.png");
    // SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene23_DialogScene23, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene23_Update(Scene *scene)
{
    Scene23Data *data = (Scene23Data *)scene->data;
}

void Scene23_Destroy(Scene *scene)
{
}

Scene *Scene23_Create()
{
    Scene23Data *mainMenu = new Scene23Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene23_Start,
        .update = Scene23_Update,
        .destroy = Scene23_Destroy
    };
    return scene;
}
