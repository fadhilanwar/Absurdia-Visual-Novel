#include "scene_7.hpp"
#include <iostream>

//belum
// MC menyusuri lorong. Ia melihat pemandangan aneh: pria berkaki bebek, wanita mengenakan jas hujan lengkap dengan payung, seekor ular mengenakan jas dan kacamata baca sambil membaca koran dari ekornya.) 

void Scene7_DialogScene(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene8 = Scene8_Create();
    SceneManager_GoToScene(scene->sceneManager, scene8, SceneTransition::Fade);
}

void Scene7_Start(Scene *scene)
{
    Scene7Data *data = (Scene7Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "background/lorong.png");
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/shockedWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide
            },
        },
        {},
        "MC",
        "Aku nggak salah masuk gedung kan? Ini seperti festival cosplay..."
    );

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/shockedWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide
            },
        },
        {},
        "MC",
        "Sepertinya rumor yang dikatakan orang-??? benar..."
    );

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "work/shockedWork.png",
                .position = DialogPersonPosition::Left,
                .animation = DialogPersonAnimation::Slide
            },
        },
        {},
        "MC",
        "Sudahlah... ini kesempatanku untuk mendapatkan sebuah pekerjaan.",
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


// void Scene7_DialogScene7(Scene *scene)
// {
//     std::cout << "Dialog beres\n";
//     Scene *scene8 = Scene8_Create();
//     SceneManager_GoToScene(scene->sceneManager, scene8);
// }

// void Scene7_Start(Scene *scene)
// {
//     Scene7Data *data = (Scene7Data *)scene->data;
//     SceneManager_SetBackground(scene->sceneManager, "tiba_dikota.png");
//     // SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene7_DialogScene7, scene);

//     SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
// }

// void Scene7_Update(Scene *scene)
// {
//     Scene7Data *data = (Scene7Data *)scene->data;
// }

// void Scene7_Destroy(Scene *scene)
// {
// }

// Scene *Scene7_Create()
// {
//     Scene7Data *mainMenu = new Scene7Data();
//     Scene *scene = new Scene{
//         .data = mainMenu,
//         .start = Scene7_Start,
//         .update = Scene7_Update,
//         .destroy = Scene7_Destroy
//     };
//     return scene;
// }