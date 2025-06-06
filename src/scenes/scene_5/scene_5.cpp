#include "scene_5.hpp"
#include <iostream>

void Scene5_DialogScene5(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene6 = Scene6_Create();
    // SceneManager_GoToScene(scene->sceneManager, scene6);
}

void Scene5_Start(Scene *scene)
{
    Scene5Data *data = (Scene5Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "tiba_dikota.png");
    // SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene5_DialogScene5, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene5_Update(Scene *scene)
{
    Scene5Data *data = (Scene5Data *)scene->data;
}

void Scene5_Destroy(Scene *scene)
{
}

Scene *Scene5_Create()
{
    Scene5Data *mainMenu = new Scene5Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene5_Start,
        .update = Scene5_Update,
        .destroy = Scene5_Destroy
    };
    return scene;
}