cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(main 
    src/main.cpp
    src/umum.hpp
    src/umum.cpp
    src/scenes/scene.hpp
    src/scenes/scene_1/scene_1.hpp
    src/scenes/scene_1/scene_1.cpp
    src/scenes/scene_2/scene_2.hpp
    src/scenes/scene_2/scene_2.cpp
    src/scenes/scene_3/scene_3.hpp
    src/scenes/scene_3/scene_3.cpp
    src/scenes/scene_4/scene_4.hpp
    src/scenes/scene_4/scene_4.cpp
    src/scenes/scene_5/scene_5.hpp
    src/scenes/scene_5/scene_5.cpp
    src/scenes/scene_6/scene_6.hpp
    src/scenes/scene_6/scene_6.cpp
    src/scenes/scene_7/scene_7.hpp
    src/scenes/scene_7/scene_7.cpp
    src/scenes/scene_8/scene_8.hpp
    src/scenes/scene_8/scene_8.cpp
    src/scenes/scene_9/scene_9.hpp
    src/scenes/scene_9/scene_9.cpp
    src/scenes/scene_10/scene_10.hpp
    src/scenes/scene_10/scene_10.cpp
    src/scenes/scene_11/scene_11.hpp
    src/scenes/scene_11/scene_11.cpp
    src/scenes/scene_12/scene_12.hpp
    src/scenes/scene_12/scene_12.cpp
    src/scenes/scene_13/scene_13.hpp
    src/scenes/scene_13/scene_13.cpp
    src/scenes/scene_14/scene_14.hpp
    src/scenes/scene_14/scene_14.cpp
    src/scenes/scene_15/scene_15.hpp
    src/scenes/scene_15/scene_15.cpp
    src/scenes/scene_16/scene_16.hpp
    src/scenes/scene_16/scene_16.cpp
    src/scenes/scene_17/scene_17.hpp
    src/scenes/scene_17/scene_17.cpp
    src/scenes/scene_18/scene_18.hpp
    src/scenes/scene_18/scene_18.cpp
    src/scenes/scene_19/scene_19.hpp
    src/scenes/scene_19/scene_19.cpp
    src/scenes/scene_20/scene_20.hpp
    src/scenes/scene_20/scene_20.cpp
    src/scenes/scene_21/scene_21.hpp
    src/scenes/scene_21/scene_21.cpp
    src/scenes/scene_22/scene_22.hpp
    src/scenes/scene_22/scene_22.cpp
    src/scenes/scene_23/scene_23.hpp
    src/scenes/scene_23/scene_23.cpp
    src/scenes/scene_24/scene_24.hpp
    src/scenes/scene_24/scene_24.cpp
    src/scenes/scene_25/scene_25.hpp
    src/scenes/scene_25/scene_25.cpp
    src/scenes/scene_26/scene_26.hpp
    src/scenes/scene_26/scene_26.cpp
    src/scenes/scene_27/scene_27.hpp
    src/scenes/scene_27/scene_27.cpp
    src/scenes/scene_28/scene_28.hpp
    src/scenes/scene_28/scene_28.cpp
    src/scenes/scene_29/scene_29.hpp
    src/scenes/scene_29/scene_29.cpp
    src/scenes/scene_30/scene_30.hpp
    src/scenes/scene_30/scene_30.cpp
    src/scenes/scene_31/scene_31.hpp
    src/scenes/scene_31/scene_31.cpp
    src/scenes/scene_32/scene_32.hpp
    src/scenes/scene_32/scene_32.cpp
    src/pages/page.hpp
    src/pages/game/game.hpp
    src/pages/game/game.cpp
    src/pages/game/scene_manager.hpp
    src/pages/game/scene_manager.cpp
    src/pages/about/about.hpp
    src/pages/about/about.cpp
    src/pages/main_menu/main_menu.hpp
    src/pages/main_menu/main_menu.cpp
    src/pages/load_game/load_game.hpp
    src/pages/load_game/load_game.cpp
    src/pages/new_game/new_game.hpp
    src/pages/new_game/new_game.cpp
    src/engine/canvas.hpp
    src/engine/canvas.cpp
    src/engine/ui.hpp
    src/engine/ui.cpp
    src/engine/page_manager.hpp
    src/engine/page_manager.cpp
    src/engine/engine.hpp
    src/engine/engine.cpp
)

target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics SFML::Audio)

add_custom_command(TARGET main POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/assets/ $<TARGET_FILE_DIR:main>
)