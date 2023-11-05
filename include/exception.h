//
// Created by Aardhyn Lavender on 2/11/23.
//

#ifndef SDL3_TEMPLATE_PROJECT_EXCEPTION_H
#define SDL3_TEMPLATE_PROJECT_EXCEPTION_H

#include <SDL3/SDL.h>
#include <SDL3_mixer/SDL_mixer.h>
#include <exception>
#include <string>
#include <utility>

class SDLException final : public std::exception {
	 typedef int ErrorCode;
	 typedef void* AnyPointer;
	 static constexpr ErrorCode UNKNOWN_ERROR = -1;
	 ErrorCode code;
	 std::string message;
public:
	 SDLException(std::string message, ErrorCode code) : message{ std::move(message) }, code{ code } {}

	 explicit SDLException(std::string message) : message{ std::move(message) }, code{ UNKNOWN_ERROR } {}

	 [[nodiscard]] const char* what() const noexcept override { return message.c_str(); }

	 // wrap functions that return an integral error code
	 template<bool enabled = true>
	 inline static ErrorCode wrap(ErrorCode errCode) {
		 if constexpr (enabled)
			 if (errCode)
				 throw SDLException{ SDL_GetError(), errCode };
		 return errCode;
	 }

	 inline static void throwIf(bool condition, std::string message = "", ErrorCode code = UNKNOWN_ERROR) {
		 if (condition)
			 throw SDLException{ message.size() ? std::move(message) : SDL_GetError(), code };
	 }

	 // wrap functions that return nullptr to indicate failure
	 template<bool enabled = true>
	 inline static auto wrap(auto* pointer) {
		 if constexpr (enabled)
			 if (!pointer)
				 throw SDLException{ SDL_GetError(), UNKNOWN_ERROR };
		 return pointer;
	 }
};

#endif //SDL3_TEMPLATE_PROJECT_EXCEPTION_H
