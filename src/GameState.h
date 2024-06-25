#pragma once
#include <raylib.h>
#include "Bird.h"
#include "Obstacles.h"


class GameState {
private:
	flappy flap;
	Pipe pipes;

public:
	
	GameState();
	bool check_Collision( flappy& flap,  Pipe& pipes) const;

};
