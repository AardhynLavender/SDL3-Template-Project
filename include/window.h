//
// Created by Aardhyn Lavender on 1/11/23.
//

#ifndef SDL3_TEMPLATE_PROJECT_WINDOW_H
#define SDL3_TEMPLATE_PROJECT_WINDOW_H

#include <SDL3/SDL.h>
#include <string>
#include <Vec2.h>

class Window final {
private:
	 struct Flags { // https://wiki.libsdl.org/SDL2/SDL_CreateWindow#remarks
		  bool fullscreen = false;
		  bool fullscreenDesktop = false;
		  bool opengl = false;
		  bool hidden = false;
		  bool borderless = false;
		  bool resizable = false;
		  bool minimized = false;
		  bool maximized = false;
		  bool mouseGrabbed = false;
		  bool inputFocus = false;
		  bool mouseFocus = false;
		  bool foreign = false;
		  bool highPixelDensity = false;
	 };
	 Flags flags{ };
	 SDL_Window* window;

	 [[nodiscard]] inline static constexpr unsigned int buildFlags(const Flags flags) {
		 int flagInt = 0;
		 if (flags.fullscreen)
			 flagInt |= SDL_WINDOW_FULLSCREEN;
		 if (flags.fullscreenDesktop)
			 flagInt |= SDL_WINDOW_FULLSCREEN;
		 if (flags.opengl)
			 flagInt |= SDL_WINDOW_OPENGL;
		 if (flags.hidden)
			 flagInt |= SDL_WINDOW_HIDDEN;
		 if (flags.borderless)
			 flagInt |= SDL_WINDOW_BORDERLESS;
		 if (flags.resizable)
			 flagInt |= SDL_WINDOW_RESIZABLE;
		 if (flags.minimized)
			 flagInt |= SDL_WINDOW_MINIMIZED;
		 if (flags.maximized)
			 flagInt |= SDL_WINDOW_MAXIMIZED;
		 if (flags.mouseGrabbed)
			 flagInt |= SDL_WINDOW_MOUSE_GRABBED;
		 if (flags.inputFocus)
			 flagInt |= SDL_WINDOW_INPUT_FOCUS;
		 if (flags.mouseFocus)
			 flagInt |= SDL_WINDOW_MOUSE_FOCUS;
		 if (flags.foreign)
			 flagInt |= SDL_WINDOW_FOREIGN;
		 if (flags.highPixelDensity)
			 flagInt |= SDL_WINDOW_HIGH_PIXEL_DENSITY;

		 return flagInt;
	 }

public:
	 Window() = delete; // no default construction
	 Window(std::string title, Vec2<int> size, Flags flags);

	 Window(const Window &) = delete; // no copy construction
	 Window(Window &&) noexcept; // no move construction
	 Window &operator=(const Window &) = delete; // no copy assignment
	 Window &operator=(Window &&other) noexcept; // move assignment
	 ~Window() {
		 if (window)
			 SDL_DestroyWindow(window);
	 }

	 static inline Vec2<int> centered{ SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED };

	 [[nodiscard]] Vec2<int> size() const;

	 void setSize(Vec2<int> size);

	 inline SDL_Window* GetWindow() { return window; }
};

#endif //SDL3_TEMPLATE_PROJECT_WINDOW_H
