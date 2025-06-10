#include "scene_20.hpp"
#include <iostream>

void Scene20_DialogScene20(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene21 = Scene21_Create();
    // // SceneManager_GoToSceneene(scene->sceneManager, scene21);
}

void Scene20_DialogPilihan1(Scene *scene)
{
    std:: cout << "Pilihan 1 dipilih (Maen Peran Peranan) ";
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/talkingWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
            },
        {},
        "Fuad Gemink",
        "Kalau begitu, mari kita aktingkan ulang sejarah pintu pertama ditemukan.");
    Scene *scene25 = Scene25_Create();
    SceneManager_GoToScene(scene->sceneManager, scene25, SceneTransition::None);
}

void Scene20_DialogPilihan2(Scene *scene)
{
    std:: cout << "Pilihan 2 dipilih (Cerita Pintu) ";

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/talkingWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
            },
        {},
        "Fuad Gemink",
        "Saya pernah jadi pintu gudang tua. Banyak kenangan berdebu di sana...");


    Scene *scene26 = Scene26_Create();
    SceneManager_GoToScene(scene->sceneManager, scene26, SceneTransition::None);
}

void Scene20_Start(Scene *scene)
{
    Scene20Data *data = (Scene20Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "background/interview.png");
    // SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene20_DialogScene20, scene);

     SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/katakTerpesona.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
            },
           {DialogQuestion{
                .question = "Ajak Main Peran",
                .onAnswered = Scene20_DialogPilihan1,
                .onAnsweredParameter = scene},
           {DialogQuestion{
                .question = "Cerita Pengalaman jadi Pintu",
                .onAnswered = Scene20_DialogPilihan2,
                .onAnsweredParameter = scene}},
           },
        "Mr. Katak",
        "(SERIUS) Ini sudah macam menonton sebuah Teater!");

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene20_Update(Scene *scene)
{
    Scene20Data *data = (Scene20Data *)scene->data;
}

void Scene20_Destroy(Scene *scene)
{
}

Scene *Scene20_Create()
{
    Scene20Data *mainMenu = new Scene20Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene20_Start,
        .update = Scene20_Update,
        .destroy = Scene20_Destroy
    };
    return scene;
}
