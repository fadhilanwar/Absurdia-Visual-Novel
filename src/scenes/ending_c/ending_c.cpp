#include "ending_c.hpp"
#include <iostream>

void Ending_c_Start(Scene *scene)
{
    Ending_cData *data = (Ending_cData *)scene->data;

    // Set hanya background, tanpa karakter
    SceneManager_SetBackground(scene->sceneManager, "endingC.png");

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

void Ending_c_Update(Scene *scene)
{
}

void Ending_c_Destroy(Scene *scene)
{
}

Scene* Ending_c_Create()
{
    Ending_cData *data = new Ending_cData();
    Scene *scene = new Scene{
        .data = data,
        .start = Ending_c_Start,
        .update = Ending_c_Update,
        .destroy = Ending_c_Destroy
    };
    return scene;
}
