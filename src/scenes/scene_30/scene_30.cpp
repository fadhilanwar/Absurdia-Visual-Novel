#include "scene_30.hpp"
#include <iostream>

void Scene30_DialogScene30(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene31 = Scene31_Create();
    SceneManager_GoToScene(scene->sceneManager, scene31);
}

void Scene30_Start(Scene *scene)
{
    Scene30Data *data = (Scene30Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "tiba_dikota.png");
    SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene30_DialogScene30, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene30_Update(Scene *scene)
{
    Scene30Data *data = (Scene30Data *)scene->data;
}

void Scene30_Destroy(Scene *scene)
{
}

Scene *Scene30_Create()
{
    Scene30Data *mainMenu = new Scene30Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene30_Start,
        .update = Scene30_Update,
        .destroy = Scene30_Destroy
    };
    return scene;
}
