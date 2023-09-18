#pragma once
#include "raylib.h"
#include "Bird.h"
#include "Obstacles.h"
#include "GameState.h"
#include "menuManager.h"
#include "Audio.h"

extern bool gameOver;
extern int frameCounter;

class Game {
private:
	flappy flap;
	Pipe pipe;


	GameState gameState;
	menuManager manager;
	AudioManager audioManager;
	

public:

	Game();
	void CollisionChecker();
	void drawGame();
	void resetGame();
	void gameLoop();
};
