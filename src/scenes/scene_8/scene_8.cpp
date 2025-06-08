#include "scene_8.hpp"
#include <iostream>

//suara speaker dipanggil belum


void Scene8_DialogPilihan1(Scene *scene)
{
    std::cout << "Pilihan 1 dipilih \n";
    Scene *scene9 = Scene9_Create();
    SceneManager_GoToScene(scene->sceneManager, scene9, SceneTransition::Fade);
}

void Scene8_DialogPilihan2(Scene *scene)
{
    std::cout << "Pilihan 2 dipilih\n";
    Scene *scene10 = Scene10_Create();
    SceneManager_GoToScene(scene->sceneManager, scene10, SceneTransition::Fade);
}

void Scene8_DialogPilihan3(Scene *scene)
{
    std::cout << "Pilihan 3 dipilih\n";
    Scene *scene11 = Scene11_Create();
    SceneManager_GoToScene(scene->sceneManager, scene11, SceneTransition::Fade);
}

void Scene8_Start(Scene *scene)
{
    Scene8Data *data = (Scene8Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "background/depan_pintu.png");
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/confusedWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
        },
        {
            DialogQuestion{
                .question = "Salam",
                .onAnswered = Scene8_DialogPilihan1,
                .onAnsweredParameter = scene},
            DialogQuestion{
                .question = "Masuk sambil teriak",
                .onAnswered = Scene8_DialogPilihan2,
                .onAnsweredParameter = scene},
            DialogQuestion{
                .question = "Masuk pelan-pelan",
                .onAnswered = Scene8_DialogPilihan3,
                .onAnsweredParameter = scene}
            },
            "MC",
            "Baiklah... sepertinya aku harus “menyesuaikan");
 
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