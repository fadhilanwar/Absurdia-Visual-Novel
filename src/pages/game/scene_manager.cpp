#include "scene_manager.hpp"
#include <iostream>

void m_SceneManager_Update(SceneManager *sceneMg);

SceneManager *SceneManager_Create(Canvas *canvas, sf::Window *window)
{
    auto sceneMg = new SceneManager{
        .window = window,
        .canvas = canvas,
        .update = m_SceneManager_Update};
    return sceneMg;
}

void SceneManager_Destroy(SceneManager *sceneMg)
{
    sceneMg->currentScene->destroy(sceneMg->currentScene);
    delete sceneMg->currentScene;

    delete sceneMg->canvas;
    delete sceneMg->backgroundImage;

    while (!sceneMg->dialogQueue.empty())
    {
        Dialog *dialog = sceneMg->dialogQueue.front();
        delete dialog;
        sceneMg->dialogQueue.pop();
    }

    delete sceneMg->musicPlaying;
}

void SceneManager_GoToScene(SceneManager *sceneMg, Scene *scene)
{
    scene->sceneManager = sceneMg;
    scene->canvas = Canvas_Create();
    scene->ui = UI_Create();

    if (sceneMg->currentScene != nullptr)
    {
        sceneMg->isTransitioningScene = true;
        sceneMg->pendingScene = scene;
        sceneMg->sceneTransitionProgress = 0.0f;

        // delete sceneMg->lastSceneCanvas;
        // sceneMg->lastSceneCanvas = Canvas_Create();
        // Canvas_Copy(sceneMg->lastSceneCanvas, sceneMg->currentScene->canvas);
    }
    else
    {
        sceneMg->currentScene = scene;
        sceneMg->currentScene->start(sceneMg->currentScene);
    }
}

void SceneManager_SetBackground(SceneManager *sceneMg, std::string filePath)
{
    if (sceneMg->backgroundImage != nullptr)
    {
        delete sceneMg->backgroundImage;
    }

    sf::Texture *image = new sf::Texture();
    if (!image->loadFromFile(GetExePath() + filePath))
    {
        std::cout << "Gagal load file background, file path: " << filePath << "\n";
    }

    sceneMg->backgroundImage = image;
}

void SceneManager_AddDialog(SceneManager *sceneMg, bool isLeft, std::string name, std::string message, std::string imageFilePath)
{
    SceneManager_AddDialog(sceneMg, isLeft, name, message, imageFilePath, nullptr, nullptr);
}

void SceneManager_AddDialog(SceneManager *sceneMg, bool isLeft, std::string name, std::string message, std::string imageFilePath, std::function<void(Scene *)> onFinished, Scene *onFinishedParameter)
{
    Dialog *dialogue = new Dialog{
        .isLeft = isLeft,
        .isQuestion = false,
        .imageFilePath = imageFilePath,
        .name = name,
        .message = message,
        .onFinished = onFinished,
        .onFinishedParameter = onFinishedParameter};
    sceneMg->dialogQueue.push(dialogue);
}

void SceneManager_AddQuestion(SceneManager *sceneMg, bool isLeft, std::string name, std::string message, std::string question1, std::string question2, std::string question3, std::string question4, std::string imageFilePath)
{
    Dialog *dialogue = new Dialog{
        .isLeft = isLeft,
        .isQuestion = true,
        .imageFilePath = imageFilePath,
        .name = name,
        .message = message,
        .question1 = question1,
        .question2 = question2,
        .question3 = question3,
        .question4 = question4};
    sceneMg->dialogQueue.push(dialogue);
}

void SceneManager_PlayMusic(SceneManager *sceneMg, std::string filePath)
{
    SceneManager_StopMusic(sceneMg);
    sceneMg->musicPlaying = new sf::Music(GetExePath() + filePath);
    sceneMg->musicPlaying->play();
}

void SceneManager_PlaySound(SceneManager *sceneMg, std::string filePath)
{
    sf::SoundBuffer *buffer = new sf::SoundBuffer;
    buffer->loadFromFile(GetExePath() + filePath);
    sf::Sound *soundPlayer = new sf::Sound(*buffer);
    Sound *sound = new Sound{
        .buffer = buffer,
        .soundPlayer = soundPlayer};

    sceneMg->soundsPlaying.push_back(sound);
    soundPlayer->play();
}

void SceneManager_StopMusic(SceneManager *sceneMg)
{
    if (sceneMg->musicPlaying == nullptr)
        return;

    sceneMg->musicPlaying->stop();
    delete sceneMg->musicPlaying;
    sceneMg->musicPlaying = nullptr;
}

