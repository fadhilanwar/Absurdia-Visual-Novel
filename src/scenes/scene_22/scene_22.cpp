#include "scene_22.hpp"
#include <iostream>

void Scene22_DialogPilihan1(Scene *scene)
{
    std:: cout << "Pilihan 1 dipilih\n";
    Scene *scene29 = Scene29_Create();
    SceneManager_GoToScene(scene->sceneManager, scene29, SceneTransition::None);
}

void Scene22_DialogPilihan2(Scene *scene)
{
    std:: cout << "Pilihan 2 dipilih\n";
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/talkingWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Pop},
        },
        {},
        "Yono",
        "Kambing saya boleh ikut rapat kan? kan? hehehehe");
    Scene *scene30 = Scene30_Create();
    SceneManager_GoToScene(scene->sceneManager, scene30, SceneTransition::None);
}

void Scene22_Start(Scene *scene)
{
    Scene22Data *data = (Scene22Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "background/interview.png");
    SceneManager_AddDialog(
        scene->sceneManager,
    {
        DialogPerson{
            .imageFilePath = "HRD/badutSenang.png",
            .position = DialogPersonPosition::Right,
            .animation = DialogPersonAnimation::None},
        },
        {},
        "Dr.Badut",
        "Oh tentu. Kami punya kebun belakang kantor penuh kambing anggora"
    );

    SceneManager_AddDialog(
        scene->sceneManager,
    {
        DialogPerson{
            .imageFilePath = "work/happyWork.png",
            .position = DialogPersonPosition::Left,
            .animation = DialogPersonAnimation::None},
        },
        {},
        "Yono",
        "Wow. Ada daftar adopsi karyawan?"
    );

    SceneManager_AddDialog(
        scene->sceneManager,
    {
        DialogPerson{
            .imageFilePath = "HRD/katakSenyum.png",
            .position = DialogPersonPosition::Right,
            .animation = DialogPersonAnimation::None},
        },
        {},
        "Mr. Katak",
        "Ada. Tapi harus lulus tes makan rumput dulu"
    );

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/shockedWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
            },
            {
                DialogQuestion{
                    .question = "Ikut tes",
                    .onAnswered = Scene22_DialogPilihan1,
                    .onAnsweredParameter = scene},
                DialogQuestion{
                    .question = "Tanya kambing lagi",
                    .onAnswered = Scene22_DialogPilihan2,
                    .onAnsweredParameter = scene}},
                "",
                "");

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene22_Update(Scene *scene)
{
    //Scene22Data *data = (Scene22Data *)scene->data;
}

void Scene22_Destroy(Scene *scene)
{
}

Scene *Scene22_Create()
{
    Scene22Data *mainMenu = new Scene22Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene22_Start,
        .update = Scene22_Update,
        .destroy = Scene22_Destroy
    };
    return scene;
}
