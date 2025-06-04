#include "scene_18.hpp"
#include <iostream>

void Scene18_DialogScene18(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene19 = Scene19_Create();
    SceneManager_GoToScene(scene->sceneManager, scene19);
}

void Scene18_Start(Scene *scene)
{
    Scene18Data *data = (Scene18Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "tiba_dikota.png");
    SceneManager_AddDialog(scene->sceneManager, true, "MC", "Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene18_DialogScene18, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene18_Update(Scene *scene)
{
    Scene18Data *data = (Scene18Data *)scene->data;
}

void Scene18_Destroy(Scene *scene)
{
}

Scene *Scene18_Create()
{
    Scene18Data *mainMenu = new Scene18Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene18_Start,
        .update = Scene18_Update,
        .destroy = Scene18_Destroy
    };
    return scene;
}