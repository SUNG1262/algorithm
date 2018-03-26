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
		cout << "[Q1.1] IsCharUnique()\n검사할 string을 입력해주세요" << endl;
		cin >> str1;
		success = IsCharUnique(str1);
		printResult(success, "Unique");
		break;
	case 2:		
		cout << "[Q1.2] reverseString()\n검사할 string을 입력해주세요" << endl;
		cin >> buffer; // char* 초기화를 위해서
		charArr = buffer;
		reverseString(charArr); // function overloading
		break;
	case 3:
		cout << "[Q1.3] Stirng1, String2와의 관계가 뒤바뀐 순열인지?\n검사할 string1을 입력해주세요" << endl;
		cin >> buffer; // char* 초기화를 위해서
		charArr = buffer;
		cout << "검사할 string2을 입력해주세요" << endl;
		cin >> str3;
		success = IsAnagram(charArr,str3);
		printResult(success, "Anagram");
		break;
	case 4:
		cout << "[Q1.4] Make URLString\ string을 입력해주세요" << endl;
		//cin >> buffer; // " "을 입력받을 수 있는가
		cin.ignore();
		cin.getline(buffer, 30);
		success = makeURLString(buffer,30);
		//printResult(success, "변환 성공");
		break;
	default:
		cout << "숫자 입력 필요함" << endl;
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

/// parameter string type일 때, cin을 통해 string으로 처리하기 용이
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
	char* copyStr = str; // str copy하지 않을 시, str의 위치를 잃으면 copy가 안됨
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
/// 방법 1) sorting	2) 문자의 출현횟수가 같은가 
bool IsAnagram(string s1, string s2)/// 방법 2 적용
{
	char asc[SIZE_ASCII+1] = { 0 };
	if (s1.length() != s2.length()) {
		return false;
	}
	else {//길이가 같다
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
///자료입력시 space를 받아드려야함 
bool makeURLString(char* str, int len) // 원본 문자열, 원본문자열 길이
{
	char* pChar = str;//초기화
	char* url = new char[3*len]; // < 3*len임 
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
		cout << "결과 : " << message << endl;
	else {
		cout << "결과 : Not " << message << endl;
	}
}