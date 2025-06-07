#include "scene_3.hpp"
#include <iostream>

void Scene3_DialogScene1(Scene *scene)
{
    SceneManager_SetBackground(scene->sceneManager, "background/depan_gedung.png");
}

void Scene1_DialogPilihan1(Scene *scene)
{
    std::cout << "Pilihan 1 dipilih\n";
    Scene *ending_a = static_cast<Scene*>(Ending_a_Create());
    SceneManager_GoToScene(scene->sceneManager, ending_a, SceneTransition::None);
}
// pilihan 2
void Scene1_DialogPilihan2(Scene *scene)
{
    std::cout << "Pilihan 2 dipilih";
    Scene *scene4 = Scene4_Create();
    SceneManager_GoToScene(scene->sceneManager, scene4, SceneTransition::Fade);
}

void Scene3_Start(Scene *scene)
{
    Scene3Data *data = (Scene3Data *)scene->data;

    SceneManager_SetBackground(scene->sceneManager, "background/trotoar.png");
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
        "Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..",
        Scene3_DialogScene1, scene);

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
        "Ini gedungnya? Bentuknya nggak biasa banget.");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/shockedWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "MC",
        "Desain jendelanya kayak kebalik. Apa ini sengaja atau tukang bangunannya ngantuk?");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/shockedWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
            },
           {DialogQuestion{
                .question = "Sepertinya lebih baik aku pulang",
                .onAnswered = Scene1_DialogPilihan1,
                .onAnsweredParameter = scene},
            DialogQuestion{
                .question = "Melangkah menuju gedung",
                .onAnswered = Scene1_DialogPilihan2,
                .onAnsweredParameter = scene}},
        "MC",
        "Atapnya... kayak topi sombrero. Ini kantor atau taman hiburan sih?");

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
    }

void Scene3_Update(Scene *scene)
{
    // Scene3Data *data = (Scene3Data *)scene->data;
}

void Scene3_Destroy(Scene *scene)
{
    // Tidak ada yang perlu dibersihkan di sini
}

Scene *Scene3_Create()
{
    Scene3Data *data = new Scene3Data();
    Scene *scene = new Scene{
        .data = data,
        .start = Scene3_Start,
        .update = Scene3_Update,
        .destroy = Scene3_Destroy
    };
    return scene;
}





// void Scene3_DialogScene3(Scene *scene)
// {
//     std::cout << "Dialog beres\n";
//     Scene *scene4 = Scene4_Create();
//     // SceneManager_GoToScene(scene->sceneManager, scene4);
// }

// void Scene3_Start(Scene *scene)
// {
//     Scene3Data *data = (Scene3Data *)scene->data;
//     SceneManager_SetBackground(scene->sceneManager, "tiba_dikota.png");
//     // SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png");
//     SceneManager_SetBackground(scene->sceneManager, "depan_gedung.png");
//     // SceneManager_AddDialog(scene->sceneManager, true, "MC", "Ini gedungnya? Bentuknya nggak biasa banget.", "confusedWork.png");
//     // SceneManager_AddDialog(scene->sceneManager, true, "MC", "Desain jendelanya kayak kebalik. Apa ini sengaja atau tukang bangunannya ngantuk?", "shockedWork.png");
//     // SceneManager_AddDialog(scene->sceneManager,true, "MC","Atapnya... kayak topi sombrero. Ini kantor atau taman hiburan sih?", "shockedWork.png", Scene3_DialogScene3, scene);

//     SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
// }

// void Scene3_Update(Scene *scene)
// {
//     Scene3Data *data = (Scene3Data *)scene->data;
// }

// void Scene3_Destroy(Scene *scene)
// {
// }

// Scene *Scene3_Create()
// {
//     Scene3Data *mainMenu = new Scene3Data();
//     Scene *scene = new Scene{
//         .data = mainMenu,
//         .start = Scene3_Start,
//         .update = Scene3_Update,
//         .destroy = Scene3_Destroy
//     };
//     return scene;
// }