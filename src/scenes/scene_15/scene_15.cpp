#include "scene_15.hpp"
#include <iostream>

void Scene15_DialogPilihan1(Scene *scene)
{
    std:: cout << "Pilihan 1 dipilih \n";

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
            "Saya ada ide untuk logo perusahaan.");
    
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/badutBicara.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
            },
            {},
            "Dr. Badut",
            "Benarkah? Beri tahu kami");

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
            "Bagaimana kita ganti dengan kambing bawa koper? Autentik bukan!");
    
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
            "YAYAYAYA! Aku suka idemu");

    SceneManager_GoToScene(scene->sceneManager, scene->connectedSceneNumbers[0], SceneTransition::None);
}

void Scene15_DialogPilihan2(Scene *scene)
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
            "Kalau boleh tahu . . . ");

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
            "Apakah kalian punya kambing peliharaan?");

    SceneManager_GoToScene(scene->sceneManager, scene->connectedSceneNumbers[1], SceneTransition::None);
}

void Scene15_DialogScene2(Scene *scene)
{
    SceneManager_SetBackground(scene->sceneManager, "background/interview.png");
}

void Scene15_Start(Scene *scene)
{
    Scene15Data *data = (Scene15Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "background/narrOrigami.png");
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            
            },
            {},
            "",
            "", Scene15_DialogScene2, scene);

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/happyWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Pop},
        },
        {},
        "Yono",
        "Tadaaaa!");

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
        "Jadilah anak kambing kecil yang lucu!");
            
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/katakTerpesona.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide},
            },
            {},
            "Mr.Katak",
            "Kamu ini memang orang yang kreatif.");
        
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/katakBicara.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::None},
            },
            {},
            "Mr.Katak",
            "Tapi kami ingin melihat bagaimana kamu berkontribusi ke citra perusahaan kami.");

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
            "Dengan kambing?");

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
            "Dengan visi dong");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/badutBicara.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::None},
            },
            {},
            "Dr. Badut",
            "Sekarang jelaskan visimu untuk menjadi bagian dari kami");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/shockedWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide},
            },
            {
                DialogQuestion{
                    .question = "Tawarkan ide",
                    .onAnswered = Scene15_DialogPilihan1,
                    .onAnsweredParameter = scene},
                DialogQuestion{
                    .question = "Tanya balik",
                    .onAnswered = Scene15_DialogPilihan2,
                    .onAnsweredParameter = scene}},
                "",
                "");
}

void Scene15_Update(Scene *scene)
{
    Scene15Data *data = (Scene15Data *)scene->data;
}

void Scene15_Destroy(Scene *scene)
{
}

Scene *Scene15_Create()
{
    Scene15Data *mainMenu = new Scene15Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene15_Start,
        .update = Scene15_Update,
        .destroy = Scene15_Destroy
    };
    return scene;
}
