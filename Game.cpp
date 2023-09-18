#include "Game.h"


gameScreen currentScreen = Title;
int frameCounter = 0;
bool gameOver;

Game::Game()
	:
	flap(4.0f, BLACK),
	pipe((float)3.0f, GREEN),
	gameState(),
	manager()
{
}

void Game::CollisionChecker()
{
	if (!gameState.check_Collision(flap, pipe) && gameOver == false)
	{
		pipe.ObstacleMovement();
		pipe.obstacleSpeed();
		flap.bird_Movement();

	}else{
		if (frameCounter > 60)
		{
			audioManager.gameOverSound();
			currentScreen = Replay;
		}
		flap.deadBird();
		gameOver = true;
	}
}

void Game::drawGame()
{
	
	BeginDrawing();
	ClearBackground(RAYWHITE);
	flap.DrawBird();
	pipe.DrawObstacle();
	if (currentScreen == Title)
	{
		manager.titleScreen();

	}else if (currentScreen == titleBridge) {

		manager.loadingAssets();
	}
	else if (currentScreen == Replay) {

		DrawText(TextFormat("High-Score: %i", highScore), 325, 200, 25, BLACK);
		DrawText(TextFormat("Your Score: %i", scoreCounter), 335, 250, 25, BLACK);
		
		manager.replayGame();
		
	}else if (gameOver == true)
	{
		
	}
	else if (gameOver == false)
	{
		DrawText(TextFormat("Score: %i", scoreCounter), 10, 10, 20, BLACK);
	}
	EndDrawing();
}


void Game::resetGame()
{
	scoreCounter = 0;
	gameOver = false;
	frameCounter = 0;
	flap.birdReset();
	audioManager.clearSound();

}


void Game::gameLoop()
{
	drawGame();
	switch (currentScreen)
	{
	case Title:
		
		currentScreen = titleBridge;
		break;

	case titleBridge:

		frameCounter++;
		if (frameCounter > 120)
		{
			frameCounter = 0;
			currentScreen = Gameplay;
		}
		
		break;

	case Gameplay:
		
		frameCounter++;
		
		if (frameCounter > 120)
		{
			CollisionChecker();
		}
		break;
		
	case Replay: 
		
		if (IsKeyPressed(KEY_Y))
		{
			resetGame();
			currentScreen = Title;
		}
		else if (IsKeyPressed(KEY_ESCAPE))
		{
			CloseWindow();
		}
		
		break;
	}
	
}


