#pragma once
#include "raylib.h"
#include <string>
#include "Bird.h"
#include "Obstacles.h"
#include "GameState.h"


class MainGame
{
private:
	void Draw();
	void Update();
	flappy flap;
	Pipe pipe;

	Collision collision;

public:
	MainGame(int Width, int Height, int fps, std::string title);
	MainGame(const MainGame& other) = delete;
	MainGame& operator = (const MainGame& other) = delete;
	~MainGame() noexcept;
	bool gameShouldClose() const;
	void gameLoop();
};