#include "scene_8.hpp"
#include <iostream>

//suara speaker dipanggil belum


void Scene8_DialogPilihan1(Scene *scene)
{
    std::cout << "Pilihan 1 dipilih \n";

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
        "Selamat Pagi tuan-tuan!");
    
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/katakSenyum.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "Mr. Katak",
        "Selamat Pagi anakku!");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/katakBicara.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::None},
        },
        {},
        "Mr. Katak",
        "Silahkan duduk!");

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
        "Baik, terima kasih tuan!");

    SceneManager_GoToScene(scene->sceneManager, scene->connectedSceneNumbers[0], SceneTransition::Fade);
}

void Scene8_DialogPilihan2(Scene *scene)
{
    std::cout << "Pilihan 2 dipilih\n";  
    SceneManager_GoToScene(scene->sceneManager, scene->connectedSceneNumbers[1], SceneTransition::Fade);
}

void Scene8_DialogPilihan3(Scene *scene)
{
    std::cout << "Pilihan 3 dipilih\n";
    SceneManager_GoToScene(scene->sceneManager, scene->connectedSceneNumbers[2], SceneTransition::Fade);
}

void Scene8_Start(Scene *scene)
{
    Scene8Data *data = (Scene8Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "background/depan_pintu.png");

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
        "Sepertinya aku harus menyesuaikan diri");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "figuran/toav2.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "Speaker Unit",
        "Nomor urut 937492312309, silahkan masuk ke ruangan A110-M-41Y.");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "figuran/toav2.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Pop},
        },
        {},
        "Speaker Unit",
        "Jangan injak garis merah!");
    
        SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "figuran/toav2.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Shake},
        },
        {},
        "Speaker Unit",
        "BEEP BEEP BEEP!");

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
        "Wah,itu giliranku");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/talkingWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Pop},
        },
        {
            DialogQuestion{
                .question = "Masuk dan salam",
                .onAnswered = Scene8_DialogPilihan1,
                .onAnsweredParameter = scene},
            DialogQuestion{
                .question = "Masuk sambil teriak",
                .onAnswered = Scene8_DialogPilihan2,
                .onAnsweredParameter = scene},
            DialogQuestion{
                .question = "Masuk pelan-pelan",
                .onAnswered = Scene8_DialogPilihan3,
                .onAnsweredParameter = scene}
            },
            "Yono",
            "Baiklah, sekarang saatnya masuk.");
 
    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene8_Update(Scene *scene)
{
    Scene8Data *data = (Scene8Data *)scene->data;
}

void Scene8_Destroy(Scene *scene)
{
}

Scene *Scene8_Create()
{
    Scene8Data *mainMenu = new Scene8Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene8_Start,
        .update = Scene8_Update,
        .destroy = Scene8_Destroy
    };
    return scene;
}