#include "scene_11.hpp"
#include <iostream>

void Scene11_DialogScene11(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene12 = Scene12_Create();
    // // SceneManager_GoToScene(scene->sceneManager, scene12);
}

void Scene11_Start(Scene *scene)
{
    Scene11Data *data = (Scene11Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "tiba_dikota.png");
    // SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene11_DialogScene11, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene11_Update(Scene *scene)
{
    Scene11Data *data = (Scene11Data *)scene->data;
}

void Scene11_Destroy(Scene *scene)
{
}

Scene *Scene11_Create()
{
    Scene11Data *mainMenu = new Scene11Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene11_Start,
        .update = Scene11_Update,
        .destroy = Scene11_Destroy
    };
    return scene;
}

