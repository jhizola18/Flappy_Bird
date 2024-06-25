#pragma once
#include "raylib.h"



class AudioManager {
private:

	Sound sfx_Over;
	Sound sfx_Fly;

public:
	AudioManager();
	~AudioManager()noexcept;
	void gameOverSound();
	void wingSound();
	void pauseSound();
};