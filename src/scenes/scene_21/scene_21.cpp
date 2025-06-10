#include "scene_21.hpp"
#include <iostream>

void Scene21_DialogPilihan1(Scene *scene)
{
    std:: cout << "Pilihan 1 dipilih\n";
    Scene *scene27 = Scene27_Create();
    SceneManager_GoToScene(scene->sceneManager, scene27, SceneTransition::None);
}

void Scene21_DialogPilihan2(Scene *scene)
{
    std:: cout << "Pilihan 2 dipilih\n";
    Scene *scene28 = Scene28_Create();
    SceneManager_GoToScene(scene->sceneManager, scene28, SceneTransition::None);
}

void Scene21_Start(Scene *scene)
{
    Scene21Data *data = (Scene21Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "background/interview.png");
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/katakTertawa.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::None},
        },
        {
            DialogQuestion{
                .question = "Setuju dan buat sketsa di kertas",
                .onAnswered = Scene21_DialogPilihan1,
                .onAnsweredParameter = scene},
            DialogQuestion{
                .question = "Mengusulkan kambing robot",
                .onAnswered = Scene21_DialogPilihan2,
                .onAnsweredParameter = scene
            },
            
        },
        "Mr. Katak",
        "Hahaha! Kita akan buat versi kambingnya!");
    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene21_Update(Scene *scene)
{
    Scene21Data *data = (Scene21Data *)scene->data;
}

void Scene21_Destroy(Scene *scene)
{
}

Scene *Scene21_Create()
{
    Scene21Data *mainMenu = new Scene21Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene21_Start,
        .update = Scene21_Update,
        .destroy = Scene21_Destroy
    };
    return scene;
}
