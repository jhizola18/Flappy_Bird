#include "GameState.h"
#include "menuManager.h"

int scores = 0;

GameState::GameState()
	:
	flap(170.0f, BLACK),
	pipes()
{
};

bool GameState::check_Collision( flappy& flap, Pipe& pipes) const
{
	
	for (const auto& topPipe : pipes.getTopPipe())
	{
		if (CheckCollisionCircleRec(flap.getPos(), flap.getRadius(), topPipe))
		{
			return true;
		}
	}

	for (const auto& botPipe : pipes.getBotPipe())
	{
		if (CheckCollisionCircleRec(flap.getPos(), flap.getRadius(), botPipe))
		{	
			return true;
		}
	}

	return false;
}

void GameState::check_PastObastacle(flappy& flap, Pipe& pipes)
{
	
	for (const auto& item : pipes.getBotPipe()) {
		if (item.x < 0 && item.x + item.width < 0) {
			scores += 1;
			break;
		}
	}
	
}














	
	

