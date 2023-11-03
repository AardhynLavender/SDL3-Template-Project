//
// Created by Aardhyn Lavender on 2/11/23.
//

#ifndef SDL3_TEMPLATE_PROJECT_EXCEPTION_H
#define SDL3_TEMPLATE_PROJECT_EXCEPTION_H

#include <SDL3/SDL.h>
#include <exception>

class SDLException final : public std::exception {
public:
	 SDLException(const char* message) : message(message) {}

	 const char* what() const noexcept { return message; }

private:
	 const char* message;
};

constexpr auto ERROR_HEADER = "SDL Error: ";

auto handleSDLError(auto errCode) {
	std::cout << ERROR_HEADER << SDL_GetError() << std::endl;
	return errCode;
}

#endif //SDL3_TEMPLATE_PROJECT_EXCEPTION_H
