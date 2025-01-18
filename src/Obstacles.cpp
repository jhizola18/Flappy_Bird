#include <iostream>
#include "Obstacles.h"




//setter/getter
void Pipe::setTopPipe(std::list<Rectangle> topPipes)
{
	this->topPipes = topPipes;

}

std::list<Rectangle> Pipe::getTopPipe()
{
	return topPipes;
}

void Pipe::setBotPipe(std::list<Rectangle> botPipes)
{
	this->botPipes = botPipes;
}

std::list<Rectangle> Pipe::getBotPipe()
{
	return botPipes;
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


Pipe::Pipe()
	:
	recTop(getTopRec()),
	recBot(getBotRec()),
	color(GREEN),
	tubeGap(150.0f),
	tubeWidth(70.0f)
{
	float tubeminY = tubeGap;
	float tubemaxY = GetScreenHeight() - tubeGap - tubeminY;

	float topTubeHeight =  GetRandomValue(tubeminY, tubemaxY);;
	float bottomTubeHeight =  GetScreenHeight() - tubeGap - topTubeHeight;

	topPipes.push_back(Rectangle{ (float)GetScreenWidth() , 0,tubeWidth, topTubeHeight });
	botPipes.push_back(Rectangle{ (float)GetScreenWidth(), GetScreenHeight() - bottomTubeHeight, tubeWidth, bottomTubeHeight });

	startPos = {(float)GetScreenWidth() - 20.0f, 0.0f};
	endPos = {(float)GetScreenWidth() - 20.0f,(float)GetScreenHeight()};
	tubeSpeed = 250.0f;
}

Pipe::~Pipe() noexcept
{
	topPipes.clear();
	botPipes.clear();
}

void Pipe::resetObstacle()
{
	
	tubeminY = tubeGap;
	tubemaxY = GetScreenHeight() - tubeGap - tubeminY;

	topTubeHeight = GetRandomValue(tubeminY, tubemaxY);;
	bottomTubeHeight = GetScreenHeight() - tubeGap - topTubeHeight;

	startPos = { (float)GetScreenWidth() - 20.0f, 0.0f };
	endPos = { (float)GetScreenWidth() - 20.0f,(float)GetScreenHeight() };

	topPipes.push_back(Rectangle{ (float)GetScreenWidth() , 0,tubeWidth, topTubeHeight });
	botPipes.push_back(Rectangle{ (float)GetScreenWidth(), GetScreenHeight() - bottomTubeHeight, tubeWidth, bottomTubeHeight });
}

void Pipe::removeObstacle()
{
	topPipes.clear();
	botPipes.clear();
}

void Pipe::initializer()
{
	startPos.x -= 8.5f;
	endPos.x -= 8.5f;
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


void Pipe::UpdateObstacle()
{
	tubeminY = tubeGap;
	tubemaxY = GetScreenHeight() - tubeGap - tubeminY;

	topTubeHeight = GetRandomValue(tubeminY, tubemaxY);;
	bottomTubeHeight = GetScreenHeight() - tubeGap - topTubeHeight;

	//if (startPos.x  < GetScreenWidth()/2.0f)
	//{
	//not popping the front this is not working after resetting the game
	if (botPipes.front().x + botPipes.front().width < 0 && botPipes.front().x < 0 && !topPipes.empty() && !botPipes.empty())
	{
		std::cout << "pop Front\n";
		botPipes.pop_front();
		topPipes.pop_front();
			
	}
	
		
	topPipes.push_back(Rectangle{ topPipes.back().x + tubeGap + tubeWidth , 0,tubeWidth, topTubeHeight});
	botPipes.push_back(Rectangle{ botPipes.back().x + tubeGap + tubeWidth, GetScreenHeight() - bottomTubeHeight, tubeWidth, bottomTubeHeight });
	//}	
}



void Pipe::obstacleSpeed()
{
	for (auto& Toppipe : topPipes)
	{
		Toppipe.x -= tubeSpeed * GetFrameTime();
	}

	for (auto& Botpipe : botPipes)
	{
		Botpipe.x -= tubeSpeed * GetFrameTime();
	}
}


















