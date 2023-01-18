#include "Match.h"


void Match::setBoard(Board _board) { board = _board; }
Board& Match::getBoard() {
	return board;
}
string Match::getNAME() {
	return NAME;
}

void Match::printPlayer(Player _player) {
	cout << "Name: " << _player.getName() << "|| Win: " << _player.getWin() << " /Draw: " << _player.getDraw() << " /Lose: " << _player.getLose() << endl;
}
Player Match::getPlayer1() { return player1; }
Player Match::getPlayer2() { return player2; }

bool Match::checkChar(vector<vector<char>> v, int ROW, int COLUMN) {

	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++) {
			if (v[i][j] == ' ') {
				return false;
			}
		}

	}
}

void Match::enterPlayer() {
	cout << "Select Match ID: ";
	cin >> matchID;
	ofstream file("Replay.txt", ios::app);
	file << "ID " << matchID << " ";
	string p1, p2;
	cout << "Enter player 1 : ";
	cin >> p1;
	file << p1 << " ";
	player1.setName(p1);
	dt->checkName(p1);
	
	
	cout << "Enter player 2 : ";
	cin >> p2;
	file << p2 <<endl;
	player2.setName(p2);
	dt->checkName(p2);
}

void Match::update() {
	ID = (ID % 2) ? 1 : 2;

	char mark;
	if (ID == 1) {
		mark = 'X';
		NAME = player1.getName();
	}
	else if(ID == 2)
	{
		mark = 'O';
		NAME = player2.getName();
	}


	int x, y;
	do
	{
		cout << "Player " << ID <<" is "<<NAME<<" turn: ";
		cin >> x >> y;
		ofstream file("Replay.txt", ios::app);
		file << x << " ";
		file << y << " ";
		file.close();
	} while (x > board.getRows() - 1 || y > board.getColumns() - 1 || board.getPoint()[x][y] != ' ');

	if (board.getPoint()[x][y] == ' ') {
		board.getPoint()[x][y] = mark;
	}
	ID++;
}
bool Match::checkWin(bool _draw)
{

	for (int i = 0; i < board.getRows(); i++) {
		for (int j = 0; j < board.getColumns(); j++) {
			// CHECK NGANG
			if (board.getPoint()[i][j] != ' ' && board.getPoint()[i][j] == board.getPoint()[i][j + 1] && board.getPoint()[i][j+1] == board.getPoint()[i][j + 2] && board.getPoint()[i][j+2] == board.getPoint()[i][j + 3]) {
				return true;
			}
			// CHECK DỌC
			else if (board.getPoint()[i][j] != ' ' && board.getPoint()[i][j] == board.getPoint()[i + 1][j] && board.getPoint()[i+1][j] == board.getPoint()[i + 2][j] && board.getPoint()[i+2][j] == board.getPoint()[i + 3][j]) {
				return true;
			}
			//CHECK CHÉO
			else if (board.getPoint()[i][j] != ' ' && board.getPoint()[i][j] == board.getPoint()[i + 1][j + 1] && board.getPoint()[i][j] == board.getPoint()[i + 2][j + 2] && board.getPoint()[i][j] == board.getPoint()[i + 3][j + 3]) {
				return true;
			}
			
			// Tổng các phần tử trong board không còn ' ' nữa.
			else if (checkChar(board.getPoint(), board.getRows(), board.getColumns())) {
				_draw = true;
				return true;
			}
			return false;

		}
	}
}




