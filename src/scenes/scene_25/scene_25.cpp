#include "scene_25.hpp"
#include <iostream>

void Scene25_DialogScene25(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene26 = Scene26_Create();
    // // SceneManager_GoToScene(scene->sceneManager, scene26);
}

void Scene25_Start(Scene *scene)
{
    Scene25Data *data = (Scene25Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "tiba_dikota.png");
    // SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene25_DialogScene25, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene25_Update(Scene *scene)
{
    Scene25Data *data = (Scene25Data *)scene->data;
}

void Scene25_Destroy(Scene *scene)
{
}

Scene *Scene25_Create()
{
    Scene25Data *mainMenu = new Scene25Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene25_Start,
        .update = Scene25_Update,
        .destroy = Scene25_Destroy
    };
    return scene;
}
