#include "scene_13.hpp"
#include <iostream>

void Scene13_DialogPilihan1(Scene *scene)
{
    std:: cout << "Pilihan 1 dipilih\n";
    Scene *scene14 = Scene14_Create();
    SceneManager_GoToScene(scene->sceneManager, scene14, SceneTransition::Fade);
}

void Scene13_DialogPilihan2(Scene *scene)
{
    std:: cout << "Pilihan 2 dipilih\n";
    Scene *scene18 = Scene18_Create();
    SceneManager_GoToScene(scene->sceneManager, scene18, SceneTransition::Fade);
}

void Scene13_DialogPilihan3(Scene *scene)
{
    std:: cout << "Pilihan 3 dipilih\n";
    Scene *scene15 =Scene15_Create();
    SceneManager_GoToScene(scene->sceneManager,scene15, SceneTransition::Fade);
}

void Scene13_Start(Scene *scene)
{
    Scene13Data *data = (Scene13Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "background/interview.png");
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
            "Akta lahirnya mana?");

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
        "Ahhh . . . ");
    
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
        "Saya lahir secara tidak resmi, hehehe");
        
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
        "Waduh waduuuuuh!");
    
    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/badutSenang.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::None},
        },
        {},
        "Dr. Badut",
        "Tenang saja, bisa kami atur, ahihiha!");

    SceneManager_AddDialog(
        scene->sceneManager,
        {
            DialogPerson{
                .imageFilePath = "HRD/badutSenang.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::None},
            },
            {
                DialogQuestion{
                    .question = "Isi dengan serius",
                    .onAnswered = Scene13_DialogPilihan1,
                    .onAnsweredParameter = scene},
                DialogQuestion{
                    .question = "Isi dengan krayon merah",
                    .onAnswered = Scene13_DialogPilihan2,
                    .onAnsweredParameter = scene},
                DialogQuestion{
                    .question = "Buat formulir jadi origami kambing",
                    .onAnswered = Scene13_DialogPilihan3,
                    .onAnsweredParameter = scene}},
                    "Dr. Badut",
                    "Silahkan isi formulirnya dulu ya");

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene13_Update(Scene *scene)
{

}

void Scene13_Destroy(Scene *scene)
{

}

Scene *Scene13_Create()
{
    Scene13Data *mainMenu = new Scene13Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene13_Start,
        .update = Scene13_Update,
        .destroy = Scene13_Destroy
    };
    return scene;
}



// void Scene13_DialogScene13(Scene *scene)
// {
//     std::cout << "Dialog beres\n";
//     Scene *scene14 = Scene14_Create();
//     // // SceneManager_GoToScene(scene->sceneManager, scene14);
// }

// void Scene13_Start(Scene *scene)
// {
//     Scene13Data *data = (Scene13Data *)scene->data;
//     SceneManager_SetBackground(scene->sceneManager, "tiba_dikota.png");
//     // SceneManager_AddDialog(scene->sceneManager, true, "MC","Aku harus cepat! Kalau telat, mereka bisa langsung mencoret namaku..", "talkingWork.png", Scene13_DialogScene13, scene);

//     SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
// }

// void Scene13_Update(Scene *scene)
// {
//     Scene13Data *data = (Scene13Data *)scene->data;
// }

// void Scene13_Destroy(Scene *scene)
// {
// }

// Scene *Scene13_Create()
// {
//     Scene13Data *mainMenu = new Scene13Data();
//     Scene *scene = new Scene{
//         .data = mainMenu,
//         .start = Scene13_Start,
//         .update = Scene13_Update,
//         .destroy = Scene13_Destroy
//     };
//     return scene;
// }
