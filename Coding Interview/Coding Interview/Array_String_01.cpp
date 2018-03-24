#include <iostream>
#include <string>
#include "Array_String_01.h"

//ASCII -127~128 but the real scope : 0~128. 
#define SIZE_ASCII 128

using namespace std;

void run(int p_num)
{
	bool success = false;
	//string str="";
	char* str=NULL;
	char buffer[30];
	switch (p_num)
	{
	case 1:
		cout << "[Q1.1] IsCharUnique()\n�˻��� string�� �Է����ּ���" << endl;
		cin >> str;
		success = IsCharUnique(str);
		if (success)
			cout << "��� : Unique" << endl;
		else {
			cout << "��� : Not Unique" << endl;
		}
		break;
	case 2:		
		cout << "[Q1.2] reverseString()\n�˻��� string�� �Է����ּ���" << endl;
		cin >> buffer; // char* �ʱ�ȭ�� ���ؼ�
		str = buffer;
		reverseString(str); // function overloading
		break;
	default:
		break;
	}

}

bool IsCharUnique(string str)
{
	if (str.length() > SIZE_ASCII) {
		return false;
	}
	else {
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

/// parameter string type�� ��, cin�� ���� string���� ó���ϱ� ����
bool reverseString(string str)
{
	if (str.length() == 0) {
		return false;
	}
	else {
		int s = 0, e = str.length() - 1;
		while (s < e) {
			char temp;
			temp = str[s];
			str[s++] = str[e];
			str[e--] = temp;
			//s++; e--;
		}
	}
	cout << str << endl; // local variable - call by value.
	return true;
}

///char* asdf/0
bool reverseString(char* str) // call by pointer - original will be changed
{
	int s=0, e=-1;
	char* copyStr = str; // str copy���� ���� ��, str�� ��ġ�� ������ copy�� �ȵ�
	//int length = sizeof(str) / sizeof(char);
	while (*copyStr != NULL) {
		e++;
		copyStr++;
	}
	if (e == -1) {
		return false;
	}
	while (s < e) {
		char temp;
		temp = str[s];
		str[s++] = str[e];
		str[e--] = temp;
	}
	cout << str << endl; // pointer
	return true;
}
