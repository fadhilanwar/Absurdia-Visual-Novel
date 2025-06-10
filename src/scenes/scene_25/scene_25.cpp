#include "scene_25.hpp"
#include <iostream>

void Scene25_DialogScene25(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene26 = Scene26_Create();
    // // SceneManager_GoToScene(scene->sceneManager, scene26);
}

void playLaughSFX(Scene *scene) {
    SceneManager_PlaySound(scene->sceneManager, "Crowd Laugh.wav");
}

void Scene25_PindahScene(Scene *scene)
{
    std::cout << "Pindah scene ke Scene 27 cenah\n";
    Scene *Scene27 = Scene27_Create();
    SceneManager_GoToScene(scene->sceneManager, Scene27, SceneTransition::Fade);

    // SceneManager_PlaySound(scene->sceneManager, "Crowd Laugh.wav");

}

void Scene25_Start(Scene *scene)
{
    Scene25Data *data = (Scene25Data *)scene->data;

    SceneManager_SetBackground(scene->sceneManager, "background/interview.png");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            // DialogPerson{
            //     .imageFilePath = "work/confusedWork.png",
            //     .position = DialogPersonPosition::Left,
            //     .animation = DialogPersonAnimation::None},
        },
        {},
        "MC",
        "(MC dan para interviewer berakting jadi pintu dan penghuni rumah.) ");
    
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
            // DialogPerson{
            //     .imageFilePath = "work/talkingWork.png",
            //     .position = DialogPersonPosition::Left,
            //     .animation = DialogPersonAnimation::None},
        },
        {},
        "MC",
        "(Mereka Tertawa dan Bertepuk Tangan..)",
        Scene25_PindahScene, scene);

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
