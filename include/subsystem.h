//
// Created by Aardhyn on 5/11/2023.
//

#ifndef SDL3_TEMPLATE_PROJECT_SUBSYSTEM_H
#define SDL3_TEMPLATE_PROJECT_SUBSYSTEM_H

#include <SDL3/SDL.h>
#include <SDL3_Mixer/SDL_mixer.h>
#include <exception.h>
#include <stdexcept>
#include <iostream>

class Video final {
private:
	 // todo: add flag abstraction
public:
	 Video() {
		 SDLException::wrap(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO));
		 std::cout << "Video initialized\n";
	 }

	 ~Video() {
		 SDL_Quit();
		 std::cout << "Video destroyed\n";
	 }
};

class Audio final {
private:
	 struct Flags { bool flac = false, mod = false, mp3 = false, ogg = false, mid = false, opus = false, wavpack = false; };
	 typedef SDL_AudioSpec Spec;

	 static auto buildFlags(Flags flags) {
		 auto result = 0;
		 if (flags.flac)
			 result |= MIX_INIT_FLAC;
		 if (flags.mod)
			 result |= MIX_INIT_MOD;
		 if (flags.mp3)
			 result |= MIX_INIT_MP3;
		 if (flags.ogg)
			 result |= MIX_INIT_OGG;
		 if (flags.mid)
			 result |= MIX_INIT_MID;
		 if (flags.opus)
			 result |= MIX_INIT_OPUS;
		 if (flags.wavpack)
			 result |= MIX_INIT_WAVPACK;
		 return result;
	 }

public:
	 Audio(Flags flags, Spec spec) {
		 const auto flagsInt = buildFlags(flags);
		 const auto result = Mix_Init(flagsInt);
		 SDLException::throwIf(result != flagsInt, "Failed to initialize audio: " + std::string{ Mix_GetError() });
		 SDLException::wrap(Mix_OpenAudio(0, &spec));
		 std::cout << "Audio initialized\n";
	 }

	 ~Audio() {
		 Mix_CloseAudio();
		 Mix_Quit();
		 std::cout << "Audio destroyed\n";
	 }
};

#endif //SDL3_TEMPLATE_PROJECT_SUBSYSTEM_H
