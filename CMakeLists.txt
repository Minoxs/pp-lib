cmake_minimum_required(VERSION 3.18)
project(pp-lib)

set(CMAKE_CXX_STANDARD 17)
set(OSU_SOURCES
        src/performance/catch/CatchScore.cpp
        src/performance/mania/ManiaScore.cpp
        src/performance/osu/OsuScore.cpp
        src/performance/taiko/TaikoScore.cpp
        src/performance/Beatmap.cpp
        src/performance/Score.cpp
        src/Common.cpp
)

include_directories(include)
add_library(pp-lib SHARED ${OSU_SOURCES})

add_executable(pp-lib-test test/main.cpp)
target_link_libraries(pp-lib-test pp-lib)
