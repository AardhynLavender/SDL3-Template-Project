#define SDL_MAIN_HANDLED

#include <iostream>
#include <renderer.h>
#include <input.h>

constexpr auto WIN_WIDTH = 800, WIN_HEIGHT = 600, SHAPE_SIZE = 50, START_X = WIN_WIDTH / 2 - SHAPE_SIZE / 2, START_Y =
		  WIN_HEIGHT / 2 - SHAPE_SIZE / 2;
constexpr auto SPEED = 0.2f;
constexpr auto FOREVER = true;

int main() {
	handleSDLError(SDL_Init(SDL_INIT_EVERYTHING));

	Window window{ "SDL3 Template Project", { WIN_WIDTH, WIN_HEIGHT }, { .opengl = true, }};
	Renderer renderer{ window, { .accelerated = true, .vsync = true, }};
	Input input{ };

	Vec2<float> pos{ START_X, START_Y };
	Rec2<float> rect{ pos, { SHAPE_SIZE, SHAPE_SIZE }};

	while (FOREVER) {
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
		renderer.DrawRect(rect);
		renderer.Present();
	}

	SDL_Quit();

	return EXIT_SUCCESS;
}
