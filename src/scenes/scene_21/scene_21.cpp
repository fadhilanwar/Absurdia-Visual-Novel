#include "scene_21.hpp"
#include <iostream>

void Scene21_DialogScene21(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene22 = Scene22_Create();
    // // SceneManager_GoToScene(scene->sceneManager, scene22);
}

void Scene21_Start(Scene *scene)
{
    Scene21Data *data = (Scene21Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "tiba_dikota.png");
    // SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene21_DialogScene21, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene21_Update(Scene *scene)
{
    Scene21Data *data = (Scene21Data *)scene->data;
}

void Scene21_Destroy(Scene *scene)
{
}

Scene *Scene21_Create()
{
    Scene21Data *mainMenu = new Scene21Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene21_Start,
        .update = Scene21_Update,
        .destroy = Scene21_Destroy
    };
    return scene;
}
