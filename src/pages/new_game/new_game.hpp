#pragma once

#include "../page.hpp"

struct NewGamePageData
{
    UIElement *inputNamaKarakter;
};

Page *NewGamePG_Create();
void NewGamePG_Start(Page *page);
void NewGamePG_Update(Page *page);
void NewGamePG_Destroy(Page *page);