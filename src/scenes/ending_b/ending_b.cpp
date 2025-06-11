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

void Ending_b_Update(Scene *scene)
{
}

void Ending_b_Destroy(Scene *scene)
{
}

Scene* Ending_b_Create()
{
    Ending_bData *data = new Ending_bData();
    Scene *scene = new Scene{
        .data = data,
        .start = Ending_b_Start,
        .update = Ending_b_Update,
        .destroy = Ending_b_Destroy
    };
    return scene;
}
