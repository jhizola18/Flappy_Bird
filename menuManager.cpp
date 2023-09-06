#include "menuManager.h"


menuManager::menuManager()
	:
	Background(Background)
{
}

void menuManager::titleScreen()
{
	BeginDrawing();
	ClearBackground(BLACK);
	DrawText("CLICK ENTER TO START", 230, 300, 30, WHITE);
	EndDrawing();
}

void menuManager::loadingAssets()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	DrawText("BASIC ASSETS LOADING", 230, 300, 30, BLACK);
	EndDrawing();
}

void menuManager::replayGame()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	DrawText("Want to play again?", 230, 300, 30, BLACK);
	DrawText("Click Y if Yes or Escape to Exit Windows", 130, 360, 30, BLACK);
	EndDrawing();
}
//fix performance
void menuManager::backGround()
{
	Background = LoadTexture("image/spriteback.png");
		ClearBackground(RAYWHITE);

		//Rectangle source = {0, 0,backGroundSize,backGroundSize};
		//Rectangle dest = { GetScreenWidth() / 2, GetScreenHeight() / 2, source.width, source.height};
		DrawTexture(Background, 0, 0, WHITE);
		
}
void menuManager::clearGround()
{
	UnloadTexture(Background);
}

void menuManager::setTexture(Texture2D back_Ground)
{
	Background = back_Ground;
}

Texture2D menuManager::getTexture()
{
	return Background;
}





