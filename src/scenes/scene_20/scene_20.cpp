#include "scene_20.hpp"
#include <iostream>

void Scene20_DialogScene20(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene21 = Scene21_Create();
    // // SceneManager_GoToSceneene(scene->sceneManager, scene21);
}

void Scene20_Start(Scene *scene)
{
    Scene20Data *data = (Scene20Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "tiba_dikota.png");
    // SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene20_DialogScene20, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene20_Update(Scene *scene)
{
    Scene20Data *data = (Scene20Data *)scene->data;
}

void Scene20_Destroy(Scene *scene)
{
}

Scene *Scene20_Create()
{
    Scene20Data *mainMenu = new Scene20Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene20_Start,
        .update = Scene20_Update,
        .destroy = Scene20_Destroy
    };
    return scene;
}
