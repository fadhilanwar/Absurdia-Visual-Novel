#include "scene_24.hpp"
#include <iostream>

void Scene24_DialogScene24(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene25 = Scene25_Create();
    // // SceneManager_GoToSceneene(scene->sceneManager, scene25);
}

void Scene24_PindahScene_KeScene31(Scene *scene)
{
    std::cout << "Pindah scene ke Scene 31 cuy\n";
    Scene *Scene31 = Scene31_Create();
    SceneManager_GoToScene(scene->sceneManager, Scene31, SceneTransition::Fade);

    // SceneManager_PlaySound(scene->sceneManager, "Crowd Laugh.wav");

}
void Scene24_PindahScene_KeScene32(Scene *scene)
{
    std::cout << "Pindah scene ke Scene 32 cenah\n";
    Scene *Scene32 = Scene32_Create();
    SceneManager_GoToScene(scene->sceneManager, Scene32, SceneTransition::Fade);

    // SceneManager_PlaySound(scene->sceneManager, "Crowd Laugh.wav");

}



void playBeatboxSFX(Scene *scene) {
    SceneManager_PlaySound(scene->sceneManager, "beatbox.mp3");
}

void Scene24_DialogPilihan1(Scene *scene)
{
    SceneManager_PlaySound(scene->sceneManager, "anthem.mp3");

    std:: cout << "Pilihan 1 dipilih (NYANYI DENGAN SEMANGAT) ";
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
        "(bernyanyi dengan gerakan tangan teatrikal) “Ngok ngok… masa depan, di atas kubus transparan~!", Scene24_PindahScene_KeScene31, scene);
    
}
void Scene24_DialogPilihan2(Scene *scene)
{
    SceneManager_PlaySound(scene->sceneManager, "beatbox.mp3");

    std:: cout << "Pilihan 2 dipilih (NYANYI DENGAN SELINGAN BEATBOX) ";
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
        "(beatbox) “Ng-ngok-ngok! Masa depan~!”", Scene24_PindahScene_KeScene32, scene);
}

void Scene24_Start(Scene *scene)
{
    Scene24Data *data = (Scene24Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "background/interview.png");

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
        "Tes terakhir… nyanyikan lagu kebangsaan Absurdia.");
        
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
        "Hah? Lagu kebangsaan?");

        SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/katakBicara.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
            },
           {DialogQuestion{
                .question = "Nyanyi dengan Penuh Semangat",
                .onAnswered = Scene24_DialogPilihan1,
                .onAnsweredParameter = scene},
           {DialogQuestion{
                .question = "Nyanyikan + Beatbox",
                .onAnswered = Scene24_DialogPilihan2,
                .onAnsweredParameter = scene}},
           },
        "Mr. Katak",
        "Iya. Judulnya ‘Ngok Ngok Masa Depan’.");
    // SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene24_DialogScene24, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene24_Update(Scene *scene)
{
    Scene24Data *data = (Scene24Data *)scene->data;
}

void Scene24_Destroy(Scene *scene)
{
}

Scene *Scene24_Create()
{
    Scene24Data *mainMenu = new Scene24Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene24_Start,
        .update = Scene24_Update,
        .destroy = Scene24_Destroy
    };
    return scene;
}
