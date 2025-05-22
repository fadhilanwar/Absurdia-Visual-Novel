#include <iostream>
#include <SFML/Audio.hpp>


#include "engine/engine.hpp"
#include "pages/main_menu/main_menu.hpp"
// #include "pages/game/game.hpp"

int main()
{
    Engine* engine = Engine_Create();

    // Page *gamePage = GameST_Create();
    Page *mainMenuPage = MainMenuPG_Create();
    PageManager_GoToScene(engine->pageManager, mainMenuPage);
    Engine_Run(engine);
}