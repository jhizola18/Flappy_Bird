#include "Window_Init.h"   
#include "Game.h"
#include<memory>
#include "menuManager.h"
#include "Audio.h"


int main() {

	constexpr int screenWidth = 800;
	constexpr int screenHeight = 600;

	MainGame mainGame{ screenWidth, screenHeight, 74 ,"Flappy Bird" };
	InitAudioDevice();

	//Score score;
	AudioManager audioStart;
	Game game;

	Image image = LoadImage("image/spriteback.png");
	Texture2D Background = LoadTextureFromImage(image);
	
	//score.connect();
	
	while (!mainGame.gameShouldClose())
	{ 
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawTexture(Background, 0, 0, WHITE); 
		game.gameLoop();
		//DrawText(TextFormat("FPS: %d", GetFPS()), 100, 100, 25, BLACK);
		EndDrawing();
	}              
	UnloadImage(image);

	return 0;
}
 
    