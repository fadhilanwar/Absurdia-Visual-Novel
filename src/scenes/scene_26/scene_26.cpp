#include "scene_26.hpp"
#include <iostream>

void Scene26_PindahScene(Scene *scene)
{
    std::cout << "Pindah scne\n";
    Scene *scene28 = Scene28_Create();
    SceneManager_GoToScene(scene->sceneManager, scene28, SceneTransition::None);
}

void Scene26_Start(Scene *scene)
{
    Scene26Data *data = (Scene26Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "background/interview.png");
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
            "Saya dulu dilumuri cat hijau, berdiri di antara aroma kayu lapuk dan tikus nostalgia.");
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/badutSenang.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::None},
            },
            {},
            "Dr. Badut",
            "Seni cerita… luar biasa",
    Scene26_PindahScene, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene26_Update(Scene *scene)
{
    Scene26Data *data = (Scene26Data *)scene->data;
}

void Scene26_Destroy(Scene *scene)
{
}

Scene *Scene26_Create()
{
    Scene26Data *mainMenu = new Scene26Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene26_Start,
        .update = Scene26_Update,
        .destroy = Scene26_Destroy
    };
    return scene;
}
