#include "scene_1_part3.hpp"

#include <iostream>

// ganti background dari kamar ke dapur
void Scene1Part3_DialogScene1(Scene *scene)
{
    Scene1Part3Data *data = (Scene1Part3Data *)scene->data;
    data->isShowingLaptop = false;
    SceneManager_SetBackground(scene->sceneManager, "background/dapur_remastered.png");
}

void Scene1Part3_DialogScene2(Scene *scene)
{
    Scene1Part3Data *data = (Scene1Part3Data *)scene->data;
    data->isShowingLaptop = true;
    SceneManager_SetBackground(scene->sceneManager, "background/laptop.png");
}
void Scene1Part3_DialogBeres(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene2 = Scene2_Create();
    SceneManager_GoToScene(scene->sceneManager, scene->connectedSceneNumbers[0], SceneTransition::Fade);
}

void Scene1Part3_Start(Scene *scene)
{
    SceneManager_SetBackground(scene->sceneManager, "background/dapur_remastered.png");

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
        "");
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
        "Ahh, hangat dan racikan yang pas tanpa gula. Sempurna!");
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
        "");

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
        Scene1Part3_DialogScene2, scene);

    SceneManager_AddDialog(
        scene->sceneManager,
        {},
        {},
        "",
        "",
        Scene1Part3_DialogScene1, scene);

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
        Scene1Part3_DialogScene1, scene);

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
        Scene1Part3_DialogBeres, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene1Part3_Update(Scene *scene)
{

    // Scene1Data *data = (Scene1Data *)scene->data;

    // if (data->animProgress < 5.0f)
    // {
    //     Canvas_DrawImage(scene->canvas, 1000, 550, "background/jam_weker.png");
    // }
}

void Scene1Part3_UpdateAfterPersons(Scene *scene)
{
    Scene1Part3Data *data = (Scene1Part3Data *)scene->data;

    if (!data->isShowingLaptop)
        Canvas_DrawImage(scene->canvas, 0, 0, "composition/scene_1/front_2.png");
}

void Scene1Part3_Destroy(Scene *scene)
{
    //
}

Scene *Scene1Part3_Create()
{
    Scene1Part3Data *data = new Scene1Part3Data();
    Scene *scene = new Scene{
        .data = data,
        .start = Scene1Part3_Start,
        .update = Scene1Part3_Update,
        .updateAfterPersons = Scene1Part3_UpdateAfterPersons,
        .destroy = Scene1Part3_Destroy};
    return scene;
}
