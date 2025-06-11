#include "scene_16.hpp"
#include <iostream>

void Scene16_DialogPilihan1(Scene *scene)
{
    std:: cout << "Pilihan 1 dipilih\n";

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
            "Maaf maaf, ini tisu motif polkadot untuk bercak apelnya, hehehe");

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
            "Omong-omong soal pintu...");
    
    Scene *scene26 = Scene26_Create();
    SceneManager_GoToScene(scene->sceneManager, scene26, SceneTransition::Fade);
}

void Scene16_DialogPilihan2(Scene *scene)
{
    std:: cout << "Pilihan 2 dipilih\n";

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
            "Ini sebenarnya ilustrasi visual.");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/talkingWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::None},
            },
            {},
            "Yono",
            "Apel mewakili ide, dan jugglingnya mewakili manajemen.");

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
            "Wah! INterpretasi yang performatif ya.");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/katakBicara.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::None},
            },
            {},
            "Mr. Katak",
            "Saya suka!");

    Scene *scene18 = Scene18_Create();
    SceneManager_GoToScene(scene->sceneManager, scene18, SceneTransition::Fade);
}

void Scene16_DialogScene2(Scene *scene)
{
    SceneManager_SetBackground(scene->sceneManager, "background/narrJuggling.png");
}

void Scene16_DialogScene1(Scene *scene)
{
    SceneManager_SetBackground(scene->sceneManager, "background/interview.png");
}

void Scene16_Start(Scene *scene)
{
    Scene16Data *data = (Scene16Data *)scene->data;
    
    SceneManager_AddDialog(
        scene->sceneManager,
        {},
        {},
        "",
        "", Scene16_DialogScene2, scene);
        
        SceneManager_AddDialog(
            scene->sceneManager,
            {},
            {},
            "",
            "", Scene16_DialogScene1, scene);

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/badutSenang.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
            },
            {},
            "Dr. Badut",
            "Hei! itu apel presentasi");

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
            "Ups... maaf, saya refleks sirkus.");

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
            "Kita apresiasi metode interaktif. Tapi kami perlu klarifikasi.");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/confusedWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
            },
            {
                DialogQuestion{
                    .question = "Minta maaf, kasih tisu",
                    .onAnswered = Scene16_DialogPilihan1,
                    .onAnsweredParameter = scene},
                DialogQuestion{
                    .question = "Klarifikasi Junggling",
                    .onAnswered = Scene16_DialogPilihan2,
                    .onAnsweredParameter = scene}},
                "",
                "");
}

void Scene16_Update(Scene *scene)
{
    Scene16Data *data = (Scene16Data *)scene->data;
}

void Scene16_Destroy(Scene *scene)
{
}

Scene *Scene16_Create()
{
    Scene16Data *mainMenu = new Scene16Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene16_Start,
        .update = Scene16_Update,
        .destroy = Scene16_Destroy
    };
    return scene;
}

