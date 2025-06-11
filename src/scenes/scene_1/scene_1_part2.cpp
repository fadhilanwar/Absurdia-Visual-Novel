#include "scene_1_part2.hpp"

#include <iostream>
#include <cmath>
#include <cstdlib>

void Scene1Part2_DialogBeres(Scene *scene)
{
    std::cout << "Dialog beres\n";
    SceneManager_GoToScene(scene->sceneManager, scene->connectedSceneNumbers[0], SceneTransition::Fade);
}


void Scene1Part2_Start(Scene *scene)
{
    SceneManager_SetBackground(scene->sceneManager, "background/kamar_pribadi_remastered.png");
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "pajamas/yawningPajamas.png",
                .position = DialogPersonPosition::Center,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "Yono",
        "Hoaaammmm. . . ");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "pajamas/talkingSleepyPajamas.png",
                .position = DialogPersonPosition::Center,
                .animation = DialogPersonAnimation::None},
        },
        {},
        "Yono",
        "Sepertinya teh matcha sangat cocok untuk mengawali hari ini.");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "pajamas/talkingSleepyPajamas.png",
                .position = DialogPersonPosition::Center,
                .animation = DialogPersonAnimation::None},
        },
        {},
        "Yono",
        "Aku akan ke dapur untuk membuatnya!",
        Scene1Part2_DialogBeres, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene1Part2_Update(Scene *scene)
{

    // Scene1Data *data = (Scene1Data *)scene->data;

    // if (data->animProgress < 5.0f)
    // {
    //     Canvas_DrawImage(scene->canvas, 1000, 550, "background/jam_weker.png");
    // }
}

void Scene1Part2_UpdateAfterPersons(Scene *scene)
{
    Canvas_DrawImage(scene->canvas, 0, 0, "composition/scene_1/front_1.png");
}

void Scene1Part2_Destroy(Scene *scene)
{
    //
}

Scene *Scene1Part2_Create()
{
    Scene1Part2Data *data = new Scene1Part2Data();
    Scene *scene = new Scene{
        .data = data,
        .start = Scene1Part2_Start,
        .update = Scene1Part2_Update,
        .updateAfterPersons = Scene1Part2_UpdateAfterPersons,
        .destroy = Scene1Part2_Destroy};
    return scene;
}
