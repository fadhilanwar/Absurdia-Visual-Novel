#pragma once

#include <queue>
#include <functional>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "../../engine/canvas.hpp"
#include "../../scenes/scene.hpp"

struct Scene;

struct Dialog
{
    bool isLeft;
    bool isQuestion;
    std::string imageFilePath;
    std::string name;
    std::string message;
    std::string question1;
    std::string question2;
    std::string question3;
    std::string question4;
    std::function<void(Scene *)> onFinished;
    Scene *onFinishedParameter;
};


enum SceneManagerState
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
    SceneManagerState state = SceneManagerState::Empty;
    Canvas *canvas;

    Scene *currentScene;
    Scene *pendingScene = nullptr;
    bool isTransitioningScene = false;
    bool isPendingSceneHasEntered = false;
    Canvas *lastSceneCanvas = nullptr;
    float sceneTransitionProgress = 0.0f;

    sf::Texture *backgroundImage = nullptr;

    std::queue<Dialog *> dialogQueue;
    // Dialogue* nowTalkingDialog = nullptr;
    float dialogPersonAnimProgress = 0.f;
    float dialogPersonAnimProgressStep = 0.05f;
    int dialogTextProgress = -1;
    int dialogTextProgressMax = -1;
    int dialogTextWaitTime = 4;
    float dialogArrowXModifier = 0.f;
    bool dialogArrowXModifierReverse = false;
    bool dialogEnterKeyPressed = false;
    // int dialogTextAnimProgressStep = 0;

    sf::Music *musicPlaying = nullptr;

    void (*update)(SceneManager *sceneMg);

    ~SceneManager()
    {
        SceneManager_Destroy(this);
    }
};

SceneManager *SceneManager_Create(Canvas *canvas);
void SceneManager_GoToScene(SceneManager *sceneManager, Scene *scene);
void SceneManager_SetBackground(SceneManager *sceneMg, std::string filePath);
void SceneManager_AddDialog(SceneManager *sceneMg, bool isLeft, std::string name, std::string message, std::string imageFilePath);
void SceneManager_AddDialog(SceneManager *sceneMg, bool isLeft, std::string name, std::string message, std::string imageFilePath, std::function<void(Scene *)> onFinished, Scene *onFinishedParameter);
void SceneManager_AddQuestion(SceneManager *sceneMg, bool isLeft, std::string name, std::string message, std::string question1, std::string question2, std::string question3, std::string question4, std::string imageFilePath);
void SceneManager_PlayMusic(SceneManager *sceneMg, std::string filePath);
void SceneManager_StopMusic(SceneManager *sceneMg);