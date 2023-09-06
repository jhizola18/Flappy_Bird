#include "GameState.h"
#include "menuManager.h"



Collision::Collision()
	:
	flap(4.0f, BLACK),
	pipes((float)3.0f, GREEN)
	
{
};


bool Collision::check_Collision(flappy& flap, Pipe& pipes) const
{
	const auto& topPipes = pipes.getTopRec();
	const auto& botPipes = pipes.getBotRec();
	const Vector2 flapPos = flap.getPos();
	const float flapRadius = flap.getRadius();


	for (const auto& topPipe : pipes.getTopPipe())
	{
		if (CheckCollisionCircleRec(flapPos, flapRadius, topPipes))
		{
			DrawText("Game Over", 350, 300, 25, BLACK);
			
			return true;
		}
	}

	for (const auto& botPipe : pipes.getBotPipe())
	{
		if (CheckCollisionCircleRec(flapPos, flapRadius, botPipe))
		{
			DrawText("Game Over", 350, 300, 25, BLACK);
			return true;
		}
	}

	return false;
}












	
	

