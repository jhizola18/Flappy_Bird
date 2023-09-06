#pragma once
#include "raylib.h"
#include "Window_Init.h"
#include "GameState.h"

typedef enum  gameScreen {Title = 0, titleBridge , Gameplay, Replay} gameScreen;

class menuManager {
private:
	
	Texture2D Background;


public:
	menuManager();
	void titleScreen();
	void loadingAssets();
	void replayGame();
	void backGround();
	void clearGround();

	void setTexture(Texture2D back_Ground);

	Texture2D getTexture();

	
};
