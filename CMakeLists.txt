cmake_minimum_required(VERSION 3.14)
project(MineSweeper)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp
        IO.h
        IO.cpp
        tiles.h
        tiles.cpp
        gamewindow.h
        gamewindow.cpp
        boardelements.h
        boardelements.cpp
        leaderboard.h
        leaderboard.cpp)
add_executable(MineSweeper ${SOURCE_FILES} main.cpp IO.h gamewindow.h boardelements.h)


find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
target_link_libraries(MineSweeper sfml-system sfml-window sfml-graphics sfml-audio)
















#cmake_minimum_required(VERSION 3.16)
#project(MineSweeper LANGUAGES CXX)
#
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
#option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
#
#include(FetchContent)
#FetchContent_Declare(SFML
#        GIT_REPOSITORY https://github.com/SFML/SFML.git
#        GIT_TAG 2.6.x)
#FetchContent_MakeAvailable(SFML)
#
#add_executable(MineSweeper main.cpp)
#target_link_libraries(MineSweeper PRIVATE sfml-graphics)
#target_compile_features(MineSweeper PRIVATE cxx_std_17)
#
#if(WIN32)
#    add_custom_command(
#            TARGET MineSweeper
#            COMMENT "Copy OpenAL DLL"
#            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:MineSweeper>
#            VERBATIM)
#endif()
#
#install(TARGETS MineSweeper)