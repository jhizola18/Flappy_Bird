#pragma once
#include "raylib.h"
#include <list>

extern int scoreCounter;
extern int highScore;

class Pipe {
private:

	Rectangle recTop, recBot;
	Color color;
	int tubeSpeed;
	float tubeGap;
	float tubeWidth;
	std::list<Rectangle> topPipes;
	std::list<Rectangle> botPipes;

	Vector2 startPos;
	Vector2 endPos;
	

public:
	Pipe(int tubeSpeed_in, Color color_in);
	~Pipe()noexcept;
	Pipe(const Pipe& other) = delete;
	Pipe& operator = (const Pipe& other) = delete;
	

public:
	void initializer();
	void DrawObstacle();
	void UpdateObstacle();
	int highScoreManager();
	void obstacleSpeed();
	void resetObstacle();

	//setter & getter
public:
	void setTubeSpeed(int tubeSpeed_in) const;
	int getTubeSpeed() const;
	void setTopPipe(std::list<Rectangle> topPipes);
	std::list<Rectangle> getTopPipe();
	void setBotPipe(std::list<Rectangle> botPipes);
	std::list<Rectangle> getBotPipe();
	void setTopRec(Rectangle rec_Top);
	Rectangle getTopRec();
	void setBotRec(Rectangle rec_Bot);
	Rectangle getBotRec();

public:
	float tubeminY;
	float tubemaxY;

	float topTubeHeight;
	float bottomTubeHeight;

};