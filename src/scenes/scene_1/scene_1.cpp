#include "scene_1.hpp"

#include <iostream>
#include <cmath>

// pilihan 1
void Scene1_DialogPilihan1(Scene *scene)
{
    std::cout << "Pilihan 1 dipilih\n";
    Scene *scene_2 = Scene2_Create();
    SceneManager_GoToScene(scene->sceneManager, scene_2, SceneTransition::None);
}
// pilihan 2
void Scene1_DialogPilihan2(Scene *scene)
{

    std::cout << "Pilihan 2 dipilih\n";
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "talkingPajamas.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Shake},
        },
        {},
        "MC",
        "Bakekok bunda",
        Scene1_DialogPilihan1,
        scene);
    SceneManager_PlaySound(scene->sceneManager, "tolong.mp3");
}
// pilihan 3
void Scene1_DialogPilihan3(Scene *scene)
{
    std::cout << "Pilihan 3 dipilih\n";
    SceneManager_PlaySound(scene->sceneManager, "tolong.mp3");
}

void Scene1_Start(Scene *scene)
{
    Scene1Data *data = (Scene1Data *)scene->data;
    //     SceneManager_SetBackground(scene->sceneManager, "wp_awal.png");
    SceneManager_SetBackground(scene->sceneManager, "wp_pilihan.png");
    //     SceneManager_AddDialog(scene->sceneManager, true, "Fuad", "asdasdasdasdasd", "muka_datar.png", Scene1_DialogBeres, scene);

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "talkingPajamas.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "MC",
        "Slide");
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "talkingPajamas.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Pop},
            DialogPerson{
                .imageFilePath = "talkingPajamas.png",
                .position = DialogPersonPosition::Center,
                .animation = DialogPersonAnimation::Slide},
            DialogPerson{
                .imageFilePath = "talkingPajamas.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::FadeIn},
        },
        {},
        "MC",
        "Loncat, Slide, Fade In");
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "talkingPajamas.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Shake},
            DialogPerson{
                .imageFilePath = "talkingPajamas.png",
                .position = DialogPersonPosition::Center,
                .animation = DialogPersonAnimation::FadeOut},
            DialogPerson{
                .imageFilePath = "talkingPajamas.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Joget},
        },
        {DialogQuestion{
             .question = "Dodol garut",
             .onAnswered = Scene1_DialogPilihan1,
             .onAnsweredParameter = scene},
         DialogQuestion{
             .question = "Dodol garut 2",
             .onAnswered = Scene1_DialogPilihan2,
             .onAnsweredParameter = scene},
         DialogQuestion{
             .question = "Dodol garut 3",
             .onAnswered = Scene1_DialogPilihan3,
             .onAnsweredParameter = scene}},
        "MC",
        "Geter, Fade Out, Joget");

    // SceneManager_AddQuestion(scene->sceneManager, "Pilihan Action: ",
    // {
    //     {"questio1", Scene1_DialogPilihan1},
    //     {"question2", Scene1_DialogPilihan2},
    //     {"question3", Scene1_DialogPilihan3}
    // }, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Goofy ahh Song.mp3");
}

void Scene1_Update(Scene *scene)
{
    Scene1Data *data = (Scene1Data *)scene->data;

    // gatau gabut
    // float rotasiFuad = fmod(data->animProgress, 1);
    // Canvas_DrawImage(scene->canvas, 200, 200, "fuad.png", 1.f, rotasiFuad * 360);
    // data->animProgress += 0.016;
}

void Scene1_Destroy(Scene *scene)
{
}

Scene *Scene1_Create()
{
    Scene1Data *data = new Scene1Data();
    Scene *scene = new Scene{
        .data = data,
        .start = Scene1_Start,
        .update = Scene1_Update,
        .destroy = Scene1_Destroy};
    return scene;
}
// void Scene1_DialogBeres(Scene *scene)
// {
//     std::cout << "Dialog beres\n";
//     Scene *newScene = Scene2_Create();
//     SceneManager_GoToScene(scene->sceneManager, newScene);
// }

// void Scene1_TestDialogBeres(Scene *scene)
// {
//     SceneManager_PlaySound(scene->sceneManager, "nya.mp3");
// }

// void Scene1_DialogBeres(Scene *scene)
// {
//     Scene *scene2 = Scene2_Create();
//     SceneManager_GoToScene(scene->sceneManager, scene2);
// }

// void Scene1_Start(Scene *scene)
// {
//     Scene1Data *data = (Scene1Data *)scene->data;

//     SceneManager_SetBackground(scene->sceneManager, "wp_awal.png");
//     SceneManager_AddDialog(scene->sceneManager, true, "Fuad", "asdasdasdasdasd", "muka_datar.png", Scene1_DialogBeres, scene);

// SceneManager_AddDialog(scene->sceneManager, false, "Mita", "Hai! Apa kabar!", "mita.png");
// SceneManager_AddDialog(scene->sceneManager, true, "Fuad", "Ehh.. ehhh.. Halo..", "fuad.png");
// SceneManager_AddDialog(scene->sceneManager, false, "Mita", "Eh.. Halo!! Nama kamu siapa?", "mita.png");
// SceneManager_AddDialog(scene->sceneManager, true, "Fuad", "Ehh.. ehhh.. Fuad.. Fuad Mubarak", "fuad_anxiety.png");
// // SceneManager_AddDialog(scene->sceneManager, false, "Mita", "Ihhhhhhhhh lucu banget dehh", "mita.png", Scene1_TestDialogBeres, scene);
// SceneManager_AddDialog(scene->sceneManager, false, "Mita", "Halo Fuad.. Kenalin aku Mita! :)", "mita_happy.png");
// SceneManager_AddDialog(scene->sceneManager, true, "Fuad", "Ehh.. ehhh.. Sa... Salam kenal!", "fuad_anxiety.png", Scene1_DialogBeres, scene);

//     SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");

// }

// void Scene1_Update(Scene *scene)
// {
//     Scene1Data *data = (Scene1Data *)scene->data;
// }

// void Scene1_Destroy(Scene *scene)
// {
// }

// Scene *Scene1_Create()
// {
//     Scene1Data *mainMenu = new Scene1Data();
//     Scene *scene = new Scene{
//         .data = mainMenu,
//         .start = Scene1_Start,
//         .update = Scene1_Update,
//         .destroy = Scene1_Destroy
//     };
//     return scene;
// }