//
// Created by Aardhyn on 3/11/2023.
//

#include <application.h>

Application::Application() {
	handleSDLError(SDL_Init(SDL_INIT_EVERYTHING));
}

void Application::run() {
	while (FOREVER) {
		events();
		if (input.getQuit())
			break; // quit

		update();
		render();
	}
}

void Application::events() {
	input.update();
}

void Application::update() {
	if (input.getKey(SDLK_w))
		rect.position.y -= SPEED;
	if (input.getKey(SDLK_s))
		rect.position.y += SPEED;
	if (input.getKey(SDLK_a))
		rect.position.x -= SPEED;
	if (input.getKey(SDLK_d))
		rect.position.x += SPEED;
}

void Application::render() {
	renderer.Clear();
	renderer.DrawRect(rect);
	renderer.Present();
}

Application::~Application() {
	SDL_Quit();
}
