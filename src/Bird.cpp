#include "Bird.h"

int vertSpeed = 0;

void flappy::setRadius(float radius_in)
{
	radius = radius_in;
}
float flappy::getRadius() const
{
	return radius;
}

void flappy::setPos(Vector2 pos)
{
	position = pos;
}

Vector2 flappy::getPos() const
{
	return Vector2(position);
};


flappy::flappy(float gravity, Color color)
	:
	position(Vector2{ 80.0f, 300 }),
	color(color),
	jumpSpeed(120),
	Audio()
{
	radius = 15;
	birdgravity = gravity;
};



void flappy::DrawBird()
{
	DrawCircleV(Vector2{position.x, position.y}, (float)radius, color);
}

void flappy::bird_Movement()
{
	float dt = GetFrameTime();
	if(IsKeyPressed(KEY_SPACE))
	{
		vertSpeed = jumpSpeed;
		Audio.wingSound();
	}
	//Formula for Bird falling 
	vertSpeed += -birdgravity * dt;
	//Formula for the circle to jump
	position.y -= (vertSpeed * 2) * dt;
}

void flappy::deadBird()
{
	
	position.y += 0;
	if (position.y + radius >= GetScreenHeight() || position.y - radius <= 0)
	{
		birdgravity *= 0;
	}
}


void flappy::birdReset()
{
	position = Vector2{ 80.0f, 300 };
}

bool flappy::collision()
{
	if (position.y + radius >= GetScreenHeight() || position.y - radius <= GetScreenHeight() / GetScreenHeight())
	{
		//this is to reverse the gravitational force that make the
		//the object move at the first place
		birdgravity *= 0;
		return true;
	}
	return false;
}



























