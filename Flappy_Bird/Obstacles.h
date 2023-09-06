#pragma once
#include "raylib.h"
#include <list>





class Pipe {
private:
	Rectangle rec;
	Color color;
	float tubeSpeed;
	const int maxTubes = 100;

	
public:
	Pipe(float tubeSpeed_in, int maxTubes_in, Color color_in);
	void DrawObstacle();
	void Draw();
	void ObstacleMovement();
	void updateObstacle();
	void setRec(Rectangle rec_in);
	Rectangle getRec();
	//void checkCollision();
	int getMax() const;


	std::list<Rectangle> topPipes;
	std::list<Rectangle> botPipes;

};