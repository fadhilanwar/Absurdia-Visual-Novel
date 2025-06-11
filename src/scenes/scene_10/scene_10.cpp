#include "scene_10.hpp"
#include <iostream>


void Scene10_DialogPilihan1(Scene *scene) {
    std::cout << "Pilihan 1 dipilih ";

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
        "Hehehehe, maaf maaf");

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
        "Kebiasaanku terbawa dari tempat sirkus dulu");

    Scene *scene9 = Scene9_Create();
    SceneManager_GoToScene(scene->sceneManager, scene9, SceneTransition::None);
}

void Scene10_DialogPilihan2(Scene *scene) {
    std::cout << "Pilihan 2 dipilih ";

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
        "Tuan-tuan, lihat ini!");

    Scene *scene16 = Scene16_Create();
    SceneManager_GoToScene(scene->sceneManager, scene16, SceneTransition::None);
}

void Scene10_Start(Scene *scene)
{
    Scene10Data *data = (Scene10Data *)scene->data;
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
        "SAYA SIAP KERJA!");
    
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/katakMeringis.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
        },
        {
            DialogQuestion{
                .question = "Minta maaf",
                .onAnswered = Scene10_DialogPilihan1,
                .onAnsweredParameter = scene},
            DialogQuestion{
                .question = "Juggling",
                .onAnswered = Scene10_DialogPilihan2,
                .onAnsweredParameter = scene},
        },
        "Mr. Katak",
        "Eh . . . saya tidak siap dengan level energi ini");

    

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene10_Update(Scene *scene)
{
    Scene10Data *data = (Scene10Data *)scene->data;
}

void Scene10_Destroy(Scene *scene)
{
}

Scene *Scene10_Create()
{
    Scene10Data *mainMenu = new Scene10Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene10_Start,
        .update = Scene10_Update,
        .destroy = Scene10_Destroy
    };
    return scene;
}