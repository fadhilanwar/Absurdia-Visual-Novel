#include "scene_26.hpp"
#include <iostream>

void Scene26_DialogScene26(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene27 = Scene27_Create();
    // SceneManager_GoToSceneene(scene->sceneManager, scene27);
}

void Scene26_Start(Scene *scene)
{
    Scene26Data *data = (Scene26Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "tiba_dikota.png");
    // SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene26_DialogScene26, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene26_Update(Scene *scene)
{
    Scene26Data *data = (Scene26Data *)scene->data;
}

void Scene26_Destroy(Scene *scene)
{
}

Scene *Scene26_Create()
{
    Scene26Data *mainMenu = new Scene26Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene26_Start,
        .update = Scene26_Update,
        .destroy = Scene26_Destroy
    };
    return scene;
}
