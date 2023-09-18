#pragma once
#include "raylib.h"



class AudioManager {
private:

	Sound sfx_Over;
	Sound sfx_Fly;

public:
	AudioManager();
	void InitAudio();
	void gameOverSound();
	void wingSound();
	void clearSound();
	void CloseSound();
	void pauseSound();
};