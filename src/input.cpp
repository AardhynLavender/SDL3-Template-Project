//
// Created by Aardhyn on 3/11/2023.
//

#include "input.h"

void Input::update() {
	while (SDL_PollEvent(&event))
		switch (event.type) {
			case SDL_EVENT_QUIT:
				quit = true;
				break;
			case SDL_EVENT_KEY_DOWN:
				keys[event.key.keysym.sym] = KEY_DOWN;
				break;
			case SDL_EVENT_KEY_UP:
				keys[event.key.keysym.sym] = KEY_UP;
				break;
			case SDL_EVENT_MOUSE_BUTTON_DOWN:
				keys[event.button.type] = KEY_DOWN;
				break;
			case SDL_EVENT_MOUSE_BUTTON_UP:
				keys[event.button.type] = KEY_DOWN;
				break;
			case SDL_EVENT_MOUSE_MOTION:
				mousePos.x = event.motion.x;
				mousePos.y = event.motion.y;
				break;
		}
}
