#include "highScore.h"
#include <iostream>
#include <string>

int highScore = 0;

void scoreManager::highScoreManager()
{
	

	if (scoreCounter > highScore)
	{
		highScore = scoreCounter - 1;
		std::ofstream scoreFile("highScore.txt");

		if (scoreFile.is_open())
		{
			
			scoreFile << highScore;

			scoreFile.close();
		}
		else {
			DrawText(" ", 10, 30, 20, BLACK);
		}

		std::ifstream highScoreFile("highScore.txt");
		if (highScoreFile.is_open())
		{
			highScoreFile >> highScore;
			highScoreFile.close();

			
		}
		else {
			DrawText(" ", 10, 30, 20, BLACK);
		}
	
	}
	
	ClearBackground(RAYWHITE);
	DrawText(TextFormat("High-Score: %i", highScore), 335, 250, 25, BLACK);
	DrawText(TextFormat("Your Score: %i", scoreCounter), 345, 300, 25, BLACK);
	DrawText("Press E", 360, 350, 25, BLACK);
	
}
