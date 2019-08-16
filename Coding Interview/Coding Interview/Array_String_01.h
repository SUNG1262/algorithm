#pragma once
#include <string>
using namespace std;

#ifndef ARAAY_STRING_01_H
#define ARAAY_STRING_01_H
void run(int);
bool IsCharUnique(string); // 1.1 ASCII SCOPE
bool reverseString(string); // 1.2 string
bool reverseString(char*); // 1.2 char*
bool IsAnagram(string s1, string s2); // 1.3
bool makeURLString(char*, int); // 1.4 
string compressStringV1(string); // 1.5 - TODO : over 9, like 10, 100.
char* compressStringV2(char*); //1.5
void rotateMatrix(int** matrix, int n); // TODO 
void setzeroMatrix(int** matrix, int r, int c); // 1.7
bool IsRotation(string, string); // 1.8
bool isSubstring(string s1, string s2); // for 1.8 referring to 1.3(Anagram)
char* itoa(int num, char*);
void printResult(bool, string); 
#endif // !ARAAY_STRING_01_H
  