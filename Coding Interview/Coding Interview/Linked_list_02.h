#pragma once

///linkedlist�� �����ϴ� ���
/// 1) ���������
/// 2) ����� (����)
#ifndef LINKED_LIST_02_H
#define LINKED_LIST_02_H
//#define MAX_TABLE 100 // TODO : SIZE �����ϱ� HASH TABLE.
/// TODO : class�� Generic�ϰ� ¥��
//template <class E> 
//class LinkedlistNode {
//private:  
//	E data;
//	node<E>* next;
//};
typedef struct LinkedlistNode {
	int data; //�������� ��
	LinkedlistNode* Next; // �ڱⱸ��ü
}node;

/// list ������ ���� '1) ���������' ���
typedef struct LinkedList {
	int num_node; // data ���� ������ ���� �߰�
	node* Head;
}list;

void run2(int);
void insertLast(list* l, int data);
void deleteDuplewithTABLE(list* l); // 2.1 -1 
void deleteDuplewithIterator(list* l); // 2.1 -2 O(N^2) Square.
node* findfromLast(list* l, int n); // 2.2 Find Nth from last - OK
void printNode(list* l);
#endif // !LINKED_LIST_02_H
