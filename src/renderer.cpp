//
// Created by Aardhyn Lavender on 1/11/23.
//

#include <renderer.h>

Renderer::Renderer(Window &window, Flags flags, ScaleQuality interpolation) : window{window}, flags{flags} {
    renderer = SDL_CreateRenderer(window.GetWindow(), nullptr, DEFAULT_FLAGS);
    if (!renderer) throw SDLException(SDL_GetError());

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

void Renderer::DrawLine(Vec2<int> a, Vec2<int> b, Color color) {
    SetColor(color);
    if (SDL_RenderLine(renderer, a.x, a.y, b.x, b.y))
        throw SDLException(SDL_GetError());
}

void Renderer::DrawRect(Rec2<int> rect, const Color color, const Color fill) {
    // draw the outline
    if (color.alpha) {
        SetColor(color);
        auto r = (SDL_FRect) rect;
        if (SDL_RenderRect(renderer, &r)) throw SDLException(SDL_GetError());
    }
    // draw the fill
    if (fill.alpha) {
        SetColor(fill);
        const auto r = (SDL_FRect) rect;
        if (SDL_RenderFillRect(renderer, &r)) throw SDLException(SDL_GetError());
    }
}

void Renderer::DrawPixel(Vec2<int> vec, Color color) {
    SetColor(color);
    if (SDL_RenderPoint(renderer, vec.x, vec.y))
        throw SDLException(SDL_GetError());
}
