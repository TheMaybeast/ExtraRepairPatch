cmake_minimum_required(VERSION 3.20)
project(ExtraRepairPatch VERSION 1.0.0 LANGUAGES CXX)
add_compile_definitions(_VERSION_MAJOR=${CMAKE_PROJECT_VERSION_MAJOR})
add_compile_definitions(_VERSION_MINOR=${CMAKE_PROJECT_VERSION_MINOR})
add_compile_definitions(_VERSION_PATCH=${CMAKE_PROJECT_VERSION_PATCH})

include_directories(thirdparty/shv/inc)
link_directories(thirdparty/shv/lib)

file(GLOB_RECURSE src src/*.cpp)
file(GLOB_RECURSE utils src/utils/*.cpp)
add_library(ExtraRepairPatch MODULE ${src} ${utils})
add_definitions(-DCMAKE_EXPORT_COMPILE_COMMANDS=ON)

set_property(TARGET ExtraRepairPatch PROPERTY CXX_STANDARD 20)
set_property(TARGET ExtraRepairPatch PROPERTY CXX_STANDARD_REQUIRED ON)

target_link_libraries(ExtraRepairPatch PRIVATE ScriptHookV)

set_target_properties(ExtraRepairPatch PROPERTIES LIBRARY_OUTPUT_DIRECTORY "../bin" SUFFIX ".asi")