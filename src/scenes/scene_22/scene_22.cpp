#include "scene_22.hpp"
#include <iostream>

void Scene22_DialogScene22(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene23 = Scene23_Create();
    // // SceneManager_GoToSceneene(scene->sceneManager, scene23);
}

void Scene22_Start(Scene *scene)
{
    Scene22Data *data = (Scene22Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "tiba_dikota.png");
    // SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene22_DialogScene22, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene22_Update(Scene *scene)
{
    Scene22Data *data = (Scene22Data *)scene->data;
}

void Scene22_Destroy(Scene *scene)
{
}

Scene *Scene22_Create()
{
    Scene22Data *mainMenu = new Scene22Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene22_Start,
        .update = Scene22_Update,
        .destroy = Scene22_Destroy
    };
    return scene;
}
