#include "game.hpp"

#include <iostream>

#include "../../scenes/scene_1/scene_1_part2.hpp"
#include "../../scenes/scene_1/scene_1_part3.hpp"
#include "../../scenes/scene_2/scene_2.hpp"
#include "../../scenes/scene_3/scene_3.hpp"
#include "../../scenes/scene_4/scene4_part1.hpp"
#include "../../scenes/scene_4/scene4_part2.hpp"
#include "../../scenes/scene_5/scene_5.hpp"
#include "../../scenes/scene_6/scene_6.hpp"
#include "../../scenes/scene_7/scene_7.hpp"
#include "../../scenes/scene_8/scene_8.hpp"
#include "../../scenes/scene_9/scene_9.hpp"
#include "../../scenes/scene_10/scene_10.hpp"
#include "../../scenes/scene_11/scene_11.hpp"
#include "../../scenes/scene_12/scene_12.hpp"
#include "../../scenes/scene_13/scene_13.hpp"
#include "../../scenes/scene_14/scene_14.hpp"
#include "../../scenes/scene_15/scene_15.hpp"
#include "../../scenes/scene_16/scene_16.hpp"
#include "../../scenes/scene_17/scene_17.hpp"
#include "../../scenes/scene_18/scene_18.hpp"
#include "../../scenes/scene_19/scene_19.hpp"
#include "../../scenes/scene_20/scene_20.hpp"
#include "../../scenes/scene_21/scene_21.hpp"
#include "../../scenes/scene_22/scene_22.hpp"
#include "../../scenes/scene_23/scene_23.hpp"
#include "../../scenes/scene_24/scene_24.hpp"
#include "../../scenes/scene_25/scene_25.hpp"
#include "../../scenes/scene_26/scene_26.hpp"
#include "../../scenes/scene_27/scene_27.hpp"
#include "../../scenes/scene_28/scene_28.hpp"
#include "../../scenes/scene_29/scene_29.hpp"
#include "../../scenes/scene_30/scene_30.hpp"
#include "../../scenes/scene_31/scene_31.hpp"
#include "../../scenes/scene_32/scene_32.hpp"
#include "../../scenes/ending_a/ending_a.hpp"
#include "../../scenes/ending_b/ending_b.hpp"
#include "../../scenes/ending_c/ending_c.hpp"
#include "../../scenes/ending_d/ending_d.hpp"


