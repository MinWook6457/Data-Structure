/*
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#pragma warning(disable:4996)
#define MAX_TERM 100
typedef struct {
	int data[MAX_TERM];
	int capacity; // 현재 크기
	int top;
}StackType;

void init_stack(StackType *s) {
	s->top = -1;
}

//스택 공백 검출 함수
int is_empty(StackType *s) {
	if (s->top == -1) {
		return 1;
	}
	else
		return 0;
}
//스택 포화 검출 함수
int is_full(StackType *s) {
	if (s->top == (MAX_TERM- 1))
		return 1;
	else
		return 0;
}
//스택 삽입 함수
void push(StackType *s, int item) {
	if (is_full(s)) {
		return 0;
	}
	s->top++;
	s->data[s->top] = item;
}
//스택 삭제 함수
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
	printf("정수 크기 입력 : ");
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