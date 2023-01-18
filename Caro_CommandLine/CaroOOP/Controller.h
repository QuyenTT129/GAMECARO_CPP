#pragma once
#include "Match.h"
#include "Data.h"

class Controller {
	Data d;
	Match m;
	bool isGameOver = false;
	bool draw = false;
public:
	void controller();
	Match& getMatch();
};