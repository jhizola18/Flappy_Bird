#pragma once
#include <raylib.h>
#include "Bird.h"
#include "Obstacles.h"




class Collision {
private:
	flappy flap;
	Pipe pipes;
	

public:
	
	Collision();
	bool check_Collision( flappy& flap,  Pipe& pipes) const;
};
