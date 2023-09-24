# SDL3 Template Project

A barebones OS and IDE agnostic C++23 SDL3 CMake project to start your dream game from.

## Setup   

Download and build a local copy of **SDL3** by following their [installation instructions](https://github.com/libsdl-org/SDL/blob/main/INSTALL.txt).

Make directories `/include`, and `/lib` in the root of this repository.

### Build SDL3

I'm not a fan of linking with system installations of libraries and frameworks. Want to use a system installation... make a *PR*.

Copy the `include/SDL3` directory from your local **SDL3** repository into `/include`;

#### MacOS

Copy `build/libSDL3.dylib` into `/lib`

#### Windows

You need to copy the generated `SDL3.lib` file from the compiled SDL library into `/lib`. It's location will vary depending on how you built SDL (MinGW, Visual Studio, etc.).

It might be something like `build/Debug/SDL3.lib`, or `build/Release/SDL3.lib`.

Copy the `SDL.dll` file into the same directory as where your `SDL-Template-Project.exe` is run.

## Development

#### Visual Studio

run `cmake .` to generate the Visual Studio project

#### CLion

Open the directory as a Clion project. You'll be prompted to create your *Build Configuration* apon opening.
