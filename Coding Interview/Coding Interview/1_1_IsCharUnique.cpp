#include <iostream>
#include <string>
#include "IsCharUnique1_1.h"

//ASCII -127~128 but the real scope : 0~128. 
#define SIZE_ASCII 128

using namespace std;

void run(string input)
{
	bool success=false;
	IsCharUnique(input);
	if (success)
		cout << "Unique" << endl;
	else {
		cout << "Not Unique" << endl;
	}
}

bool IsCharUnique(string str)
{
	if (str.length() > SIZE_ASCII) {
		return false;
	}
	else {
		//bool* IsChar = new bool[SIZE_ASCII];
		bool IsChar[SIZE_ASCII + 1] = { false };
		for (int i = 0; i < str.length(); i++) {
			int index = str.at(i);
			if (!IsChar[index]) {
				IsChar[index] = true;
			}
			else {
				return false;
			}
		}
	}
	return true;
}
