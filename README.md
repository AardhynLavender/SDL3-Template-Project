# SDL3 Template Project

A barebones OS and IDE agnostic C++23 SDL3 CMake project to start your dream software project from.

## Setup

Download and build a local copy of **SDL3** by following
their [installation instructions](https://github.com/libsdl-org/SDL/blob/main/INSTALL.txt).

Make directories `/include`, and `/lib` in the root of this repository.

### Build SDL3

I'm not a fan of linking with system installations of libraries and frameworks. Want to use a system installation...
make a *PR*.

Copy the `include/SDL3` directory from your local **SDL3** repository into `/include`

#### MacOS

Copy `build/libSDL3.dylib` into `/lib`

#### Windows

You need to copy the generated `SDL3.lib` file from the compiled SDL library into `/lib`. It's location will vary
depending on how you built SDL (MinGW, Visual Studio, etc.).

It might be something like `build/Debug/SDL3.lib`, or `build/Release/SDL3.lib`.

Copy the `SDL.dll` file into the same directory as where your `SDL-Template-Project.exe` is run.

> If you get an error like `Process finished with exit code -1073741515 (0xC0000135)`, It probably means you didn't copy
> the `SDL.dll` file into the same directory as the executable.

### Build SDL3_Mixer

The headers for **SDL3_Mixer** are included in the **SDL3** repository.
You'll need to build the library yourself though.

#### MacOS

#### Windows

Download and build **SDL_Mixer** on your platform. Move the `.lib` file into `/lib` and the `.dll` file into the same
directory as your executable.

## Development

#### Visual Studio

run `cmake .` to generate the Visual Studio project

#### CLion

Open the directory as a Clion project. You'll be prompted to create your *Build Configuration* upon opening.
