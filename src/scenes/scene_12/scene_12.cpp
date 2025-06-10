#include "scene_12.hpp"
#include <iostream>


void Scene12_DialogPilihan1(Scene *scene)
{
    std:: cout << "Pilihan 1 dipilih\n";

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/happyWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "Yono",
        "Terimakasih!");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/talkingWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::None},
        },
        {},
        "Yono",
        "Dari kecil saya memang suka sekali bermain denga bunyi, hehehe");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/badutSenang.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "Dr. Badut",
        "Wah begitu!");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/badutBingung.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::None},
        },
        {},
        "Dr. Badut",
        "Kulihat-lihat sepertinya kamu keturunan kambing juga ya?");

    Scene *scene13 = Scene13_Create();
    SceneManager_GoToScene(scene->sceneManager, scene13, SceneTransition::Fade);
}

void Scene12_DialogPilihan2(Scene *scene)
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
        "MBEEEEEEE!");

        SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/katakTertawa.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "Mr. Katak",
        "Oke oke, kita lanjut ya");

    Scene *scene14 = Scene14_Create();
    SceneManager_GoToScene(scene->sceneManager, scene14, SceneTransition::Fade);
}

void Scene12_Start(Scene *scene)
{
    Scene12Data *data = (Scene12Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "background/interview.png");
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "figuran/katakTertawa.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
            },
            {
                DialogQuestion{
                    .question = "Terimakasih dan duduk tegap",
                    .onAnswered = Scene12_DialogPilihan1,
                    .onAnsweredParameter = scene},
                DialogQuestion{
                    .question = "Mbeeeee (dengan nada pelan)",
                    .onAnswered = Scene12_DialogPilihan2,
                    .onAnsweredParameter = scene}},
                    "Mr.Katak",
                    "Kreatif dengan fonetik. . .  saya suka! ");
    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene12_Update(Scene *scene)
{
    Scene12Data *data = (Scene12Data *)scene->data;
}

void Scene12_Destroy(Scene *scene)
{
}

Scene *Scene12_Create()
{
    Scene12Data *mainMenu = new Scene12Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene12_Start,
        .update = Scene12_Update,
        .destroy = Scene12_Destroy
    };
    return scene;
}
