#include "Audio.h"



AudioManager::AudioManager()
	:
	sfx_Fly(),
	sfx_Over()
{
	sfx_Over = LoadSound("Sounds/sfx_gameOver.mp3");
	sfx_Fly = LoadSound("Sounds/sfx_wing.mp3");
}

AudioManager::~AudioManager() noexcept
{
	UnloadSound(sfx_Over);
	UnloadSound(sfx_Fly);
	CloseAudioDevice();
}


void AudioManager::gameOverSound() 
{

	if (!IsSoundValid(sfx_Over))
	{
		DrawText("Error In Sound", GetScreenWidth()/2, GetScreenHeight()/2, 40, BLACK);
	}
	else {

		PlaySound(sfx_Over);
		SetSoundVolume(sfx_Over, 0.3f);
	}
}

void AudioManager::wingSound()
{
	
	PlaySound(sfx_Fly);
	SetSoundVolume(sfx_Fly,0.3f);
}

void AudioManager::pauseSound()
{
	PauseSound(sfx_Over);
	PauseSound(sfx_Fly);
};
