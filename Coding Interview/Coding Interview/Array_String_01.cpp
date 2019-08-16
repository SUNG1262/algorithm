#include <iostream>
#include <stdio.h>
#include <string>
#include "Array_String_01.h"

//ASCII -127~128 but the real scope : 0~128. 
#define SIZE_ASCII 128

using namespace std;

void run(int p_num)
{
	bool success = false;
	int n=0;
	string str1="", str3 ="";
	char* charArr=NULL;
	char buffer[30];
	int** matrix =NULL; // typedef int* IntArrayPtr;//편리하게 선언가능 

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
	case 5:
		cout << "[Q1.5] compressString\ string을 입력해주세요" << endl;
		cin >> buffer; // char* 초기화를 위해서
		charArr = buffer;
		compressStringV2(charArr);
		break;
	case 6:
		cout << "[Q1.6] rotateMatrix\ matrix의 크기를 입력해주세요" << endl;
		cin >> n; // char* 초기화를 위해서
		cout << "matrix의 원소를 순서대로 n개 입력해주세요  ex) 1 2 3 4 5 6 7 8 0 10" << endl;
		matrix = new int*[n]; // typedef int* IntArrayPtr;//편리하게 선언가능 
		for (int i = 0; i < n; i++) {
			matrix[i] = new int[n];
			for (int j = 0; j < n; j++) {
				cin >> matrix[i][j];
			}
		}
		cout << "Echoing the tow-dimensional array:\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << matrix[i][j] << " ";
			cout << endl;
		}
		rotateMatrix(matrix, n);
		for (int i = 0; i < n; i++) {
			delete[] matrix[i];
		}
		delete[] matrix;
		break;
	case 7:
		cout << "[Q1.7] Matirx\ matrix의 row와 column을 입력해주세요 ex) 2 5" << endl;
		int r, c;
		cin >> r >> c;
		cout << "matrix의 원소를 순서대로 입력해주세요  ex) 1 2 3 4 5 6 7 8 0 10" << endl;
		// int** matrix = new int*[r]; 
		matrix = new int*[r]; // typedef int* IntArrayPtr;//편리하게 선언가능 
		for (int i = 0; i < r; i++) {
			matrix[i] = new int[c];
			for (int j = 0; j < c; j++) {
				cin >> matrix[i][j];
			}
		}
		cout << "Echoing the tow-dimensional array:\n";
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++)
				cout << matrix[i][j] << " ";
			cout << endl;
		}
	/*	printf("%d\n", sizeof(matrix));
		printf("%d", sizeof(matrix[0]));
	*/
		setzeroMatrix(matrix, r, c);
		for (int i = 0; i < r; i++) {
			delete[] matrix[i];
		}
		delete[] matrix; 
		break;
	case 8:
		cout << "[Q1.8] IsRotation\ string을 입력해주세요" << endl;
		cin >> str1 >> str3;
		if(IsRotation(str1, str3))
			printf("True");
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
		bool IsChar[SIZE_ASCII + 1] = { false, };
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
///인스턴스가 배열로 들어와야 바꿀 수 있음
bool reverseString(char* str) // call by pointer - original will be changed
{
	//int s=0, e=-1;
	//char* copyStr = str; // str copy하지 않을 시, str의 위치를 잃으면 copy가 안됨
	//int length = sizeof(str) / size of(char);
	//while (*copyStr != NULL) {
	//	e++;
	//	copyStr++;
	//}
	//if (e == -1) {
	//	return false;
	//}
	//while (s < e) {
	//	char temp;
	//	temp = str[s];
	//	str[s++] = str[e];
	//	str[e--] = temp;
	//}
	//cout << str << endl; // pointer
	//return true;
	char* e = str;
	char* s = str;
	while (*e) {
		e++;
	}
	e--;
	while (s < e) {
		char t;
		t = *e;
		*(e--) = *s;
		*(s++) = t;
	}

	cout << str;
	return str;
}

