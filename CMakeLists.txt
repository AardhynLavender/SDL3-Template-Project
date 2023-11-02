cmake_minimum_required(VERSION 3.22)
project(SDL3-Template-Project)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_SUPPRESS_REGENERATION true) # disable ZERO_CHECK target creation

include_directories(include)
link_directories(lib)

add_executable(SDL3-Template-Project src/main.cpp
        src/window.cpp
        include/window.h
        src/renderer.cpp
        include/renderer.h
        src/input.cpp
        include/input.h
        include/vec2.h
        include/color.h
        include/rec2.h
        include/concept.h
        include/exception.h)

if (APPLE)
    target_link_libraries(SDL3-Template-Project libSDL3.dylib)
elseif (WIN32)
    target_link_libraries(SDL3-Template-Project SDL3.lib)
endif ()