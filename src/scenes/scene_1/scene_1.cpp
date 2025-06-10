#include "scene_1.hpp"

#include <iostream>
#include <cmath>

//ganti background dari kamar ke dapur
void Scene1_DialogScene1(Scene *scene)
{
    SceneManager_SetBackground(scene->sceneManager, "background/dapur_.png");
}

void Scene1_DialogScene2(Scene *scene)
{
    SceneManager_SetBackground(scene->sceneManager, "background/laptop.png");
}
void Scene1_DialogBeres(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene2 = Scene2_Create();
    SceneManager_GoToScene(scene->sceneManager, scene2, SceneTransition::Fade);
}
void Scene1_Start(Scene *scene)
{
    Scene1Data *data = (Scene1Data *)scene->data;
    
    SceneManager_SetBackground(scene->sceneManager, "background/kamar_pribadi.png");
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
        Scene1_DialogScene1, scene);

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "pajamas/teaPajamas.png",
                .position = DialogPersonPosition::Center,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "",
        ""
    );
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "pajamas/talkingTeaPajamas.png",
                .position = DialogPersonPosition::Center,
                .animation = DialogPersonAnimation::Pop},
        },
        {},
        "Yono",
        "Ahh, hangat dan racikan yang pas tanpa gula. Sempurna!"
    );
        SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "pajamas/teaLookingPajamas.png",
                .position = DialogPersonPosition::Center,
                .animation = DialogPersonAnimation::None},
        },
        {},
        "",
        ""
    );

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "pajamas/teaLookingTalkingPajamas.png",
                .position = DialogPersonPosition::Center,
                .animation = DialogPersonAnimation::None},
        },
        {},
        "Yono",
        "Sebentar . . . ",
        Scene1_DialogScene2, scene);

    SceneManager_AddDialog(
        scene->sceneManager,
        {},
        {},
        "",
        "",
        Scene1_DialogScene1, scene
    );

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "pajamas/shockedPajamas.png",
                .position = DialogPersonPosition::Center,
                .animation = DialogPersonAnimation::Shake},
        },
        {},
        "Yono",
        "ADUH GAWAT ITU HARI INI?!!!",
    Scene1_DialogScene1, scene);

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "pajamas/shockedPajamas.png",
                .position = DialogPersonPosition::Center,
                .animation = DialogPersonAnimation::Pop},
        },
        {},
        "Yono",
        "AKU HARUS SEGERA SIAP-SIAP!", 
    Scene1_DialogBeres, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
        }

void Scene1_Update(Scene *scene)
{

    Scene1Data *data = (Scene1Data *)scene->data;

    data->animProgress < 5.0f;
    {
        Canvas_DrawImage(scene->canvas, 1000, 550, "background/jam_weker.png");
    }

}

void Scene1_Destroy(Scene *scene)
{
    // 
}

Scene *Scene1_Create()
{
    Scene1Data *data = new Scene1Data();
    Scene *scene = new Scene{
        .data = data,
        .start = Scene1_Start,
        .update = Scene1_Update,
        .destroy = Scene1_Destroy};
    return scene;
    }

