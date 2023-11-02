//
// Created by Aardhyn on 3/11/2023.
//

#ifndef SDL3_TEMPLATE_PROJECT_INPUT_H
#define SDL3_TEMPLATE_PROJECT_INPUT_H

#include <vec2.h>
#include <SDL3/SDL_events.h>
#include <unordered_map>

class Input {
private:
	 static constexpr size_t KEYS = 256;
	 static constexpr bool KEY_DOWN = true, KEY_UP = false;

	 SDL_Event event;
	 bool quit = false;
	 Vec2<float> mousePos{ };
	 std::unordered_map<Uint32, bool> keys{ };
	 std::unordered_map<Uint32, bool> mouseKeys{ };
public:
	 void update();

	 inline bool getQuit() const { return quit; }

	 inline bool getKey(SDL_KeyCode key) { return keys[key]; }

	 inline bool getMouseKey(SDL_KeyCode button) { return keys[button]; }

	 auto getMousePos() { return mousePos; };
};

#endif //SDL3_TEMPLATE_PROJECT_INPUT_H
