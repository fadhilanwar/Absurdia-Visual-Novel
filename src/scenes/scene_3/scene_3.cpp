#include "scene_3.hpp"
#include <iostream>

void Scene3_DialogScene1(Scene *scene)
{
    SceneManager_SetBackground(scene->sceneManager, "background/depan_gedung.png");
}

void Scene3_DialogScene2(Scene *scene)
{
    SceneManager_SetBackground(scene->sceneManager, "background/resepsionis.png");
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

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/talkingWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Pop},
        },
        {},
        "Yono",
        "Ah . . . mungkin hanya luarnya saja");

    Scene *scene4Part1 = Scene4Part1_Create();
    SceneManager_GoToScene(scene->sceneManager, scene4Part1, SceneTransition::Fade);
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
        "Yono",
        "Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..",
        Scene3_DialogScene1, scene);

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
        "Akhirnya sampai juga!");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/confusedWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::None},
        },
        {},
        "Yono",
        "Ini gedungnya? Bentuknya nggak biasa banget.");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/shockedWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::None},
        },
        {},
        "Yono",
        "Desain jendelanya aneh. Apa ini disengaja atau tukang bangunannya ngantuk?");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/confusedWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::None},
            },
           {DialogQuestion{
                .question = "Pulang",
                .onAnswered = Scene1_DialogPilihan1,
                .onAnsweredParameter = scene},
            DialogQuestion{
                .question = "Masuk",
                .onAnswered = Scene1_DialogPilihan2,
                .onAnsweredParameter = scene}},
        "Yono",
        "Atapnya. . .  kayak topi sombrero. Ini kantor atau taman hiburan sih?");

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
    }

void Scene3_Update(Scene *scene)
{
}

void Scene3_Destroy(Scene *scene)
{

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
