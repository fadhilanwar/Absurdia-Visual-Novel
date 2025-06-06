#include "scene_8.hpp"
#include <iostream>

void Scene8_DialogScene8(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene9 = Scene9_Create();
    // SceneManager_GoToScene(scene->sceneManager, scene9);
}

void Scene8_Start(Scene *scene)
{
    Scene8Data *data = (Scene8Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "tiba_dikota.png");
    // SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene8_DialogScene8, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene8_Update(Scene *scene)
{
    Scene8Data *data = (Scene8Data *)scene->data;
}

void Scene8_Destroy(Scene *scene)
{
}

Scene *Scene8_Create()
{
    Scene8Data *mainMenu = new Scene8Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene8_Start,
        .update = Scene8_Update,
        .destroy = Scene8_Destroy
    };
    return scene;
}