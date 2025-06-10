#include "scene_5.hpp"
#include <iostream>

void Scene5_PindahScene1(Scene *scene)
{
    std:: cout << "Pindah scene\n";
    Scene *scene6 = Scene6_Create();
    SceneManager_GoToScene(scene->sceneManager, scene6, SceneTransition::Fade);
}

void Scene5_PindahScene2(Scene *scene)
{
    std:: cout << "Pindah scene\n";
    Scene *scene7 = Scene7_Create();
    SceneManager_GoToScene(scene->sceneManager, scene7, SceneTransition::Fade);
}


//pilihan 1
void Scene5_DialogPilihan1(Scene *scene)
{
    std:: cout << "Pilihan 1 dipilih\n";
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/defaultWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
            },
        {},
        "Yono",
        "Permisi, Pak. . . ini. . .  ruang interview di mana ya?");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "figuran/satpamTalk.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
            },
            {},
            "Satpam",
            "Hmm. . .  di lantai 5");

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
            "Lho, ini bukan lantai 5?");
    
     SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "figuran/satpamTalking.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
            },
            {},
            "Satpam",
            "Hahaha. . .  di sini dunia bekerja secara terbalik, kawanku.");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "figuran/satpamTalking.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
            },
            {},
            "Satpam",
            "Ya. . .  setidaknya di beberapa bagian gedung.");   
            
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
                ". . .  Eh. . .  baiklah. Terima kasih, Pak.",
            Scene5_PindahScene1, scene);
}

void Scene5_DialogPilihan2(Scene *scene)
{
    std::cout << "pilihan 2 dipilih\n";
    SceneManager_SetBackground(scene->sceneManager, "background/tangga.png");
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
        "Ya ampun. . .  tangganya kok begini sih??",
    Scene5_PindahScene2, scene);
    
}

void Scene5_Start(Scene *scene)
{
    Scene5Data *data = (Scene5Data *)scene->data;

    SceneManager_SetBackground(scene->sceneManager, "background/basement.png");
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/confusedWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::FadeIn},
        },
        {
            DialogQuestion{
                .question = "Bertanya kepada satpam",
                .onAnswered = Scene5_DialogPilihan1,
                .onAnsweredParameter =scene},
            DialogQuestion{
                .question = "Naik tangga",
                .onAnswered = Scene5_DialogPilihan2,
                .onAnsweredParameter = scene}},
        "Yono",
        "Lho. . . ???");
        SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene5_Update(Scene *scene)
{
    Scene5Data *data = (Scene5Data *)scene->data;
}

void Scene5_Destroy(Scene *scene)
{
}

Scene *Scene5_Create()
{
    Scene5Data *mainMenu = new Scene5Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene5_Start,
        .update = Scene5_Update,
        .destroy = Scene5_Destroy
    };
    return scene;
}


// void Scene5_DialogScene5(Scene *scene)
// {
//     std::cout << "Dialog beres\n";
//     Scene *scene6 = Scene6_Create();
//     // SceneManager_GoToScene(scene->sceneManager, scene6);
// }

// void Scene5_Start(Scene *scene)
// {
//     Scene5Data *data = (Scene5Data *)scene->data;
//     SceneManager_SetBackground(scene->sceneManager, "tiba_dikota.png");
//     // SceneManager_AddDialog(scene->sceneManager, true, "Yono","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene5_DialogScene5, scene);

//     SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
// }

// void Scene5_Update(Scene *scene)
// {
//     Scene5Data *data = (Scene5Data *)scene->data;
// }

// void Scene5_Destroy(Scene *scene)
// {
// }

// Scene *Scene5_Create()
// {
//     Scene5Data *mainMenu = new Scene5Data();
//     Scene *scene = new Scene{
//         .data = mainMenu,
//         .start = Scene5_Start,
//         .update = Scene5_Update,
//         .destroy = Scene5_Destroy
//     };
//     return scene;
// }