/*
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MAX_STACK_SIZE 100

typedef struct {
	int data[MAX_STACK_SIZE];
	int top;
}StackType;

//���� �ʱ�ȭ �Լ�
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
	if (s->top == (MAX_STACK_SIZE - 1))
		return 1;
	else
		return 0;
}
//���� ���� �Լ�
void push(StackType *s, int item) {
	if (is_full(s)) {
		fprintf(stderr, "Full Error\n");
		exit(1);
	}
	else {
		s->top++;
		s->data[s->top] = item;
	}
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
	StackType *s;
	s = (StackType*)malloc(sizeof(StackType));
	init_stack(s);
	push(s, 1);
	push(s, 2);
	push(s, 3);
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));

	free(s);
}
*/