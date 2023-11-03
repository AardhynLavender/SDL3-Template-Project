#define SDL_MAIN_HANDLED

#include <iostream>
#include <application.h>

int main() {
	Application app{ };
	app.run();

	return EXIT_SUCCESS;
}
