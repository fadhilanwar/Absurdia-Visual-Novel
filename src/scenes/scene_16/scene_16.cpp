#include "scene_16.hpp"
#include <iostream>

void Scene16_DialogPilihan1(Scene *scene)
{
    std:: cout << "Memilih pilihan 1\n";
    Scene *scene26 = Scene26_Create();
    SceneManager_GoToScene(scene->sceneManager, scene26, SceneTransition::Fade);
}

void Scene16_DialogPilihan2(Scene *scene)
{
    std:: cout << "Memilih pilihan 2\n";
    Scene *scene18 = Scene18_Create();
    SceneManager_GoToScene(scene->sceneManager, scene18, SceneTransition::Fade);
}

void Scene16_Start(Scene *scene)
{
    Scene16Data *data = (Scene16Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "background/interview.png");
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
            "Hei! itu apel presentasi");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/confusedWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
            },
            {},
            "MC",
            "Ups... semangat saya refleks sirkus, Pak.");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/katakBicara.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
            },
            {},
            "Mr. Katak",
            "Kita apresiasi metode interaktif. Tapi kami perlu klarifikasi.");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/confusedWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
            },
            {
                DialogQuestion{
                    .question = "Minta maaf dan tawarkan tisu bertema",
                    .onAnswered = Scene16_DialogPilihan1,
                    .onAnsweredParameter = scene},
                DialogQuestion{
                    .question = "Menjelaskan Junggling",
                    .onAnswered = Scene16_DialogPilihan2,
                    .onAnsweredParameter = scene}},
                "",
                "");
}

void Scene16_Update(Scene *scene)
{
    Scene16Data *data = (Scene16Data *)scene->data;
}

void Scene16_Destroy(Scene *scene)
{
}

Scene *Scene16_Create()
{
    Scene16Data *mainMenu = new Scene16Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene16_Start,
        .update = Scene16_Update,
        .destroy = Scene16_Destroy
    };
    return scene;
}


// void Scene16_DialogScene16(Scene *scene)
// {
//     std::cout << "Dialog beres\n";
//     Scene *scene17 = Scene17_Create();
//     // // SceneManager_GoToSceneene(scene->sceneManager, scene17);
// }

// void Scene16_Start(Scene *scene)
// {
//     Scene16Data *data = (Scene16Data *)scene->data;
//     SceneManager_SetBackground(scene->sceneManager, "tiba_dikota.png");
//     // SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene16_DialogScene16, scene);

//     SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
// }

// void Scene16_Update(Scene *scene)
// {
//     Scene16Data *data = (Scene16Data *)scene->data;
// }

// void Scene16_Destroy(Scene *scene)
// {
// }

// Scene *Scene16_Create()
// {
//     Scene16Data *mainMenu = new Scene16Data();
//     Scene *scene = new Scene{
//         .data = mainMenu,
//         .start = Scene16_Start,
//         .update = Scene16_Update,
//         .destroy = Scene16_Destroy
//     };
//     return scene;
// }
