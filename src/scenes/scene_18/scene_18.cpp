#include "scene_18.hpp"
#include <iostream>

void Scene18_DialogPilihan1(Scene *scene)
{
    std:: cout << "Pilihan 1 dipilih ";
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
            "Saya ada ide untuk logo perusahaan.");
    
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
            "Benarkah? Beri tahu kami");

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
            "Bagaimana kita ganti dengan kambing bawa koper? Autentik bukan!");
    
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
            "YAYAYAYA! Aku suka idemu");

    SceneManager_GoToScene(scene->sceneManager, scene->connectedSceneNumbers[0], SceneTransition::None);
}

void Scene18_DialogPilihan2(Scene *scene)
{
    std:: cout << "Pilihan 1 dipilih";
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
            "Kalau boleh tahu, Anda punya kambing peliharaan juga?");

    SceneManager_GoToScene(scene->sceneManager, scene->connectedSceneNumbers[1], SceneTransition::None);
}

void Scene18_Start(Scene *scene)
{
    Scene18Data *data = (Scene18Data *)scene->data;
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
        "Dr. Badut",
        "Kamu punya sisis seni yang kuat");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/katakBicara.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::None},
            },
        {},
        "Dr. Badut",
        "Kami butuh orang sepertimu!");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/defaultWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
            },
        {
            DialogQuestion{
                .question = "Tawarkan Ide Logo",
                .onAnswered = Scene18_DialogPilihan1,
                .onAnsweredParameter = scene},
            DialogQuestion{
                .question = "Tanya balik soal kambing",
                .onAnswered = Scene18_DialogPilihan2,
                .onAnsweredParameter = scene}
            },
        "Yono",
        "");

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene18_Update(Scene *scene)
{
    Scene18Data *data = (Scene18Data *)scene->data;
}

void Scene18_Destroy(Scene *scene)
{
}

Scene *Scene18_Create()
{
    Scene18Data *mainMenu = new Scene18Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene18_Start,
        .update = Scene18_Update,
        .destroy = Scene18_Destroy
    };
    return scene;
}