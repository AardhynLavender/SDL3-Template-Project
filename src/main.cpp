#define SDL_MAIN_HANDLED

#include <iostream>
#include <application.h>

int main() {
	try {
		Application app{ };

		app.run();

		Out::line("Application exited successfully");
		return EXIT_SUCCESS;
	} catch (const std::exception &exception) {
		Err::lines("Application encountered an error:", exception.what());
		return EXIT_FAILURE;
	} catch (...) {
		Err::line("Application encountered an unknown error");
		return EXIT_FAILURE;
	}
}
