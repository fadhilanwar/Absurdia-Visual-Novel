#include "scene_1.hpp"
#include <iostream>

void Scene1_DialogBeres(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *newScene = Scene2_Create();
    SceneManager_GoToScene(scene->sceneManager, newScene);
}

void Scene1_TestDialogBeres(Scene *scene)
{
    SceneManager_PlaySound(scene->sceneManager, "nya.mp3");
}

void Scene1_Start(Scene *scene)
{
    Scene1Data *data = (Scene1Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "Futon_Room.png");
    SceneManager_AddDialog(scene->sceneManager, false, "Mita", "Hai! Apa kabar!", "mita.png");
    SceneManager_AddDialog(scene->sceneManager, true, "Fuad", "Ehh.. ehhh.. Halo..", "fuad.png");
    SceneManager_AddDialog(scene->sceneManager, false, "Mita", "Eh.. Halo!! Nama kamu siapa?", "mita.png");
    SceneManager_AddDialog(scene->sceneManager, true, "Fuad", "Ehh.. ehhh.. Fuad.. Fuad Mubarak", "fuad_anxiety.png");
    SceneManager_AddDialog(scene->sceneManager, false, "Mita", "Ihhhhhhhhh lucu banget dehh", "mita.png", Scene1_TestDialogBeres, scene);
    SceneManager_AddDialog(scene->sceneManager, false, "Mita", "Halo Fuad.. Kenalin aku Mita! :)", "mita_happy.png");
    SceneManager_AddDialog(scene->sceneManager, true, "Fuad", "Ehh.. ehhh.. Sa... Salam kenal!", "fuad_anxiety.png", Scene1_DialogBeres, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene1_Update(Scene *scene)
{
    Scene1Data *data = (Scene1Data *)scene->data;
    Canvas_DrawText(scene->canvas, 0, 0, "Abc 123", TextStyle::NORMAL, 24, sf::Color::White);
}

void Scene1_Destroy(Scene *scene)
{
}

Scene *Scene1_Create()
{
    Scene1Data *mainMenu = new Scene1Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene1_Start,
        .update = Scene1_Update,
        .destroy = Scene1_Destroy
    };
    return scene;
}