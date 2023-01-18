#include "Controller.h"
#include "Replay.h"

int main() {
	int menu;
	cout << "\tGAME CARO C++" << endl;
	cout << "\t-------------" << endl;
	cout << "\t1.Play Game  " << endl;
	cout << "\t2.List Player Information  " << endl;
	cout << "\t3.Replay  " << endl;
	cout << "\t4.Guide" << endl;
	cout << "\t5.Exit" << endl;
	cout << "Select to continue: ";

	cin >> menu;
	if (menu == 1) {
		cout << "PLAYER 1 - [X] \t PLAYER 2 = [O]\n" << endl;
		Controller c;
		c.getMatch().enterPlayer(); // Nhập tên 2 người chơi
		c.getMatch().getBoard().plotCaro();
		c.controller();
	}
	if (menu == 2) {
		cout << "\tList Player Information" << endl;
		cout << "\t-----------------------" << endl;
		Data d;
		d.printListPlayer();
	}
	if (menu == 3) {
		Replay r;
		string ID_Match;
		cout << "Please enter the Match ID: ";
		cin >> ID_Match;
		r.replayMatch(ID_Match);
	}
	if (menu == 4) {
		cout << "Guide to Pro-player:" << endl;
		cout << "https://gameviethoa.vn/cach-choi-co-caro-luon-thang-cung-voi-bi-quyet-tap-luyen-sieu-dinh/" << endl;
	}
	if (menu == 5) {
		system("cls");
	}
	return 0;
}
