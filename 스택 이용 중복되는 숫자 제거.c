/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#define MAX_STACK_SIZE 100

typedef int element;               //������ ����ü�� ����
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType* s)
{
	s->top = -1;
}

// ���� �˻� �Լ�
int is_empty(StackType* s)
{
	return (s->top == -1);
}

// ��ȭ �˻� �Լ�
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

// �����Լ�
void push(StackType* s, element item)
{
	if (is_full(s))
	{
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

// �����Լ�
element pop(StackType* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "���� ���� ����\n");
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

	printf("������ �Է��Ͻÿ� : ");
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