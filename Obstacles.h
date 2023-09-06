#pragma once
#include "raylib.h"
#include <list>
#include <fstream>
#include "raylib.h"
#include "Bird.h"


extern int scoreCounter;
extern int highScore;

class Pipe {
private:

	Rectangle recTop, recBot;
	Color color;
	float tubeSpeed;
	float tubeGap;
	float tubeWidth;
	std::list<Rectangle> topPipes;
	std::list<Rectangle> botPipes;
	

public:
	Pipe(float tubeSpeed_in, Color color_in);
	Pipe(const Pipe& other) = delete;
	Pipe& operator = (const Pipe& other) = delete;
	void setTopRec(Rectangle rec_Top);
	Rectangle getTopRec();
	void setBotRec(Rectangle rec_Bot);
	Rectangle getBotRec();
	void DrawObstacle();
	void ObstacleMovement();
	void updateObstacle();
	void scoreManager();
	//setter & getter
	void setTubeSpeed(float tubeSpeed_in);
	int getTubeSpeed();
	void setTopPipe(std::list<Rectangle> topPipes);
	std::list<Rectangle> getTopPipe();
	void setBotPipe(std::list<Rectangle> botPipes);
	std::list<Rectangle> getBotPipe();
	void setTubeGap(float tubeGap);
	float getTubeGap();
	void setTubeWidth(float tubeWidth);
	float getTubeWidth();


};