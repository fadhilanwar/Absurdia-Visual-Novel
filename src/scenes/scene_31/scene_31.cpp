#include "scene_31.hpp"
#include <iostream>

void Scene31_DialogScene31(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene32 = Scene32_Create();
    // SceneManager_GoToScene(scene->sceneManager, scene32);
}

void playMusicSFX(Scene *scene) {
    SceneManager_PlayMusic(scene->sceneManager, "Applause.mp3");
}

void playMusicSFX2(Scene *scene) {
    SceneManager_PlayMusic(scene->sceneManager, "Crowd Laugh.wav");
}

void Scene31_PindahScene(Scene *scene)
{
    std::cout << "ENDING D TERBUKAAA\n";
    Scene *ending_d = Ending_d_Create();
    SceneManager_GoToScene(scene->sceneManager, ending_d, SceneTransition::Fade);

    // SceneManager_PlaySound(scene->sceneManager, "Crowd Laugh.wav");

}

void Scene31_Start(Scene *scene)
{
    Scene31Data *data = (Scene31Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "background/interview.png");
    // SceneManager_AddDialog(scene->sceneManager, true, "Yono", "Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene31_DialogScene31, scene);

    SceneManager_PlaySound(scene->sceneManager, "Crowd Laugh.wav");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/badutSenang.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
            DialogPerson{
                .imageFilePath = "HRD/KatakTertawa.png",
                .position = DialogPersonPosition::Center,
                .animation = DialogPersonAnimation::Slide},
            DialogPerson{
                .imageFilePath = "HRD/pisangBicara.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
            },
            
        {},
        "",
        "", playMusicSFX, scene);

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
        "Dengan ini Selamat! Kamu jadi penyanyi utama acara tahunan kita!", Scene31_PindahScene, scene);

        SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");

}

void Scene31_Update(Scene *scene)
{
    Scene31Data *data = (Scene31Data *)scene->data;
}

void Scene31_Destroy(Scene *scene)
{
}

Scene *Scene31_Create()
{
    Scene31Data *mainMenu = new Scene31Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene31_Start,
        .update = Scene31_Update,
        .destroy = Scene31_Destroy
    };
    return scene;
}