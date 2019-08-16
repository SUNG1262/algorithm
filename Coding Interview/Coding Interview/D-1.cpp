#include <stdio.h>
#include <string.h>
#define max 31
int cnt = 0;
int pos = -1;
int ans[max * 2];
int stack[max * 2];

typedef struct element{
	int value;
}e;
e st[max];

void push(int i) {
	stack[++pos] = i;	
	ans[cnt++] = -1;
}
void pop() {
	ans[cnt++] = +1;
	pos--;
}

int main() {
	char str[max];
	scanf("%s", str);
	int j = 0;
	for (int i = 0; i < strlen(str); i++) {
		if ((str[i] - 'a') == j) {
			push(j);
			pop();
			j++;
		}
		else if (pos != -1 && stack[pos] == str[i] - 'a') {
			pop();
		}
		else {
			push(j);
			j++;
			i--;
		}
		if (j == strlen(str) + 2) //push가 한번 더 일어나면? stack에서 찾지못한 것이므로 break;함
			break;
	}
	if (cnt == strlen(str) * 2 - 1) {
		printf("impossible");
	}
	else {
		for (int i = 0; i < cnt; i++) {
			if (ans[i] == -1)
				printf("push\n");
			else
				printf("pop\n");
		}
	}
}