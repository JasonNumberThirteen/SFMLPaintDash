cmake_minimum_required(VERSION 3.28)
project(PaintDash LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.x
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(main src/main.cpp headers/constants.hpp src/constants.cpp headers/sprite.hpp src/sprite.cpp headers/ui/textUI.hpp src/ui/textUI.cpp headers/scenes/scene.hpp src/scenes/scene.cpp headers/scenes/mainMenuScene.hpp src/scenes/mainMenuScene.cpp headers/gameApplication.hpp src/gameApplication.cpp headers/managers/textureManager.hpp src/managers/textureManager.cpp headers/managers/sceneManager.hpp src/managers/sceneManager.cpp headers/managers/spriteManager.hpp src/managers/spriteManager.cpp headers/ui/mainMenuPanelUI.hpp src/ui/mainMenuPanelUI.cpp)
target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics)
