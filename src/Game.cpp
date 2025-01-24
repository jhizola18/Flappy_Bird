#include <iostream>
#include "Game.h"

gameScreen currentScreen = Title;
int frameCounter = 0;
bool gameOver;
std::string playerName = "";

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
			
		}
		flap.deadBird();
		gameOver = true;
		score.displayscore();
		currentScreen = Replay;
	}
}

void Game::resetGame()
{                      
	scores = 0;
	gameOver = false;
	frameCounter = 0;
	flap.birdReset();
	pipe.removeObstacle();
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

		if (frameCounter > 120 && !gameOver)
		{
			gameState.check_PastObastacle(flap, pipe);
			CollisionChecker();
			DrawText(TextFormat("High-Score: %i", score.showHighScore()), 10, 10, 20, BLACK);
			DrawText(TextFormat("Score: %d", scores), 10, 25, 20, BLACK);
			pipe.initializer();
			pipe.UpdateObstacle();
			pipe.obstacleSpeed();
			flap.bird_Movement();

		}
		break;

	case Replay:
		DrawText(TextFormat("Your Score: %i", scores), 335, 250, 25, BLACK);
		manager.replayGame();

		score.current_highscore = score.highScoreManager(scores);
		if (scores > score.current_highscore) {
			playerName = manager.insertscore();
		}
		if (IsKeyPressed(KEY_Y))
		{
			if (scores > score.current_highscore) {
				int currentScore = scores;
				score.insertscore(playerName, score.highScoreManager(currentScore));
				scores = 0;
			}
			resetGame();
			currentScreen = Title;
		}
		
		
		
		break;
	default:
		break;
	}
	
}


