#include "Data.h"
#include <vector>


int Data::countLine() {
    ifstream f1;
    int numlines;
    string Line;
    f1.open("Data.txt");

    numlines = 0;
    while (getline(f1, Line)) {
        numlines = numlines + 1;
    }
    return numlines;

}
void Data::checkName(string TEN) {
    ifstream file;
    string fileName("Data.txt");
    file.open(fileName, ios::app);
    string line;
    vector<string> V;
    if (file.is_open()) {
       
        while (getline(file, line)) {

            //Khai báo biến kiểu string để lưu từng từ đọc được
            string str;
            //Đọc và in lần lượt các từ trong file
            while (file >> str) {
                V.push_back(str);
            }
        }
        int SIZE = V.size() / 4;
        for (int i = 0;i<SIZE;i++) {
            if (TEN==V[4*i]) {
              cout << "Name: " << TEN << "|| Win: " << V[4*i+1] << " /Draw: " << V[4*i+2] << " /Lose: " << V[4*i+3] << endl;
            }
            else {
                cout << TEN << " is a New Player" << endl;
                break;
            }
        }

        file.close();
    }
}

void Data::saveData(string Name, int win, int draw, int lose) {
	ofstream file("Data.txt", ios::app );

	file << Name << " ";
	file << win << " ";
	file << draw << " ";
	file << lose << endl;
	file.close();
}
void Data::printListPlayer() {
    ifstream file;
    string fileName("Data.txt");
    file.open(fileName, ios::app);
    string line;
    vector<string> V;
    if (file.is_open()) {

        while (getline(file, line)) {

            //Khai báo biến kiểu string để lưu từng từ đọc được
            string str;
            //Đọc và in lần lượt các từ trong file
            while (file >> str) {
                V.push_back(str);
            }
        }
        int SIZE = V.size() / 4;
        for (int i = 0; i < SIZE; i++) {
             cout << "Name: " << V[4*i] << "|| Win: " << V[4 * i + 1] << " /Draw: " << V[4 * i + 2] << " /Lose: " << V[4 * i + 3] << endl;
        }

        file.close();
    }
}