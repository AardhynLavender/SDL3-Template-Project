//
// Created by Aardhyn Lavender on 1/11/23.
//

#ifndef SDL3_TEMPLATE_PROJECT_RENDERER_H
#define SDL3_TEMPLATE_PROJECT_RENDERER_H

#include <SDL3/SDL.h>
#include <window.h>
#include <exception.h>
#include <color.h>
#include <rec2.h>

class Renderer final {
public:
	 enum class ScaleQuality {
		  nearest, linear
	 };
	 static constexpr int DEFAULT_FLAGS = 0;
	 struct Flags { // https://wiki.libsdl.org/SDL
		  bool software = false;
		  bool accelerated = false;
		  bool vsync = false;
		  bool targetTexture = false;
	 };

	 Renderer() = delete; // no default construction
	 Renderer(Window &window, Flags flags, ScaleQuality interpolation = ScaleQuality::nearest);

	 Renderer(const Renderer &other) = delete;

	 Renderer(Renderer &&other) noexcept; // move
	 Renderer &operator=(const Renderer &other) = delete;

	 Renderer &operator=(Renderer &&other) noexcept; // move assignment
	 ~Renderer() {
		 if (renderer)
			 SDL_DestroyRenderer(renderer);
	 }

	 inline void Present() { SDL_RenderPresent(renderer); }

	 inline void Clear() {
		 ResetColor();
		 SDLException::wrap(SDL_RenderClear(renderer));
	 }

	 void DrawLine(Vec2<> a, Vec2<> b, Color color = Colors::white);

	 void DrawRect(Rec2<> rect, Color color = Colors::white, Color fill = Colors::transparent);

	 void DrawPixel(Vec2<> vec, Color color = Colors::white);

private:
	 Flags flags{ };
	 Window &window;
	 SDL_Renderer* renderer;

	 [[nodiscard]] inline constexpr static unsigned int buildFlags(const Flags flags) {
		 unsigned int flagsInt = 0;
		 if (flags.software)
			 flagsInt |= SDL_RENDERER_SOFTWARE;
		 if (flags.accelerated)
			 flagsInt |= SDL_RENDERER_ACCELERATED;
		 if (flags.vsync)
			 flagsInt |= SDL_RENDERER_PRESENTVSYNC;
//        if (flags.targetTexture) flagsInt |= SDL_RENDERER_TARGETTEXTURE; // todo: implement this
		 return flagsInt;
	 }

	 inline void SetColor(const Color color) {
		 SDLException::wrap(SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, color.alpha));
	 }

	 inline void ResetColor() { SetColor(Colors::black); }
};

#endif //SDL3_TEMPLATE_PROJECT_RENDERER_H
