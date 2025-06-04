#include "scene_17.hpp"
#include <iostream>

void Scene17_DialogScene17(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene18 = Scene18_Create();
    SceneManager_GoToScene(scene->sceneManager, scene18);
}

void Scene17_Start(Scene *scene)
{
    Scene17Data *data = (Scene17Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "tiba_dikota.png");
    SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene17_DialogScene17, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene17_Update(Scene *scene)
{
    Scene17Data *data = (Scene17Data *)scene->data;
}

void Scene17_Destroy(Scene *scene)
{
}

Scene *Scene17_Create()
{
    Scene17Data *mainMenu = new Scene17Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene17_Start,
        .update = Scene17_Update,
        .destroy = Scene17_Destroy
    };
    return scene;
}
