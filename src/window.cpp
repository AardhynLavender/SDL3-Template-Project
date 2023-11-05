//
// Created by Aardhyn Lavender on 1/11/23.
//

#include <window.h>
#include <exception.h>

Window::Window(std::string title, const Vec2<int> size, Flags flags) : flags{ flags } {
	const auto [w, h] = size;
	window = SDLException::wrap(SDL_CreateWindow(title.c_str(), w, h, buildFlags(flags)));
}

Window::Window(Window &&other) noexcept: window{ other.window }, flags{ other.flags } {
	other.window = nullptr; // UB safeguard
}

Window &Window::operator=(Window &&other) noexcept {
	if (this != &other) { // protect against self-assignment
		window = other.window;
		flags = other.flags;
		other.window = nullptr; // UB safeguard
	}
	return *this;
}

Vec2<int> Window::size() const {
	int w, h;
	SDL_GetWindowSize(window, &w, &h);
	return { w, h };
}

void Window::setSize(const Vec2<int> size) {
	if (size <= Vec2<int>{ })
		throw std::invalid_argument("Window must have a positive size");
	const auto [w, h] = size;

	SDL_SetWindowSize(window, w, h);
}