void GamePG_Start(Page *page)
{
    GamePageData *data = (GamePageData *)page->data;

    Graph *graph = Graph_Create({
        Scene1Part2_Create(),
        Scene1Part3_Create(),
        Scene2_Create(),
        Scene3_Create(),
        Scene4Part1_Create(),
        Scene4Part2_Create(),
        Scene5_Create(),
        Scene6_Create(),
        Scene7_Create(),
        Scene8_Create(),
        Scene9_Create(),
        Scene10_Create(),
        Scene11_Create(),
        Scene12_Create(),
        Scene13_Create(),
        Scene14_Create(),
        Scene15_Create(),
        Scene16_Create(),
        Scene17_Create(),
        Scene18_Create(),
        Scene19_Create(),
        Scene20_Create(),
        Scene21_Create(),
        Scene22_Create(),
        Scene23_Create(),
        Scene24_Create(),
        Scene25_Create(),
        Scene26_Create(),
        Scene27_Create(),
        Scene28_Create(),
        Scene29_Create(),
        Scene30_Create(),
        Scene31_Create(),
        Scene32_Create(),
        Ending_a_Create(),
        Ending_b_Create(),
        Ending_c_Create(),
        Ending_d_Create(),
    });

    // Scene 1 (Part 1)
    Graph_AddConnection(graph, 0, 1);
    // Scene 1 (Part 2)
    Graph_AddConnection(graph, 1, 2);

    // Scene 2
    Graph_AddConnection(graph, 2, 3);

    // Scene 3
    Graph_AddConnection(graph, 3, 34);
    Graph_AddConnection(graph, 3, 4);

    // Scene 4 (Part 1)
    Graph_AddConnection(graph, 4, 5);
    // Scene 4 (Part 2)
    Graph_AddConnection(graph, 5, 6);
    Graph_AddConnection(graph, 5, 7);

    // Scene 5... (Start from 6)
    Graph_AddConnection(graph, 6, 7);
    Graph_AddConnection(graph, 6, 8);

    // Scene 6
    Graph_AddConnection(graph, 7, 8);

    // Scene 7
    Graph_AddConnection(graph, 8, 9);

    // Scene 8
    Graph_AddConnection(graph, 9, 10);
    Graph_AddConnection(graph, 9, 11);
    Graph_AddConnection(graph, 9, 12);

    // Scene 9
    Graph_AddConnection(graph, 10, 13);
    Graph_AddConnection(graph, 10, 14);
    Graph_AddConnection(graph, 10, 15);
    Graph_AddConnection(graph, 10, 16);

    // Scene 10
    Graph_AddConnection(graph, 11, 10);
    Graph_AddConnection(graph, 11, 17);

    // Scene 11
    Graph_AddConnection(graph, 12, 18);
    Graph_AddConnection(graph, 12, 19);

    // Scene 12
    Graph_AddConnection(graph, 13, 14);
    Graph_AddConnection(graph, 13, 16);

    // Scene 13
    Graph_AddConnection(graph, 14, 15);

    // Scene 14
    Graph_AddConnection(graph, 15, 23);

    // Scene 15
    Graph_AddConnection(graph, 16, 22);
    Graph_AddConnection(graph, 16, 23);

    // Scene 16
    Graph_AddConnection(graph, 17, 27);
    Graph_AddConnection(graph, 17, 19);

    // Scene 17
    Graph_AddConnection(graph, 18, 20);
    Graph_AddConnection(graph, 18, 21);

    // Scene 18
    Graph_AddConnection(graph, 19, 22);
    Graph_AddConnection(graph, 19, 23);

    // Scene 19
    Graph_AddConnection(graph, 20, 24);

    // Scene 20
    Graph_AddConnection(graph, 21, 26);

    // Scene 21
    Graph_AddConnection(graph, 22, 28);

    // Scene 22
    Graph_AddConnection(graph, 23, 30);
    Graph_AddConnection(graph, 23, 31);

    // Scene 23
    Graph_AddConnection(graph, 24, 25);

    // Scene 24
    Graph_AddConnection(graph, 25, 32);

    // Scene 25
    Graph_AddConnection(graph, 26, 27);

    // Scene 26
    Graph_AddConnection(graph, 27, 29);

    // Scene 27
    Graph_AddConnection(graph, 28, 35);

    // Scene 28
    Graph_AddConnection(graph, 29, 37);

    // Scene 29
    Graph_AddConnection(graph, 30, 36);

    // Scene 30
    Graph_AddConnection(graph, 31, 35);

    // Scene 31
    // Graph_AddConnection(graph, 23, 30);

    // Scene 32
    Graph_AddConnection(graph, 33, 37);
    Graph_AddConnection(graph, 33, 36);


    Canvas *canvas = Canvas_Create();
    SceneManager *sceneMg = SceneManager_Create(graph, canvas, page->pageManager->engineWindow);
    data->sceneMg = sceneMg;

    Scene *mainMenuScene = Scene1Part2_Create();
    SceneManager_GoToScene(sceneMg, 0, SceneTransition::None);

    data->sceneImage = UI_AddImage(page->ui, nullptr, 0, 0, 1000, 550, false, "");
}

void GamePG_Update(Page *page)
{
    GamePageData *data = (GamePageData *)page->data;
    SceneManager *sceneMg = data->sceneMg;

    sceneMg->update(sceneMg);
    UI_CopyCanvasToImage(page->ui, (Image *)data->sceneImage->properties, sceneMg->canvas);
}

void GamePG_Destroy(Page *page)
{
    GamePageData *data = (GamePageData *)page->data;
    delete data->sceneImage;
    delete data->sceneMg;
}

Page *GamePG_Create()
{
    GamePageData *data = new GamePageData{};
    Page *page = new Page{
        .data = data,
        .start = GamePG_Start,
        .update = GamePG_Update,
        .destroy = GamePG_Destroy};
    return page;
}

Page *GamePG_CreateFromSave(const char *saveName)
{
    GamePageData *data = new GamePageData{};
    Page *page = new Page{
        .data = data,
        .start = GamePG_Start,
        .update = GamePG_Update,
        .destroy = GamePG_Destroy};
    return page;
}