///1.3 substring - permutation
/// 방법 1) sorting	2) 문자의 출현횟수가 같은가 
bool IsAnagram(string s1, string s2)/// 방법 2 적용
{
	char asc[SIZE_ASCII+1] = { 0, };
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
	while (*pChar) { //(*pChar) != '\0'char '', str ""
		if ((*pChar) == ' ') {
			*(url + i) = '%';
			*(url + ++i ) = '2';
			*(url + ++i) = '0';
	//		i++;
		}
		else {
			*(url + i) = *pChar;
		//	i++;
		}
		i++;
		pChar++;
	}
	*(url + i) = '\0';
	cout << url << endl;
	delete []url;
	return true;
} 
string compressStringV1(string str) {
	return str;
}
char * compressStringV2(char* arr)
{
	char* ch;
	char* count = arr;
	int cnt = 1;
	int i, index = 0;
	int len=0;

	while (*count != '\0') { //*count라는걸 주의하기!
		len++;
		count++;
	}
	char* nChar = new char[len+1];
	for (i = 1; i < len; i++) {
		if (arr[i] == arr[i - 1]) {
			cnt++;
		}
		else {
			nChar[index++] = arr[i - 1];
			//int temp = cnt;
			//int digit=0;
			//while (temp != 0) {
			//	temp /= 10;
			//	digit++;
			//} // 113(?)
			//if(cnt<10)
				nChar[index++] = cnt+'0';
		/*	else {
				nChar[index++] = cnt + '0';
			}*/
			cnt = 1;
		}
	}
	nChar[index++] = arr[i - 1];
	nChar[index++] = cnt + '0'; // int를 char로 하면 원하는 값 ㄴㄴ itoa
	nChar[index] = '\0';
	if (index < len)
		printf("%s", nChar);
	else
		printf("%s", arr);
	return nChar;
}

void rotateMatrix(int** matrix, int n)
{
	//int** result = new int*[n]; // typedef int* IntArrayPtr;//편리하게 선언가능 
	//for (int i = 0; i < n; i++) {
	//	result[i] = new int[n];
	//}
	//
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		result[j][-i + 2] = matrix[i][j];
	//	}
	//}
	//cout << "Result : the tow-dimensional array:\n";
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++)
	//		cout << result[i][j] << " ";
	//	cout << endl;
	//}
	//for (int i = 0; i < n; i++) {
	//	delete[] result[i];
	//}
	//delete[] result;
	
}
/// The two temp array is used.
/// 2*5 = row * column
void  setzeroMatrix(int** matrix, int row, int col)
{
	///w정적 배열만 구할 수 있음. 동적배열 불가능
//	int row = sizeof(matrix) / sizeof(matrix[0]);   // 2: 2차원 배열의 세로 크기를 구할 때는 배열이 차지하는 공간을 가로 한 줄의 크기로 나눠줌
//	int col = sizeof(matrix[0]) / sizeof(int);      // 5: 2차원 배열의 가로 크기(열(세로줄)의 크기) 를 구할 때는 가로 한 줄을 요소의 크기로 나눠줌

	bool* IsRowZero = new bool[row];// bool IsRowZero[row] = { false }; row가 constant value가 아니므로 신텍스 에러
	bool* IsColumnZero = new bool[col];

	///check
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (matrix[i][j] == 0) {
				IsRowZero[i] = true;
				IsColumnZero[j] = true;
			}
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (IsRowZero[i] == true || IsColumnZero[j] == true) {
				matrix[i][j] = 0;
			}
		}
	}

	cout << "Result : Echoing the tow-dimensional array:\n";
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}

}

///
/// s1 = erbottlewatt
/// s2 = watterbottle
bool IsRotation(string s1, string s2) {
	string s1s1;
	if (s1.length() != s2.length()) {
		return false;
	}
	s1s1 = s1 + s1;
	if(isSubstring(s1s1, s2))
		return true;
	return false;
}

///Is s2 a subsring from s1?
bool isSubstring(string s1, string s2)
{
	char asc[SIZE_ASCII + 1] = { 0 };
	for (int i = 0; i < s1.length(); i++) {
		asc[s1[i]]++;
	}
	for (int i = 0; i < s2.length(); i++) {
		if (--asc[s2[i]] < 0) {
			return false;
		}
	}
	return true;
}

//123
char* itoa(int num, char* arr)
{
	int d = 1;
	int idx = 0;
	char ch;
	while (num / d > 0) {
		d *= 10;
	}
	d /= 10;
	while (num > 0) {
		ch = num / d + '0';
		num -= (num / d) * d;
		arr[idx++] = ch;
		d /= 10;
	}
	arr[idx] = '\0';
	return arr;
}

void printResult(bool res, string message) {
	if (res)
		cout << "결과 : " << message << endl;
	else {
		cout << "결과 : Not " << message << endl;
	}
}