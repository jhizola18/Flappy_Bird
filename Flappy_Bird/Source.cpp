#include "Window_Init.h"
#include <iostream>

int main()
  {

	const int screenWidth = 800;
	const int screenHeight = 600;
	
	MainGame game{ screenWidth, screenHeight, 60 ,"Flappy Bird" };

	while(!game.gameShouldClose())
	{ 
		game.gameLoop();
	}

	return 0;
}   