void m_SceneManager_DrawDialog(SceneManager *sceneMg)
{
    Dialog *dialogue = sceneMg->dialogQueue.front();

    if (sceneMg->dialogTextProgress == -1)
    {
        sceneMg->dialogTextProgressMax = dialogue->message.length();
        sceneMg->dialogTextProgress = dialogue->message.length();
    }

    if (dialogue->isLeft)
    {
        int x = -180 + (200 * sceneMg->dialogPersonAnimProgress);
        Canvas_DrawImage(sceneMg->currentScene->canvas, x, 80, dialogue->imageFilePath);
    }
    else
    {
        int x = 700 - (200 * sceneMg->dialogPersonAnimProgress);
        Canvas_DrawImage(sceneMg->currentScene->canvas, x, 80, dialogue->imageFilePath);
    }

    int nametagX = dialogue->isLeft ? 752 : 46;
    int modifierY = 100 * std::min((sceneMg->dialogPersonAnimProgress * 2.f), 1.f);

    Canvas_DrawRect(sceneMg->currentScene->canvas, 48, 480 - modifierY, 904, 144, sf::Color(0, 0, 0, 150));
    Canvas_DrawImage(sceneMg->currentScene->canvas, nametagX, 345, "nametag.png");
    Canvas_DrawText(sceneMg->currentScene->canvas, nametagX + 14, 350, dialogue->name, TextStyle::BOLD, 20, sf::Color::White);

    if (sceneMg->dialogPersonAnimProgress >= 0.8f)
    {
        std::string cuttedMessage = dialogue->message.substr(0, sceneMg->dialogTextProgressMax - sceneMg->dialogTextProgress);
        Canvas_DrawText(sceneMg->currentScene->canvas, 72, 504 - modifierY, cuttedMessage, TextStyle::NORMAL, 24, sf::Color::White);

        if (sceneMg->dialogTextWaitTime > 3)
        {
            if (sceneMg->dialogTextProgress - 2 < 0)
            {
                sceneMg->dialogTextProgress = 0;
            }
            else
            {
                sceneMg->dialogTextProgress -= 2;
            }
            sceneMg->dialogTextWaitTime = 0;
        }
        else
        {
            sceneMg->dialogTextWaitTime++;
        }
    }
    if (sceneMg->dialogPersonAnimProgress >= 1.0f)
    {
        if (sceneMg->dialogArrowXModifier >= 10.0f)
        {
            sceneMg->dialogArrowXModifierReverse = true;
        }
        else if (sceneMg->dialogArrowXModifier <= -10.0f)
        {
            sceneMg->dialogArrowXModifierReverse = false;
        }
        sceneMg->dialogArrowXModifier += 1.0f * sceneMg->dialogArrowXModifierReverse ? -1 : 1;

        Canvas_DrawImage(sceneMg->currentScene->canvas, 918 + sceneMg->dialogArrowXModifier, 500, "arrow_dialog.png");
    }
}

void m_SceneManager_ResetDialog(SceneManager *sceneMg)
{
    sceneMg->dialogPersonAnimProgress = 0.f;
    sceneMg->dialogPersonAnimProgressStep = 0.05f;
    sceneMg->dialogTextProgress = -1;
    sceneMg->dialogTextProgressMax = -1;
    sceneMg->dialogTextWaitTime = 4;
    sceneMg->dialogArrowXModifier = 0.f;
    sceneMg->dialogArrowXModifierReverse = false;
}

