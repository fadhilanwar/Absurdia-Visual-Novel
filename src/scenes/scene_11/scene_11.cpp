#include "scene_11.hpp"
#include <iostream>

void Scene11_DialogPilihan1(Scene *scene)
{
    std:: cout << "Pilihan 1 dipilih\n";
    Scene *scene17 = Scene17_Create();
    SceneManager_GoToScene(scene->sceneManager, scene17, SceneTransition::Fade);
}

void Scene11_DialogPilihan2(Scene *scene)
{
    std:: cout << "Pilihan 2 dipilih\n";
    Scene *scene18 =Scene18_Create();
    SceneManager_GoToScene(scene->sceneManager, scene18, SceneTransition::Fade);
}

void Scene11_Start(Scene *scene)
{
    Scene11Data *data = (Scene11Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "background/interview.png");
    SceneManager_AddDialog(
            scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/confusedWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
            },
            {},
            "MC",
            "Ciieeeeetttsss. . .");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/katakMeringis.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
            },
            {
                DialogQuestion{
                    .question = "Jawab dengan serius",
                    .onAnswered = Scene11_DialogPilihan1,
                    .onAnsweredParameter = scene},
                DialogQuestion{
                    .question = "Tertawa dan bercanda",
                    .onAnswered = Scene11_DialogPilihan2,
                    .onAnsweredParameter = scene}},
                "Mr.Katak",
                "Suara pintu kamu sangat realistis. Kamu mantan pintu?");
}


void Scene11_Update(Scene *scene)
{
    // Scene11Data *data = (Scene11Data *)scene->data;
}

void Scene11_Destroy(Scene *scene)
{
}

Scene *Scene11_Create()
{
    Scene11Data *mainMenu = new Scene11Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene11_Start,
        .update = Scene11_Update,
        .destroy = Scene11_Destroy
    };
    return scene;
}