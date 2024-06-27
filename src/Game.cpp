#include <iostream>
#include "Game.h"


gameScreen currentScreen = Title;
int frameCounter = 0;
bool gameOver;


//REFACTOR AND CREATE MENU AND FINISH DATABASE
Game::Game()
	:
	flap(170.0f, BLACK),
	pipe(),
	gameState(),
	score()
{
}

Game::~Game() noexcept
{

}

void Game::CollisionChecker()
{
	if (gameState.check_Collision(flap, pipe) || flap.collision())
	{
		if (frameCounter > 60)
		{
			audioManager.gameOverSound();
			currentScreen = Replay;
		}
		flap.deadBird();
		gameOver = true;
		score.displayscore();
	}
}

void Game::resetGame()
{
	scoreCounter = 0;
	gameOver = false;
	frameCounter = 0;
	flap.birdReset();
	pipe.resetObstacle();
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

		frameCounter++;
		manager.loadingAssets();
		if (frameCounter > 120)
		{
			frameCounter = 0;
			currentScreen = Menu;
		}
		
		break;
	case Menu:

		manager.MenuScreen();
		if (IsKeyPressed(KEY_E)) {
			currentScreen = Gameplay;
		}


		break;

	case Gameplay:
		
		frameCounter++;
		
		flap.DrawBird();
		pipe.DrawObstacle();
		DrawText(TextFormat("Score: %i", scoreCounter), 10, 10, 20, BLACK);
		if (frameCounter > 120 && !gameOver)
		{
			pipe.initializer();
			pipe.UpdateObstacle();
			pipe.obstacleSpeed();
			flap.bird_Movement();
			CollisionChecker();
		}
		break;
		
	case Replay: 

		DrawText(TextFormat("High-Score: %i", highScore), 325, 200, 25, BLACK);
		DrawText(TextFormat("Your Score: %i", scoreCounter), 335, 250, 25, BLACK);

		manager.replayGame();
		if (IsKeyPressed(KEY_Y))
		{
			int rank;
			std::string name;
			int scored;
			std::cout << "Enter score: ";
			std::cin >> scored;
			std::cout << "\n";
			std::cout << "Enter name: ";
			std::cin >> name;
			std::cout << "Enter Rank: ";
			std::cin >> rank;
			std::cout << "\n";
			score.insertscore(rank, name, scored);
			resetGame();
			currentScreen = Title;
			
		}
		
		break;
	}
	
}


