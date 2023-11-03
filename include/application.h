//
// Created by Aardhyn on 3/11/2023.
//

#ifndef SDL3_TEMPLATE_PROJECT_APPLICATION_H
#define SDL3_TEMPLATE_PROJECT_APPLICATION_H

#include <renderer.h>
#include <input.h>

class Application {
private:
	 static constexpr auto TITLE = "SDL3 Template Project";
	 static constexpr auto WIN_WIDTH = 800, WIN_HEIGHT = 600, SHAPE_SIZE = 50, START_X =
				WIN_WIDTH / 2 - SHAPE_SIZE / 2, START_Y =
				WIN_HEIGHT / 2 - SHAPE_SIZE / 2;
	 static constexpr auto SPEED = 0.2f;
	 static constexpr auto FOREVER = true;

	 Window window{ TITLE, { WIN_WIDTH, WIN_HEIGHT }, { .opengl = true, }};
	 Renderer renderer{ window, { .accelerated = true, .vsync = true, }};
	 Input input{ };

	 Vec2<float> pos{ START_X, START_Y };
	 Rec2<float> rect{ pos, { SHAPE_SIZE, SHAPE_SIZE }};

	 void update();

	 void render();

	 void events();

public:
	 Application();

	 void run();

	 ~Application();
};

#endif //SDL3_TEMPLATE_PROJECT_APPLICATION_H
