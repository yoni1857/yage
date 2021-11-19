cmake_minimum_required(VERSION 3.0.0)
project(game VERSION 0.1.0)

include(CTest)
enable_testing()


set(BOX2D_INCLUDE_DIR CACHE PATH "The folder where box2d/box2d.h is located.")
set(BOX2D_LIB_DIR CACHE PATH "The folder where libbox2d.a is located.")
set(SDL2_INCLUDE_DIR CACHE PATH "The folder where SDL/SDL.h is located.")
set(SDL2_LIB_DIR CACHE PATH "The folder where libSDL2.a is located.")
set(SDL2_DLL CACHE FILEPATH "The SDL2 binary dll file to copy over when the game builds.")

add_executable(game 
    src/main.cpp
    src/game.hpp
    src/game.cpp
    src/gameobject.cpp
    src/gameobject.hpp
    src/tools/tools.hpp
    src/tools/tools.cpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

file(COPY ${SDL2_DLL} DESTINATION ${PROJECT_BINARY_DIR})
include_directories(${SDL2_INCLUDE_DIR} ${BOX2D_INCLUDE_DIR})
target_link_libraries(game "${SDL2_LIB_DIR}/libSDL2.dll.a" "${SDL2_LIB_DIR}/libSDL2main.a" "${BOX2D_LIB_DIR}/libbox2d.a")
include(CPack)
