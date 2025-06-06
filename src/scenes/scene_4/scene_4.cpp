#include "scene_4.hpp"
#include <iostream>

void Scene4_DialogScene4(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene5 = Scene5_Create();
    // SceneManager_GoToScene(scene->sceneManager, scene5);
}

void Scene4_Start(Scene *scene)
{
    Scene4Data *data = (Scene4Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "resepsionis.png");
    // // // // SceneManager_AddDialog(scene->sceneManager, false, "Resepsionis","(sambil tersenyum lebar) Pasti kamu mau bertanya kan, haha!", "resepsionisTertawa.png");
    // // SceneManager_AddDialog(scene->sceneManager, true, "MC","Eh… iya, saya...", "talkingWork.png");
    // // SceneManager_AddDialog(scene->sceneManager, false, "Resepsionis","Ayo ayo, mau tanya apa, ha?", "resepsionisTalk.png");
    // // SceneManager_AddDialog(scene->sceneManager, true, "MC","A-aku ke sini... ingin interview kerja di Absurdia Inc.", "confusedWork.png");
    // // SceneManager_AddDialog(scene->sceneManager, false, "Resepsionis", "Ooo begitu! Langsung naik lift saja, ada di lantai 3. Oke!!", "resepsionisSenyum.png");
    // // SceneManager_AddDialog(scene->sceneManager, true, "MC","Baik. Terima kasih", "talkingWork.png", Scene4_DialogScene4, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene4_Update(Scene *scene)
{
    Scene4Data *data = (Scene4Data *)scene->data;
}

void Scene4_Destroy(Scene *scene)
{
}

Scene *Scene4_Create()
{
    Scene4Data *mainMenu = new Scene4Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene4_Start,
        .update = Scene4_Update,
        .destroy = Scene4_Destroy
    };
    return scene;
}