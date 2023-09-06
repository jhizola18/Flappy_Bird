#include "Window_Init.h"   
#include "Game.h"




int main() {

	constexpr int screenWidth = 800;
	constexpr int screenHeight = 600;
	
	menuManager manager{};

	MainGame mainGame{ screenWidth, screenHeight, 75 ,"Flappy Bird" };
	
	while (!mainGame.gameShouldClose())
	{
		Game game;
		do {
			
			game.gameLoop();
		} while (gameOver == false);
	}

	return 0;
}

