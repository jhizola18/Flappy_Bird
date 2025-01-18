#pragma once
#include "raylib.h"
#include <list>


class Pipe {
private:

	const Color color;
	int tubeSpeed;
	const float tubeGap;
	const float tubeWidth;
	std::list<Rectangle> topPipes;
	std::list<Rectangle> botPipes;

	Vector2 startPos;
	Vector2 endPos;

	float tubeminY;
	float tubemaxY;

	float topTubeHeight;
	float bottomTubeHeight;
	
public:
	Pipe();
	~Pipe()noexcept;
	Pipe(const Pipe& other) = delete;
	Pipe& operator = (const Pipe& other) = delete;
	

public:
	void initializer();
	void DrawObstacle();
	void UpdateObstacle();
	void obstacleSpeed();
	void resetObstacle();
	void removeObstacle();

	//setter & getter
public:
	//void setTubeSpeed(int tubeSpeed_in) const;
	//int getTubeSpeed() const;
	void setTopPipe(std::list<Rectangle> topPipes);
	std::list<Rectangle> getTopPipe();
	void setBotPipe(std::list<Rectangle> botPipes);
	std::list<Rectangle> getBotPipe();

	
};