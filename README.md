# SDL3 Template Project

A barebones OS and IDE agnostic C++23 SDL3 CMake project to start your dream software project from.

## Setup

Download and build a local copy of **SDL3
** ([installation instructions](https://github.com/libsdl-org/SDL/blob/main/INSTALL.txt)) and **SDL3_Mixer** (The've no
installation instructions, but its near identical to **SDL3**s)

Make a `/lib` and `/include/SDL3` and `/include/SDL3_Mixer` directories in the root of this project.

I'm not a fan of downloading prebuilt libraries or installing them globally, so I've included the steps to build the
dependencies and include them in the project.

### Build SDL3

Copy the `include/SDL3` directory from your local **SDL3** repository into `/include`

#### MacOS

Copy the generated `*.dylib` files from the compiled SDL library into `/lib`. Including the versioned ones.

#### Windows

Download and build **SDL3** on your platform. Move the `.lib` file into `/lib` and the `.dll` file into the same
directory as your executable.

### Build SDL3_Mixer

Copy the headers from the **SDL3_Mixer** repository into `/include/SDL3_Mixer`.
I've called the directory `SDL3_Mixer` intentionally.
You'll need to build the library yourself though.

#### MacOS

Copy the generated `*.dylib` files from the compiled SDL library into `/lib`. Including the versioned ones.

#### Windows

Download and build **SDL_Mixer** on your platform. Move the `.lib` file into `/lib` and the `.dll` file into the same
directory as your executable.

## Development

#### Visual Studio

run `cmake .` to generate the Visual Studio project

#### CLion

Open the directory as a Clion project. You'll be prompted to create your *Build Configuration* upon opening.

## Known Issues

### (**Windows**) `Process finished with exit code -1073741515 (0xC0000135)`

If you get an error like this, It probably means you didn't copy the `*.dll` files into the same directory as the
executable.
