#include "scene_17.hpp"
#include <iostream>



void Scene17_DialogScene17(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene18 = Scene18_Create();
    // // SceneManager_GoToSceneene(scene->sceneManager, scene18);
}

void Scene17_DialogPilihan1(Scene *scene)
{
    std:: cout << "Pilihan 1 dipilih (Jawab Serius) ";
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/talkingWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::None},
            },
        {},
        "Fuad Gemink",
        "Ya. Saya penuh rahasia. Berengsel kuat, tapi sering dibuka tanpa izin.");
    Scene *scene18 = Scene18_Create();
    SceneManager_GoToScene(scene->sceneManager, scene18, SceneTransition::None);
}

void Scene17_DialogPilihan2(Scene *scene)
{
    std:: cout << "Pilihan 2 dipilih (Balas dengan Guyonan) ";

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/happyWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
            },
        {},
        "Fuad Gemink",
        "Kalau begitu, saya harus buka dan tutup interview ini cepat. (Layaknya pintu)");


    Scene *scene19 = Scene19_Create();
    SceneManager_GoToScene(scene->sceneManager, scene19, SceneTransition::None);
}

void Scene17_DialogPilihan3(Scene *scene)
{
    Scene17Data *data = (Scene17Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "background/interview.png");

    std:: cout << "Pilihan 3 dipilih (Berdiri, lalu buat suara 'creak' Pintu) ";

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/happyWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
            },
        {},
        "Fuad Gemink",
        "(Berdiri dan menirukan suara pintu...) Krekk... ciiitt... tok!");

    Scene *scene20 = Scene20_Create();
    SceneManager_GoToScene(scene->sceneManager, scene20, SceneTransition::None);
}

void Scene17_Start(Scene *scene)
{
    Scene17Data *data = (Scene17Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "background/interview.png");

     SceneManager_AddDialog(
        scene->sceneManager,
        {
            // DialogPerson{
            //     .imageFilePath = "",
            //     .position = DialogPersonPosition::None,
            //     .animation = DialogPersonAnimation::None},
            },
        {},
        "Fuad Gemink",
        "(MC Menjawab bercanda soal dirinya adalah 'Mantan Pintu')");

   
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/KatakTertawa.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
            },
           {DialogQuestion{
                .question = "Jawab Serius",
                .onAnswered = Scene17_DialogPilihan1,
                .onAnsweredParameter = scene},
            DialogQuestion{
                .question = "Balas dengan Guyonan",
                .onAnswered = Scene17_DialogPilihan2,
                .onAnsweredParameter = scene},
            DialogQuestion{
                .question = "Berdiri dan Tiru suara pintu",
                .onAnswered = Scene17_DialogPilihan3,
                .onAnsweredParameter = scene}},
        "Mr. Katak",
        "Hahahaha!.. Reinkarnasi lemari 90-an? Unik juga.");
        

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene17_Update(Scene *scene)
{
    Scene17Data *data = (Scene17Data *)scene->data;
}

void Scene17_Destroy(Scene *scene)
{
}

Scene *Scene17_Create()
{
    Scene17Data *mainMenu = new Scene17Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene17_Start,
        .update = Scene17_Update,
        .destroy = Scene17_Destroy
    };
    return scene;
}
