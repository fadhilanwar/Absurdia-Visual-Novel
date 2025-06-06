#include "scene_16.hpp"
#include <iostream>

void Scene16_DialogScene16(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene17 = Scene17_Create();
    // // SceneManager_GoToSceneene(scene->sceneManager, scene17);
}

void Scene16_Start(Scene *scene)
{
    Scene16Data *data = (Scene16Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "tiba_dikota.png");
    // SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene16_DialogScene16, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene16_Update(Scene *scene)
{
    Scene16Data *data = (Scene16Data *)scene->data;
}

void Scene16_Destroy(Scene *scene)
{
}

Scene *Scene16_Create()
{
    Scene16Data *mainMenu = new Scene16Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene16_Start,
        .update = Scene16_Update,
        .destroy = Scene16_Destroy
    };
    return scene;
}
