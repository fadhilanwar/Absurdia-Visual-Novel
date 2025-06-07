#include "scene_2.hpp"
#include <iostream>

void Scene2_DialogBeres(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene3 = Scene3_Create();
    SceneManager_GoToScene(scene->sceneManager, scene3, SceneTransition::Fade);
}

void Scene2_Start(Scene *scene)
{
    Scene2Data *data = (Scene2Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "background/kejar_kereta.png");
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/lari.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
            },
        {},
        "MC",
        "Permisi! Permisi! Maaf!");

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
        "Tahu bulat digoreng dadakan, lima rat—woi! Hati-hati dong!");

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
        "Maaf, saya terburu-buru. Saya harus ke stasiun kereta api!");

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
        "Oh, ya ampun! Kamu harus cepat!");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/talkingWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
            },
        {},
        "MC",
        "Oke, lokasi gedungnya nggak jauh dari sini. Seharusnya... lima menit cukup.",
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
//     // SceneManager_AddDialog(scene->sceneManager, true, "MC","Permisi! Permisi! Maaf!", "confusedWork.png");
//     // SceneManager_AddDialog(scene->sceneManager, false, "Penjual Tahu", "Tahu bulat digoreng dadakan, lima rat—woi! Hati-hati dong!", "tahu_marah.png");
//     // SceneManager_AddDialog(scene->sceneManager, true, "MC", "Maaf, saya terburu-buru. Saya harus ke stasiun kereta api!", "talkingWork.png");
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