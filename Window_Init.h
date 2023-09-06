#pragma once
#include "raylib.h"
#include "GameState.h"
#include <string>
#include "menuManager.h"





class MainGame
{
public:
	MainGame(int Width, int Height, int fps, std::string title);
	MainGame(const MainGame& other) = delete;
	MainGame& operator = (const MainGame& other) = delete;
	~MainGame() noexcept;
	bool gameShouldClose() const;


};