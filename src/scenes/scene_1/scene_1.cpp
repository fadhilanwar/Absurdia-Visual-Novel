#include "scene_1.hpp"

#include <iostream>
#include <cmath>

void Scene1_DialogScene1(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene2 = Scene2_Create();
    SceneManager_GoToScene(scene->sceneManager, scene2, SceneTransition::None);
}

void Scene1_Start(Scene *scene)
{
    Scene1Data *data = (Scene1Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "background/jam.png");
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "pajamas/talkingPajamas.png",
                .position = DialogPersonPosition::Center,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "",
        ""
    );
    SceneManager_SetBackground(scene->sceneManager, "background/kamar.png");
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "pajamas/yawningPajamas.png",
                .position = DialogPersonPosition::Center,
                .animation = DialogPersonAnimation::Slide},
            },
            {},
            "MC",
            "Hoaaammmm...");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "pajamas/talkingSleepyPajamas.png",
                .position = DialogPersonPosition::Center,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "MC",
        "Sepertinya teh matcha sangat cocok untuk mengawali hari ini.");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "pajamas/talkingSleepyPajamas.png",
                .position = DialogPersonPosition::Center,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "MC",
        "Aku akan ke dapur untuk membuatnya");

    SceneManager_SetBackground(scene->sceneManager, "background/dapur.png");
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "pajamas/teaPajamas.png",
                .position = DialogPersonPosition::Center,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "",
        ""
    );

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "pajamas/talkingTeaPajamas.png",
                .position = DialogPersonPosition::Center,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "MC",
        "Ahh, hangat dan racikan yang pas tanpa gula, sempurna!"
    );
        SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "pajamas/teaLookingPajamas.png",
                .position = DialogPersonPosition::Center,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "",
        ""
    );

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "pajamas/teaLookingTalkingPajamas.png",
                .position = DialogPersonPosition::Center,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "MC",
        "Sebentar"
    );

    SceneManager_SetBackground(scene->sceneManager, "background/laptop.png");
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "pajamas/laptopPajamas.png",
                .position = DialogPersonPosition::Center,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "",
        ""
    );

    SceneManager_SetBackground(scene->sceneManager, "background/dapur.png");
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "pajamas/shockedPajamas.png",
                .position = DialogPersonPosition::Center,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "",
        ""
    );

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "pajamas/talkingShockedPajamas.png",
                .position = DialogPersonPosition::Center,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "MC",
        "ADUH GAWAT ITU HARI INI?!!!");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "pajamas/talkingShockedPajamas.png",
                .position = DialogPersonPosition::Center,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "MC",
        "AKU HARUS SEGERA SIAP-SIAP!");

    SceneManager_PlayMusic(scene->sceneManager, "Goofy ahh Song.mp3");
        }

void Scene1_Update(Scene *scene)
{
    //
}

void Scene1_Destroy(Scene *scene)
{
    // 
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

// // pilihan 1
// void Scene1_DialogPilihan1(Scene *scene)
// {
//     std::cout << "Pilihan 1 dipilih\n";
//     Scene *scene_2 = Scene2_Create();
//     SceneManager_GoToScene(scene->sceneManager, scene_2, SceneTransition::None);
// }
// // pilihan 2
// void Scene1_DialogPilihan2(Scene *scene)
// {

//     std::cout << "Pilihan 2 dipilih\n";
//     SceneManager_AddDialog(
//         scene->sceneManager,
//         {
//             DialogPerson{
//                 .imageFilePath = "talkingPajamas.png",
//                 .position = DialogPersonPosition::Left,
//                 .animation = DialogPersonAnimation::Shake},
//         },
//         {},
//         "MC",
//         "Bakekok bunda",
//         Scene1_DialogPilihan1,
//         scene);
//     SceneManager_PlaySound(scene->sceneManager, "tolong.mp3");
// }
// // pilihan 3
// void Scene1_DialogPilihan3(Scene *scene)
// {
//     std::cout << "Pilihan 3 dipilih\n";
//     SceneManager_PlaySound(scene->sceneManager, "tolong.mp3");
// }

// void Scene1_Start(Scene *scene)
// {
//     Scene1Data *data = (Scene1Data *)scene->data;
//     SceneManager_SetBackground(scene->sceneManager, "wp_pilihan.png");

//     SceneManager_AddDialog(
//         scene->sceneManager,
//         {
//             DialogPerson{
//                 .imageFilePath = "talkingPajamas.png",
//                 .position = DialogPersonPosition::Left,
//                 .animation = DialogPersonAnimation::Slide},
//         },
//         {},
//         "MC",
//         "Slide");
//     SceneManager_AddDialog(
//         scene->sceneManager,
//         {
//             DialogPerson{
//                 .imageFilePath = "talkingPajamas.png",
//                 .position = DialogPersonPosition::Left,
//                 .animation = DialogPersonAnimation::Pop},
//             DialogPerson{
//                 .imageFilePath = "talkingPajamas.png",
//                 .position = DialogPersonPosition::Center,
//                 .animation = DialogPersonAnimation::Slide},
//             DialogPerson{
//                 .imageFilePath = "talkingPajamas.png",
//                 .position = DialogPersonPosition::Right,
//                 .animation = DialogPersonAnimation::FadeIn},
//         },
//         {},
//         "MC",
//         "Loncat, Slide, Fade In");
//     SceneManager_AddDialog(
//         scene->sceneManager,
//         {
//             DialogPerson{
//                 .imageFilePath = "talkingPajamas.png",
//                 .position = DialogPersonPosition::Left,
//                 .animation = DialogPersonAnimation::Shake},
//             DialogPerson{
//                 .imageFilePath = "talkingPajamas.png",
//                 .position = DialogPersonPosition::Center,
//                 .animation = DialogPersonAnimation::FadeOut},
//             DialogPerson{
//                 .imageFilePath = "talkingPajamas.png",
//                 .position = DialogPersonPosition::Right,
//                 .animation = DialogPersonAnimation::Joget},
//         },
//         {DialogQuestion{
//              .question = "Dodol garut",
//              .onAnswered = Scene1_DialogPilihan1,
//              .onAnsweredParameter = scene},
//          DialogQuestion{
//              .question = "Dodol garut 2",
//              .onAnswered = Scene1_DialogPilihan2,
//              .onAnsweredParameter = scene},
//          DialogQuestion{
//              .question = "Dodol garut 3",
//              .onAnswered = Scene1_DialogPilihan3,
//              .onAnsweredParameter = scene}},
//         "MC",
//         "Geter, Fade Out, Joget");

//     SceneManager_PlayMusic(scene->sceneManager, "Goofy ahh Song.mp3");
// }

// void Scene1_Update(Scene *scene)
// {
//     Scene1Data *data = (Scene1Data *)scene->data;

//     //gatau gabut
//     float rotasiFuad = fmod(data->animProgress, 1);
//     Canvas_DrawImage(scene->canvas, 200, 200, "fuad.png", 1.f, rotasiFuad * 360);
//     data->animProgress += 0.016;
// }

// void Scene1_Destroy(Scene *scene)
// {
// }

// Scene *Scene1_Create()
// {
//     Scene1Data *data = new Scene1Data();
//     Scene *scene = new Scene{
//         .data = data,
//         .start = Scene1_Start,
//         .update = Scene1_Update,
//         .destroy = Scene1_Destroy};
//     return scene;
// }