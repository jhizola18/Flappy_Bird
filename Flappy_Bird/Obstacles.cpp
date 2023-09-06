#include "Obstacles.h"
#include <raylib.h>
#include  <iostream>



///FIX THE PIPES DISTANCE EACH OTHER
///FIX THE Birds velocity when going down make it more faster not hover like vel;


Pipe::Pipe(float tubeSpeed_in, int maxTubes_in, Color color_in)
	:
	rec(rec),
	color(color_in),
	maxTubes(maxTubes_in),
	tubeSpeed(tubeSpeed_in)

{
	//std::list<Rectangle>::iterator topitr;
	
	for (int i = 0; i < getMax(); ++i)
	{
			float tubeGap = 150.0f;;
			float tubeWidth = 70.0f;
			int minY = tubeGap; //120 min
			int maxY = GetScreenHeight() - tubeGap - minY; //360 max

			float topTubeHeight = GetRandomValue(minY, maxY);
			float bottomTubeHeight = GetScreenHeight() - tubeGap - topTubeHeight;

			topPipes.push_back(Rectangle{ rec.x + i * (tubeGap + tubeWidth), 0, tubeWidth, topTubeHeight });

	}

	for (int i = 0; i < maxTubes; ++i)
	{

		float tubeGap = 150.0f;;
		float tubeWidth = 70.0f;
		int minY = tubeGap; //120 min
		int maxY = GetScreenHeight() - tubeGap - minY; //360 max

		float topTubeHeight = GetRandomValue(minY, maxY);
		float bottomTubeHeight = GetScreenHeight() - tubeGap - topTubeHeight;

		
		botPipes.push_back(Rectangle{ rec.x + i * (tubeGap + tubeWidth), GetScreenHeight() - bottomTubeHeight, tubeWidth, bottomTubeHeight });
	}	
};

void Pipe::Draw()
{

	DrawObstacle();

}
int Pipe::getMax() const
{
	return maxTubes;
}
;




void Pipe::setRec(Rectangle rec_in)
{
	for (auto topitr = topPipes.begin(); topitr != topPipes.end(); ++topitr)
	{
		*topitr = rec_in;
		rec = rec_in;
	}
	
}


Rectangle Pipe::getRec()
{
	return rec;
}


void Pipe::DrawObstacle()
{
	std::list<Rectangle>::iterator topitr;
	std::list<Rectangle>::iterator botitr;
		for (topitr = topPipes.begin(); topitr != topPipes.end(); ++topitr)
		{
			for (botitr = botPipes.begin(); botitr != botPipes.end(); ++botitr)
			{
				
					DrawRectangleRec(*topitr, color);
					DrawRectangleRec(*botitr, color);
				
			}
			
		}
		
};



void Pipe::updateObstacle()
{
	ObstacleMovement();
}


void Pipe::ObstacleMovement()
{
	
	

	for (auto topitr = topPipes.begin(); topitr != topPipes.end(); ++topitr)
	{
		topitr->x -= tubeSpeed;
	}

	for (auto botitr = botPipes.begin(); botitr != botPipes.end(); ++botitr)
	{
		botitr->x -= tubeSpeed;
	}
	

	//create to if statement for the pipe1 and pipe 2
	if (topPipes.front().x + topPipes.front().width < GetScreenWidth()/15)
	{
		
		float tubeGap = 150.0f;
		float tubeWidth = 70.0f;
		float minY = tubeGap;
		float maxY = GetScreenHeight() - tubeGap - minY;

		float topTubeHeight = GetRandomValue(minY, maxY);
		float bottomTubeHeight = GetScreenHeight() - tubeGap - topTubeHeight;
		

		topPipes.push_back(Rectangle{ topPipes.back().x + tubeGap + tubeWidth, 0,tubeWidth, topTubeHeight });
		topPipes.pop_front();

		botPipes.push_back(Rectangle{ botPipes.back().x + tubeGap + tubeWidth, GetScreenHeight() - bottomTubeHeight, tubeWidth, bottomTubeHeight });
		botPipes.pop_front();


	}


	if (topPipes.front().x + topPipes.front().width < GetScreenWidth()/15 )
	{
		
			topPipes.push_back(topPipes.front());
			topPipes.pop_front();

			botPipes.push_back(botPipes.front());
			botPipes.pop_front();
			
	}

	
}


//every 3 pair of pipes its showing the game over
//fix this tomorrow
/*void Pipe::checkCollision()
{

	
	//collision checker for top pipes and bot pipes 
	for (auto topitr = topPipes.begin(); topitr != topPipes.end(); ++topitr)
	{
		for (auto botitr = botPipes.begin(); botitr != botPipes.end(); ++botitr)
		{

			float radius = (float)20;
			Vector2 position = { GetScreenHeight() / 2 - (float)20 };
			flap.setRadius(radius);
			flap.setPos(position);

			if (CheckCollisionCircleRec(flap.getPos(), flap.getRadius(), *topitr))
			{
				DrawText("Game Over", 350, 300, 25, BLACK);
			}

			if (CheckCollisionCircleRec(flap.getPos(), flap.getRadius(), *botitr))
			{
				DrawText("Game Over", 350, 300, 25, BLACK);
			}

		}
		
	}

}*/












