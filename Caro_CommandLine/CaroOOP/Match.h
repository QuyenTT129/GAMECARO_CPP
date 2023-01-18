#pragma once
#pragma once
#include "Board.h"
#include <vector>
#include "Player.h"
#include "Data.h"
#pragma once

class Match {
public:
	Data* dt;
	Board board;
	int matchID;
	Player player1, player2;
	int ID = 1;
	string NAME;

public:
	string getNAME();
	Player getPlayer1();
	Player getPlayer2();
	void printPlayer(Player _player);
	void setBoard(Board _board);
	Board& getBoard();

	bool checkChar(vector<vector<char>> v, int ROW, int COLUMN);
	void update();
	bool checkWin(bool draw);

	void enterPlayer();
};
