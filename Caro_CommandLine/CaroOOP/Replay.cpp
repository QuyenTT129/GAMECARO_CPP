#include "Replay.h"

void Replay::getData(string MatchID) {
    ifstream file;
    string fileName("Replay.txt");
    file.open(fileName, ios::app);
    string line;
    vector<string> V;
    int IDT;

    if (file.is_open()) {

        while (getline(file, line)) {

            //Khai báo biến kiểu string để lưu từng từ đọc được
            string str;
            //Đọc và in lần lượt các từ trong file
            while (file >> str) {
                V.push_back(str);
            }
        }

        for (int i = 0; i < V.size(); i++) {
            if (V[i] == "ID") {
                if (MatchID == V[i + 1]) {
                    Name1 = V[i + 2];
                    Name2 = V[i + 3];
                    for (int k = 1; k < V.size() - i - 3; k++) {
                        if (V[i + 3 + k] == "ID") {
                            IDT = i + 3 + k;

                            for (int p = i + 4; p < IDT; p++) {
                                if (p % 2 == 0) {
                                    vtx.push_back(V[p]);
                                }
                                else {
                                    vty.push_back(V[p]);
                                }
                            }
                        }
                        else {
                            if ((i + 3 + k) % 2 == 0) {
                                vtx.push_back(V[i + 3 + k]);
                            }
                            else {
                                vty.push_back(V[i + 3 + k]);
                            }
                        }
                    }

                }
               
            }
        }


        file.close();
    }
}
vector<string> Replay::getVTX() {
    return vtx;
}
vector<string> Replay::getVTY() {
    return vty;
}
void Replay::replayMatch(string _MatchID) {
    getData(_MatchID);
    cout << " REPLAY MATCH ID: " << _MatchID << endl;
    cout << "Player 1: " << Name1 << " -[X]" << endl;
    cout << "Player 2: " << Name2 <<" -[O]" << endl;
    BOARD.plotCaro();
    BOARD.plotBoard();
    for (int i = 0; i < vtx.size(); i++) {
        if (i % 2 == 0) {
            BOARD.getPoint()[stoi(vtx[i])][stoi(vty[i])] = 'X';
            BOARD.plotBoard();
            cout << "Player : " << Name1 << " turn: ";
            cout << vtx[i] << " " << vty[i] << endl;
            Sleep(1000);
        }
        else{
            BOARD.getPoint()[stoi(vtx[i])][stoi(vty[i])] = 'O';
            BOARD.plotBoard();
            cout << "Player : " << Name2 << " turn: ";
            cout << vtx[i] << " " << vty[i] << endl;
            Sleep(1000);
        }
    }

}