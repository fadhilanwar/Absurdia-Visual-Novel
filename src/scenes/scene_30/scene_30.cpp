#include "scene_30.hpp"
#include <iostream>

void Scene30_DialogScene30(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *ending_d = static_cast<Scene*>(Ending_d_Create());
    SceneManager_GoToScene(scene->sceneManager, ending_d, SceneTransition::Fade);
}

void Scene30_Start(Scene *scene)
{
    Scene30Data *data = (Scene30Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "background/interview.png");
    // SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene30_DialogScene30, scene);

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
            "Selama kambingmu bisa pakai jas dan tak ganggu presentasi, silakan.");

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
            "Okee! Aku akan latih dia untuk voting nanti", Scene30_DialogScene30, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene30_Update(Scene *scene)
{
    Scene30Data *data = (Scene30Data *)scene->data;
}

void Scene30_Destroy(Scene *scene)
{
}

Scene *Scene30_Create()
{
    Scene30Data *mainMenu = new Scene30Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene30_Start,
        .update = Scene30_Update,
        .destroy = Scene30_Destroy
    };
    return scene;
}
