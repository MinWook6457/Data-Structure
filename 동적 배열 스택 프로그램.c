/*
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct {
	int *data; // 포인터 = 배열
	int capacity; // 현재 크기
	int top;
}StackType;

void init_stack(StackType *s) {
	s->top = -1;
	s->capacity = 1;
	s->data = (int *)malloc(s->capacity * sizeof(int)); // 동적할당
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
	if (s->top == (s->capacity - 1))
		return 1;
	else
		return 0;
}
//스택 삽입 함수
void push(StackType *s, int item) {
	if (is_full(s)) {
		s->capacity *= 2;
		s->data = (int *)realloc(s->data,s->capacity * sizeof(int)); // 메모리 재할당
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
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));

	free(s.data);
}*/