#pragma once
#include "raylib.h"
#include "Window_Init.h"

typedef enum  gameScreen {Title = 0, titleBridge , Gameplay, Replay} gameScreen;

class menuManager {
private:
	Texture2D Background{};
public:
	menuManager();
	void titleScreen();
	void loadingAssets();
	void replayGame();
	void clearGround();

	void setTexture(Texture2D background_in);

	Texture2D getTexture();

	
};
