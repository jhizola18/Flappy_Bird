#include "menuManager.h"


menuManager::menuManager() 
{
}

void menuManager::titleScreen()
{
	DrawText("CLICK ENTER TO START", 230, 300, 30, WHITE);
}

void menuManager::loadingAssets()
{
	DrawText("BASIC ASSETS LOADING", 230, 300, 30, BLACK);
}

void menuManager::replayGame()
{
	DrawText("Want to play again?", 260, 300, 30, BLACK);
	DrawText("Click Y if Yes or Escape to Exit Windows", 130, 360, 30, BLACK);
}

void menuManager::clearGround()
{
	UnloadTexture(Background);
}

void menuManager::setTexture(Texture2D background_in)
{
	  Background = background_in;
}

Texture2D menuManager::getTexture()
{
	return Background;
}





