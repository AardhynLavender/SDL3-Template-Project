//
// Created by Aardhyn on 4/11/2023.
//

#ifndef SDL3_TEMPLATE_PROJECT_SOUND_H
#define SDL3_TEMPLATE_PROJECT_SOUND_H

#include <SDL3_Mixer/SDL_mixer.h>
#include <exception.h>
#include <stdexcept>
#include <iostream>
#include <filesystem>

enum class SoundType { SOUND_EFFECT, MUSIC };

template<SoundType type>
class Sound {
private:
	 static constexpr int FIRST_AVAILABLE_CHANNEL = -1, LOOP = -1, NO_LOOP = 0, GET_VOLUME = -1, MIN_VOLUME = 0, MAX_VOLUME = MIX_MAX_VOLUME;

	 Mix_Chunk* sound = nullptr;
	 Mix_Music* music = nullptr;

	 bool loaded = false;

	 int channel = FIRST_AVAILABLE_CHANNEL;
public:
	 explicit Sound(const std::filesystem::path &path) {
		 if (!std::filesystem::exists(path))
			 throw std::runtime_error("File does not exist");
		 if (std::filesystem::is_directory(path))
			 throw std::runtime_error("File is a directory");
		 if (std::filesystem::is_empty(path))
			 throw std::runtime_error("File is empty");

		 if constexpr (type == SoundType::SOUND_EFFECT) {
			 sound = Mix_LoadWAV(path.string().c_str());
			 if (!sound)
				 throw SDLException{ SDL_GetError() };
		 } else {
			 music = Mix_LoadMUS(path.string().c_str());
			 if (!music)
				 throw SDLException{ SDL_GetError(), };
		 }

		 loaded = true;
	 }

	 // todo: implement more constructors (move, copy, etc.)

	 ~Sound() {
		 if (!loaded)
			 return;

		 if constexpr (type == SoundType::SOUND_EFFECT)
			 Mix_FreeChunk(sound);
		 else
			 Mix_FreeMusic(music);

		 std::cout << "sound destroyed" << std::endl;
	 }

	 void play(bool loop = false) {
		 if (!loaded)
			 return;

		 if constexpr (type == SoundType::SOUND_EFFECT)
			 channel = Mix_PlayChannel(FIRST_AVAILABLE_CHANNEL, sound, loop ? LOOP : NO_LOOP);
		 else {
			 Mix_PlayMusic(music, loop ? LOOP : NO_LOOP);
		 }
	 }

	 [[nodiscard]] bool isPlaying() const {
		 if (!loaded)
			 return false;

		 if constexpr (type == SoundType::SOUND_EFFECT)
			 return Mix_Playing(channel) == 1;
		 else
			 return Mix_PlayingMusic() == 1;
	 }

	 void pause() {
		 if (!loaded)
			 return;

		 if constexpr (type == SoundType::SOUND_EFFECT)
			 Mix_Pause(channel);
		 else
			 Mix_PauseMusic();
	 }

	 void resume() {
		 if (!loaded)
			 return;

		 if constexpr (type == SoundType::SOUND_EFFECT)
			 Mix_Resume(channel);
		 else
			 Mix_ResumeMusic();
	 }

	 void stop() {
		 if (!loaded)
			 return;

		 if constexpr (type == SoundType::SOUND_EFFECT)
			 Mix_HaltChannel(channel);
		 else
			 Mix_HaltMusic();
	 }

	 void setVolume(int volume) {
		 if (!loaded)
			 return;

		 if (volume < MIN_VOLUME || volume > MAX_VOLUME)
			 throw std::runtime_error("Volume must be between 0 and MIX_MAX_VOLUME");

		 if constexpr (type == SoundType::SOUND_EFFECT)
			 Mix_Volume(channel, volume);
		 else
			 Mix_VolumeMusic(volume);
	 }

	 int getVolume() {
		 if (!loaded)
			 return 0;
		 if constexpr (type == SoundType::SOUND_EFFECT)
			 return Mix_Volume(channel, GET_VOLUME);
		 else
			 return Mix_VolumeMusic(GET_VOLUME);
	 }
};


#endif //SDL3_TEMPLATE_PROJECT_SOUND_H
