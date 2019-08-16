#pragma once

///linkedlist를 구현하는 방법
/// 1) 헤드포인터
/// 2) 헤드노드 (더미)
#ifndef LINKED_LIST_02_H
#define LINKED_LIST_02_H
//#define MAX_TABLE 100 // TODO : SIZE 결정하기 HASH TABLE.
/// TODO : class로 Generic하게 짜기
//template <class E> 
//class LinkedlistNode {
//private:  
//	E data;
//	node<E>* next;
//};
typedef struct LinkedlistNode {
	int data; //데이터의 수
	LinkedlistNode* Next; // 자기구조체
}node;

/// list 관리를 위한 '1) 헤드포인터' 방법
typedef struct LinkedList {
	int num_node; // data 개수 관리를 위해 추가
	node* Head;
}list;

void run2(int);
void insertLast(list* l, int data);
void deleteDuplewithTABLE(list* l); // 2.1 -1 
void deleteDuplewithIterator(list* l); // 2.1 -2 O(N^2) Square.
node* findfromLast(list* l, int n); // 2.2 Find Nth from last - OK
void printNode(list* l);
#endif // !LINKED_LIST_02_H
