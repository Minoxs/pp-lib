cmake_minimum_required(VERSION 3.18)
project(pp-lib)

set(CMAKE_CXX_STANDARD 17)
set(OSU_SOURCES
        src/diff/calculator/DifficultyCalculator.cpp
        src/diff/calculator/FullBeatmap.cpp
        src/diff/calculator/HitObject.cpp
        src/diff/calculator/Skill.cpp
        src/diff/calculator/osu/OsuDifficultyHitObject.cpp
        src/diff/calculator/osu/OsuDifficultyCalculator.cpp
        src/diff/calculator/skill/aim.cpp
        src/diff/calculator/skill/flashlight.cpp
        src/diff/calculator/skill/speed.cpp
        src/diff/ruleset/Ruleset.cpp
        src/pp/performance/catch/CatchScore.cpp
        src/pp/performance/mania/ManiaScore.cpp
        src/pp/performance/osu/OsuScore.cpp
        src/pp/performance/taiko/TaikoScore.cpp
        src/pp/performance/Score.cpp
        src/shared/Beatmap.cpp
        src/shared/Common.cpp
)

include_directories(include)
add_library(pp-lib SHARED ${OSU_SOURCES})
add_library(pp-libc SHARED src/Bindings.cpp ${OSU_SOURCES})

add_executable(pp-lib-test test/main.cpp)
target_link_libraries(pp-lib-test pp-lib)
