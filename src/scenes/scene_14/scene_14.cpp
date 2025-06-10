#include "scene_14.hpp"
#include <iostream>

void Scene14_DialogPilihan1(Scene *scene)
{
    std:: cout << "Memilih pilihan 1\n";
    Scene *scene22 = Scene22_Create();
    SceneManager_GoToScene(scene->sceneManager, scene22, SceneTransition::Fade);
}

void Scene14_DialogPilihan2(Scene *scene)
{
    std:: cout << "Memilih pilihan 2\n";
    Scene *scene23 = Scene23_Create();
    SceneManager_GoToScene(scene->sceneManager, scene23, SceneTransition::Fade);
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
            "Selamat datang di tahap lanjutan: Tes Kambing Terapan.");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/badutSenang.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
            },
            {},
            "Dr. Badut",
            "Kami ingin tahu bagaimana kamu bersosialisasi di habitat kambing korporat.");

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




// void Scene14_DialogScene14(Scene *scene)
// {
//     std::cout << "Dialog beres\n";
//     Scene *scene15 = Scene15_Create();
//     // // SceneManager_GoToScene(scene->sceneManager, scene15);
// }

// void Scene14_Start(Scene *scene)
// {
//     Scene14Data *data = (Scene14Data *)scene->data;
//     SceneManager_SetBackground(scene->sceneManager, "tiba_dikota.png");
//     // SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene14_DialogScene14, scene);

//     SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
// }

// void Scene14_Update(Scene *scene)
// {
//     Scene14Data *data = (Scene14Data *)scene->data;
// }

// void Scene14_Destroy(Scene *scene)
// {
// }

// Scene *Scene14_Create()
// {
//     Scene14Data *mainMenu = new Scene14Data();
//     Scene *scene = new Scene{
//         .data = mainMenu,
//         .start = Scene14_Start,
//         .update = Scene14_Update,
//         .destroy = Scene14_Destroy
//     };
//     return scene;
// }