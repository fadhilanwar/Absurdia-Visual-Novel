#include "ending_b.hpp"
#include <iostream>

void Ending_b_Start(Scene *scene)
{
    Ending_bData *data = (Ending_bData *)scene->data;

    // Set hanya background, tanpa karakter
    SceneManager_SetBackground(scene->sceneManager, "endingB.png");

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

Scene* Ending_b_Create()
{
    Ending_bData *data = new Ending_bData();
    Scene *scene = new Scene{
        .data = data,
        .start = Ending_b_Start,
        .update = nullptr,   // Tidak ada update per frame
        .destroy = nullptr   // Tidak ada resource tambahan
    };
    return scene;
}
