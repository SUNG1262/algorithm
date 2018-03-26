#include <iostream>
#include <string>
#include "Array_String_01.h"

//ASCII -127~128 but the real scope : 0~128. 
#define SIZE_ASCII 128

using namespace std;

void run(int p_num)
{
	bool success = false;
	string str1="", str3 ="";
	char* charArr=NULL;
	char buffer[30];
	switch (p_num)
	{
	case 1:
		cout << "[Q1.1] IsCharUnique()\n�˻��� string�� �Է����ּ���" << endl;
		cin >> str1;
		success = IsCharUnique(str1);
		printResult(success, "Unique");
		break;
	case 2:		
		cout << "[Q1.2] reverseString()\n�˻��� string�� �Է����ּ���" << endl;
		cin >> buffer; // char* �ʱ�ȭ�� ���ؼ�
		charArr = buffer;
		reverseString(charArr); // function overloading
		break;
	case 3:
		cout << "[Q1.3] Stirng1, String2���� ���谡 �ڹٲ� ��������?\n�˻��� string1�� �Է����ּ���" << endl;
		cin >> buffer; // char* �ʱ�ȭ�� ���ؼ�
		charArr = buffer;
		cout << "�˻��� string2�� �Է����ּ���" << endl;
		cin >> str3;
		success = IsAnagram(charArr,str3);
		printResult(success, "Anagram");
		break;
	case 4:
		cout << "[Q1.4] Make URLString\ string�� �Է����ּ���" << endl;
		//cin >> buffer; // " "�� �Է¹��� �� �ִ°�
		cin.ignore();
		cin.getline(buffer, 30);
		success = makeURLString(buffer,30);
		//printResult(success, "��ȯ ����");
		break;
	default:
		cout << "���� �Է� �ʿ���" << endl;
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

///1.2
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

///1.3 substring - permutation
/// ��� 1) sorting	2) ������ ����Ƚ���� ������ 
bool IsAnagram(string s1, string s2)/// ��� 2 ����
{
	char asc[SIZE_ASCII+1] = { 0 };
	if (s1.length() != s2.length()) {
		return false;
	}
	else {//���̰� ����
		for (int i = 0; i < s1.length(); i++) {
			asc[s1[i]]++;
		}
		for (int i = 0; i < s2.length(); i++) {
			if (--asc[s2[i]] < 0) {
				return false;
			}
		}
	}
	return true;
}

///1.4
///small -> big
///�ڷ��Է½� space�� �޾Ƶ������ 
bool makeURLString(char* str, int len) // ���� ���ڿ�, �������ڿ� ����
{
	char* pChar = str;//�ʱ�ȭ
	char* url = new char[3*len]; // < 3*len�� 
	int i = 0;
	while ((*pChar) != '\0') { //char '', str ""
		if ((*pChar) == ' ') {
			*(url + i) = '%';
			*(url + ++i ) = '2';
			*(url + ++i) = '0';
			i++;
		}
		else {
			*(url + i) = *pChar;
			i++;
		}
		pChar++;
	}
	*(url + i) = '\0';
	cout << url << endl;
	delete []url;
	return true;
} 

void printResult(bool res, string message) {
	if (res)
		cout << "��� : " << message << endl;
	else {
		cout << "��� : Not " << message << endl;
	}
}