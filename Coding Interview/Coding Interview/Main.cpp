///// run
/////#include "Array_String_01.h"
//#include "Linked_list_02.h"
/////STL
//#include <iostream>
//#include <string>
//#include <list>
//#include <stdlib.h>
//using namespace std;
/////User define
//
//void strcat(char ch[], char* add) {
//	char* end = ch;
//	while (*end) {
//		end++;
//	}
//	while (*add) {
//		*end++ = *add++;
//	}
//	*end = '\0';
//	printf("%s", ch);
//
//	return;
//}
//void rev(char* ss) {
//	char* e = ss;
//	char* s = ss;
//	while (*e) {
//		e++;
//	}
//	e--;
//	while (s < e) {
//		char t;
//		t = *e;
//		*(e--) = *s;
//		*(s++) = t;
//	}
//
//	cout << ss;
//}
//char* itoch(int num, char* arr)
//{
//	int d = 1;
//	int idx = 0;
//	char ch;
//	while (num / d > 0) {
//		d *= 10;
//	}
//	d /= 10;
//	while (num > 0) {
//		ch = num / d + '0';
//		num -= (num / d) * d;
//		arr[idx++] = ch;
//		d /= 10;
//	}
//	arr[idx] = '\0';
//	return arr;
//}
//
//
//int main() {
//	int n;
//	//freopen("String.txt", "r", stdin);
//	//scanf("%d", &n);
//
//	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // 메모리누수 탐지
//
//	//cout << "문제번호 입력 후 엔터" << endl;
//	//cin >> n;
//	//run2(n);
//	/*char word[10] = "hello";
//	cout << sizeof(word) / sizeof(char) << endl;
//
//	cout << strlen(word) << endl;
//	*/
//	int num = 123;
//	//char* s;
//	char* s = (char*) malloc(sizeof(char)*100);
//	//char* arr = (char*)malloc(sizeof(char)*(len + 1));
//	s=itoch(num,s);
//	cout << s;
//	return 0;
//
//}
