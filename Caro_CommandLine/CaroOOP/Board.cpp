#include "Board.h"

void Board::setSize(int& _rows, int& _columns) {
	rows = _rows;
	columns = _columns;
}
int Board::getRows() { return rows; }
int Board::getColumns() { return columns; }

void Board::setPoint(vector<vector< char>>& _point) {
	point = _point;
}
vector<vector< char>>& Board::getPoint() { return point; }

void Board::plotBoard() {
	cout << "-----------------------------------------" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << "| " << point[i][j] << " ";
		}
		cout << "|" << endl;
		cout << "-----------------------------------------" << endl;
	}
}
void Board::resizeVector(vector <vector<char>>& _point) {
	_point.resize(rows);
	for (int i = 0; i < rows; ++i)
		_point.at(i).resize(columns);
}
void Board::plotCaro()
{
	point.resize(rows);
	for (int i = 0; i < rows; ++i)
		point.at(i).resize(columns);
	// Tạo ô trống để điền XO
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			point.at(i).at(j) = ' ';
		}
	}
}
