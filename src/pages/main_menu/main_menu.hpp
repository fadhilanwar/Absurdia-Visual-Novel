#pragma once

#include "../page.hpp"
// #include "../game/game.hpp"
#include "../about/about.hpp"

struct MainMenuPageData
{
    Text *heading;
};

Page *MainMenuPG_Create();