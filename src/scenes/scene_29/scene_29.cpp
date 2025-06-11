#include "scene_29.hpp"
#include <iostream>

void Scene29_DialogBeres(Scene *scene)
{
    std::cout << "Dialog beres\n";
    
    SceneManager_GoToScene(scene->sceneManager, scene->connectedSceneNumbers[0], SceneTransition::Fade);
    // SceneManager_GoToSceneene(scene->sceneManager, scene30);
}

void Scene29_DialogScene1(Scene *scene)
{
    SceneManager_SetBackground(scene->sceneManager, "background/biteGrass.png");
}

void Scene29_DialogScene2(Scene *scene)
{
    SceneManager_SetBackground(scene->sceneManager, "background/interview.png");
}

void Scene29_Start(Scene *scene)
{
    Scene29Data *data = (Scene29Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "background/biteGrass.png");
    SceneManager_AddDialog(
        scene->sceneManager,
        {},
        {},
        "",
        "",
        Scene29_DialogScene2, scene
);
    // SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene29_DialogScene29, scene);
    
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
            "Hmmm . . . timothy, orchard grass, sedikit clover. Tipikal tekstur rumput ideal.");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/badutBicara.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
            },
            {},
            "Dr. Badut",
            "Wah, benar semua!");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/badutSenang.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::None},
            },
            {},
            "Dr. Badut",
            "Selamat menjadi Peneliti Nutrisi Kambing kita!",
        Scene29_DialogBeres, scene);
            
    // SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene29_DialogScene29, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene29_Update(Scene *scene)
{
    Scene29Data *data = (Scene29Data *)scene->data;
}

void Scene29_Destroy(Scene *scene)
{
}

Scene *Scene29_Create()
{
    Scene29Data *mainMenu = new Scene29Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene29_Start,
        .update = Scene29_Update,
        .destroy = Scene29_Destroy
    };
    return scene;
}
