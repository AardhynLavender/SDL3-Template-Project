cmake_minimum_required(VERSION 3.22)
project(SDL3-Template-Project)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_SUPPRESS_REGENERATION true) # disable ZERO_CHECK target creation

include_directories(include)
link_directories(lib)

add_executable(SDL3-Template-Project src/main.cpp src/window.cpp src/renderer.cpp src/input.cpp src/application.cpp)

if (APPLE)
    target_link_libraries(SDL3-Template-Project libSDL3.dylib libSDL3_Mixer.dylib)
elseif (WIN32)
    target_link_libraries(SDL3-Template-Project SDL3.lib SDL3_Mixer.lib)
endif ()