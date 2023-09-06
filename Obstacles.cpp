#include "Obstacles.h"
//global variable
int scoreCounter = 0;

//setter/getter
void Pipe::setTopPipe(std::list<Rectangle> topPipes)
{
	topPipes = topPipes;

}

std::list<Rectangle> Pipe::getTopPipe()
{
	return topPipes;
}

void Pipe::setBotPipe(std::list<Rectangle> botPipes)
{
	botPipes = botPipes;
}

std::list<Rectangle> Pipe::getBotPipe()
{
	return botPipes;
}

void Pipe::setTubeGap(float tubeGap)
{
	tubeGap = tubeGap;
}

float Pipe::getTubeGap()
{
	return tubeGap;
}

void Pipe::setTubeWidth(float tubeWidth)
{
	tubeWidth = tubeWidth;
}

float Pipe::getTubeWidth()
{
	return tubeWidth;
}

void Pipe::setTopRec(Rectangle rec_Top)
{
	recTop = rec_Top;
}

Rectangle Pipe::getTopRec()
{
	return recTop;
}

void Pipe::setBotRec(Rectangle rec_Bot)
{
	recBot = rec_Bot;
}

Rectangle Pipe::getBotRec()
{
	return recBot;
}

void Pipe::setTubeSpeed(float tubeSpeed_in)
{
	tubeSpeed = tubeSpeed_in;
}

int Pipe::getTubeSpeed()
{
	return tubeSpeed;
}

//Find a way to spawn obstacles outside the Screen or middle of the screen
//constructor
Pipe::Pipe(float tubeSpeed_in, Color color_in)
	:
	recTop(getTopRec()),
	recBot(getBotRec()),
	color(color_in),
	tubeSpeed(tubeSpeed_in),
	tubeGap(150.0f),
	tubeWidth(70.0f)

{
	float minY = tubeGap; //120 min
	float maxY = GetScreenHeight() - tubeGap - minY; //360 max
	float topTubeHeight = GetRandomValue(minY, maxY);
	float bottomTubeHeight = GetScreenHeight() - tubeGap - topTubeHeight;

	topPipes.push_back(Rectangle{ (float)GetScreenWidth(), 0, tubeWidth, topTubeHeight });
	botPipes.push_back(Rectangle{ (float)GetScreenWidth(), GetScreenHeight() - bottomTubeHeight, tubeWidth, bottomTubeHeight });
}





void Pipe::DrawObstacle()
{
		for(const auto& topPipe : topPipes)
		{
			DrawRectangleRec(topPipe, color);
		}
		
		for (const auto& botPipe : botPipes)
		{
			DrawRectangleRec(botPipe, color);
		}
		
}

void Pipe::updateObstacle()
{
	ObstacleMovement(); 
}


void Pipe::scoreManager()
{
	
	DrawText(TextFormat("Score: %i", scoreCounter), 10, 10, 20, BLACK);
	
	if (topPipes.front().x + topPipes.front().width < 0)
	{
		scoreCounter += 1;
		
		topPipes.pop_front();
		botPipes.pop_front();
	}

	std::ifstream highScoreFile("highScore.txt");
	if (highScoreFile.is_open())
	{

		highScoreFile >> highScore;
		highScoreFile.close();

	}
	else {
		DrawText(" ", 10, 30, 20, BLACK);
	}
	DrawText(TextFormat("High-Score: %i", highScore), 10, 30, 20, BLACK);
}



void Pipe::ObstacleMovement()
{
	float minY = tubeGap;
	float maxY = GetScreenHeight() - tubeGap - minY;

	float topTubeHeight = GetRandomValue(minY, maxY);
	float bottomTubeHeight = GetScreenHeight() - tubeGap - topTubeHeight;

	if (topPipes.front().x + topPipes.front().width < GetScreenWidth())
	{
		
		

		topPipes.push_back(Rectangle{ topPipes.back().x + tubeGap + tubeWidth , 0,tubeWidth, topTubeHeight });
		botPipes.push_back(Rectangle{ botPipes.back().x + tubeGap + tubeWidth, GetScreenHeight() - bottomTubeHeight, tubeWidth, bottomTubeHeight });
	}


	for (auto& Toppipe : topPipes)
	{
		Toppipe.x -= tubeSpeed;
	}

	for (auto& Botpipe : botPipes)
	{
		Botpipe.x -= tubeSpeed;
	}
}
















