#pragma once
#include <iostream>
#include <vector>


using namespace std;
class Board {
	int rows = 10;
	int columns = 10;
	vector<vector< char>> point;

public:
	void resizeVector(vector <vector<char>>& _point);
	int getRows();
	int getColumns();
	void setSize(int& _rows, int& _columns);
	void setPoint(vector<vector< char>>& _point);
	vector<vector< char>>& getPoint();
	void plotBoard();
	void plotCaro();

};
