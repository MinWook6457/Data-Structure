/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define MAX_STACK_SIZE 100

typedef int element;               //스택을 구조체로 정의
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s)
{
	s->top = -1;
}

// 공백 검사 함수
int is_empty(StackType* s)
{
	return (s->top == -1);
}

// 포화 검사 함수
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

// 삽입함수
void push(StackType* s, element item)
{
	if (is_full(s))
	{
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

// 삭제함수
element pop(StackType* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
element StackSize(StackType *s) {
	return s->top + 1;
}
int main(void)
{
	int num = 0;
	StackType s;
	init_stack(&s);

	printf("정수를 입력하시오 : ");
	char string[MAX_STACK_SIZE];
	scanf("%s", string);
	num = strlen(string) - 1;

	while (num > -1)
	{
		if (string[num] != string[num - 1])
			push(&s, string[num] - '0');
		num--;
	}

	while (!is_empty(&s))
	{
		printf("%d", pop(&s));
	}

	return 0;
}*/