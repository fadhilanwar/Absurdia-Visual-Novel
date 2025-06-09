#include "scene_12.hpp"
#include <iostream>

void Scene12_DialogPilihan1(Scene *scene)
{
    std:: cout << "Pilihan 1 dipilih\n";
    Scene *scene14 = Scene14_Create();
    SceneManager_GoToScene(scene->sceneManager, scene14, SceneTransition::Fade);
}

void Scene12_DialogPilihan2(Scene *scene)
{
    std:: cout << "Pilihan 2 dipilih\n";
    Scene *scene18 = Scene18_Create();
    SceneManager_GoToScene(scene->sceneManager, scene18, SceneTransition::Fade);
}

void Scene12_DialogPilihan3(Scene *scene)
{
    std:: cout << "Pilihan 3 dipilih\n";
    Scene *scene15 =Scene15_Create();
    SceneManager_GoToScene(scene->sceneManager,scene15, SceneTransition::Fade);
}

void Scene12_Start(Scene *scene)
{
    Scene12Data *data = (Scene12Data *)scene->data;
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
                .imageFilePath = "HRD/badutSenang.png",
                .position = DialogPersonPosition::Right,
                .animation = DialogPersonAnimation::None},
            },
            {
                DialogQuestion{
                    .question = "Isi dengan serius",
                    .onAnswered = Scene12_DialogPilihan1,
                    .onAnsweredParameter = scene},
                DialogQuestion{
                    .question = "Isi dengan krayon merah",
                    .onAnswered = Scene12_DialogPilihan2,
                    .onAnsweredParameter = scene},
                DialogQuestion{
                    .question = "Buat formulir jadi origami kambing",
                    .onAnswered = Scene12_DialogPilihan3,
                    .onAnsweredParameter = scene}},
                    "Dr. Badut",
                    "Silahkan isi Formulir");

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene12_Update(Scene *scene)
{

}

void Scene12_Destroy(Scene *scene)
{

}

Scene *Scene12_Create()
{
    Scene12Data *mainMenu = new Scene12Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene12_Start,
        .update = Scene12_Update,
        .destroy = Scene12_Destroy
    };
    return scene;
}

// void Scene12_DialogPilihan1(Scene *scene)
// {stroy
//     std:: cout << "Memilih pilihan 1\n";
//     Scene *scen(Scene *e13 = Scene13_Create();
//     SceneManager_GoToScene(scene->sceneManager, scene13, SceneTransition::Fade);
// }

// void Scene12_DialogPilihan2(Scene *scene)
// {
//     std:: cout << "Memilih pilihan 2\n";
//     Scene *scene14 = Scene14_Create();
//     SceneManager_GoToScene(scene->sceneManager, scene14, SceneTransition::Fade);
// }

// void Scene12_Start(Scene *scene)
// {
//     Scene12Data *data = (Scene12Data *)scene->data;
//     SceneManager_SetBackground(scene->sceneManager, "background/interview.png");
//     SceneManager_AddDialog(
//         scene->sceneManager,
//         {
//             DialogPerson{
//                 .imageFilePath = "figuran/katakTertawa.png",
//                 .position = DialogPersonPosition::Right,
//                 .animation = DialogPersonAnimation::Slide},
//             },
//             {
//                 DialogQuestion{
//                     .question = "Terimakasih dan duduk tegap",
//                     .onAnswered = Scene12_DialogPilihan1,
//                     .onAnsweredParameter = scene},
//                 DialogQuestion{
//                     .question = "Mbeeeee (dengan nada pelan)",
//                     .onAnswered = Scene12_DialogPilihan2,
//                     .onAnsweredParameter = scene}},
//                     "Mr.Katak",
//                     "Kreatif dengan fonetik. . .  saya suka! ");
//     SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
// }

// void Scene12_Update(Scene *scene)
// {
//     Scene12Data *data = (Scene12Data *)scene->data;
// }

// void Scene12_Destroy(Scene *scene)
// {
// }

// Scene *Scene12_Create()
// {
//     Scene12Data *mainMenu = new Scene12Data();
//     Scene *scene = new Scene{
//         .data = mainMenu,
//         .start = Scene12_Start,
//         .update = Scene12_Update,
//         .destroy = Scene12_Destroy
//     };
//     return scene;
// }
