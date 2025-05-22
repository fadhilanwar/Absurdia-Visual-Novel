#include "scene_2.hpp"
#include <iostream>



void Scene2_Start(Scene *scene)
{
    Scene2Data *data = (Scene2Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "Restaurant_A.png");
    SceneManager_AddDialog(scene->sceneManager, false, "Mita", "Hai! Apa kabar!", "mita.png");
    SceneManager_AddDialog(scene->sceneManager, true, "Fuad", "Ehh.. ehhh.. Halo..", "fuad.png");

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene2_Update(Scene *scene)
{
    Scene2Data *data = (Scene2Data *)scene->data;
}

void Scene2_Destroy(Scene *scene)
{
}

Scene *Scene2_Create()
{
    Scene2Data *mainMenu = new Scene2Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene2_Start,
        .update = Scene2_Update,
        .destroy = Scene2_Destroy
    };
    return scene;
}