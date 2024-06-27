#include "Obstacles.h"
#include <fstream>

int scoreCounter = 0;
int highScore = 0;

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
	for (size_t i = 0; i < topPipes.size(); ++i) {
		topPipes.pop_front();
	}
	for (size_t i = 0; i < botPipes.size(); ++i) {
		botPipes.pop_front();
	}
}

void Pipe::resetObstacle()
{
	for (size_t i = 0; i < topPipes.size(); ++i) {
		topPipes.pop_front();
	}
	for (size_t i = 0; i < botPipes.size(); ++i) {
		botPipes.pop_front();
	}

	tubeminY = tubeGap;
	tubemaxY = GetScreenHeight() - tubeGap - tubeminY;

	topTubeHeight = GetRandomValue(tubeminY, tubemaxY);;
	bottomTubeHeight = GetScreenHeight() - tubeGap - topTubeHeight;

	startPos = { (float)GetScreenWidth() - 20.0f, 0.0f };
	endPos = { (float)GetScreenWidth() - 20.0f,(float)GetScreenHeight() };

	topPipes.push_back(Rectangle{ (float)GetScreenWidth() , 0,tubeWidth, topTubeHeight });
	botPipes.push_back(Rectangle{ (float)GetScreenWidth(), GetScreenHeight() - bottomTubeHeight, tubeWidth, bottomTubeHeight });
}

void Pipe::initializer()
{
	//DrawLine(startPos.x, startPos.y, endPos.x, endPos.y, BLACK);
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

	if (startPos.x  < GetScreenWidth()/2)
	{
		if (topPipes.front().x + topPipes.front().width < 0)
		{
			scoreCounter += 1;

			topPipes.pop_front();
			botPipes.pop_front();
		}

		topPipes.push_back(Rectangle{ topPipes.back().x + tubeGap + tubeWidth , 0,tubeWidth, topTubeHeight});
		botPipes.push_back(Rectangle{ botPipes.back().x + tubeGap + tubeWidth, GetScreenHeight() - bottomTubeHeight, tubeWidth, bottomTubeHeight });
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
	
	highScoreManager();
}



int Pipe::highScoreManager()
{
	if (scoreCounter > highScore)
	{
		highScore = scoreCounter - 1;
		std::ofstream scoreFile("highScore.txt");

		if (scoreFile.is_open())
		{

			scoreFile << highScore;

			scoreFile.close();
		}

		std::ifstream highScoreFile("highScore.txt");
		if (highScoreFile.is_open())
		{
			highScoreFile >> highScore;
			highScoreFile.close();
		}

		return highScore;
	}
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


















