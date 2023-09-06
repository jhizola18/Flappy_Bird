#include "Bird.h"
#include <raylib.h>
#include <iostream>




flappy::flappy(Vector2 position, float radius, Color color)
	:
	position(position),
	radius(radius),
	color(color)
	
{
	gravity = 5;
};


void flappy::DrawBird()
{
	DrawCircle(position.x, position.y, radius, color);	
}

void flappy::Draw()
{
	DrawBird();	
}


void flappy::bird_Movement()
{


	if(IsKeyDown(KEY_SPACE))
	{
		position.y -= 5;
		
	}else {
		//y position got updated bt adding the value of the current y position
		// and the gravity
		position.y = position.y + gravity;
	}

	if (position.y + radius >= GetScreenHeight() || position.y - radius < 0)
	{
		//this is to reverse the gravitational force that make the
		//the object move at the first place
		gravity *= 0;
		DrawText("Game Over", 350,  300, 25, BLACK);
		
	}
}




void flappy::setRadius(float radius_in)
{
	radius = radius_in;
}

float flappy::getRadius()
{
	return radius;
}


void flappy::setPos(Vector2 pos)
{
	position = pos;
}

Vector2 flappy::getPos()
{
	return position;
}











