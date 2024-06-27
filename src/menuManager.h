#pragma once
#include "raylib.h"
#include "Window_Init.h"



typedef enum  gameScreen {Title = 0, titleBridge , Menu , Scores ,Gameplay, Replay} gameScreen;

class menuManager {
private:
	Texture2D Background{};
public:
	menuManager();
	~menuManager()noexcept;
	void titleScreen();
	void loadingAssets();
	void MenuScreen();
	void replayGame();
	void insertscore();

	void setTexture(Texture2D background_in);

	Texture2D getTexture();
};
