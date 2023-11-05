//
// Created by Aardhyn on 3/11/2023.
//

#include <application.h>

Application::Application() {

	// <initialize stuff>

//	music = std::make_unique<Sound<SoundType::MUSIC>>("../asset/sound.mp3");
//	sfx = std::make_unique<Sound<SoundType::SOUND_EFFECT>>("../asset/sound.wav");

	std::cout << "Application initialized\n";
}

void Application::run() {

	// <set up stuff>

	while (FOREVER) {
		delta = timer.restart();

		if constexpr (LOG_DELTA)
			std::cout << delta << std::endl;

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

	// <update stuff>

	if (input.getKey(SDLK_w))
		rect.position.y -= SPEED * delta;
	if (input.getKey(SDLK_s))
		rect.position.y += SPEED * delta;
	if (input.getKey(SDLK_a))
		rect.position.x -= SPEED * delta;
	if (input.getKey(SDLK_d))
		rect.position.x += SPEED * delta;

//	if (input.getKey(SDLK_SPACE) && !sfx->isPlaying())
//		sfx->play();
}

void Application::render() {
	renderer.Clear();
	renderer.DrawRect(rect);
	renderer.Present();
}

Application::~Application() {

	// <clean up stuff>

	std::cout << "Application destroyed\n";
}
