#include "scene_3.hpp"
#include <iostream>

void Scene3_DialogScene3(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene4 = Scene4_Create();
    SceneManager_GoToScene(scene->sceneManager, scene4);
}

void Scene3_Start(Scene *scene)
{
    Scene3Data *data = (Scene3Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "tiba_dikota.png");
    SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png");
    SceneManager_SetBackground(scene->sceneManager, "depan_gedung.png");
    SceneManager_AddDialog(scene->sceneManager, true, "MC", "Ini gedungnya? Bentuknya nggak biasa banget.", "confusedWork.png");
    SceneManager_AddDialog(scene->sceneManager, true, "MC", "Desain jendelanya kayak kebalik. Apa ini sengaja atau tukang bangunannya ngantuk?", "shockedWork.png", Scene3_DialogScene3, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene3_Update(Scene *scene)
{
    Scene3Data *data = (Scene3Data *)scene->data;
}

void Scene3_Destroy(Scene *scene)
{
}

Scene *Scene3_Create()
{
    Scene3Data *mainMenu = new Scene3Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene3_Start,
        .update = Scene3_Update,
        .destroy = Scene3_Destroy
    };
    return scene;
}