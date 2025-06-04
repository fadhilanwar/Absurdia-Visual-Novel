#include "scene_7.hpp"
#include <iostream>

void Scene7_DialogScene7(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene7 = Scene7_Create();
    SceneManager_GoToScene(scene->sceneManager, scene7);
}

void Scene7_Start(Scene *scene)
{
    Scene7Data *data = (Scene7Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "tiba_dikota.png");
    SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene7_DialogScene7, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene7_Update(Scene *scene)
{
    Scene7Data *data = (Scene7Data *)scene->data;
}

void Scene7_Destroy(Scene *scene)
{
}

Scene *Scene7_Create()
{
    Scene7Data *mainMenu = new Scene7Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene7_Start,
        .update = Scene7_Update,
        .destroy = Scene7_Destroy
    };
    return scene;
}