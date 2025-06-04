// #include "scene_1.hpp"
// #include <iostream>

// // Fungsi yang dipanggil jika pilihan 1 diklik
// void Scene1_DialogPilihan1(Scene *scene)
// {
//     std::cout << "Pilihan 1 dipilih\n";
//     Scene *scene2 = Scene2_Create(); // Ganti dengan scene lanjutan
//     SceneManager_GoToScene(scene->sceneManager, scene2);
// }

// // Fungsi untuk pilihan 2
// void Scene1_DialogPilihan2(Scene *scene)
// {
//     std::cout << "Pilihan 2 dipilih\n";
//     // Bisa arahkan ke scene lain atau lanjut dialog
// }

// // Fungsi untuk pilihan 3
// void Scene1_DialogPilihan3(Scene *scene)
// {
//     std::cout << "Pilihan 3 dipilih\n";
//     // Bisa arahkan ke scene lain atau lanjut dialog
// }

// // Fungsi Start Scene
// void Scene1_Start(Scene *scene)
// {
//     Scene1Data *data = (Scene1Data *)scene->data;

//     // Set background gelap polos
//     SceneManager_SetBackground(scene->sceneManager, "dialog_background.png");

//     // Tampilkan sprite karakter di kiri
//     SceneManager_ShowCharacter(scene->sceneManager, "char1.png", 100, 80); // posisi kiri bawah

//     // Nama karakter di atas box dialog
//     SceneManager_AddTextBox(scene->sceneManager, "Char name", 120, 360, 150, 30, {100, 100, 255}); // warna biru

//     // Box dialog besar
//     SceneManager_AddDialogBox(scene->sceneManager, "Dialogue text here", 50, 400, 900, 150, {255, 255, 240}); // warna krem

//     // Tombol pilihan (kanan tengah)
//     SceneManager_AddButton(scene->sceneManager, "Choice 1", 650, 180, 200, 40, Scene1_DialogPilihan1, scene);
//     SceneManager_AddButton(scene->sceneManager, "Choice 2", 650, 230, 200, 40, Scene1_DialogPilihan2, scene);
//     SceneManager_AddButton(scene->sceneManager, "Choice 3", 650, 280, 200, 40, Scene1_DialogPilihan3, scene);

//     // Musik latar
//     SceneManager_PlayMusic(scene->sceneManager, "dialog_music.mp3");
// }

// // Fungsi Update scene (jika diperlukan)
// void Scene1_Update(Scene *scene)
// {
//     Scene1Data *data = (Scene1Data *)scene->data;
//     // Logika update bisa ditambahkan di sini
// }

// // Fungsi Destroy scene
// void Scene1_Destroy(Scene *scene)
// {
//     // Bersihkan resource jika perlu
// }

// // Fungsi Create scene
// Scene *Scene1_Create()
// {
//     Scene1Data *data = new Scene1Data();
//     Scene *scene = new Scene{
//         .data = data,
//         .start = Scene1_Start,
//         .update = Scene1_Update,
//         .destroy = Scene1_Destroy
//     };
//     return scene;
// }
