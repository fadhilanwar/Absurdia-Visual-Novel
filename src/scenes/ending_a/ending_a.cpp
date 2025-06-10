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
        "MC",
        "Selamat! Kamu telah menyelesaikan game ini. Terima kasih telah bermain!"
    );

    // Mainkan musik ending
    SceneManager_PlayMusic(scene->sceneManager, "Ending Unlock.wav");
}

Scene* Ending_a_Create()
{
    Ending_aData *data = new Ending_aData();
    Scene *scene = new Scene{
        .data = data,
        .start = Ending_a_Start,
        .update = nullptr,   // Tidak ada update per frame
        .destroy = nullptr   // Tidak ada resource tambahan
    };
    return scene;
}
