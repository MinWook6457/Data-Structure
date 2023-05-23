/*
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#pragma warning(disable:4996)
#define MAX_TERM 100
typedef struct {
	int data[MAX_TERM];
	int capacity; // ���� ũ��
	int top;
}StackType;

void init_stack(StackType *s) {
	s->top = -1;
}

//���� ���� ���� �Լ�
int is_empty(StackType *s) {
	if (s->top == -1) {
		return 1;
	}
	else
		return 0;
}
//���� ��ȭ ���� �Լ�
int is_full(StackType *s) {
	if (s->top == (MAX_TERM- 1))
		return 1;
	else
		return 0;
}
//���� ���� �Լ�
void push(StackType *s, int item) {
	if (is_full(s)) {
		return 0;
	}
	s->top++;
	s->data[s->top] = item;
}
//���� ���� �Լ�
int pop(StackType *s) {
	if (is_empty(s)) {
		fprintf(stderr, "Empty Error\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}
void main() {
	StackType s;
	init_stack(&s);
	int x;
	printf("���� ũ�� �Է� : ");
	scanf("%d", &x);

	int *p = (int *)malloc(sizeof(int)*x);
	for (int i = 0; i < x; i++)
		scanf("%d", &p[i]);
	
	for (int i = 0; i < x; i++)
		push(&s, p[i]);

	for (int i = 0; i < x; i++)
		printf("%d ", pop(&s));
	


	free(p);
}
*/