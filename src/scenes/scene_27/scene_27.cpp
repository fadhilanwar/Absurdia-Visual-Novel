#include "scene_27.hpp"
#include <iostream>

void Scene27_DialogScene27(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene28 = Scene28_Create();
    // SceneManager_GoToScene(scene->sceneManager, scene28);
}

void Scene27_PindahScene(Scene *scene)
{
     std::cout << "ENDING B TERBUKAAA\n";
    Scene *ending_b = Ending_b_Create();
    SceneManager_GoToScene(scene->sceneManager, ending_b, SceneTransition::Fade);

}

void playApplauseSFX(Scene *scene) {
    SceneManager_PlaySound(scene->sceneManager, "Applause.mp3");
}

void Scene27_Start(Scene *scene)
{
    Scene27Data *data = (Scene27Data *)scene->data;
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
        "SELAMAATTT! Dengan ini kamu kami terima sebagai bagian dari Absurdia Inc.!", playApplauseSFX, scene);
    
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/shockedWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "Fuad Gemink",
        "Se-sserius, Pak? Saya… diterima?");

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
        "Kamu satu-satunya yang bertahan sampai akhir tanpa menjadi bayangan sendiri.!");

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
        "PISAANGGG!", Scene27_PindahScene, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene27_Update(Scene *scene)
{
    Scene27Data *data = (Scene27Data *)scene->data;
}

void Scene27_Destroy(Scene *scene)
{
}

Scene *Scene27_Create()
{
    Scene27Data *mainMenu = new Scene27Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene27_Start,
        .update = Scene27_Update,
        .destroy = Scene27_Destroy
    };
    return scene;
}
