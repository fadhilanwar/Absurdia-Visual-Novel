#include "scene_manager.hpp"

#include <iostream>
#include <cmath>

void m_SceneManager_Update(SceneManager *sceneMg);

SceneManager *SceneManager_Create(Graph *graph, Canvas *canvas, EngineWindow *engineWindow)
{
    auto sceneMg = new SceneManager{
        .graph = graph,
        .engineWindow = engineWindow,
        .canvas = canvas,
        .update = m_SceneManager_Update};
    return sceneMg;
}

void SceneManager_Log(SceneManager *sceneMg) // UI Dialog
{
    // UI Dialog-
    // Canvas_DrawTexture(sceneMg->canvas, )
    Canvas_DrawImage(sceneMg->canvas, 904, 16, "backgrouund/wp_pilihan", 0.3);                                                                          // sementara
    Canvas_DrawText(sceneMg->canvas, 401, 36, 198, 39, "Log Dialogue", "fonts/Chonky Bunny.ttf", Alignment::Center, 20, sf::Color(255, 251, 239, 255)); // sementara
    Canvas_DrawImage(sceneMg->canvas, 904, 16, "ui/dialogue_log.png");                                                                                  // sementara
}

void SceneManager_LogButton(SceneManager *sceneMg)
{
    // UI Botton
    Canvas_DrawImage(sceneMg->canvas, 904, 16, "ui/logs.png");
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

void SceneManager_GoToScene(SceneManager *sceneMg, int sceneNumber, SceneTransition transition)
{
    Scene *scene = sceneMg->graph->scenes[sceneNumber];
    scene->sceneManager = sceneMg;
    scene->canvas = Canvas_Create();
    scene->ui = UI_Create();
    scene->connectedSceneNumbers = sceneMg->graph->connections[sceneNumber];

    sceneMg->sceneTransition = transition;

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

void SceneManager_AddDialog(SceneManager *sceneMg, std::vector<DialogPerson> persons, std::vector<DialogQuestion> questions, std::string name, std::string message)
{
    SceneManager_AddDialog(sceneMg, persons, questions, name, message, nullptr, nullptr);
}

void SceneManager_AddDialog(SceneManager *sceneMg, std::vector<DialogPerson> persons, std::vector<DialogQuestion> questions, std::string name, std::string message, std::function<void(Scene *)> onFinished, Scene *onFinishedParameter)
{
    Dialog *dialogue = new Dialog{
        .name = name,
        .message = message,
        .persons = persons,
        .questions = questions,
        .onFinished = onFinished,
        .onFinishedParameter = onFinishedParameter};
    sceneMg->dialogQueue.push(dialogue);
}

void SceneManager_PlayMusic(SceneManager *sceneMg, std::string filePath)
{
    SceneManager_StopMusic(sceneMg);
    sceneMg->musicPlaying = new sf::Music(GetExePath() + filePath);
    sceneMg->musicPlaying->setLooping(true);
    sceneMg->musicPlaying->play();
}

void SceneManager_StopMusic(SceneManager *sceneMg)
{
    if (sceneMg->musicPlaying == nullptr)
        return;

    sceneMg->musicPlaying->stop();
    delete sceneMg->musicPlaying;
    sceneMg->musicPlaying = nullptr;
}

void SceneManager_PlaySound(SceneManager *sceneMg, std::string filePath)
{
    sf::SoundBuffer *buffer = new sf::SoundBuffer;
    if (!buffer->loadFromFile(GetExePath() + filePath))
    {
        std::cerr << "Failed to load sound: " << filePath << "\n";
        return;
    }
    sf::Sound *soundPlayer = new sf::Sound(*buffer);
    SceneSound *sound = new SceneSound{
        .buffer = buffer,
        .soundPlayer = soundPlayer};

    sceneMg->soundsPlaying.push_back(sound);
    soundPlayer->play();
}

void m_SceneManager_ResetDialog(SceneManager *sceneMg)
{
    sceneMg->dialogAnimProgress = 0.f;
    sceneMg->dialogAnimProgressStep = 0.05f;
    sceneMg->dialogTextProgress = -1;
    sceneMg->dialogTextProgressMax = -1;
    sceneMg->dialogTextWaitTime = 0;
    sceneMg->dialogAnimProgressAfterText = 0.f;
}

void m_SceneManager_DrawDialogPersons(SceneManager *sceneMg, Dialog *dialog)
{
    for (auto &person : dialog->persons)
    {
        // Kalau gaada animasi
        if (person.animation == DialogPersonAnimation::None)
        {
            Alignment alignment;
            int x = 0;

            if (person.position == DialogPersonPosition::Left)
            {
                x = 65;
                alignment = Alignment::Left;
            }
            else if (person.position == DialogPersonPosition::Center)
            {
                x = 500;
                alignment = Alignment::Center;
            }
            else
            {
                x = 935;
                alignment = Alignment::Right;
            }

            Canvas_DrawImage(sceneMg->currentScene->canvas, x, 0, alignment, person.imageFilePath);
        }
        // Kalau animasinya Slide
        else if (person.animation == DialogPersonAnimation::Slide)
        {
            Alignment alignment;
            int x;
            int y = 0;

            // Posisi gesernya tergantung posisinya
            if (person.position == DialogPersonPosition::Left)
            {
                x = -135 + (200 * (1 - pow(1 - std::min(sceneMg->dialogAnimProgress, 1.0f), 3)));
                alignment = Alignment::Left;
            }
            else if (person.position == DialogPersonPosition::Center)
            {
                x = 500;
                y = 200 - (1 - pow(1 - std::min(sceneMg->dialogAnimProgress, 1.0f), 3)) * 200;
                alignment = Alignment::Center;
            }
            else
            {
                x = 1135 - (200 * (1 - pow(1 - std::min(sceneMg->dialogAnimProgress, 1.0f), 3)));
                alignment = Alignment::Right;
            }

            Canvas_DrawImage(sceneMg->currentScene->canvas, x, y, alignment, person.imageFilePath);
        }
        // Kalau animasinya Fade In
        else if (person.animation == DialogPersonAnimation::FadeIn)
        {
            Alignment alignment;
            int x = 0;

            if (person.position == DialogPersonPosition::Left)
            {
                x = 65;
                alignment = Alignment::Left;
            }
            else if (person.position == DialogPersonPosition::Center)
            {
                x = 500;
                alignment = Alignment::Center;
            }
            else
            {
                x = 935;
                alignment = Alignment::Right;
            }

            Canvas_DrawImage(sceneMg->currentScene->canvas, x, 0, alignment, person.imageFilePath, std::min(sceneMg->dialogAnimProgress / 2.0f, 1.0f));
        }
        // Kalau animasinya Fade Out
        else if (person.animation == DialogPersonAnimation::FadeOut)
        {
            Alignment alignment;
            int x = 0;

            if (person.position == DialogPersonPosition::Left)
            {
                x = 65;
                alignment = Alignment::Left;
            }
            else if (person.position == DialogPersonPosition::Center)
            {
                x = 500;
                alignment = Alignment::Center;
            }
            else
            {
                x = 935;
                alignment = Alignment::Right;
            }

            Canvas_DrawImage(sceneMg->currentScene->canvas, x, 0, alignment, person.imageFilePath, 1.0f - std::min(sceneMg->dialogAnimProgress / 2.0f, 1.0f));
        }
        // Kalau animasinya Shake
        else if (person.animation == DialogPersonAnimation::Shake)
        {
            Alignment alignment;
            int x = 0;
            int y = 0;

            if (person.position == DialogPersonPosition::Left)
            {
                x = 65;
                alignment = Alignment::Left;
            }
            else if (person.position == DialogPersonPosition::Center)
            {
                x = 500;
                alignment = Alignment::Center;
            }
            else
            {
                x = 935;
                alignment = Alignment::Right;
            }

            float divided = sceneMg->dialogAnimProgress / 0.25;
            float result = divided - ceil(divided - 1);
            if (result <= 0.5)
            {
                x += -(result * 20);
            }
            else
            {
                x += -((-2 * result + 2) * 10);
            }

            Canvas_DrawImage(sceneMg->currentScene->canvas, x, 0, alignment, person.imageFilePath);
        }
        // Kalau animasinya Pop
        else if (person.animation == DialogPersonAnimation::Pop)
        {
            Alignment alignment;
            int x = 0;
            int y = 0;

            if (person.position == DialogPersonPosition::Left)
            {
                x = 65;
                alignment = Alignment::Left;
            }
            else if (person.position == DialogPersonPosition::Center)
            {
                x = 500;
                alignment = Alignment::Center;
            }
            else
            {
                x = 935;
                alignment = Alignment::Right;
            }

            if (sceneMg->dialogAnimProgress <= 0.5f)
            {
                y = -((1 - pow(1 - sceneMg->dialogAnimProgress * 2, 3)) * 50);
            }
            else if (sceneMg->dialogAnimProgress <= 1.0f)
            {
                y = -((-2 * sceneMg->dialogAnimProgress + 2) * 50);
            }

            Canvas_DrawImage(sceneMg->currentScene->canvas, x, y, alignment, person.imageFilePath);
        }
        else if (person.animation == DialogPersonAnimation::Joget)
        {
            Alignment alignment;
            int x = 0;
            int y = 0;

            if (person.position == DialogPersonPosition::Left)
            {
                x = 65;
                alignment = Alignment::Left;
            }
            else if (person.position == DialogPersonPosition::Center)
            {
                x = 500;
                alignment = Alignment::Center;
            }
            else
            {
                x = 935;
                alignment = Alignment::Right;
            }

            float divided = sceneMg->dialogAnimProgress / 1.75;
            float result = divided - ceil(divided - 1);
            if (result <= 0.5)
            {
                y = -(sin((result * 2) * M_PI / 2) * 30);
            }
            else
            {
                y = -((-2 * result + 2) * 30);
            }

            Canvas_DrawImage(sceneMg->currentScene->canvas, x, y, alignment, person.imageFilePath);
        }
    }
}

void m_SceneManager_DrawDialogQuestions(SceneManager *sceneMg, Dialog *dialog, bool &requestNextDialog)
{
    if (sceneMg->dialogTextProgress == 0 && !dialog->questions.empty())
    {
        if (sceneMg->dialogAnimProgressAfterText == 0.f)
            sceneMg->dialogAnimProgressAfterText = sceneMg->dialogAnimProgress;

        float _dialogAnimProgress = sceneMg->dialogAnimProgress - sceneMg->dialogAnimProgressAfterText;
        if (_dialogAnimProgress > 1.f)
        {
            // Dapatkan posisi mouse
            sf::Vector2i mousePos = sf::Mouse::getPosition(sceneMg->engineWindow->window);

            int questionNumber = 0;
            for (auto &question : dialog->questions)
            {
                float questionStartProgress = questionNumber * 0.5f;
                if (_dialogAnimProgress > questionStartProgress)
                {
                    float questionProgress = std::min((_dialogAnimProgress - questionStartProgress) / 2, 1.f);
                    int questionY = 223 + (questionNumber * (31 + 15)) - (EaseOutCubic(questionProgress) * 100);

                    bool isHovered = false;
                    if (mousePos.x >= 381 && mousePos.x <= 619 &&
                        mousePos.y >= questionY && mousePos.y <= questionY + 31)
                    {
                        isHovered = true;
                        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                        {
                            if (question.onAnswered != nullptr)
                                question.onAnswered(question.onAnsweredParameter);
                            requestNextDialog = true;
                        }
                    }

                    Canvas_DrawImage(sceneMg->currentScene->canvas, 381, questionY, "dialog/question_bg.png", questionProgress, 0.f, isHovered ? 1.05f : 1.f);
                    Canvas_DrawText(sceneMg->currentScene->canvas, 381, questionY, 238, 31, question.question, "fonts/Chonky Bunny.ttf", Alignment::Center, 20, sf::Color(255, 251, 239, questionProgress * 255));
                }
                questionNumber++;
            }
        }
    }
}

void m_SceneManager_DrawDialogContent(SceneManager *sceneMg, Dialog *dialog, bool &requestNextDialog)
{
    // Kalau misalkan isi dialognya kosong, jangan gambar dialognya,
    // langsung gambar questionsnya aja
    if (!dialog->message.empty())
    {
        float dialogBgProgress = (sceneMg->isFirstDialog ? EaseOutBack(std::min((sceneMg->dialogAnimProgress / 2.f), 1.f)) : 1);
        int dialogBgYModifier = 300 * dialogBgProgress;

        Canvas_DrawImage(sceneMg->currentScene->canvas, 47, 694 - dialogBgYModifier, "dialog/dialog_bg.png", 1.f, 0.f, std::min(dialogBgProgress * 1.1f, 1.f));
        Canvas_DrawImage(sceneMg->currentScene->canvas, 381, 677 - dialogBgYModifier, "dialog/nametag.png");
        Canvas_DrawText(sceneMg->currentScene->canvas, 381 + 17, 677 + 5 - dialogBgYModifier, 204, 21, dialog->name, "fonts/Chonky Bunny.ttf", Alignment::Center, 20, sf::Color::White);

        // Gambar teks dialog sama questions (kalau ada)
        if (sceneMg->dialogAnimProgress >= 0.8f)
        {
            // Gambar teks dialog
            std::string cuttedMessage = dialog->message.substr(0, sceneMg->dialogTextProgressMax - sceneMg->dialogTextProgress);
            Canvas_DrawText(sceneMg->currentScene->canvas, 72, 721 - dialogBgYModifier, cuttedMessage, "fonts/Chonky Bunny.ttf", 24, sf::Color(50, 41, 47));

            // Lupa ini buat apa
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

            // Gambar questions (kalau ada)
            m_SceneManager_DrawDialogQuestions(sceneMg, dialog, requestNextDialog);
        }
    }
    else
    {
        // Gambar questions (kalau ada)
        m_SceneManager_DrawDialogQuestions(sceneMg, dialog, requestNextDialog);
    }
}

void m_SceneManager_ProcessDialog(SceneManager *sceneMg)
{
    Dialog *dialog = sceneMg->dialogQueue.front();
    bool requestSkipDialog;

    // Ketika dialog ini pertama kali digambar,
    // atur semua variabel yang dibutuhkan buat ngegambar teks isi dialog
    if (sceneMg->dialogTextProgress == -1)
    {
        sceneMg->dialogTextProgressMax = dialog->message.length();
        sceneMg->dialogTextProgress = dialog->message.length();
    }

    // Gambar semua orangnya + dianimasiin
    m_SceneManager_DrawDialogPersons(sceneMg, dialog);

    // Kalau di scenenya ada fungsi updateAfterPersons, panggil
    if (sceneMg->currentScene->updateAfterPersons != nullptr)
        sceneMg->currentScene->updateAfterPersons(sceneMg->currentScene);

    // Gambar background dialog, teks nama orang, teks isi dialog, sama questions
    // kalau salah satu question dijawab, requestSkipDialog akan menjadi true
    m_SceneManager_DrawDialogContent(sceneMg, dialog, requestSkipDialog);

    // Kalau tidak ada question apa-apa,
    // atur requestSkipDialog = true apabila keyboard enter dipencet
    if (dialog->questions.empty() && (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && !sceneMg->dialogEnterKeyPressed))
    {
        requestSkipDialog = true;
    }

    // Kalau requestSkipDialog = true, pindah ke dialog berikutnya
    // Kalau kagak yaudah
    if (requestSkipDialog)
    {
        bool dontSetFirstDialog;

        sceneMg->dialogEnterKeyPressed = true;

        Dialog *dialog = sceneMg->dialogQueue.front();
        if (dialog->onFinished != nullptr)
        {
            dialog->onFinished(dialog->onFinishedParameter);
        }
        if (dialog->message.empty())
        {
            sceneMg->isFirstDialog = true;
            dontSetFirstDialog = true;
        }
        sceneMg->dialogQueue.pop();
        delete dialog;

        m_SceneManager_ResetDialog(sceneMg);

        if (sceneMg->dialogQueue.empty())
        {
            sceneMg->state = SceneManagerState::Rest;
            sceneMg->isFirstDialog = true;
        }
        else
        {
            if (!dontSetFirstDialog)
                sceneMg->isFirstDialog = false;
            // m_SceneManager_DrawDialog(sceneMg);
            // sceneMg->dialogAnimProgress += sceneMg->dialogAnimProgressStep;
        }
    }
}

void m_SceneManager_Update(SceneManager *sceneMg)
{
    // Hapus semua sound yang udah selesai playing
    // if (!sceneMg->soundsPlaying.empty())
    // {
    for (int i = 0; i < sceneMg->soundsPlaying.size(); i++)
    {
        SceneSound *sound = sceneMg->soundsPlaying[i];
        if (sound->soundPlayer->getStatus() == sf::SoundSource::Status::Stopped)
        {
            sceneMg->soundsPlaying.erase(sceneMg->soundsPlaying.begin() + i);
            delete sound;
        }
    }
    // }

    // Animasiin transisi scene kalau lagi ngetransisiin scene
    if (sceneMg->isTransitioningScene)
    {
        if (sceneMg->sceneTransition == SceneTransition::None)
        {
            // Mulai pending scene
            sceneMg->pendingScene->start(sceneMg->pendingScene);

            // sceneMg->pendingScene->childScenes =

            // Hapus isi canvas
            Canvas_Clear(sceneMg->canvas);

            // Gambar background image kalau ada
            if (sceneMg->backgroundImage)
            {
                Canvas_DrawTexture(sceneMg->pendingScene->canvas, 0, 0, sceneMg->backgroundImage);
            }

            // Kasih tau pending scene bahwa ada update
            sceneMg->pendingScene->update(sceneMg->pendingScene);

            // Copy canvas scene ke canvas scene_manager
            Canvas_Update(sceneMg->pendingScene->canvas);
            Canvas_Copy(sceneMg->canvas, sceneMg->pendingScene->canvas);
            Canvas_Update(sceneMg->canvas);

            // Hapus scene sebelumnya
            sceneMg->currentScene->destroy(sceneMg->currentScene);
            delete sceneMg->currentScene;

            sceneMg->isTransitioningScene = false;
            sceneMg->currentScene = sceneMg->pendingScene;
            sceneMg->pendingScene = nullptr;
            // delete sceneMg->lastSceneCanvas;
            // sceneMg->lastSceneCanvas = nullptr;
            sceneMg->isPendingSceneHasEntered = false;
        }
        else if (sceneMg->sceneTransition == SceneTransition::Fade)
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
                if (sceneMg->pendingScene->updateAfterPersons != nullptr)
                    sceneMg->pendingScene->updateAfterPersons(sceneMg->pendingScene);

                // Copy canvas scene ke canvas scene_manager
                Canvas_Update(sceneMg->pendingScene->canvas);
                Canvas_Copy(sceneMg->canvas, sceneMg->pendingScene->canvas);

                // Fade out
                Canvas_DrawRect(sceneMg->canvas, 0, 0, 1000, 550, sf::Color(0, 0, 0, 255 - ((sceneMg->sceneTransitionProgress - 1.0f) * 255)));
                // Suruh compositor untuk menampilkan canvas
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
        UI_EventTest(sceneMg->currentScene->ui, sceneMg->engineWindow);
        // Gambar UI
        if (sceneMg->currentScene->ui->isDirty)
        {
            UI_DrawAll(sceneMg->currentScene->ui);
        }
        Canvas_Copy(sceneMg->currentScene->canvas, sceneMg->currentScene->ui->canvas);

        // Apabila ada dialog
        if (!sceneMg->dialogQueue.empty())
        {
            if (sceneMg->dialogEnterKeyPressed && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
                sceneMg->dialogEnterKeyPressed = false;
            if (sceneMg->state != SceneManagerState::Talking)
                sceneMg->state = SceneManagerState::Talking;

            m_SceneManager_ProcessDialog(sceneMg);
            sceneMg->dialogAnimProgress += sceneMg->dialogAnimProgressStep;
        }
        else
        {
            if (sceneMg->currentScene->updateAfterPersons != nullptr)
                sceneMg->currentScene->updateAfterPersons(sceneMg->currentScene);
        }

        if (sceneMg->isLogOpen)
        {

            SceneManager_Log(sceneMg);
        }
        else
        {
            SceneManager_LogButton(sceneMg);
        }
        // Copy canvas scene ke canvas scene_manager
        Canvas_Update(sceneMg->currentScene->canvas);
        Canvas_Copy(sceneMg->canvas, sceneMg->currentScene->canvas);

        Canvas_Update(sceneMg->canvas);
    }
}