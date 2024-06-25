#include "GameState.h"
#include "menuManager.h"

GameState::GameState()
	:
	flap(170.0f, BLACK),
	pipes(3.0f, GREEN)
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














	
	

