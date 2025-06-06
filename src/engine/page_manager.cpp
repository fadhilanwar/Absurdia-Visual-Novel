#include "page_manager.hpp"

void m_PageManager_Update(PageManager *);

PageManager *PageManager_Create(EngineWindow *engineWindow, sf::RenderTexture *engineRenderTexture)
{
    Canvas *canvas = Canvas_Create(engineRenderTexture);
    PageManager *pageManager = new PageManager{
        .engineWindow = engineWindow,
        .canvas = canvas,
        .update = m_PageManager_Update};
    return pageManager;
}

void PageManager_GoToPage(PageManager *pageMg, Page *page)
{
    UI *ui = UI_Create();
    page->ui = ui;
    page->pageManager = pageMg;

    if (pageMg->currentPage != nullptr)
    {
        pageMg->isTransitioningPage = true;
        pageMg->pendingPage = page;
        pageMg->pageTransitionProgress = 0.0f;

        delete pageMg->lastPageCanvas;
        pageMg->lastPageCanvas = Canvas_Create();
        Canvas_Copy(pageMg->lastPageCanvas, pageMg->currentPage->ui->canvas);
    }
    else
    {
        pageMg->currentPage = page;
        pageMg->currentPage->start(pageMg->currentPage);
    }
}

void PageManager_PlayMusic(PageManager *pageMg, std::string filePath)
{
    PageManager_StopMusic(pageMg);
    pageMg->musicPlaying = new sf::Music(GetExePath() + filePath);
    pageMg->musicPlaying->setLooping(true);
    pageMg->musicPlaying->play();
}

void PageManager_StopMusic(PageManager *pageMg)
{
    if (pageMg->musicPlaying == nullptr)
        return;

    pageMg->musicPlaying->stop();
    delete pageMg->musicPlaying;
    pageMg->musicPlaying = nullptr;
}

void PageManager_PlaySound(PageManager *pageMg, std::string filePath)
{
    sf::SoundBuffer *buffer = new sf::SoundBuffer;
    buffer->loadFromFile(GetExePath() + filePath);
    sf::Sound *soundPlayer = new sf::Sound(*buffer);
    PageSound *sound = new PageSound{
        .buffer = buffer,
        .soundPlayer = soundPlayer};

    pageMg->soundsPlaying.push_back(sound);
    soundPlayer->play();
}

void m_PageManager_Update(PageManager *pageMg)
{
    if (!pageMg->isTransitioningPage)
    {
        pageMg->currentPage->update(pageMg->currentPage);

        UI_EventTest(pageMg->currentPage->ui, pageMg->engineWindow);
        if (pageMg->currentPage->ui->isDirty)
        {
            UI_DrawAll(pageMg->currentPage->ui);
        }
        if (pageMg->currentPage->ui->isRequireCopy)
        {
            Canvas_Clear(pageMg->canvas);
            Canvas_Copy(pageMg->canvas, pageMg->currentPage->ui->canvas);
            pageMg->currentPage->ui->isRequireCopy = false;
        }
    }
    else
    {
        if (pageMg->pageTransitionProgress == 0.0f)
        {
            UI_ResetCursor(pageMg->currentPage->ui, pageMg->engineWindow);
        }
        else if (pageMg->pageTransitionProgress <= 1.0f)
        {
            // Clear canvas first
            Canvas_Clear(pageMg->canvas);
            // Copy last rendered frame from last page to compositor
            Canvas_Copy(pageMg->canvas, pageMg->lastPageCanvas);
            // Fade in
            Canvas_DrawRect(pageMg->canvas, 0, 0, 1000, 550, sf::Color(0, 0, 0, 255 * pageMg->pageTransitionProgress));
            // Tell compositor to display our canvas
            Canvas_Update(pageMg->canvas);
        }
        else if (pageMg->pageTransitionProgress > 1.0f && pageMg->pageTransitionProgress <= 2.0f)
        {
            if (!pageMg->isPendingPageHasEntered)
            {
                pageMg->pendingPage->start(pageMg->pendingPage);
                pageMg->isPendingPageHasEntered = true;
            }

            pageMg->pendingPage->update(pageMg->pendingPage);

            if (pageMg->pendingPage->ui->isDirty)
            {
                UI_DrawAll(pageMg->pendingPage->ui);
            }

            // Always copy pending page canvas to compositor
            Canvas_Clear(pageMg->canvas);
            Canvas_Copy(pageMg->canvas, pageMg->pendingPage->ui->canvas);
            if (pageMg->pendingPage->ui->isRequireCopy)
            {
                pageMg->pendingPage->ui->isRequireCopy = false;
            }

            // Fade out
            Canvas_DrawRect(pageMg->canvas, 0, 0, 1000, 550, sf::Color(0, 0, 0, 255 - ((pageMg->pageTransitionProgress - 1.0f) * 255)));
            // Tell compositor to display our canvas
            Canvas_Update(pageMg->canvas);
        }
        else if (pageMg->pageTransitionProgress > 2.0f)
        {
            pageMg->currentPage->destroy(pageMg->currentPage);
            delete pageMg->currentPage;

            pageMg->isTransitioningPage = false;
            pageMg->currentPage = pageMg->pendingPage;
            pageMg->pendingPage = nullptr;
            delete pageMg->lastPageCanvas;
            pageMg->lastPageCanvas = nullptr;
            pageMg->isPendingPageHasEntered = false;
        }

        pageMg->pageTransitionProgress += 0.025f;
    }

    // sf::Texture texture = pageMg->currentPage->canvas->renderTexture->getTexture();
    // sf::Sprite sprite(texture);
    // pageMg->canvas->draw(sprite);
    // pageMg->canvas->display();
}
