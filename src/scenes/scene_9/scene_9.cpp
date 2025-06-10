#include "scene_9.hpp"
#include <iostream>

void Scene9_DialogPilihan1(Scene *scene)
{
    std:: cout << "Pilihan 1 dipilih Baadrunsyah";
    // Scene *scene12 = Scene12_Create();
    // SceneManager_GoToScene(scene->sceneManager, scene12, SceneTransition::Fade);
    Scene *scene17 = Scene17_Create();
    SceneManager_GoToScene(scene->sceneManager, scene17, SceneTransition::Fade);
}

void Scene9_DialogPilihan2(Scene *scene)
{
    std:: cout << "Pilihan 2 dipilih ";
    Scene *scene13 = Scene13_Create();
    SceneManager_GoToScene(scene->sceneManager, scene13, SceneTransition::Fade);
}

void Scene9_DialogPilihan3(Scene *scene)
{
    std:: cout << "Pilihan 3 dipilih";
    Scene *scene14 = Scene14_Create();
    SceneManager_GoToScene(scene->sceneManager, scene14, SceneTransition::Fade);
}

void Scene9_DialogPilihan4(Scene *scene)
{
    std:: cout << "Pilihan 4 dipilih";
    Scene *scene15 = Scene15_Create();
    SceneManager_GoToScene(scene->sceneManager, scene15, SceneTransition::Fade);
}

void Scene9_Start(Scene *scene)
{
    Scene9Data *data = (Scene9Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "background/interview.png");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/badutBicara.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "Dr. Badut",
        "Oke, kita mulai saja ya tesnya!");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/badutBicara.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::None},
            },
            {
                DialogQuestion{
                    .question = "Baaaa-drun Syah",
                    .onAnswered = Scene9_DialogPilihan1,
                    .onAnsweredParameter = scene},
                DialogQuestion{
                    .question = "Kambing bin Ternak",
                    .onAnswered = Scene9_DialogPilihan2,
                    .onAnsweredParameter = scene},
                DialogQuestion{
                    .question = "Mengembik ",
                    .onAnswered = Scene9_DialogPilihan3,
                    .onAnsweredParameter = scene},
                DialogQuestion{
                    .question = "Tulis nama di kertas",
                    .onAnswered = Scene9_DialogPilihan4,
                    .onAnsweredParameter = scene}},
                "Dr. Badut",
                "Pertama. . .  kalau kamu seekor kambing, apa nama lengkapmu, mbee?");

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene9_Update(Scene *scene)
{
    //Scene9Data *data = (Scene9Data *)scene->data;
}

void Scene9_Destroy(Scene *scene)
{
}

Scene *Scene9_Create()
{
    Scene9Data *mainMenu = new Scene9Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene9_Start,
        .update = Scene9_Update,
        .destroy = Scene9_Destroy
    };
    return scene;
}