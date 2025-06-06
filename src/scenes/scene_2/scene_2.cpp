#include "scene_2.hpp"
#include <iostream>

void Scene2_DialogBeres(Scene *scene)
{
    std::cout << "Dialog beres\n";
    Scene *scene3 = Scene3_Create();
    // // SceneManager_GoToSceneene(scene->sceneManager, scene3);
}

void Scene2_Start(Scene *scene)
{
    Scene2Data *data = (Scene2Data *)scene->data;
    SceneManager_SetBackground(scene->sceneManager, "kejar_kereta.png");
    // SceneManager_AddDialog(scene->sceneManager, true, "MC","Permisi! Permisi! Maaf!", "confusedWork.png");
    // SceneManager_AddDialog(scene->sceneManager, false, "Penjual Tahu", "Tahu bulat digoreng dadakan, lima rat—woi! Hati-hati dong!", "tahu_marah.png");
    // SceneManager_AddDialog(scene->sceneManager, true, "MC", "Maaf, saya terburu-buru. Saya harus ke stasiun kereta api!", "talkingWork.png");
    // SceneManager_AddDialog(scene->sceneManager, false, "Penjual Tahu", "Oh, ya ampun! Kamu harus cepat!", "tahu_senang.png", Scene2_DialogBeres, scene);

    SceneManager_PlayMusic(scene->sceneManager, "Morning.mp3");
}

void Scene2_Update(Scene *scene)
{
    Scene2Data *data = (Scene2Data *)scene->data;
}

void Scene2_Destroy(Scene *scene)
{
}

Scene *Scene2_Create()
{
    Scene2Data *mainMenu = new Scene2Data();
    Scene *scene = new Scene{
        .data = mainMenu,
        .start = Scene2_Start,
        .update = Scene2_Update,
        .destroy = Scene2_Destroy
    };
    return scene;
}