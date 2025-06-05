#include "scene_27.hpp"
#include <iostream>

void Scene27_DialogScene27(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene28 = Scene28_Create();
    SceneManager_GoToScene(scene->sceneManager, scene28);
}

void Scene27_Start(Scene *scene)
{
    Scene27Data *data = (Scene27Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "tiba_dikota.png");
    SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene27_DialogScene27, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene27_Update(Scene *scene)
{
    Scene27Data *data = (Scene27Data *)scene->data;
}

void Scene27_Destroy(Scene *scene)
{
}

Scene *Scene27_Create()
{
    Scene27Data *mainMenu = new Scene27Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene27_Start,
        .update = Scene27_Update,
        .destroy = Scene27_Destroy
    };
    return scene;
}
