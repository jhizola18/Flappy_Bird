#include "Audio.h"



AudioManager::AudioManager()
	:
	sfx_Fly(),
	sfx_Over()
{
}

void AudioManager::InitAudio()
{
	InitAudioDevice();
}

void AudioManager::gameOverSound() 
{
	
	sfx_Over = LoadSound("Sounds/sfx_gameOver.mp3");
	if (!IsSoundReady(sfx_Over))
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
	sfx_Fly = LoadSound("Sounds/sfx_wing.mp3");
	PlaySound(sfx_Fly);
	SetSoundVolume(sfx_Fly,0.3f);
}

void AudioManager::clearSound()
{
	UnloadSound(sfx_Over);
	UnloadSound(sfx_Fly);
}

void AudioManager::CloseSound()
{
	CloseAudioDevice();
}
void AudioManager::pauseSound()
{
	PauseSound(sfx_Over);
	PauseSound(sfx_Fly);
};
