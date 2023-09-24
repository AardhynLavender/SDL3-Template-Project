# SDL3 Template Project

## Configuration

Download and build a local copy of **SDL3** following their [installation instructions](https://github.com/libsdl-org/SDL/blob/main/INSTALL.txt).

Make directories `./include`, and `./lib` in the root of this repository.

I'm not a fan of linking with system installations of libraries and frameworks.
Copy the /include/SDL3` directory from your local **SDL3** repository into `./include`;

### MacOS

Copy `build/libSDL3.dylib` into `./lib`

### Windows

You need to copy the generated `SDL3.lib` file from the compiled SDL library into `/lib`. Its location will vary depending on how you build SDL ( MinGW, Visual Studio, etc. ).

It might be something like `build/Debug/SDL3.lib`, or `build/Release/SDL3.lib`.

Copy the `SDL.dll` file into the same directory as where your `SDL-Template-Project.exe` is run.