#define SDL_MAIN_HANDLED

#include <iostream>
#include <renderer.h>
#include <input.h>

constexpr int WIN_WIDTH = 800, WIN_HEIGHT = 600;
constexpr auto SPEED = 0.2f;

int main() {
	handleSDLError(SDL_Init(SDL_INIT_EVERYTHING));

	Window window{ "SDL3 Template Project", { WIN_WIDTH, WIN_HEIGHT }, { .opengl = true, }};
	Renderer renderer{ window, { .accelerated = true, .vsync = true, }};
	Input input{ };

	Vec2<float> pos{ (float) WIN_WIDTH / 2, (float) WIN_HEIGHT / 2 };
	Rec2<float> rect{ pos, { 50, 50 }};

	while (1) {
		input.update();
		if (input.getQuit())
			break; // quit

		if (input.getKey(SDLK_w))
			rect.position.y -= SPEED;
		if (input.getKey(SDLK_s))
			rect.position.y += SPEED;
		if (input.getKey(SDLK_a))
			rect.position.x -= SPEED;
		if (input.getKey(SDLK_d))
			rect.position.x += SPEED;

		renderer.Clear();
		renderer.DrawRect(rect, Colors::white, Colors::transparent);
		renderer.Present();
	}

	SDL_Quit();

	return EXIT_SUCCESS;
}
