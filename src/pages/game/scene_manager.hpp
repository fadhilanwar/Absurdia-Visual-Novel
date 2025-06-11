#pragma once

#include <queue>
#include <functional>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "../../engine/canvas.hpp"
#include "../../engine/ui.hpp"
#include "../../scenes/scene.hpp"
#include "graph.hpp"

struct Scene;
struct Graph;

//
// ============================
// ========== Dialog ==========
// ============================
//

// Posisi orang di dialognya
enum class DialogPersonPosition
{
    Left,
    Center,
    Right
};
// Animasi orangnya
enum class DialogPersonAnimation
{
    None, // Gausah dikasih animasi
    Slide, // Masuk geser dari kiri/kanan/bawah tergantung posisinya dimana
    FadeIn, // Opacitynya 0 -> 1
    FadeOut, // Opacitynya 1 -> 0
    Shake, // Geter
    Pop, // Loncat dikit
    Joget, // Joget
};
// Data orangnya
struct DialogPerson
{
    std::string imageFilePath;
    DialogPersonPosition position;
    DialogPersonAnimation animation = DialogPersonAnimation::None;
};

// Data pertanyaan dialognya
struct DialogQuestion
{
    std::string question;

    // Callback kalau question dijawab
    std::function<void(Scene *)> onAnswered;
    Scene *onAnsweredParameter;
};

// Data dialog
struct Dialog
{
    std::string name;
    std::string message;
    std::vector<DialogPerson> persons;
    std::vector<DialogQuestion> questions;

    // Callback kalau dialog udah beres
    std::function<void(Scene *)> onFinished;
    Scene *onFinishedParameter;
};

//
// =============================
// =========== Sound ===========
// =============================
//

struct SceneSound
{
    sf::SoundBuffer *buffer;
    sf::Sound *soundPlayer;

    ~SceneSound()
    {
        delete buffer;
        delete soundPlayer;
    }
};

//
// =============================
// ======= Scene Manager =======
// =============================
//

enum class SceneTransition
{
    None,
    Fade
};

enum class SceneManagerState
{
    Empty,
    Navigating,
    Talking,
    Rest
};

struct SceneManager;
void SceneManager_Destroy(SceneManager *sceneManager);
struct SceneManager
{
    std::string saveName;

    Graph *graph;
    
    SceneManagerState state = SceneManagerState::Empty;
    EngineWindow *engineWindow;
    Canvas *canvas;
    
    Scene *currentScene;
    int currentSceneNumber;
    Scene *pendingScene = nullptr;
    SceneTransition sceneTransition = SceneTransition::None;
    bool isTransitioningScene = false;
    bool isPendingSceneHasEntered = false;
    // Canvas *lastSceneCanvas = nullptr;
    float sceneTransitionProgress = 0.0f;

    sf::Texture *backgroundImage = nullptr;

    std::queue<Dialog *> dialogQueue;
    // Dialogue* nowTalkingDialog = nullptr;
    bool isFirstDialog = true;
    float dialogAnimProgress = 0.f;
    float dialogAnimProgressStep = 0.05f;
    int dialogTextProgress = -1;
    int dialogTextProgressMax = -1;
    int dialogTextWaitTime = 4;
    float dialogAnimProgressAfterText = 0.f;
    bool dialogEnterKeyPressed = false;
    // int dialogTextAnimProgressStep = 0;

    bool isSaveButtonClicked;

    sf::Music *musicPlaying = nullptr;
    std::vector<SceneSound *> soundsPlaying;

    void (*update)(SceneManager *sceneMg);

    ~SceneManager()
    {
        SceneManager_Destroy(this);
    }
};

// Buat SceneManager (jangan dipanggil dipanggil kecuali dari game.cpp)
SceneManager *SceneManager_Create(std::string saveName, Graph *graph, Canvas *canvas, EngineWindow *engineWindow);

// Pindah scene
void SceneManager_GoToScene(SceneManager *sceneManager, int sceneNumber, SceneTransition transition);
// Atur background scene
void SceneManager_SetBackground(SceneManager *sceneMg, std::string filePath);

// Tambah dialog
void SceneManager_AddDialog(SceneManager *sceneMg, std::vector<DialogPerson> persons, std::vector<DialogQuestion> questions, std::string name, std::string message);
// Tambah dialog (dengan callback ketika dialognya beres)
void SceneManager_AddDialog(SceneManager *sceneMg, std::vector<DialogPerson> persons, std::vector<DialogQuestion> questions, std::string name, std::string message, std::function<void(Scene *)> onFinished, Scene *onFinishedParameter);

// Main musik (kalau ada yang panggil ini tapi masih ada musik yang diplay, musiknya bakal langsung distop ya kids)
void SceneManager_PlayMusic(SceneManager *sceneMg, std::string filePath);
// Stop musik
void SceneManager_StopMusic(SceneManager *sceneMg);

// Main suara (bebas mau panggil berapa kali juga, ga kayak musik)
void SceneManager_PlaySound(SceneManager *sceneMg, std::string filePath);

// Tampilan log dialog
void SceneManager_Log(SceneManager *sceneMg);

// Tombol untuk membuka log dialog
void SceneManager_LogButton(SceneManager *sceneMg);