#include "scene_23.hpp"
#include <iostream>

void Scene23_DialogScene23(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene24 = Scene24_Create();
    // // // SceneManager_GoToScene(scene->sceneManager, scene24);
}

void Scene23_PindahScene(Scene *scene)
{
    std::cout << "Pindah scene ke Scene 24 cenah\n";

    SceneManager_GoToScene(scene->sceneManager, scene->connectedSceneNumbers[0], SceneTransition::None);

    // SceneManager_PlaySound(scene->sceneManager, "Crowd Laugh.wav");

}

void Scene23_Start(Scene *scene)
{
    Scene23Data *data = (Scene23Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "background/interview.png");
    // SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene23_DialogScene23, scene);

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
        "Wah! Inisiatif yang jarang ditemukan");

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
        "PISANG");

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
        "Setuju. Kita beri satu hari cuti khusus 'latihan suara ternak'.");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/happyWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "Fuad Gemink",
        "Terima kasih, Pak! Mbeeee!", Scene23_PindahScene, scene);

    // Scene *scene24 = Scene24_Create();
    // SceneManager_GoToScene(scene->sceneManager, scene24, SceneTransition::None);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene23_Update(Scene *scene)
{
    Scene23Data *data = (Scene23Data *)scene->data;
}

void Scene23_Destroy(Scene *scene)
{
}

Scene *Scene23_Create()
{
    Scene23Data *mainMenu = new Scene23Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene23_Start,
        .update = Scene23_Update,
        .destroy = Scene23_Destroy
    };
    return scene;
}
