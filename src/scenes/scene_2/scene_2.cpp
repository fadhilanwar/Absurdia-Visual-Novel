#include "scene_2.hpp"
#include <iostream>

void Scene2_DialogBeres(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene3 = Scene3_Create();
    SceneManager_GoToScene(scene->sceneManager, scene3, SceneTransition::Fade);
}

void Scene2_DialogScene2(Scene *scene)
{
    SceneManager_SetBackground(scene->sceneManager, "background/dalamKereta.png");
}

void Scene2_Start(Scene *scene)
{
    Scene2Data *data = (Scene2Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "background/outSubway.png");
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/lari.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
            },
        {},
        "Yono",
        "Permisi! Permisi! Maaf!");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "figuran/tahu_senang.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
            },
        {},
        "Penjual Tahu",
        "Tahuuuu bulat! diiigoreng dadakan! lima rat. . .");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "figuran/tahu_marah.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Joget},
            },
        {},
        "Penjual Tahu",
        "Hey! Hati-hati dong kalau jalan!");
    
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "figuran/tahu_marah.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Joget},
            },
        {},
        "Penjual Tahu",
        "Hampir saja tahuku terjatuh"
    );

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/lari.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
            },
        {},
        "Yono",
        "Duh! Maaf! Aku sedang buru-buru!");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/lari.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::None},
            },
        {},
        "Yono",
        "Itu keretanya! Tunggu!",
        Scene2_DialogScene2, scene);

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/shockedWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
            },
            {},
            "Yono",
            "Hampir saja aku tertinggal kereta");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/shockedWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
            },
            {},
            "Yono",
            "Bisa gawat kalau aku ketinggalan.");

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
        "Oke, lokasi gedungnya nggak jauh dari sini. Seharusnya. . . lima menit cukup.",
    Scene2_DialogBeres, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene2_Update(Scene *scene)
{
}

void Scene2_Destroy(Scene *scene)
{
}

Scene *Scene2_Create()
{
    Scene2Data *data = new Scene2Data();
    Scene *scene = new Scene{
        .data = data,
        .start = Scene2_Start,
        .update = Scene2_Update,
        .destroy = Scene2_Destroy
    };
    return scene;
}


//yang kemarin
// void Scene2_DialogBeres(Scene *scene)
// {
//     std::cout << "Dialog beres\n";
//     Scene *scene3 = Scene3_Create();
//     // // SceneManager_GoToSceneene(scene->sceneManager, scene3);
// }

// void Scene2_Start(Scene *scene)
// {
//     Scene2Data *data = (Scene2Data *)scene->data;
//     SceneManager_SetBackground(scene->sceneManager, "kejar_kereta.png");
//     // SceneManager_AddDialog(scene->sceneManager, true, "Yono","Permisi! Permisi! Maaf!", "confusedWork.png");
//     // SceneManager_AddDialog(scene->sceneManager, false, "Penjual Tahu", "Tahu bulat digoreng dadakan, lima rat—woi! Hati-hati dong!", "tahu_marah.png");
//     // SceneManager_AddDialog(scene->sceneManager, true, "Yono", "Maaf, saya terburu-buru. Saya harus ke stasiun kereta api!", "talkingWork.png");
//     // SceneManager_AddDialog(scene->sceneManager, false, "Penjual Tahu", "Oh, ya ampun! Kamu harus cepat!", "tahu_senang.png", Scene2_DialogBeres, scene);

//     SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
// }

// void Scene2_Update(Scene *scene)
// {
//     Scene2Data *data = (Scene2Data *)scene->data;
// }

// void Scene2_Destroy(Scene *scene)
// {
// }

// Scene *Scene2_Create()
// {
//     Scene2Data *mainMenu = new Scene2Data();
//     Scene *scene = new Scene{
//         .data = mainMenu,
//         .start = Scene2_Start,
//         .update = Scene2_Update,
//         .destroy = Scene2_Destroy
//     };
//     return scene;
// }