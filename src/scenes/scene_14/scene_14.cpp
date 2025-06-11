#include "scene_14.hpp"
#include <iostream>

void Scene14_DialogPilihan1(Scene *scene)
{
    std:: cout << "Pilihan 1 dipilih \n";

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
        "Kalau saya diterima . . .");

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
        "Kambing saya boleh ikut rapat kan? kan? hehehehe");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/katakBicara.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "Mr. Katak",
        "Yaa tentu saja boleh!");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/KatakTertawa.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::None},
        },
        {},
        "Mr. Katak",
        "Asalkan kambingmu pakai jas dan bisa angkat tangan saat voting");
    
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/shockedWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::None},
        },
        {},
        "Yono",
        "Yahhhh . . .");

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
        "Kalian punya kambing peliharaan tidak?");

    Scene *scene22 = Scene22_Create();
    SceneManager_GoToScene(scene->sceneManager, scene22, SceneTransition::None);
}

void Scene14_DialogPilihan2(Scene *scene)
{
    std:: cout << "Memilih pilihan 2\n";

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
        "Apa aku boleh minta cuti satu hari?");

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
        "Buat latihan suara kambing, hehehe");

    Scene *scene23 = Scene23_Create();
    SceneManager_GoToScene(scene->sceneManager, scene23, SceneTransition::None);
}

void Scene14_Start(Scene *scene)
{
    Scene14Data *data = (Scene14Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "background/interview.png");
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/katakBicara.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
            },
            {},
            "Mr.Katak",
            "Kita masuk ke tahap lanjutan, Tes Kambing Terapan.");

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
            "Kami ingin tahu bagaimana kamu bersosialisasi di habitat \nkambing korporat.");

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
                    .question = "Bertanya",
                    .onAnswered = Scene14_DialogPilihan1,
                    .onAnsweredParameter = scene},
                DialogQuestion{
                    .question = "Meminta cuti",
                    .onAnswered = Scene14_DialogPilihan2,
                    .onAnsweredParameter = scene}},
                "",
                "");
    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene14_Update(Scene *scene)
{
}

void Scene14_Destroy(Scene *scene)
{

}

Scene *Scene14_Create()
{
    Scene14Data *mainMenu = new Scene14Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene14_Start,
        .update = Scene14_Update,
        .destroy = Scene14_Destroy
    };
    return scene;
}
