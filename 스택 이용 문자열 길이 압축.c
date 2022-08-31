
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define MAX_STACK_SIZE 100

typedef char element;
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
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// 삭제함수
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

element peek(StackType* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}

int main(void)
{
	int i, j, num = 0;
	int count = 0;
	StackType s;
	init_stack(&s);

	char string[MAX_STACK_SIZE];
	printf("문자열을 입력하시오 : ");
	scanf("%s", string);
	num = strlen(string);

	for (i = 0; i < num; i++)
		push(&s, string[i]);

	for (i = 97; i < 123; i++)
	{
		for (j = 0; j < num; j++)
		{
			if (65 <= string[j] && string[j] <= 90)
				string[j] += 32;
			if (i == string[j])
				count++;
		}
		if (count == 0)
			continue;
		printf("%d%c", count, i);
		count = 0;
	}

	return 0;
}