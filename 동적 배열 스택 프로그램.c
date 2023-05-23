/*
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct {
	int *data; // ������ = �迭
	int capacity; // ���� ũ��
	int top;
}StackType;

void init_stack(StackType *s) {
	s->top = -1;
	s->capacity = 1;
	s->data = (int *)malloc(s->capacity * sizeof(int)); // �����Ҵ�
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
	if (s->top == (s->capacity - 1))
		return 1;
	else
		return 0;
}
//���� ���� �Լ�
void push(StackType *s, int item) {
	if (is_full(s)) {
		s->capacity *= 2;
		s->data = (int *)realloc(s->data,s->capacity * sizeof(int)); // �޸� ���Ҵ�
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
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));

	free(s.data);
}*/