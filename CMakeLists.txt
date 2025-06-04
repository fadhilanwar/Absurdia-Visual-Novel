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