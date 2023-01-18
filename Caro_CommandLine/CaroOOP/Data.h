#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Data {
public:
	int countLine();
	void saveData(string Name, int win, int draw, int lose);
	void checkName(string TEN);
	void printListPlayer();

	
};