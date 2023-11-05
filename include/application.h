//
// Created by Aardhyn on 3/11/2023.
//

#ifndef SDL3_TEMPLATE_PROJECT_APPLICATION_H
#define SDL3_TEMPLATE_PROJECT_APPLICATION_H

#include <renderer.h>
#include <input.h>
#include <memory>
#include <sound.h>
#include <subsystem.h>

#include <SDL3_Mixer/SDL_mixer.h>

class Application {
private:
	 // constants
	 static constexpr auto TITLE = "SDL3 Template Project";
	 static constexpr auto WIN_WIDTH = 800, WIN_HEIGHT = 600, SHAPE_SIZE = 50, START_X =
				WIN_WIDTH / 2 - SHAPE_SIZE / 2, START_Y =
				WIN_HEIGHT / 2 - SHAPE_SIZE / 2;
	 static constexpr auto SPEED = 0.2f;
	 static constexpr auto FOREVER = true;

	 // subsystems (order matters)
	 Video video{ };
	 Input input{ };
	 Audio audio{{ .mp3 = true, }, { .format = MIX_DEFAULT_FORMAT, .channels = MIX_DEFAULT_CHANNELS, .freq = MIX_DEFAULT_FREQUENCY, }};
	 Window window{ TITLE, { WIN_WIDTH, WIN_HEIGHT }, { .opengl = true, }};
	 Renderer renderer{ window, { .accelerated = true, .vsync = true, }};

	 // assets
	 std::unique_ptr<Sound<SoundType::MUSIC>> music;
	 std::unique_ptr<Sound<SoundType::SOUND_EFFECT>> sfx;

	 // demo
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
