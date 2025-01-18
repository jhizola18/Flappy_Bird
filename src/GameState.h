#pragma once
#include <raylib.h>
#include "Bird.h"
#include "Obstacles.h"
#include "score.h"


class GameState {
private:
	flappy flap;
	Pipe pipes;
	Score score;

public:
	
	GameState();
	bool check_Collision( flappy& flap,  Pipe& pipes) const;
	void check_PastObastacle(flappy& flap, Pipe& pipes);
	
};
