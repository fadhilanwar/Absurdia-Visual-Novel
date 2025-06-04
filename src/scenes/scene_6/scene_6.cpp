#include "scene_6.hpp"
#include <iostream>

void Scene6_DialogScene6(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene6 = Scene6_Create();
    SceneManager_GoToScene(scene->sceneManager, scene6);
}

void Scene6_Start(Scene *scene)
{
    Scene6Data *data = (Scene6Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "tiba_dikota.png");
    SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene6_DialogScene6, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene6_Update(Scene *scene)
{
    Scene6Data *data = (Scene6Data *)scene->data;
}

void Scene6_Destroy(Scene *scene)
{
}

Scene *Scene6_Create()
{
    Scene6Data *mainMenu = new Scene6Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene6_Start,
        .update = Scene6_Update,
        .destroy = Scene6_Destroy
    };
    return scene;
}