#include "scene_19.hpp"
#include <iostream>

void Scene19_DialogPilihan1(Scene *scene)
{
    std:: cout << "Pilihan 1 dipilih ";
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
        "Boleh minta cuti satu hari buat latihan suara kambing, Pak?");
    Scene *scene23 = Scene23_Create();
    SceneManager_GoToScene(scene->sceneManager, scene23, SceneTransition::None);
}

void Scene19_DialogPilihan2(Scene *scene)
{
    std:: cout << "Pilihan 2 dipilih ";

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
        "Kalo gitu.. Ada tes apa lagi nih? Saya mulai penasarann...");


    Scene *scene24 = Scene24_Create();
    SceneManager_GoToScene(scene->sceneManager, scene24, SceneTransition::None);
}

void Scene19_Start(Scene *scene)
{
    Scene19Data *data = (Scene19Data *)scene->data;
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
        "Hahahaha! Kalau begitu, kita cocok di sini...");

        SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/katakTerpesona.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
            },
           {DialogQuestion{
                .question = "Minta Cuti buat Latihan",
                .onAnswered = Scene19_DialogPilihan1,
                .onAnsweredParameter = scene},
           {DialogQuestion{
                .question = "Tanya Test Berikutnya",
                .onAnswered = Scene19_DialogPilihan2,
                .onAnsweredParameter = scene}},
           },
        "Mr. Katak",
        "Aku suka orang absurd yang sadar diri.");

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene19_Update(Scene *scene)
{
    Scene19Data *data = (Scene19Data *)scene->data;
}

void Scene19_Destroy(Scene *scene)
{
}

Scene *Scene19_Create()
{
    Scene19Data *mainMenu = new Scene19Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene19_Start,
        .update = Scene19_Update,
        .destroy = Scene19_Destroy
    };
    return scene;
}
