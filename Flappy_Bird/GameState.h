#pragma once
#include <raylib.h>
#include "Bird.h"
#include "Obstacles.h"

class Collision {
private:
	flappy flap;
	Pipe pipe;

	

public:
	Collision(flappy flap, Pipe pipe);
	void check_Collision();

};
