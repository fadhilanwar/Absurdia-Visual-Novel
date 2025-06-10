#include "scene4_part1.hpp"
#include <iostream>


void Scene4Part1_PindahScene(Scene *scene)
{
    std::cout << "Pindah scene\n";
    Scene *scene4Part2 = Scene4Part2_Create();
    SceneManager_GoToScene(scene->sceneManager, scene4Part2, SceneTransition::Fade);
}

void Scene4Part1_Start(Scene *scene)
{
    Scene4Part1Data *data = (Scene4Part1Data *)scene->data;
    
    SceneManager_SetBackground(scene->sceneManager, "background/resepsionis.png");
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "figuran/resepsionisTertawa.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "Resepsionis",
        "Pasti kamu mau bertanya kan? haha!");
    
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/confusedWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "Yono",
        "Eh. . . Iya. Saya. . . ");
    
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "figuran/resepsionisTalk.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "Resepsionis",
        "Ayo ayo! mau tanya apa? ha?");
    
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/confusedWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "Yono",
        "Aa. . . aku ke sini. . . ingin interview kerja untuk lowongan pekerjaan yang baru dibuka disini");
    
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "figuran/resepsionisTertawa.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "Resepsionis",
        "Ooo begitu! Langsung naik lift saja, ruangannya ada di lantai 3, Oke!!");
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
        "Baik! Terima kasih");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "figuran/resepsionisTertawa.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
        },
        {},
        "Resepsionis",
        "Oiyaaa. . . jangan kaget ya. . . kau akan terbiasa. . . ahahahaaa!");

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
        "Baiklah, lantai 3 ya.",
        Scene4Part1_PindahScene, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void scene4Part1_Update(Scene *scene)
{
    // Scene4Data *data = (Scene4Data *)scene->data;
}

void Scene4Part1_Destroy(Scene *scene)
{
    // Scene4Data *data = (Scene4Data *)scene->data;
    // delete data;
}

Scene *Scene4Part1_Create()
{
    Scene4Part1Data *data = new Scene4Part1Data();
    Scene *scene = new Scene{
        .data = data,
        .start = Scene4Part1_Start,
        .update = scene4Part1_Update,
        .destroy = Scene4Part1_Destroy
    };
    return scene;
}
