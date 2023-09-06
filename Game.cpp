#include "Game.h"
#include<memory>

gameScreen currentScreen = Title;
int frameCounter = 0;
bool gameOver;

Game::Game()
	:
	flap(4.0f, BLACK),
	pipe((float)3.0f, GREEN),
	collision(),
	manager()
{
}

void Game::CollisiongChecker()
{
	
	if (!collision.check_Collision(flap, pipe) && gameOver == false)
	{
		
		pipe.ObstacleMovement();
		flap.bird_Movement();
	}
	else{
		score.highScoreManager();
		flap.deadBird();
		gameOver = true;
	}
	
}


void Game::drawGame()
{
	
	BeginDrawing();
	ClearBackground(LIGHTGRAY);
	manager.backGround();
	flap.DrawBird();
	pipe.DrawObstacle();
	pipe.scoreManager();
	
	EndDrawing();
	manager.clearGround();
}

//Find a way to destroy the pipe after the game
void Game::resetGame()
{
	
	BeginDrawing();
	ClearBackground(LIGHTGRAY);
	
	scoreCounter = 0;
	gameOver = false;
	frameCounter = 0;
	
	flap.birdReset();
	
	EndDrawing();
}


void Game::gameLoop()
{
	
	switch (currentScreen)
	{
	case Title:
		manager.titleScreen();
		currentScreen = titleBridge;
		break;

	case titleBridge:

		manager.loadingAssets();
		frameCounter++;
		if (frameCounter > 120)
		{
			frameCounter = 0;
			currentScreen = Gameplay;
		}
		
		break;

	case Gameplay:
	
		
		frameCounter++;
		
		drawGame();
		if (frameCounter > 120)
		{
			CollisiongChecker();
		}
		
		if (IsKeyPressed(KEY_E))
		{
			currentScreen = Replay;
		}
		break;

	case Replay: 
		
		manager.replayGame();
		if (IsKeyPressed(KEY_Y))
		{
			resetGame();
			currentScreen = Title;
		}
		else if (IsKeyPressed(KEY_ESCAPE))
		{
			WindowShouldClose();
		}
		
		break;
	}
	
}
