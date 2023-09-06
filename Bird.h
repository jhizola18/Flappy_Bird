#pragma once
#include <raylib.h>




class flappy
{
private:
	Vector2 position;
	float radius;
	float gravity;
	const Color color;
	
	
public:

	flappy(float gravity ,Color color);
	void setRadius(float radius_in);
	float getRadius() const;
	void setPos(Vector2 pos);
	Vector2 getPos() const;
	void DrawBird();
	void bird_Movement();
	void deadBird();
	void birdReset();

};                 