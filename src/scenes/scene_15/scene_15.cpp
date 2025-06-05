#include "scene_15.hpp"
#include <iostream>

void Scene15_DialogScene15(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene16 = Scene16_Create();
    SceneManager_GoToScene(scene->sceneManager, scene16);
}

void Scene15_Start(Scene *scene)
{
    Scene15Data *data = (Scene15Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "tiba_dikota.png");
    SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene15_DialogScene15, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene15_Update(Scene *scene)
{
    Scene15Data *data = (Scene15Data *)scene->data;
}

void Scene15_Destroy(Scene *scene)
{
}

Scene *Scene15_Create()
{
    Scene15Data *mainMenu = new Scene15Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene15_Start,
        .update = Scene15_Update,
        .destroy = Scene15_Destroy
    };
    return scene;
}