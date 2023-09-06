#include "GameState.h"
#include <iostream>
#include "Bird.h"


Collision::Collision(flappy flap, Pipe pipe)
	:
	pipe(pipe),
	flap(Vector2{ 80.0f, GetScreenHeight() / 2 - (float)20 }, (float)20, BLACK)
	
{
};


void Collision::check_Collision()
{
	/*if (CheckCollisionCircleRec(flap.getPos(), flap.getRadius(), pipe.getRec()))
	{
		DrawText("Game Over", 350, 300, 25, BLACK);
	}*/
	for (int i = 0; i < pipe.getMax(); ++i)
	{
		float tubeGap = 150.0f;
		float tubeWidth = 70.0f;
		float minY = tubeGap;
		float maxY = GetScreenHeight() - tubeGap - minY;

		float topTubeHeight = GetRandomValue(minY, maxY);
		float bottomTubeHeight = GetScreenHeight() - tubeGap - topTubeHeight;

		Rectangle topPipes = { pipe.getRec().x + i * (tubeGap + tubeWidth), 0, tubeWidth, topTubeHeight };
		Rectangle botPipes = { pipe.getRec().x + i * (tubeGap + tubeWidth), GetScreenHeight() - bottomTubeHeight, tubeWidth, bottomTubeHeight };

		//flap.setPos(Vector2{80.0f, GetScreenHeight() / 2 - (float)20});
		//flap.setRadius((float)20);
		/*(if (CheckCollisionCircleRec({flap.getPos().x, flap.getPos().y}, flap.getRadius(), {topPipes}))
		{
			DrawText("Game Over", 350, 300, 25, BLACK);
		}

		if (CheckCollisionCircleRec({ flap.getPos().x, flap.getPos().y }, flap.getRadius(), { botPipes }))
		{
			DrawText("Game Over", 350, 300, 25, BLACK);
		}*/
		
		//DO SOMETHING FOR THE COLLISION
		if (flap.getPos().y + flap.getRadius() > topPipes.width && flap.getPos().y + flap.getRadius() > topPipes.height || flap.getPos().y - flap.getRadius() < botPipes.height && flap.getPos().y - flap.getRadius() < botPipes.width)
		{
			DrawText("Game Over", 350, 300, 25, BLACK);
		}


	}
	
	
};