void m_SceneManager_Update(SceneManager *sceneMg)
{
    // Hapus semua sound yang udah selesai playing
    if (!sceneMg->soundsPlaying.empty())
    {
        for (auto it = sceneMg->soundsPlaying.begin(); it != sceneMg->soundsPlaying.end(); it++)
        {
            Sound *sound = *it;
            if (sound->soundPlayer->getStatus() == sf::SoundSource::Status::Stopped)
            {
                sceneMg->soundsPlaying.erase(it);
                delete sound;
            }
        }
    }

    if (sceneMg->isTransitioningScene)
    {
        if (sceneMg->sceneTransitionProgress <= 1.0f)
        {
            // Clear canvas first
            Canvas_Clear(sceneMg->canvas);
            // Copy last rendered frame from last page to compositor
            Canvas_Copy(sceneMg->canvas, sceneMg->currentScene->canvas);
            // Fade in
            Canvas_DrawRect(sceneMg->canvas, 0, 0, 1000, 550, sf::Color(0, 0, 0, 255 * sceneMg->sceneTransitionProgress));
            // Tell compositor to display our canvas
            Canvas_Update(sceneMg->canvas);
        }
        else if (sceneMg->sceneTransitionProgress > 1.0f && sceneMg->sceneTransitionProgress <= 2.0f)
        {
            if (!sceneMg->isPendingSceneHasEntered)
            {
                sceneMg->pendingScene->start(sceneMg->pendingScene);
                sceneMg->isPendingSceneHasEntered = true;
            }

            Canvas_Clear(sceneMg->canvas);

            // Gambar background image kalau ada
            if (sceneMg->backgroundImage)
            {
                Canvas_DrawTexture(sceneMg->pendingScene->canvas, 0, 0, sceneMg->backgroundImage);
            }

            // Kasih tau scene bahwa ada update
            sceneMg->pendingScene->update(sceneMg->pendingScene);

            // Copy canvas scene ke canvas scene_manager
            Canvas_Update(sceneMg->pendingScene->canvas);
            Canvas_Copy(sceneMg->canvas, sceneMg->pendingScene->canvas);

            // Fade out
            Canvas_DrawRect(sceneMg->canvas, 0, 0, 1000, 550, sf::Color(0, 0, 0, 255 - ((sceneMg->sceneTransitionProgress - 1.0f) * 255)));
            // Tell compositor to display our canvas
            Canvas_Update(sceneMg->canvas);
        }
        else if (sceneMg->sceneTransitionProgress > 2.0f)
        {
            sceneMg->currentScene->destroy(sceneMg->currentScene);
            delete sceneMg->currentScene;

            sceneMg->isTransitioningScene = false;
            sceneMg->currentScene = sceneMg->pendingScene;
            sceneMg->pendingScene = nullptr;
            // delete sceneMg->lastSceneCanvas;
            // sceneMg->lastSceneCanvas = nullptr;
            sceneMg->isPendingSceneHasEntered = false;
        }

        sceneMg->sceneTransitionProgress += 0.025f;
    }
    else
    {
        Canvas_Clear(sceneMg->canvas);
        Canvas_Clear(sceneMg->currentScene->canvas);

        // Gambar background image kalau ada
        if (sceneMg->backgroundImage)
        {
            Canvas_DrawTexture(sceneMg->currentScene->canvas, 0, 0, sceneMg->backgroundImage);
        }

        // Kasih tau scene bahwa ada update
        sceneMg->currentScene->update(sceneMg->currentScene);

        // Hit test UI
        UI_HitTest(sceneMg->currentScene->ui, sceneMg->window);
        // Gambar UI
        if (sceneMg->currentScene->ui->isDirty)
        {
            UI_DrawAll(sceneMg->currentScene->ui);
        }
        Canvas_Copy(sceneMg->currentScene->canvas, sceneMg->currentScene->ui->canvas);

        // Apabila ada dialog
        if (!sceneMg->dialogQueue.empty())
        {
            // Kalau enter dipencet, pindah ke dialog berikutnya
            // Kalau kagak suruh draw dialognya
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
            {
                if (!sceneMg->dialogEnterKeyPressed)
                {
                    std::cout << "Enter pressed!\n";
                    sceneMg->dialogEnterKeyPressed = true;

                    Dialog *dialog = sceneMg->dialogQueue.front();
                    if (dialog->onFinished != nullptr)
                    {
                        dialog->onFinished(dialog->onFinishedParameter);
                    }
                    sceneMg->dialogQueue.pop();
                    delete dialog;

                    if (sceneMg->dialogQueue.empty())
                    {
                        sceneMg->state = SceneManagerState::Rest;
                    }

                    m_SceneManager_ResetDialog(sceneMg);
                }
            }
            else
            {
                if (sceneMg->dialogEnterKeyPressed)
                    sceneMg->dialogEnterKeyPressed = false;
                if (sceneMg->state != SceneManagerState::Talking)
                    sceneMg->state = SceneManagerState::Talking;

                m_SceneManager_DrawDialog(sceneMg);
                if (sceneMg->dialogPersonAnimProgress < 1.0f)
                {
                    sceneMg->dialogPersonAnimProgress += sceneMg->dialogPersonAnimProgressStep;
                }
            }
        }

        // Copy canvas scene ke canvas scene_manager
        Canvas_Update(sceneMg->currentScene->canvas);
        Canvas_Copy(sceneMg->canvas, sceneMg->currentScene->canvas);

        Canvas_Update(sceneMg->canvas);
    }
}