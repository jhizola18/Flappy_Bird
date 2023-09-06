#pragma once
#include "raylib.h"
#include "Bird.h"
#include "Obstacles.h"
#include "GameState.h"
#include "highScore.h"
#include "menuManager.h"

extern bool gameOver;
extern int frameCounter;

class Game {
private:
	flappy flap;
	Pipe pipe;

	Collision collision;
	scoreManager score;
	menuManager manager;
	


public:
	Game();
	void CollisiongChecker();
	void drawGame();
	void resetGame();
	void gameLoop();
	
};
