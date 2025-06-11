#include "scene_20.hpp"
#include <iostream>

void Scene20_DialogPilihan1(Scene *scene)
{
    std:: cout << "Pilihan 1 dipilih";
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
        "Kalau begitu, mari kita aktingkan ulang sejarah pintu pertama ditemukan.");
    Scene *scene25 = Scene25_Create();
    SceneManager_GoToScene(scene->sceneManager, scene25, SceneTransition::None);
}

void Scene20_DialogPilihan2(Scene *scene)
{
    std:: cout << "Pilihan 2 dipilih";

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
        "Saya pernah jadi pintu gudang tua. Banyak kenangan berdebu di sana...");
    
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
        "Dan aku selalu melihat robot kambing tua yang sudah berkarat");

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
        "Setiap hari aku menggambarnya, dan menyimpannya gambarnya di sakuku");
    
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
        "Dan aku berpikir untuk membuatnya lagi disini!");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/katakTerpesona.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
            },
        {},
        "Mr. Katak",
        "Wah ide yang sangat bagus!");

    Scene *scene26 = Scene26_Create();
    SceneManager_GoToScene(scene->sceneManager, scene26, SceneTransition::None);
}

void Scene20_Start(Scene *scene)
{
    Scene20Data *data = (Scene20Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "background/interview.png");

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
                .question = "Cerita Pengalaman",
                .onAnswered = Scene20_DialogPilihan2,
                .onAnsweredParameter = scene}},
           },
        "Mr. Katak",
        "Ini sudah seperti menonton sebuah Teater!");

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
