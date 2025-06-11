#include "scene_11.hpp"
#include <iostream>

void Scene11_DialogPilihan1(Scene *scene)
{
    std:: cout << "Pilihan 1 dipilih\n";

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/talkingWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "Yono",
        "Betull! Saya reinkarnasi lemari tahun 90-an");

    SceneManager_GoToScene(scene->sceneManager, scene->connectedSceneNumbers[0], SceneTransition::None);
}

void Scene11_DialogPilihan2(Scene *scene)
{
    std:: cout << "Pilihan 2 dipilih\n";

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/talkingWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "Yono",
        "Tidak tidak, saya hanya mantan narator kisah horor.");

    SceneManager_GoToScene(scene->sceneManager, scene->connectedSceneNumbers[1], SceneTransition::None);
}

void Scene11_Start(Scene *scene)
{
    Scene11Data *data = (Scene11Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "background/interview.png");
    SceneManager_AddDialog(
            scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/talkingWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
            },
            {},
            "Yono",
            "Ciieeeeetttsss. . .");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/katakBicara.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
            },
            {
                DialogQuestion{
                    .question = "Jawab dengan serius",
                    .onAnswered = Scene11_DialogPilihan1,
                    .onAnsweredParameter = scene},
                DialogQuestion{
                    .question = "Tertawa dan bercanda",
                    .onAnswered = Scene11_DialogPilihan2,
                    .onAnsweredParameter = scene}},
                "Mr.Katak",
                "Suara pintu kamu sangat realistis. Kamu mantan pintu?");

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}


void Scene11_Update(Scene *scene)
{
    // Scene11Data *data = (Scene11Data *)scene->data;
}

void Scene11_Destroy(Scene *scene)
{
}

Scene *Scene11_Create()
{
    Scene11Data *mainMenu = new Scene11Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene11_Start,
        .update = Scene11_Update,
        .destroy = Scene11_Destroy
    };
    return scene;
}