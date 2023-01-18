#pragma once
#include "Controller.h"
#include <Windows.h>
class Replay {
	vector<string> vtx, vty;
	string Name1, Name2;

	Board BOARD;


public: 
	void getData(string MatchID);
	vector<string> getVTX();
	vector<string> getVTY();
	void replayMatch(string MatchID);
};
