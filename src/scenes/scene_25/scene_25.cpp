#include "scene_25.hpp"
#include <iostream>


void playLaughSFX(Scene *scene) {
    SceneManager_PlaySound(scene->sceneManager, "Crowd Laugh.wav");
}

void Scene25_PindahScene(Scene *scene)
{
    std::cout << "Pindah scene\n";
    Scene *Scene27 = Scene27_Create();
    SceneManager_GoToScene(scene->sceneManager, Scene27, SceneTransition::None);

    // SceneManager_PlaySound(scene->sceneManager, "Crowd Laugh.wav");

}

void Scene25_Start(Scene *scene)
{
    Scene25Data *data = (Scene25Data *)scene->data;

    SceneManager_SetBackground(scene->sceneManager, "background/interview.png");
    
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/katakBicara.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "Mr. Katak",
        "Oh Oh! Aku yang jadi Kunci..!");

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
        "Kalau begitu, aku yang jadi Engsel..!");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/pisangBicara.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "Pisang",
        "PISAANGGG!", playLaughSFX, scene);


    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/happyWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Joget},
            DialogPerson{
                .imageFilePath = "HRD/badutSenang.png",
                .position = DialogPersonPosition::Center,
                .animation = DialogPersonAnimation::Joget},
            DialogPerson{
                .imageFilePath = "HRD/katakTertawa.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Joget},
            DialogPerson{
                .imageFilePath = "HRD/pisangBicara.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Joget},
        },
        {},
        "",
        "");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/katakTertawa.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Joget},
        },
        {},
        "Mr. Katak",
        "Hahaha! Tadi itu asyik", Scene25_PindahScene, scene);

    // Musik
    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}



void Scene25_Update(Scene *scene)
{
    Scene25Data *data = (Scene25Data *)scene->data;
}

void Scene25_Destroy(Scene *scene)
{
}

Scene *Scene25_Create()
{
    Scene25Data *mainMenu = new Scene25Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene25_Start,
        .update = Scene25_Update,
        .destroy = Scene25_Destroy
    };
    return scene;
}
