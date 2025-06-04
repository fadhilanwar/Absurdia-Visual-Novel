#include "scene_13.hpp"
#include <iostream>

void Scene13_DialogScene13(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene14 = Scene14_Create();
    SceneManager_GoToScene(scene->sceneManager, scene14);
}

void Scene13_Start(Scene *scene)
{
    Scene13Data *data = (Scene13Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "tiba_dikota.png");
    SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene13_DialogScene13, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene13_Update(Scene *scene)
{
    Scene13Data *data = (Scene13Data *)scene->data;
}

void Scene13_Destroy(Scene *scene)
{
}

Scene *Scene13_Create()
{
    Scene13Data *mainMenu = new Scene13Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene13_Start,
        .update = Scene13_Update,
        .destroy = Scene13_Destroy
    };
    return scene;
}
