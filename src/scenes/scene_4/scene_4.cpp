#include "scene_4.hpp"
#include <iostream>

void Scene4_DialogScene1(Scene *scene)
{
    SceneManager_SetBackground(scene->sceneManager, "background/lift.png");
}
//pilihan 1
void Scene4_DialogPilihan1(Scene *scene)
{
    std::cout << "Pilihan 1 dipilih\n";
    Scene *scene5 = Scene5_Create();
    SceneManager_GoToScene(scene->sceneManager, scene5, SceneTransition::Fade);
}

//pilihan 2
void Scene4_DialogPilihan2(Scene *scene)
{
    std::cout << "Pilihan 2 dipilih\n";
    Scene *scene6 = Scene6_Create();
    SceneManager_GoToScene(scene->sceneManager, scene6, SceneTransition::Fade);
}

void Scene4_Start(Scene *scene)
{
    Scene4Data *data = (Scene4Data *)scene->data;
    
    SceneManager_SetBackground(scene->sceneManager, "background/resepsionis.png");
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "figuran/resepsionisTertawa.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "Resepsionis",
        "Pasti kamu mau bertanya kan, haha!");
    
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
        "iya saya...");
    
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "figuran/resepsionisTalk.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "Resepsionis",
        "Ayo ayo, mau tanya apa, ha?");
    
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
        "A-aku ke sini... ingin interview kerja di Absurdia Inc.");
    
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "figuran/resepsionisSenyum.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "Resepsionis",
        "Ooo begitu! Langsung naik lift saja, ada di lantai 3. Oke!!");
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
        "Baik. Terima kasih");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/talkingWork.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "Resepsionis",
        "Oiya, jangan kaget ya... kau akan terbiasa... ahahaha!");

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
        "Aneh, tapi yasudahlah",
        Scene4_DialogScene1, scene);

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/talkingWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
            },
            {
                DialogQuestion{
                    .question = "Naik",
                    .onAnswered = Scene4_DialogPilihan1,
                    .onAnsweredParameter = scene},
                DialogQuestion{
                    .question = "Turun",
                    .onAnswered = Scene4_DialogPilihan2,
                    .onAnsweredParameter = scene}},
        "MC",
        "Nah, sekarang tinggal ke atas.");

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void scene4_Update(Scene *scene)
{
    // Scene4Data *data = (Scene4Data *)scene->data;
}

void Scene4_Destroy(Scene *scene)
{
    // Scene4Data *data = (Scene4Data *)scene->data;
    // delete data;
}

Scene *Scene4_Create()
{
    Scene4Data *data = new Scene4Data();
    Scene *scene = new Scene{
        .data = data,
        .start = Scene4_Start,
        .update = scene4_Update,
        .destroy = Scene4_Destroy
    };
    return scene;
}










// void Scene4_DialogScene4(Scene *scene)
// {
//     std::cout << "Dialog beres\n";
//     Scene *scene5 = Scene5_Create();
//     // SceneManager_GoToScene(scene->sceneManager, scene5);
// }

// void Scene4_Start(Scene *scene)
// {
//     Scene4Data *data = (Scene4Data *)scene->data;
//     SceneManager_SetBackground(scene->sceneManager, "resepsionis.png");
//     // // // // SceneManager_AddDialog(scene->sceneManager, false, "Resepsionis","(sambil tersenyum lebar) Pasti kamu mau bertanya kan, haha!", "resepsionisTertawa.png");
//     // // SceneManager_AddDialog(scene->sceneManager, true, "MC","Eh… iya, saya...", "talkingWork.png");
//     // // SceneManager_AddDialog(scene->sceneManager, false, "Resepsionis","Ayo ayo, mau tanya apa, ha?", "resepsionisTalk.png");
//     // // SceneManager_AddDialog(scene->sceneManager, true, "MC","A-aku ke sini... ingin interview kerja di Absurdia Inc.", "confusedWork.png");
//     // // SceneManager_AddDialog(scene->sceneManager, false, "Resepsionis", "Ooo begitu! Langsung naik lift saja, ada di lantai 3. Oke!!", "resepsionisSenyum.png");
//     // // SceneManager_AddDialog(scene->sceneManager, true, "MC","Baik. Terima kasih", "talkingWork.png", Scene4_DialogScene4, scene);

//     SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
// }

// void Scene4_Update(Scene *scene)
// {
//     Scene4Data *data = (Scene4Data *)scene->data;
// }

// void Scene4_Destroy(Scene *scene)
// {
// }

// Scene *Scene4_Create()
// {
//     Scene4Data *mainMenu = new Scene4Data();
//     Scene *scene = new Scene{
//         .data = mainMenu,
//         .start = Scene4_Start,
//         .update = Scene4_Update,
//         .destroy = Scene4_Destroy
//     };
//     return scene;
// }