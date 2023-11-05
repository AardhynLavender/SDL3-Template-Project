#define SDL_MAIN_HANDLED

#include <iostream>
#include <application.h>

int main() {
	try {
		Application app{ };
		app.run();
	} catch (const std::exception &e) {
		std::cerr << "Application encountered an error:" << std::endl;
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	std::cout << "Application exited successfully!" << std::endl;
	return EXIT_SUCCESS;
}
