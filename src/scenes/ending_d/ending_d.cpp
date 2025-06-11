#include "ending_d.hpp"
#include <iostream>


void playEndingSFX(Scene *scene) {
    SceneManager_PlaySound(scene->sceneManager, "Ending Unlock.wav");
}


void Ending_d_Start(Scene *scene)
{
    Ending_dData *data = (Ending_dData *)scene->data;

    // Set hanya background, tanpa karakter
    SceneManager_SetBackground(scene->sceneManager, "endingD.png");

    // Tampilkan pesan akhir tanpa karakter
    SceneManager_AddDialog(
        scene->sceneManager,
        {}, // Tidak ada karakter
        {},
        "Bintang Kantor",
        "Yono menjadi selebriti kantor, selalu menjadi pusat perhatian dan tampil di semua acara kantor", playEndingSFX, scene
    );

    // Mainkan musik ending
    SceneManager_PlayMusic(scene->sceneManager, "Ending Unlock.wav");
}

void Ending_d_Update(Scene *scene)
{
}

void Ending_d_Destroy(Scene *scene)
{
}

Scene* Ending_d_Create()
{
    Ending_dData *data = new Ending_dData();
    Scene *scene = new Scene{
        .data = data,
        .start = Ending_d_Start,
        .update = Ending_d_Update,
        .destroy = Ending_d_Destroy
    };
    return scene;
}
