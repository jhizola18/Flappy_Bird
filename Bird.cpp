#include "Bird.h"


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
	radius(15),
	color(color),
	gravity(gravity)

{
};



void flappy::DrawBird()
{
	DrawCircleV(Vector2{position.x, position.y}, (float)radius, color);
}



void flappy::bird_Movement()
{

	if(IsKeyDown(KEY_SPACE))
	{
		position.y -= 5;
	}
	else {
		//y position got updated bt adding the value of the current y position
		// and the gravity
		position.y += gravity;
	}
	
	if (position.y + radius >= GetScreenHeight() || position.y - radius <= 0)
	{
		//this is to reverse the gravitational force that make the
		//the object move at the first place
		gravity *= 0;
		
	}
}


void flappy::deadBird()
{
	position.y += 0;
	if (position.y + radius >= GetScreenHeight() || position.y - radius < 0)
	{
		gravity *= 0;
	}
}


void flappy::birdReset()
{
	position = Vector2{ 80.0f, 300 };
}


























