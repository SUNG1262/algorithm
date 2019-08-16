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
	int** matrix =NULL; // typedef int* IntArrayPtr;//���ϰ� ���𰡴� 

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
	case 5:
		cout << "[Q1.5] compressString\ string�� �Է����ּ���" << endl;
		cin >> buffer; // char* �ʱ�ȭ�� ���ؼ�
		charArr = buffer;
		compressStringV2(charArr);
		break;
	case 6:
		cout << "[Q1.6] rotateMatrix\ matrix�� ũ�⸦ �Է����ּ���" << endl;
		cin >> n; // char* �ʱ�ȭ�� ���ؼ�
		cout << "matrix�� ���Ҹ� ������� n�� �Է����ּ���  ex) 1 2 3 4 5 6 7 8 0 10" << endl;
		matrix = new int*[n]; // typedef int* IntArrayPtr;//���ϰ� ���𰡴� 
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
		cout << "[Q1.7] Matirx\ matrix�� row�� column�� �Է����ּ��� ex) 2 5" << endl;
		int r, c;
		cin >> r >> c;
		cout << "matrix�� ���Ҹ� ������� �Է����ּ���  ex) 1 2 3 4 5 6 7 8 0 10" << endl;
		// int** matrix = new int*[r]; 
		matrix = new int*[r]; // typedef int* IntArrayPtr;//���ϰ� ���𰡴� 
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
		cout << "[Q1.8] IsRotation\ string�� �Է����ּ���" << endl;
		cin >> str1 >> str3;
		if(IsRotation(str1, str3))
			printf("True");
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
///�ν��Ͻ��� �迭�� ���;� �ٲ� �� ����
bool reverseString(char* str) // call by pointer - original will be changed
{
	//int s=0, e=-1;
	//char* copyStr = str; // str copy���� ���� ��, str�� ��ġ�� ������ copy�� �ȵ�
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
/// ��� 1) sorting	2) ������ ����Ƚ���� ������ 
bool IsAnagram(string s1, string s2)/// ��� 2 ����
{
	char asc[SIZE_ASCII+1] = { 0, };
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

	while (*count != '\0') { //*count��°� �����ϱ�!
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
	nChar[index++] = cnt + '0'; // int�� char�� �ϸ� ���ϴ� �� ���� itoa
	nChar[index] = '\0';
	if (index < len)
		printf("%s", nChar);
	else
		printf("%s", arr);
	return nChar;
}

void rotateMatrix(int** matrix, int n)
{
	//int** result = new int*[n]; // typedef int* IntArrayPtr;//���ϰ� ���𰡴� 
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
	///w���� �迭�� ���� �� ����. �����迭 �Ұ���
//	int row = sizeof(matrix) / sizeof(matrix[0]);   // 2: 2���� �迭�� ���� ũ�⸦ ���� ���� �迭�� �����ϴ� ������ ���� �� ���� ũ��� ������
//	int col = sizeof(matrix[0]) / sizeof(int);      // 5: 2���� �迭�� ���� ũ��(��(������)�� ũ��) �� ���� ���� ���� �� ���� ����� ũ��� ������

	bool* IsRowZero = new bool[row];// bool IsRowZero[row] = { false }; row�� constant value�� �ƴϹǷ� ���ؽ� ����
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
		cout << "��� : " << message << endl;
	else {
		cout << "��� : Not " << message << endl;
	}
}