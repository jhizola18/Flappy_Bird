#include "Window_Init.h"
#include <assert.h>

MainGame::MainGame(int Width, int Height, int fps, std::string title)
{
	assert(!GetWindowHandle());
	InitWindow(Width, Height, title.c_str());
	SetTargetFPS(fps);
};

MainGame::~MainGame() noexcept
{
	CloseWindow();
}

bool MainGame::gameShouldClose() const
{
	return WindowShouldClose();
}



