
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
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// �����Լ�
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

element peek(StackType* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "���� ���� ����\n");
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
	printf("���ڿ��� �Է��Ͻÿ� : ");
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