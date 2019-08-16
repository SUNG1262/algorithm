#include "Linked_list_02.h"
#include <iostream>

using namespace std;

void run2(int p_num)
{
	list unsorted = {0, NULL}; // list 구조체 num = 0; Head = NULL(0x000000);
	list* sorted = new list;
	sorted->num_node = 0;
	sorted->Head = NULL;
	insertLast(&unsorted, 7);
	insertLast(&unsorted, 4);
	insertLast(&unsorted, 4);
	insertLast(&unsorted, 4);
	insertLast(&unsorted, 4);
	insertLast(sorted, 3);
	insertLast(sorted, 2);
	insertLast(sorted, 1);
	printNode(&unsorted);
	printNode(sorted);
	 
	int k=0;
	switch (p_num)
	{
	case 1:
		cout << "[Q2.1] deleteDuple()\n검사할 list num을 입력해주세요" << endl;
		cin >> k; // 이미 정의된 리스트
		if (k == 1) {
			deleteDuplewithIterator(&unsorted);
		}
		else
			deleteDuplewithIterator(sorted);
		break;
	case 2:
		cout << "[Q2.2] findfromLast()\n검사할 노드의 숫자를 입력해주세요" << endl;
		cin >> k;
		findfromLast(&unsorted, k);
		break;
	default:
		cout << "숫자 입력 필요함" << endl;
		break;
	}

}

/// Add node Last
void insertLast(list* l, int data)
{
	node* cur = l->Head;
	node* newnode = new node; // dynamic allocation
	newnode->data = data;
	newnode->Next = nullptr;
	if (cur == nullptr) { // c++ 11 부터. NULL = 0 임
		l->Head = newnode;
	}
	else {
		while (cur->Next != nullptr) {
			cur = cur->Next;
		}
		cur->Next = newnode; // 그 끝에 동적할당 된 노드를 연결
	}
}

void deleteDuplewithTABLE(list * l)
{
}

void deleteDuplewithIterator(list * l)
{
}

/// Already stored the number of node.
/// ASSUME : didn't know the number of node.
/// Runner Vs length - k?
/// 1) Runner
/// 2) Length : int varaible are reuqired.
node * findfromLast(list* l, int n)
{
	node* cur = l->Head;
	node* runner = cur;
	if (cur == nullptr) {
		return nullptr;
	}
	else {
		for (int i = 0; i < n; i++) { // Node : 0-> 1 -> Nth
			if (runner->Next == nullptr) {
				printf("outofindex");
				exit(1);
			}
			runner = runner->Next;
		}
		while (runner->Next != nullptr) { // Nth -> N + 1 -> Last Node 
			runner = runner->Next;
			cur = cur->Next;
		}
	}
	printf("%d", cur->data);
	return cur;
}

void printNode(list * l)
{
	node* cur = l->Head;
	while (cur) {
			cout << cur->data << "-->";
			cur = cur->Next;
		}
		cout << "NULL" << endl;
}
