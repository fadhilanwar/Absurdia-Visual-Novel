#include "scene_28.hpp"
#include <iostream>

void Scene28_DialogScene28(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *ending_d = static_cast<Scene*>(Ending_d_Create());
    SceneManager_GoToScene(scene->sceneManager, ending_d, SceneTransition::Fade);
    // SceneManager_GoToSceneene(scene->sceneManager, ending_d);
}

void Scene28_Start(Scene *scene)
{
    Scene28Data *data = (Scene28Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "background/interview.png");
    // SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene28_DialogScene28, scene);

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/katakTerpesona.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "Mr. Katak",
        "Kami akan buat prortitpenya! Kamu resmi jadi kepala riset kambing!");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/happyWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
            },
        {},
        "Yono",
        "Wah! terimakasih pak");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/happyWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Pop},
        },
        {},
        "Yono",
        "Ini mimpi jadi nyata!", Scene28_DialogScene28, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene28_Update(Scene *scene)
{
    Scene28Data *data = (Scene28Data *)scene->data;
}

void Scene28_Destroy(Scene *scene)
{
}

Scene *Scene28_Create()
{
    Scene28Data *mainMenu = new Scene28Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene28_Start,
        .update = Scene28_Update,
        .destroy = Scene28_Destroy
    };
    return scene;
}
