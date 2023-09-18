#include "Window_Init.h"   
#include "Game.h"
#include<memory>
#include "menuManager.h"
#include "Audio.h"

//fix display of background
int main() {

	const int screenWidth = 800;
	const int screenHeight = 600;

	MainGame mainGame{ screenWidth, screenHeight, 75 ,"Flappy Bird" };
	
	GameState gameState;
	menuManager manager;
	AudioManager audioStart;
	
	Image image = LoadImage("image/spriteback.png");
	Texture2D Background = LoadTextureFromImage(image);

	audioStart.InitAudio();
	   
	UnloadImage(image);
	while (!mainGame.gameShouldClose())
	{ 
		//Game game;
		std::unique_ptr<Game> ptr = std::make_unique<Game>();
		do {
			DrawTexture(Background, 0, 0, WHITE);
			ptr->gameLoop();
			
		} while (gameOver == false);
		ptr.reset();
	} 
	    
	manager.clearGround();       
	audioStart.CloseSound();   
	return 0; 
}
 
    