#include "ending_a.hpp"
#include <iostream>

void Ending_a_Start(Scene *scene)
{
    Ending_aData *data = (Ending_aData *)scene->data;

    // Set hanya background, tanpa karakter
    SceneManager_SetBackground(scene->sceneManager, "endingA.png");

    // Tampilkan pesan akhir tanpa karakter
    SceneManager_AddDialog(
        scene->sceneManager,
        {}, // Tidak ada karakter
        {},
        "Hidup sederhana",
        "Yono pun pulang ke rumah, menyeduh kembali tehnya, dan menikmati pemandangan kota dari atas\n apartemennya. Tamat."
    );

    // Mainkan musik ending
    SceneManager_PlayMusic(scene->sceneManager, "Ending Unlock.wav");
}

void Ending_a_Update(Scene *scene)
{
}

void Ending_a_Destroy(Scene *scene)
{
}

Scene* Ending_a_Create()
{
    Ending_aData *data = new Ending_aData();
    Scene *scene = new Scene{
        .data = data,
        .start = Ending_a_Start,
        .update = Ending_a_Update,
        .destroy = Ending_a_Destroy
    };
    return scene;
}
