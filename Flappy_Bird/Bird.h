#pragma once
#include <raylib.h>


class flappy
{
private:
	Vector2 position;
	float radius;
	int gravity;
	const Color color;
	
	
public:

	flappy(Vector2 position,float radius, Color color);
	void DrawBird();
	void Draw();
	void bird_Movement();
	void setRadius(float radius_in);
	float getRadius();
	void setPos(Vector2 pos);
	Vector2 getPos();

};                 