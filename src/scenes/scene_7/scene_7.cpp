#include "scene_7.hpp"
#include <iostream>


void Scene7_DialogScene(Scene *scene)
{
    std::cout << "Dialog beres\n";
    SceneManager_GoToScene(scene->sceneManager, scene->connectedSceneNumbers[0], SceneTransition::None);
}

void Scene7_Start(Scene *scene)
{
    Scene7Data *data = (Scene7Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "background/depan_pintu.png");
    
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "figuran/manusiaBebek.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide
            },
        },
        {},
        "Manusia Bebek",
        "Haduh lama sekali ya, QUACK-QUACK!"
    );

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "figuran/jasHujan.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide
            },
        },
        {},
        "Little Daydream",
        "Hihihi!"
    );

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "figuran/jasHujan.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Pop
            },
        },
        {},
        "Little Daydream",
        "Aku tidak sabar ingin interview"
    );

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "figuran/manusiaUlar.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::Slide
            },
        },
        {},
        "Mr. Ular",
        ". . ."
    );

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/confusedWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide
            },
        },
        {},
        "Yono",
        "Aku nggak salah masuk gedung kan? Ini seperti festival cosplay . . ."
    );

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/shockedWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::None
            },
        },
        {},
        "Yono",
        "Sepertinya rumor yang dikatakan orang-orang benar"
    );

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/talkingWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Pop
            },
        },
        {},
        "Yono",
        "Sudahlah. . .  ini kesempatanku untuk mendapatkan sebuah pekerjaan.",
    Scene7_DialogScene, scene);

}

void Scene7_Update(Scene *scene)
{
    Scene7Data *data = (Scene7Data *)scene->data;
}

void Scene7_Destroy(Scene *scene)
{
}

Scene *Scene7_Create()
{
    Scene7Data *mainMenu = new Scene7Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene7_Start,
        .update = Scene7_Update,
        .destroy = Scene7_Destroy
    };
    return scene;
}

