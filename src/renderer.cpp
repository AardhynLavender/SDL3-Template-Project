//
// Created by Aardhyn Lavender on 1/11/23.
//

#include <renderer.h>

Renderer::Renderer(Window &window, Flags flags, ScaleQuality interpolation) : window{ window }, flags{ flags } {
	renderer = SDLException::wrap(SDL_CreateRenderer(window.GetWindow(), nullptr, DEFAULT_FLAGS));

//    SDL_RenderSetIntegerScale(renderer, SDL_bool::SDL_TRUE);
//    SetScaleQuality(interpolation);

	Clear();
}

Renderer::Renderer(Renderer &&other) noexcept
		  : renderer(other.renderer), window(other.window) {
	other.renderer = nullptr; // invalidate the other renderer
}

Renderer &Renderer::operator=(Renderer &&other) noexcept {
	if (this != &other) { // not the same object
		renderer = other.renderer;
		other.renderer = nullptr;
	}
	return *this;
}

void Renderer::DrawLine(Vec2<> a, Vec2<> b, Color color) {
	SetColor(color);
	SDLException::wrap(SDL_RenderLine(renderer, a.x, a.y, b.x, b.y));
}

void Renderer::DrawRect(Rec2<> rect, Color color, Color fill) {
	// draw the outline
	if (color.alpha) {
		SetColor(color);
		auto r = (SDL_FRect) rect;
		SDLException::wrap(SDL_RenderRect(renderer, &r));
	}
	// draw the fill
	if (fill.alpha) {
		SetColor(fill);
		const auto r = (SDL_FRect) rect;
		SDLException::wrap(SDL_RenderFillRect(renderer, &r));
	}
}

void Renderer::DrawPixel(Vec2<> vec, Color color) {
	SetColor(color);
	SDLException::wrap(SDL_RenderPoint(renderer, vec.x, vec.y));
}
