#include "scene_2.hpp"

#include <iostream>
#include <cmath>

void Scene2_DialogBeres(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene3 = Scene3_Create();
    SceneManager_GoToScene(scene->sceneManager, scene3, SceneTransition::Fade);
}

void Scene2_DialogScene2(Scene *scene)
{
    SceneManager_SetBackground(scene->sceneManager, "background/dalamKereta.png");
}

void Scene2_Start(Scene *scene)
{
    Scene2Data *data = (Scene2Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "background/outSubway.png");
}


void Scene2_Part3(Scene *scene)
{
    Scene2Data *data = (Scene2Data *)scene->data;
    if (data->part == 3.f)
        data->part = 4.f;

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "figuran/tahu_marah_flipped.png",
                .position = DialogPersonPosition::Center,
                .animation = DialogPersonAnimation::Shake},
        },
        {},
        "Penjual Tahu",
        "Hey! Hati-hati dong kalau jalan!");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "figuran/tahu_marah_flipped.png",
                .position = DialogPersonPosition::Center,
                .animation = DialogPersonAnimation::Shake},
        },
        {},
        "Penjual Tahu",
        "Hampir saja tahuku terjatuh");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "figuran/tahu_marah_flipped.png",
                .position = DialogPersonPosition::Center,
                .animation = DialogPersonAnimation::None},
            DialogPerson{
                .imageFilePath = "work/confusedWork_flipped.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "Yono",
        "Duh! Maaf! Aku sedang buru-buru!");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "figuran/tahu_marah_flipped.png",
                .position = DialogPersonPosition::Center,
                .animation = DialogPersonAnimation::FadeOut},
            DialogPerson{
                .imageFilePath = "work/lari.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Pop},
        },
        {},
        "Yono",
        "Itu keretanya! Tunggu!",
        Scene2_DialogScene2, scene);

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/shockedWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "Yono",
        "Hampir saja aku tertinggal kereta");

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
        "Bisa gawat kalau aku ketinggalan.");

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
        "Oke, lokasi gedungnya nggak jauh dari sini. Seharusnya. . . lima menit cukup.",
        Scene2_DialogBeres, scene);
}

void Scene2_Part2(Scene *scene)
{
    Scene2Data *data = (Scene2Data *)scene->data;
    if (data->part != 2.f)
    {
        data->part = 2.f;
        data->animProgressPart = data->animProgress;
    }
    float animProgressSubstracted = data->animProgress - data->animProgressPart;

    {
        int y = 0;
        float divided = data->animProgress / 1.75;
        float result = divided - ceil(divided - 1);
        if (result <= 0.5)
        {
            y = -(sin((result * 2) * M_PI / 2) * 30);
        }
        else
        {
            y = -((-2 * result + 2) * 30);
        }

        if (animProgressSubstracted > 4.5f)
        {
            data->part = 3.f;
        }
        else if (animProgressSubstracted > 0.5f)
        {
            float rotationSpeed = std::max((float)fmod(4 - animProgressSubstracted, 4), 0.f);
            float rotation = std::max((float)fmod(4 - animProgressSubstracted, 4), 0.f) * 1080 * rotationSpeed;
            Canvas_DrawImage(scene->canvas, 314, y + 30, "figuran/tahu_marah.png", 1.f, rotation);
        }
        else
        {
            Canvas_DrawImage(scene->canvas, 314, y + 30, "figuran/tahu_senang.png");
        }
    }

    {
        int x = (animProgressSubstracted * 1500.f) - 497;
        Canvas_DrawImage(scene->canvas, x, 0, "work/lari.png");
    }
}

void Scene2_Part1(Scene *scene)
{
    Scene2Data *data = (Scene2Data *)scene->data;

    int y = 0;
    float divided = data->animProgress / 1.75;
    float result = divided - ceil(divided - 1);
    if (result <= 0.5)
    {
        y = -(sin((result * 2) * M_PI / 2) * 30);
    }
    else
    {
        y = -((-2 * result + 2) * 30);
    }

    Canvas_DrawImage(scene->canvas, 314, y + 30, "figuran/tahu_senang.png");

    if (data->animProgress > 3.f && data->part == 1.f)
    {
        data->part = 1.5f;
        SceneManager_AddDialog(
            scene->sceneManager,
            {
                
            },
            {},
            "Penjual Tahu",
            "Tahuuuu bulat! diiigoreng dadakan! lima rat. . .",
            Scene2_Part2,
            scene);
    }
}

void Scene2_Update(Scene *scene)
{
    Scene2Data *data = (Scene2Data *)scene->data;
    if (data->part < 2.f)
    {
        Scene2_Part1(scene);
    }
    else if (data->part == 2.f)
    {
        Scene2_Part2(scene);
    }
    else if (data->part == 3.f)
    {
        Scene2_Part3(scene);
    }

    data->animProgress += 0.016f;
}

void Scene2_Destroy(Scene *scene)
{
}

Scene *Scene2_Create()
{
    Scene2Data *data = new Scene2Data();
    Scene *scene = new Scene{
        .data = data,
        .start = Scene2_Start,
        .update = Scene2_Update,
        .destroy = Scene2_Destroy};
    return scene;
}

