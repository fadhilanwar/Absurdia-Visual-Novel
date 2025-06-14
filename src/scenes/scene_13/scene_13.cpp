#include "scene_13.hpp"
#include <iostream>

void Scene13_DialogPilihan1(Scene *scene)
{
    std::cout << "Pilihan 1 dipilih\n";

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
        "Baiklah, sudah aku isi dengan lengkap dan rapi!");

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
        "Bagus, asistenku akan mengurusnya nanti");

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
        "Oke pak! ");

    SceneManager_GoToScene(scene->sceneManager, scene->connectedSceneNumbers[0], SceneTransition::Fade);
}

void Scene13_DialogPilihan2(Scene *scene)
{
    std::cout << "Pilihan 2 dipilih\n";

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
        "Ini pak!");

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
        "Sudah kuisi formulirnya dengan krayon merah");

    SceneManager_GoToScene(scene->sceneManager, scene->connectedSceneNumbers[2], SceneTransition::Fade);
}

void Scene13_DialogPilihan3(Scene *scene)
{
    std::cout << "Pilihan 3 dipilih\n";
    SceneManager_GoToScene(scene->sceneManager, scene->connectedSceneNumbers[1], SceneTransition::None);
}

void Scene13_Start(Scene *scene)
{
    Scene13Data *data = (Scene13Data *)scene->data;
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
        "Akta lahirnya mana?");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/confusedWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "Yono",
        "Ahhh . . . ");

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
        "Saya lahir secara tidak resmi, hehehe");

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
        "Waduh waduuuuuh!");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/badutSenang.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::None},
        },
        {},
        "Dr. Badut",
        "Tenang saja, bisa kami atur, ahihiha!");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/badutBicara.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::None},
        },
        {DialogQuestion{
             .question = "Isi dengan serius",
             .onAnswered = Scene13_DialogPilihan1,
             .onAnsweredParameter = scene},
         DialogQuestion{
             .question = "Ambil krayon merah",
             .onAnswered = Scene13_DialogPilihan2,
             .onAnsweredParameter = scene},
         DialogQuestion{
             .question = "Jadikan origami",
             .onAnswered = Scene13_DialogPilihan3,
             .onAnsweredParameter = scene}},
        "Dr. Badut",
        "Silahkan isi formulirnya dulu ya");

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene13_Update(Scene *scene)
{
}

void Scene13_Destroy(Scene *scene)
{
}

Scene *Scene13_Create()
{
    Scene13Data *mainMenu = new Scene13Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene13_Start,
        .update = Scene13_Update,
        .destroy = Scene13_Destroy};
    return scene;
}
