/*
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
typedef struct StackNode {
	int data;
	struct StackNode *link;
}StackNode;

typedef struct {
	struct StackNode *top;
}LinkedStackType;

void init(LinkedStackType *s) {
	s->top = NULL;
}

int is_empty(LinkedStackType *s) {
	if (s->top == NULL) {
		return 1;
	}
	else return 0;
}

void push(LinkedStackType *s, int value) {
	StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
	if (temp == NULL) {
		fprintf(stderr, "메모리 할당 실패\n");
	}
	temp->data = value;
	temp->link = s->top;
	s->top = temp;
}

int pop(LinkedStackType *s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비었습니다.");
		exit(1);
	}
	else {
		StackNode *temp = s->top;
		int data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}
void print_stack(LinkedStackType *s) {
	for (StackNode *p = s->top; p != NULL; p = p->link)
		printf("!< %d > !\n", p->data);
	printf("-------\n");
}

void clear(LinkedStackType *s) {
	StackNode *temp = s->top;
	StackNode *removed;
	while (temp) {
		removed = temp;
		temp = temp->link;
		free(removed);
	}
	s->top = temp;
}
void main() {
	LinkedStackType s;
	init(&s);
	FILE *fp;
	init(&s);
	fp = fopen("StackLink.txt", "r");
	if (fp == NULL) {
		fprintf(stderr, "파일 열기 실패\n");
		exit(1);
	}

	int data;
	int count = 0;
	printf("--출력--\n");
	while (!feof(fp)) {
		fscanf(fp, "%d", &data);
		push(&s, data);
		count++;
	}
	print_stack(&s);
	int result;
	printf("\n");
	printf("---Clear---\n");
	printf("출력\n");
	clear(&s);
	print_stack(&s);

	fclose(fp);
}
*/